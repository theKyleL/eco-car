#include "stdafx.h"
#include "LaneLineFinder.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "IFinder.h"

using namespace cv;
using namespace std;

void LaneLineFinder::find(cv::Mat* frame1, cv::Mat* frame2, unsigned int frameSeqNum)
{
	//Save the frame locally
	frame1->copyTo(local_frame1);
	frame2->copyTo(local_frame2);

	//Set done variable false
	initProcessing(); //REQUIRED BEFORE THREAD LAUNCH

	//Launch Thread
	finderThread = std::thread(&LaneLineFinder::finder, this, 1);
}

void LaneLineFinder::finder(int frameNum)
{
	Mat tempFrame1,
		transformedFrame1,
		sectionOfTransformed1,
		grayImage1,
		xGaussian,
		normalGaussian,
		noiseRemovedFrame1;

	//Get a subsection to perspective transform
	if(frameNum == 1)
		local_frame1(cv::Rect(0, HORIZON, 1280, 719 - HORIZON)).copyTo(tempFrame1);
	else
		local_frame2(cv::Rect(0, HORIZON, 1280, 719 - HORIZON)).copyTo(tempFrame1);

	//Get the perspective transform
	warpPerspective(tempFrame1, transformedFrame1, lambda, Size(1280, 719 - HORIZON));

	transformedFrame1.copyTo(perspective);

	//Chop usuable area of warped photo
	//414 - 866 
	transformedFrame1(cv::Rect(450, 70, 300, (719 - HORIZON) - 70)).copyTo(sectionOfTransformed1);
	
	/* Debug */
	//transformedFrame1(cv::Rect(450, 70, 300, (719 - HORIZON) - 70)).copyTo(output_frame1_dbg);
	/* Debug */

	//Change to gray color space
	cvtColor(sectionOfTransformed1, grayImage1, CV_BGR2GRAY);

	//Get a normal gaussian blur
	GaussianBlur(
		grayImage1,			//SRC
		normalGaussian,		//DST
		Size(0, 0),			//USED for gaussian kernal
		3,					//sigmaX
		3,					//sigmaY
		BORDER_DEFAULT		//pixel extrapolation method
	);

	//Get an extreme x gaussian
	GaussianBlur(
		grayImage1,			//SRC
		xGaussian,	//DST
		Size(0, 0),			//USED for gaussian kernal
		5,					//sigmaX
		3,					//sigmaY
		BORDER_DEFAULT		//pixel extrapolation method
	);
	
	//Edge Detector
	int normThres,
		xThres;
	
	normThres = 6;
	xThres = 6;

	Canny(normalGaussian, normalGaussian, normThres, normThres * 3, 3);
	Canny(xGaussian, xGaussian, xThres, xThres * 4, 3);
	
	////Get an extreme x gaussian
	//blur(
	//	xGaussian,			//SRC
	//	output_frame1_dbg,	//DST
	//	Size(9, 9)		    //USED for gaussian kernal
	//);

	//equalizeHist(xGaussian, xGaussian);

	/* Debug */
	normalGaussian.copyTo(output_dbg_frame1);
	//xGaussian.copyTo(output_frame1_dbg);
	/* Debug */

	int erosion_size = 2;
	int erosion_type = MORPH_RECT;

	Mat element = getStructuringElement(erosion_type,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));

	dilate(xGaussian, dilated, element);

	//xGaussian.copyTo(output_frame1_dbg);


	/*
	I want Everywhere that is white in xGaussian to be black in normalGaussian

	To do this, xGaussian must be not-ed and then it must be and-ed with normalGaussian

	This would give the following truth table:
		
		norm	|	xGaus	
		0			1
		1			1
		0			0
		1			0

		xGaus not-ed

		norm	|	xGaus	|	Out (and inputs)
		0			0			0
		1			0			0
		0			1			0
		1			1			1

		This gives the logic that: 
		if its white (1) in xGaus, it shall be black (0), 
		and
		if  its black (0) in xGaus, we want the color from norm.

	*/

	//Combine the normal and x gaussian in such a way that the normal noise is gone
	bitwise_not(dilated, dilated);
	bitwise_and(normalGaussian, dilated, noiseRemovedFrame1);

	/* Debug */
	//noiseRemovedFrame1.copyTo(output_frame1_dbg);
	/* Debug */
	//noiseRemovedFrame1.copyTo(output_dbg_frame2);
	output_dbg_frame2 = noiseRemovedFrame1;

	/* Sense lines */
	//vector<Vec4i> lines;
	//HoughLinesP(
	//	noiseRemovedFrame1,		//Frame to analyze
	//	lines,					//Vector to put lines into
	//	1,						//rho, in pixels
	//	CV_PI / 180,			//theta, in radians
	//	50,						//threshold, the minimum num of intersections to detect a line
	//	30,						//minLinLength: The minimum number of points that can form a line. Lines with less than this number of points are disregarded.
	//	20						//maxLineGap: The maximum gap between two points to be considered in the same line.
	//);
	
	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	Vec4i l = lines[i];
	//	line(output_frame1_dbg, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 255, 255), 3, CV_AA);
	//}

	vector<Vec2f> lines;
	HoughLines(
		noiseRemovedFrame1,		//Frame to analyze
		lines,					//Vector to put lines into
		1,						//rho, in pixels
		CV_PI / 180,			//theta, in radians
		40,					//threshold, the minimum num of intersections to detect a line
		0,						//srn
		0						//stn
	);

	int rejectAngle;
	rejectAngle = 30; //Reject a line whose angle is greater than +/- rejectAngle (DEGREES)

	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];

		int thetaTemp = theta * 180 / CV_PI;

		//Get rid of lines outside +/- rejectAngle degrees
		if ((((int)thetaTemp + 360 ) % 360) > rejectAngle && (((int)thetaTemp + 360) % 360) < 360 - rejectAngle)
		{
			//REmove this line
			lines.erase(lines.begin() + i);
			//cout << "Delete: " <<theta << "\n";
		}
		else
		{
			//cout << "Keep: " << theta << "\n";
			//Draw this line
			Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a*rho, y0 = b*rho;
			pt1.x = cvRound(x0 + 1000 * (-b));
			pt1.y = cvRound(y0 + 1000 * (a));
			pt2.x = cvRound(x0 - 1000 * (-b));
			pt2.y = cvRound(y0 - 1000 * (a));
			line(output_dbg_frame2, pt1, pt2, Scalar(255, 255, 255), 3, CV_AA);
		}
	}

	//Add this frames lines to the queue
	lineGroupVector.push_back(lines);

	/* Debug */
	//noiseRemovedFrame1.copyTo(output_frame1_dbg);
	/* Debug */

	//processed.copyTo(warped_section1);

	filterOutput();


	//Let watcher know its done
	doneProcessing(true); //true means we have data we want to transmit (REQUIRED AFTER PROCESSING IS COMPLETLY DONE IS DONE)
}

void LaneLineFinder::filterOutput()
{
	/* Here we filter the queue of found lines such that the lines in the output variables are the filtered version of the queued lines */
	
	int vectorGroupLength,
		vectorGroupLIndex;

	vectorGroupLength = 5;

	//Make sure queue is only n items long (kill the oldest)
	if (lineGroupVector.size() > vectorGroupLength)
	{
		lineGroupVector.erase(lineGroupVector.begin()); //Kill the first index, all the rest is shifted back
	}

	//Iterate through each group of lines
	for (vectorGroupLIndex = 0; vectorGroupLIndex < lineGroupVector.size(); vectorGroupLIndex++)
	{
		//Iterate over the i-th group of lines
		for (size_t i = 0; i < lineGroupVector[vectorGroupLIndex].size(); i++)
		{
			float	rho = lineGroupVector[vectorGroupLIndex][i][0],
					theta = lineGroupVector[vectorGroupLIndex][i][1];


			
		}
	}

}

void LaneLineFinder::initLambda()
{
	//Create the points to make transformation matrix
	Point2f inputQuad[4];
	Point2f outputQuad[4];

	//Lambda Matrix
	lambda = Mat(2, 4, CV_32FC1);
	Mat input, output;

	//Setup the Lambda matrix
	lambda = Mat::zeros(1280, 720, 16);
	//output_frame1 = Mat::zeros(1920, 1080, 16);

	/* Assign values to the input and output points to generate the transform */
	// These four pts are the sides of the rect box used as input 
	//From drawing a square
	//inputQuad[0] = Point2f(568, 677);
	//inputQuad[1] = Point2f(658, 677);
	//inputQuad[2] = Point2f(658, 710);
	//inputQuad[3] = Point2f(568, 710);

	//From clicking
	//inputQuad[0] = Point2f(509, 603);//UL
	//inputQuad[1] = Point2f(602, 601);//UR
	//inputQuad[2] = Point2f(498, 635);//LL
	//inputQuad[3] = Point2f(605, 635);//LR

	//From road
	//inputQuad[0] = Point2f(567, 302);//UL
	//inputQuad[1] = Point2f(631, 301);//UR
	//inputQuad[2] = Point2f(0, 719);//LL
	//inputQuad[3] = Point2f(1279, 719);//LR

	//from road video after crop
	inputQuad[0] = Point2f(523, 23);//UL
	inputQuad[1] = Point2f(650, 23);//UR
	inputQuad[2] = Point2f(0, 719 - HORIZON);//LL
	inputQuad[3] = Point2f(1279, 719 - HORIZON);//LR

	// The 4 points where the mapping is to be done , from top-left in clockwise order
	//From drawing a square
	//outputQuad[0] = Point2f(565, 570);
	//outputQuad[1] = Point2f(662, 570);
	//outputQuad[2] = Point2f(662, 710);
	//outputQuad[3] = Point2f(565, 710);
	
	//From clicking
	//outputQuad[0] = Point2f(498, 484);//UL
	//outputQuad[1] = Point2f(605, 484);//UR
	//outputQuad[2] = Point2f(498, 635);//LL
	//outputQuad[3] = Point2f(605, 635);//LR

	//From road
	//outputQuad[0] = Point2f(567, 302);//UL
	//outputQuad[1] = Point2f(631, 301);//UR
	//outputQuad[2] = Point2f(567, 719);//LL
	//outputQuad[3] = Point2f(631, 719);//LR

	//from video of road after crop
	outputQuad[0] = Point2f(523, 23);//UL
	outputQuad[1] = Point2f(650, 23);//UR
	outputQuad[2] = Point2f(523, 719 - HORIZON);//LL
	outputQuad[3] = Point2f(650, 719 - HORIZON);//LR

	//Get the perspective transform matrix
	lambda = getPerspectiveTransform(inputQuad, outputQuad);
}

LaneLineFinder::LaneLineFinder()
{
	//Let watcher know its done
	doneProcessing(false); //Dont start a transmitter, but feed us a frame!  (REQUIRED TO START PROCESSING)

	initLambda();
}


LaneLineFinder::~LaneLineFinder()
{
}
