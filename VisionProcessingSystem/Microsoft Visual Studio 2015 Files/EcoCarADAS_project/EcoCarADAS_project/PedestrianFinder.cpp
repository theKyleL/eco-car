/// Author: Austin Musser
///
///
/// Some code from GitHub
/// Author: Chris Dahms
/// GitHub page: MicrocontrollersAndMore
/// Project: OpenCV_3_KNN_Character_Recognition_Cpp
/// URL: https://github.com/MicrocontrollersAndMore/OpenCV_3_KNN_Character_Recognition_Cpp
///

#include "stdafx.h"
#include "PedestrianFinder.h"
#include <opencv2\opencv.hpp>

#include <cstdio>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>
#include "IFinder.h"


using namespace cv;

//B = distance between cameras
//x0 = number of pixels in the width of the camera
//theata0 = viewing angle of the camera 60 degrees
//deltaX = difference between x points of the same object in the two images images
//D the distance to the object
//D = (B * x0)/(2*Tan(theata0/2)*(deltaX));

// The constatant is calculated by:
// DISTANCE_CALC_VALUE = (B * x0)/(2*Tan(theata0/2)) = ((1 foot) * (1280 pixels)) / (2 * tan((60 degress) / 2))
// To calculate distance:
// D = DISTANCE_CALC_VALUE / deltaX
const double DISTANCE_CALC_VALUE = 1108.512517;

void PedestrianFinder::find(cv::Mat* frame1, cv::Mat* frame2, unsigned int frameSeqNum)
{
	//Save the frame locally
	frame1->copyTo(local_frame1);
	frame2->copyTo(local_frame2);

	//Set done variable false
	initProcessing(); //REQUIRED BEFORE THREAD LAUNCH

	pedestrianData.header.sequence = frameSeqNum;
	//pedestrianData.header.type = pedestrian; //////////////////////////////////////?????????????????????????????????????????? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?

	//Launch Thread
	finderThread = std::thread(&PedestrianFinder::processFrame1and2, this);
}

void PedestrianFinder::processFrame1and2()
{
	std::thread thread1(&PedestrianFinder::finder, this, 1);
	std::thread thread2(&PedestrianFinder::finder, this, 2);
	thread1.join();
	thread2.join();

	bool tempTest = false;

	if ((pedestrianMemFrame1[0].x > -1) && (pedestrianMemFrame2[0].x > -1))
	{
		double deltaX = abs((pedestrianMemFrame1[0].x + (pedestrianMemFrame1[0].width / 2)) - (pedestrianMemFrame2[0].x + (pedestrianMemFrame2[0].width / 2)));

		distanceToP = DISTANCE_CALC_VALUE / deltaX;
		tempTest = true;
	}
	else
	{
		distanceToP = -1;
	}

	//These two need to be transmited to the user plus distanceToSS
	confidence = (confidenceFrame1 + confidenceFrame2) / 2;		//taking the average confidence of frame1 and frame2
	pedestrianToTransmit = pedestrianMemFrame1[0];					// Only sending the location of the stop sign in the right frame because that is the one being shown on the display.


	if (confidence >= frameConfidenceToTransmit)
	{
		foundPedestrian = true;
	}
	else
	{
		foundPedestrian = false;
	}

	pedestrianData.confidence = confidence;
	pedestrianData.distance = distanceToP;
	pedestrianData.x_location = (pedestrianToTransmit.x - (pedestrianToTransmit.width / 2));
	pedestrianData.y_location = (pedestrianToTransmit.y - (pedestrianToTransmit.height / 2));
	pedestrianData.radius = pedestrianToTransmit.width / 2;


	//Let watcher know its done  (REQUIRED AFTER PROCESSING IS COMPLETLY DONE IS DONE)
	//doneProcessing(foundStopSign);	// if a stop sign is found in either frame will say that there is a stop sign
	doneProcessing(true);		// This is for debuging to see all the frames
								//doneProcessing(tempTest); // This is for degubgin just to see the last frame that had a distance

	std::cout << "SS Distance: " << distanceToP << "\n" << "SS Confidence: " << confidence << "\n\n";
}

void PedestrianFinder::finder(int frameNum)
{
	//WRITE ALGORITHM HERE

	//////////////////////////////////////////////////////////////////////////////////////////
	//Initialize variables																	//
	//////////////////////////////////////////////////////////////////////////////////////////
	///These variables are being initialized here so that this can be threaded for both input
	///frames so that each thread will have its own variables.

	//Vectors of contours of type CountourWithData defined in the header file
	std::vector<ContourWithData> allContoursWithData;
	std::vector<ContourWithData> validContoursWithData;
	//std::vector<ContourWithData> STOPContoursWithData;
	//std::vector<ContourWithData> validSTOPContoursWithData;
	//std::vector<ContourWithData> stopSignContoursWithData;
	//std::vector<ContourWithData> validStopSignContoursWithData;

	//Mat vars for finding countors
	cv::Mat matGrayscale;
	cv::Mat matBlurred;
	cv::Mat matThresh;
	cv::Mat matThreshCopy;

	std::vector<std::vector<cv::Point> > ptContours;
	std::vector<cv::Vec4i> v4iHierarchy;

	ContourWithData contourWithData;
	cv::Mat matROIResized;
	cv::Mat matROIFloat;

	cv::Mat inputImage;

	//BMDIT vars
	//cv::Mat3b bgr, hsv;
	//cv::Mat1b mask1, mask2, hsvMask;

	//cv::Mat part;
	//cv::Mat outPutBMDIT = cv::Mat(FRAME_HEIGHT, FRAME_WIDTH, CV_8UC3);;

	//int x, y, w, h;
	//int range = 8;	// 8 is good, 6 is ok
	//int gap = 2;	// 2 is good

	//bool rowMem[1280];

	//Stop sign averages 
	int PaverageX = 0;
	int PaverageY = 0;
	int PaverageWidth = 0;
	int PaverageHeight = 0;

	//Stop sign memory
	cv::Rect pedestrianMem[10];

	int pedestrianPercentage = 0;

	//STOP letter contour vars
	//int S = 0;
	//int T = 0;
	//int O = 0;
	//int P = 0;

	//int saveValidContours = 0;
	//int savedPrevValidSTOPContours = 0;



	if (frameNum == 1)
	{
		inputImage = local_frame1;
		for (int i = 0; i < PMemSize; i++)
		{
			pedestrianMem[i] = pedestrianMemFrame1[i];
		}
	}
	else if (frameNum == 2)
	{
		inputImage = local_frame2;
		for (int i = 0; i < PMemSize; i++)
		{
			pedestrianMem[i] = pedestrianMemFrame2[i];
		}
	}



	//////////////////////////////////////////////////////////////////////////////////////////
	//BMDIT code																			//
	//////////////////////////////////////////////////////////////////////////////////////////
	/// First an HSV mas is appied to the input image for the color red. Then it made into a
	/// binary image where white corresponds to the red part of the image.  Then parts from
	/// the original image that are at and around the white parts of the binary image are
	/// coppied to a blank image. This new image is then processed, having a lot less too work
	/// with speeding up the time it takes to find contours.  This also does not loop through
	/// every single pixle from the binary image, but skips through them base on the defined 'gap'.

	// Create a red hsv mask
	//bgr = inputImage;

	//cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);

	//inRange(hsv, cv::Scalar(171, 115, 0), cv::Scalar(180, 255, 255), mask1);
	//inRange(hsv, cv::Scalar(0, 115, 0), cv::Scalar(9, 255, 255), mask2);

	//hsvMask = mask1 | mask2;

	////Copy areas that contain and are around red pixles from the original image onto a blank image
	//for (int k = topShift; k < heightSift; k += gap)			// Loops through the rows from the indexes of the reduced image skipping some rows based on 'gap' 
	//{
	//	for (int j = widthSift; j < inputImage.cols; j += gap)	// Loops through the cols from the indexes of the reduced image skipping some cols based on 'gap' 
	//	{
	//		cv::Scalar colour = hsvMask.at<uchar>(cv::Point(j, k));	// get the value the current pixel, the hsvMask is a binary image

	//		if (colour.val[0] > 0.00000000)	// If the pixel is not black (if its white)
	//		{
	//			// find the x value to use
	//			if (j < range + widthSift)			//if we are too close to the left bound
	//			{
	//				x = widthSift;
	//			}
	//			else if (rowMem[j - gap] == true)	//looks at previous column in that row, if 1 then we dont need to copy some of that image bcause it was done last time
	//			{
	//				x = j + (range - gap);
	//			}
	//			else								//if we are away from left bound and previous comlumn on this row was not coppied
	//			{
	//				x = j - range;
	//			}

	//			// find the y value to use
	//			if (k < range + topShift)			//if we are too close to the top bound
	//			{
	//				y = topShift;
	//			}
	//			else if (rowMem[j] == true)			//Looks at the previous row in that column, if 1 then we dont need to copy some of that image bcause it was done on the last row
	//			{
	//				y = k + (range - gap);
	//			}
	//			else								//if we are away from the top bound and previous row in this column was not coppied
	//			{
	//				y = k - range;
	//			}

	//			// find the width to use
	//			if ((inputImage.cols - j) <= range)	//if we are too close the the right bound
	//			{
	//				if (rowMem[j - gap] == true)		//looks at previous column in that row
	//				{
	//					w = 0;
	//				}
	//				else
	//				{
	//					w = inputImage.cols - j + range;
	//				}
	//			}
	//			else if (rowMem[j - gap] == true)	//looks at previous column in that row
	//			{
	//				w = gap;
	//			}
	//			else
	//			{
	//				w = range * 2;
	//			}

	//			// find the height to use
	//			if ((heightSift - k) <= range)		//if we are too close to the bottom bound
	//			{
	//				if (rowMem[j] == true)			//Looks at the previous row in that column
	//				{
	//					h = 0;
	//				}
	//				else
	//				{
	//					h = heightSift - k + range;
	//				}
	//			}
	//			else if (rowMem[j] == true)			//Looks at the previous row in that column
	//			{
	//				h = gap;
	//			}
	//			else
	//			{
	//				h = range * 2;
	//			}

	//			// if the width and height are greater than 0 copy the chunk from the original on to the blank image
	//			if ((w > 0) && (h > 0))
	//			{
	//				part = inputImage(cv::Rect(x, y, w, h));
	//				part.copyTo(outPutBMDIT(cv::Rect(cv::Rect(x, y, w, h))));
	//			}

	//			rowMem[j] = true;	//Saves true if it currenly just did a copy for its position
	//		}
	//		else
	//		{
	//			rowMem[j] = false;	//Saves fales if it currenly did NOT copy anything for its position
	//		}
	//	}
	//}



	//////////////////////////////////////////////////////////////////////////////////////////
	//Creating reduced images for processing												//
	//////////////////////////////////////////////////////////////////////////////////////////

	// Create reduced imaged to work with
	//cv::Mat matReducedBMDIT(
	//	outPutBMDIT,
	//	cv::Range(topShift, heightSift),			//rows
	//	cv::Range(widthSift, inputImage.cols));		// cols

	cv::Mat matReducedOriginal(
		inputImage,
		cv::Range(topShift, heightSift),			//rows
		cv::Range(widthSift, inputImage.cols));		// cols



													//////////////////////////////////////////////////////////////////////////////////////////
													//Finding valid contours and add them to a vector										//
													//////////////////////////////////////////////////////////////////////////////////////////


													// convert to grayscale
	cv::cvtColor(matReducedOriginal, matGrayscale, CV_BGR2GRAY);

	// blur
	cv::GaussianBlur(matGrayscale,              // input image
		matBlurred,								// output image
		cv::Size(5, 5),							// smoothing window width and height in pixels
		0);										// sigma value, determines how much the image will be blurred, zero makes function choose the sigma value

												// filter image from grayscale to black and white
	cv::adaptiveThreshold(matBlurred,           // input image
		matThresh,								// output image
		255,									// make pixels that pass the threshold full white
		cv::ADAPTIVE_THRESH_GAUSSIAN_C,			// use gaussian rather than mean, seems to give better results
		cv::THRESH_BINARY_INV,					// invert so foreground will be white, background will be black
		11,										// size of a pixel neighborhood used to calculate threshold value
		2);										// constant subtracted from the mean or weighted mean

												// make a copy of the thresh image, this in necessary b/c findContours modifies the image
	matThreshCopy = matThresh.clone();


	cv::findContours(matThreshCopy,             // input image, make sure to use a copy since the function will modify this image in the course of finding contours
		ptContours,                             // output contours
		v4iHierarchy,                           // output hierarchy
		cv::RETR_LIST,							// retrieve the outermost contours only //EXTERNAL
		cv::CHAIN_APPROX_SIMPLE);               // compress horizontal, vertical, and diagonal segments and leave only their end points


	for (int i = 0; i < ptContours.size(); i++) {											// for each contour
		contourWithData.ptContour = ptContours[i];                                          // assign contour to contour with data
		contourWithData.boundingRect = cv::boundingRect(contourWithData.ptContour);         // get the bounding rect
		contourWithData.fltArea = cv::contourArea(contourWithData.ptContour);               // calculate the contour area
		allContoursWithData.push_back(contourWithData);                                     // add contour with data object to list of all contours with data
	}

	for (int i = 0; i < allContoursWithData.size(); i++) {                      // for all contours
		if (allContoursWithData[i].checkIfContourIsValid()) {                   // check if valid
			validContoursWithData.push_back(allContoursWithData[i]);            // if so, append to valid contour list
		}
	}
	// sort contours from left to right
	std::sort(validContoursWithData.begin(), validContoursWithData.end(), ContourWithData::sortByBoundingRectXPosition);



	//////////////////////////////////////////////////////////////////////////////////////////
	//Looping though every contour and comparing to trained data							//
	//////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < validContoursWithData.size(); i++) {            // for each contour


		cv::Mat matROI = matThresh(validContoursWithData[i].boundingRect);							// get ROI image of bounding rect

		cv::resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));     // resize image, this will be more consistent for recognition and storage

		matROIResized.convertTo(matROIFloat, CV_32FC1);												// convert Mat to float, necessary for call to find_nearest

		cv::Mat matROIFlattenedFloat = matROIFloat.reshape(1, 1);

		cv::Mat matCurrentChar(0, 0, CV_32F);

		kNearest->findNearest(matROIFlattenedFloat, 1, matCurrentChar);								// finally we can call find_nearest !!!

		float fltCurrentChar = (float)matCurrentChar.at<float>(0, 0);


		// If a z is found then that means it things its a stop sign
		if (int(fltCurrentChar) == 'z')
		{
			//strFinalString = strFinalString + char(int(fltCurrentChar));        // append current char to full string

			//contourWithData.contourChar = int(fltCurrentChar);
			//contourWithData.boundingRect = validContoursWithData[i].boundingRect;
			//stopSignContoursWithData.push_back(contourWithData);
		}

		// If a STOP contour was found save it and its letter to a vector of STOP contours
		//if ((int(fltCurrentChar) == 'S') || int(fltCurrentChar) == 'T' || int(fltCurrentChar) == 'O' || int(fltCurrentChar) == 'P')
		//{
		//	contourWithData.contourChar = int(fltCurrentChar);
		//	contourWithData.boundingRect = validContoursWithData[i].boundingRect;
		//	STOPContoursWithData.push_back(contourWithData);

		//	//strFinalString = strFinalString + char(int(fltCurrentChar));        // append current char to full string

		//	// Set the variables STOP to 1 if they were found. This is to remember what letters we have seen in a single frame
		//	if (int(fltCurrentChar) == 'S')
		//	{
		//		S = 1;
		//	}
		//	if (int(fltCurrentChar) == 'T')
		//	{
		//		T = 1;
		//	}
		//	if (int(fltCurrentChar) == 'O')
		//	{
		//		O = 1;
		//	}
		//	if (int(fltCurrentChar) == 'P')
		//	{
		//		P = 1;
		//	}
		//}
	}



	//////////////////////////////////////////////////////////////////////////////////////////
	//Outlining valid stop signs and keeping track of there locations						//
	//////////////////////////////////////////////////////////////////////////////////////////

	// Loop though every stop sign contour and add the components
	//for (int q = 0; q < stopSignContoursWithData.size(); q++)
	//{
	//	if (abs(stopSignContoursWithData[q].boundingRect.width - stopSignContoursWithData[q].boundingRect.height) <= SS_WIDTH_HEIGHT_DIFF)
	//	{
	//		validStopSignContoursWithData.push_back(stopSignContoursWithData[q]);

	//		//adding each of the stop sign componets together to get the average
	//		SSaverageX += stopSignContoursWithData[q].boundingRect.x + widthSift;
	//		SSaverageY += stopSignContoursWithData[q].boundingRect.y + topShift;
	//		SSaverageWidth += stopSignContoursWithData[q].boundingRect.width;
	//		SSaverageHeight += stopSignContoursWithData[q].boundingRect.height;
	//	}
	//}

	//if at least one stop sign was found 
	//if (validStopSignContoursWithData.size() > 0)
	//{
	//	//calculating the acutal averages of all the stop signs found
	//	SSaverageX = std::round(SSaverageX / validStopSignContoursWithData.size()) - widthSift;
	//	SSaverageY = std::round(SSaverageY / validStopSignContoursWithData.size()) - topShift;
	//	SSaverageWidth = std::round(SSaverageWidth / validStopSignContoursWithData.size());
	//	SSaverageHeight = std::round(SSaverageHeight / validStopSignContoursWithData.size());

	//	//draw the stop sign
	//	cv::rectangle(matReducedBMDIT,                           // draw rectangle on reduced BMDIT image
	//		cv::Point(SSaverageX, SSaverageY),
	//		cv::Point(SSaverageWidth + SSaverageX, SSaverageHeight + SSaverageY),
	//		cv::Scalar(0, 255, 0),							// green
	//		2);												// thickness

	//	cv::rectangle(matReducedOriginal,                   // draw rectangle on reduced original image
	//		cv::Point(SSaverageX, SSaverageY),
	//		cv::Point(SSaverageWidth + SSaverageX, SSaverageHeight + SSaverageY),
	//		cv::Scalar(0, 255, 0),							// green
	//		2);												// thickness

	//	stopSignMem[0].x = SSaverageX;
	//	stopSignMem[0].y = SSaverageY;
	//	stopSignMem[0].width = SSaverageWidth;
	//	stopSignMem[0].height = SSaverageHeight;
	//}
	//else
	//{
	//	stopSignMem[0].x = -1;
	//	stopSignMem[0].y = -1;
	//	stopSignMem[0].width = -1;
	//	stopSignMem[0].height = -1;
	//}

	pedestrianPercentage = 0;

	//adds 8 percent for every stop sign that has been seen in the last 10 frames
	for (int i = 0; i < PMemSize; i++)
	{
		if (pedestrianMem[i].x > 0)
		{
			pedestrianPercentage += 8;
		}
	}



	//////////////////////////////////////////////////////////////////////////////////////////
	//Find and outlining valid STOP(letters) countours if three were found in a frame		//
	//////////////////////////////////////////////////////////////////////////////////////////

	// If at least three of the four letters were found a frame run this code
	//if ((S + T + O + P) >= 3)
	//{
	//	// This loop determind if the found letters are valid (if they all are close enough to each other to be considered on a single stop sign)
	//	for (int q = 0; q < STOPContoursWithData.size() - 1; q++)
	//	{
	//		//Checks the x points of the current letter and the next letter to see if they are with a range of each other
	//		if (abs(STOPContoursWithData[q].boundingRect.x - STOPContoursWithData[q + 1].boundingRect.x) < STOPContoursWithData[q].boundingRect.width * 2.15)
	//		{
	//			//Checks the y points of the current letter and the next letter to see if they are with a range of each other
	//			if (abs(STOPContoursWithData[q].boundingRect.y - STOPContoursWithData[q + 1].boundingRect.y) < STOPContoursWithData[q].boundingRect.height * 0.5)
	//			{
	//				// If the current letter is a S the the next one must be a T or an O
	//				if (STOPContoursWithData[q].contourChar == 'S')
	//				{
	//					if ((STOPContoursWithData[q + 1].contourChar == 'T') || (STOPContoursWithData[q + 1].contourChar == 'O'))
	//					{
	//						saveValidContours = 1;
	//					}
	//				}
	//				// If the current letter is an T the the next one must be an O or a P
	//				if (STOPContoursWithData[q].contourChar == 'T')
	//				{
	//					if ((STOPContoursWithData[q + 1].contourChar == 'O') || (STOPContoursWithData[q + 1].contourChar == 'P'))
	//					{
	//						saveValidContours = 1;
	//					}
	//				}
	//				// If the current letter is an O the the next one must ba a P
	//				if (STOPContoursWithData[q].contourChar == 'O')
	//				{
	//					if (STOPContoursWithData[q + 1].contourChar == 'P')
	//					{
	//						saveValidContours = 1;
	//					}
	//				}
	//				// If the order of the two letters being comparied makes sense save them to valedSTOPContoursWithData
	//				if (saveValidContours == 1)
	//				{
	//					// If the previous set of countours were saved dont save the current one because it was already save last time
	//					if (savedPrevValidSTOPContours == 0)
	//					{
	//						// save current contour
	//						contourWithData.boundingRect = STOPContoursWithData[q].boundingRect;
	//						validSTOPContoursWithData.push_back(contourWithData);
	//					}

	//					// save next contour
	//					contourWithData.boundingRect = STOPContoursWithData[q + 1].boundingRect;
	//					validSTOPContoursWithData.push_back(contourWithData);

	//					savedPrevValidSTOPContours = 1;		// Set this to a 1 for next valed STOP contour
	//				}
	//				else
	//				{
	//					savedPrevValidSTOPContours = 0;		// Set this to a 0 for next valed STOP contour
	//				}
	//				saveValidContours = 0;	// Rest for next STOP contour
	//			}
	//		}
	//	}

	//if (validSTOPContoursWithData.size() >= 3)
	//{
	//	//strFinalString = strFinalString + "'z'";
	//	stopSignPercentage += 20;
	//}

	//// Loop though every valid letter contour and draw blue box around it
	//for (int q = 0; q < validSTOPContoursWithData.size(); q++)
	//{
	//	cv::rectangle(matReducedBMDIT,                           // draw rectangle on reduced BMDIT image
	//		validSTOPContoursWithData[q].boundingRect,       // rect to draw
	//		cv::Scalar(255, 0, 0),							// blue
	//		2);												// thickness

	//	cv::rectangle(matReducedOriginal,                   // draw rectangle on reduced original image
	//		validSTOPContoursWithData[q].boundingRect,       // rect to draw
	//		cv::Scalar(255, 0, 0),							// blue
	//		2);												// thickness
	//}
	//}




	//////////////////////////////////////////////////////////////////////////////////////////
	//End stuff and resting vars for next frame												//
	//////////////////////////////////////////////////////////////////////////////////////////

	// Draw out lines on redueced images
	//cv::rectangle(matReducedBMDIT,							// draw outline of the reduced BMDIT image
	//	cv::Point(0, 0),
	//	cv::Point(matReducedBMDIT.cols, matReducedBMDIT.rows),
	//	cv::Scalar(0, 0, 255),							// red
	//	2);												// thickness

	cv::rectangle(matReducedOriginal,                   // draw outline of the reduced original image
		cv::Point(0, 0),
		cv::Point(matReducedOriginal.cols, matReducedOriginal.rows),
		cv::Scalar(0, 0, 255),							// red
		2);												// thickness


														// Print the percentage
														//std::cout << " Confident Percentage: " << stopSignPercentage << "%" <<"\n\n";


														//Shifting stop sign memory
	for (int i = PMemSize - 1; i > 0; i--)
	{
		pedestrianMem[i] = pedestrianMem[i - 1];
	}


	// Saving data after processing frame 1 and frame 2
	if (frameNum == 1)
	{
		output_dbg_frame1 = inputImage;

		for (int i = 0; i < PMemSize; i++)
		{
			pedestrianMemFrame1[i] = pedestrianMem[i];
		}

		confidenceFrame1 = pedestrianPercentage;
	}
	else if (frameNum == 2)
	{
		output_dbg_frame2 = inputImage;

		for (int i = 0; i < PMemSize; i++)
		{
			pedestrianMemFrame2[i] = pedestrianMem[i];
		}

		confidenceFrame2 = pedestrianPercentage;
	}
}


PedestrianFinder::PedestrianFinder()
{
	//////////////////////////////////////////////////////////////////////////////////////////
	//Reading in the training data and training the KNN object								//
	//////////////////////////////////////////////////////////////////////////////////////////

	cv::Mat matClassificationInts;																	// we will read the classification numbers into this variable as though it is a vector

	cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::READ);				// open the classifications file

	if (fsClassifications.isOpened() == false)
	{																								// if the file was not opened successfully
		std::cout << "error, unable to open training classifications file, exiting program\n\n";    // show error message
	}

	fsClassifications["classifications"] >> matClassificationInts;									// read classifications section into Mat classifications variable
	fsClassifications.release();																	// close the classifications file


																									// read in training images //
	cv::Mat matTrainingImagesAsFlattenedFloats;														// we will read multiple images into this single image variable as though it is a vector

	cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::READ);							// open the training images file

	if (fsTrainingImages.isOpened() == false)
	{																								// if the file was not opened successfully
		std::cout << "error, unable to open training images file, exiting program\n\n";				// show error message
	}

	fsTrainingImages["images"] >> matTrainingImagesAsFlattenedFloats;								// read images section into Mat training images variable
	fsTrainingImages.release();																		// close the traning images file

	kNearest = (cv::ml::KNearest::create());														// train and instantiate the KNN object

	kNearest->train(matTrainingImagesAsFlattenedFloats, cv::ml::ROW_SAMPLE, matClassificationInts);	// finally we get to the call to train, note that both parameters have to be of type Mat (a single Mat)
																									// even though in reality they are multiple images / numbers

																									//Let watcher know its done
	doneProcessing(false);//dont start a transmitter but feed us a frame (REQUIRED TO START PROCESSING)
}


PedestrianFinder::~PedestrianFinder()
{
}
