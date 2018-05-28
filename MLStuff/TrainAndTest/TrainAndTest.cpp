/// Author: Austin Musser
///
/// This code reads in frames from a video file and looks for stop signs in them.
/// It is able to find stop signs by reading in two xml files of trained data of stop signs
/// where the letter 'z' represents a stop sign, 'x' represents not a stop sign, 'S', 'T',
/// 'O', and 'P' represent the letters on a stop sign. When it reads in these xml files 
/// it trains a KNN object.  The program finds contours in the image and compares them 
/// to the trained KNN object.  To speed up the processing the area of the frame that it 
/// it is looking at has been reduced in two ways.  The first way is by taking a small part
/// of the entire image where the stopsign can come into view.  The second way is to only show 
/// the areas around and containing red.  When looking for the letters on the stop sign, 
/// the accepted letters are checked to see if they are close enough to each other, are in 
/// the correct order to spell "stop", and if there are at least three of the four letters 
/// in a single frame.  When the program is first looking for counters it also limits valid
/// contour based on a min and max height and width, along with a maximum difference between
/// height and width.
///
/// Some code from GitHub
/// Author: Chris Dahms
/// GitHub page: MicrocontrollersAndMore
/// Project: OpenCV_3_KNN_Character_Recognition_Cpp
/// URL: https://github.com/MicrocontrollersAndMore/OpenCV_3_KNN_Character_Recognition_Cpp
///


#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<iostream>
#include<sstream>
#include<string>


// global variables ///////////////////////////////////////////////////////////////////////////////
//const int MIN_CONTOUR_AREA = 100;
//const int MAX_CONTOUR_AREA = 2000;
const int RESIZED_IMAGE_WIDTH = 30;
const int RESIZED_IMAGE_HEIGHT = 30;

const int MIN_CONTOUR_WIDTH = 20;
const int MAX_CONTOUR_WIDTH = 150;
const int WIDTH_HEIGHT_DIFF = 20;	

//These are used to reduce the size of frame that is being procesed.
const double RIGHT_PORTION = 0.55; //percentage of the top right of the image to look for things
const double TOP_PORTION = 0.6; //percentage of the top right of the image to look for things
const double BOTTOM_PORTION = 0.9; //percentage of the bottom of the image to look for things

//These are used to take a portion of the orignal fram to be zoomed in on
//The digital zoom will also use right and top portion from above
const double ZOOM_BOTTOM_PORTION = 0.65;
const double ZOOM_LEFT_PORTION = 0.6;
const int ZOOM_FACTOR = 3;

const int FRAME_START = 0;
const char FILE_NAME[77] = "C:\\Users\\Austin Musser\\Videos\\New folder\\New folder (6)\\Camera_1_capture.avi";




///////////////////////////////////////////////////////////////////////////////////////////////////
class ContourWithData {
public:
	// member variables 
	std::vector<cv::Point> ptContour;           // contour
	cv::Rect boundingRect;                      // bounding rect for contour
	float fltArea;                              // area of contour
	int contourChar;

	bool checkIfContourIsValid() {                              // obviously in a production grade program we would have a much more robust function for 
		//(fltArea < MIN_CONTOUR_AREA) || (fltArea > MAX_CONTOUR_AREA) 
		if ((boundingRect.width < MIN_CONTOUR_WIDTH) || (boundingRect.width > MAX_CONTOUR_WIDTH)
			|| (boundingRect.height < MIN_CONTOUR_WIDTH) || (boundingRect.height > MAX_CONTOUR_WIDTH)
			|| (abs(boundingRect.height - boundingRect.width) > WIDTH_HEIGHT_DIFF))
			return false;										
		return true;                                            // identifying if a contour is valid !!
	}

	static bool sortByBoundingRectXPosition(const ContourWithData& cwdLeft, const ContourWithData& cwdRight) {      // this function allows us to sort
		return(cwdLeft.boundingRect.x < cwdRight.boundingRect.x);                                                   // the contours from left to right
	}

};


int main() {
	//////////////////////////////////////////////////////////////////////////////////////////
	//Declare vars!!!																		//
	//////////////////////////////////////////////////////////////////////////////////////////

	std::vector<ContourWithData> allContoursWithData;           // declare empty vectors,
	std::vector<ContourWithData> validContoursWithData;         // we will fill these shortly
	std::vector<ContourWithData> STOPContoursWithDat;        
	std::vector<ContourWithData> validSTOPContoursWithDat;
	std::vector<ContourWithData> stopSignContoursWithDat;
	std::vector<ContourWithData> validStopSignContoursWithDat;


	cv::Mat matGrayscale;           //
	cv::Mat matBlurred;             // declare more image variables
	cv::Mat matThresh;              //
	cv::Mat matThreshCopy;          //


	std::vector<std::vector<cv::Point> > ptContours;        // declare a vector for the contours
	std::vector<cv::Vec4i> v4iHierarchy;                    // declare a vector for the hierarchy (we won't use this in this program but this may be helpful for reference)


	std::string strFinalString;         // declare final string, this will have the final number sequence by the end of the program

	ContourWithData contourWithData;                                                    // instantiate a contour with data object
	cv::Mat matROIResized;
	cv::Mat matROIFloat;

	cv::Mat inputImage;


	//int frameCount = 0;

	//These are used to produce the reduced image to process
	//They use constants that define the percentage of the desired image
	int widthSift;
	int heightSift;
	int topShift;

	//Zoom vars
	cv::Mat portionToZoom;
	cv::Mat zoomedInPortion;
	int ZoomX, ZoomY, ZoomWidth, ZoomHeight;

	//BMDIT vars
	cv::Mat3b bgr, hsv;
	cv::Mat1b mask1, mask2, hsvMask;

	cv::Mat part;
	cv::Mat outPutBMDIT(720, 1280, CV_8UC3); //this is an empyt image and will need to be reset every frame
	outPutBMDIT *= 0;						//this sets the image to black to start with

	int x, y, w, h;
	int range = 8;	// 8 is good, 6 is ok
	int gap = 2;	// 2 is good

	bool rowMem[1280];

	//Image saving var
	int imageNum = 0; 

	//Stop sign memory
	int SSaverageX;
	int SSaverageY;
	int SSaverageWidth;
	int SSaverageHeight;

	int SSMemSize = 10;
	int SSxLocation[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int SSyLocation[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int SSwidth[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int SSheight[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	//STOP letter contour vars
	int S = 0;
	int T = 0;
	int O = 0;
	int P = 0;

	int saveValidContours = 0;
	int savedPrevValidSTOPContours = 0;

	


	//////////////////////////////////////////////////////////////////////////////////////////
	//Reading training data and train KNN object											//
	//////////////////////////////////////////////////////////////////////////////////////////

	// read in training classifications //
	cv::Mat matClassificationInts;																	// we will read the classification numbers into this variable as though it is a vector

	cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::READ);				// open the classifications file

	if (fsClassifications.isOpened() == false) {                                                    // if the file was not opened successfully
		std::cout << "error, unable to open training classifications file, exiting program\n\n";    // show error message
		return(0);                                                                                  // and exit program
	}

	fsClassifications["classifications"] >> matClassificationInts;									// read classifications section into Mat classifications variable
	fsClassifications.release();																	// close the classifications file


	// read in training images //
	cv::Mat matTrainingImagesAsFlattenedFloats;														// we will read multiple images into this single image variable as though it is a vector

	cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::READ);							// open the training images file

	if (fsTrainingImages.isOpened() == false) {														// if the file was not opened successfully
		std::cout << "error, unable to open training images file, exiting program\n\n";				// show error message
		return(0);																					// and exit program
	}

	fsTrainingImages["images"] >> matTrainingImagesAsFlattenedFloats;								// read images section into Mat training images variable
	fsTrainingImages.release();																		// close the traning images file

	// train //
	cv::Ptr<cv::ml::KNearest>  kNearest(cv::ml::KNearest::create());								// instantiate the KNN object
														
	kNearest->train(matTrainingImagesAsFlattenedFloats, cv::ml::ROW_SAMPLE, matClassificationInts);	// finally we get to the call to train, note that both parameters have to be of type Mat (a single Mat)
																									// even though in reality they are multiple images / numbers


	//////////////////////////////////////////////////////////////////////////////////////////
	//Set up input grabbing!!																//
	//////////////////////////////////////////////////////////////////////////////////////////

	cv::VideoCapture videoCap;

	//Open camera capture, check that it opened
	videoCap.open(FILE_NAME);
	//videoCap.open(0);

	videoCap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	videoCap.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

	//C:\Users\Austin Musser\Videos\New folder\New folder
	if (!(videoCap.isOpened()))  // check if we succeeded
	{
		printf("\nError: Could not open camera 1, thread going down...\n\n");
		return 1;
	}



	//////////////////////////////////////////////////////////////////////////////////////////
	//Create the size of the reduce mats for processing										//
	//////////////////////////////////////////////////////////////////////////////////////////
	
	videoCap.grab();
	videoCap.retrieve(inputImage);

	//producing the pixel loctions of the reduced image
	widthSift = cvRound((inputImage.cols)*(1-RIGHT_PORTION));
	heightSift = cvRound((inputImage.rows)*TOP_PORTION);
	topShift = cvRound((inputImage.rows)*(1-BOTTOM_PORTION));  

	//The size of the portion to be zoomed
	ZoomX = cvRound((inputImage.cols)*(1 - RIGHT_PORTION));
	ZoomY = cvRound((inputImage.rows)*(1 - ZOOM_BOTTOM_PORTION));
	ZoomWidth = cvRound((inputImage.cols)*ZOOM_LEFT_PORTION) - ZoomX;
	ZoomHeight = cvRound((inputImage.rows)*TOP_PORTION) - ZoomY;



	//////////////////////////////////////////////////////////////////////////////////////////
	//Skip to a start frame and start the processing loop									//
	//////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < FRAME_START; i++)
	{
		videoCap.grab();
	}

	while (1) {

		//printf("%d\n",frameCount++);

		videoCap.grab();

		videoCap.retrieve(inputImage);									// capture frame

		if (inputImage.empty()) {										// if unable to open image
			std::cout << "error: image not read from file\n\n";         // show error message on command line
			return(0);                                                  // and exit program
		}



		//////////////////////////////////////////////////////////////////////////////////////////
		//BMDIT code																			//
		//////////////////////////////////////////////////////////////////////////////////////////

		// Create a red hsv mask
		bgr = inputImage;

		cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);

		inRange(hsv, cv::Scalar(171, 115, 0), cv::Scalar(180, 255, 255), mask1);
		inRange(hsv, cv::Scalar(0, 115, 0), cv::Scalar(9, 255, 255), mask2);

		hsvMask = mask1 | mask2;

		//Copy areas that contain and are around red pixles from the original image onto a blank image
		for (int k = topShift; k < heightSift; k += gap)			// Loops through the rows from the indexes of the reduced image skipping some rows based on 'gap' 
		{
			for (int j = widthSift; j < inputImage.cols; j += gap)	// Loops through the cols from the indexes of the reduced image skipping some cols based on 'gap' 
			{
				cv::Scalar colour = hsvMask.at<uchar>(cv::Point(j, k));	// get the value the current pixel, the hsvMask is a binary image

				if (colour.val[0] > 0.00000000)	// If the pixel is not black (if its white)
				{
					// find the x value to use
					if (j < range + widthSift)			//if we are too close to the left bound
					{
						x = widthSift;
					}
					else if (rowMem[j - gap] == true)	//looks at previous column in that row, if 1 then we dont need to copy some of that image bcause it was done last time
					{
						x = j + (range - gap);
					}
					else								//if we are away from left bound and previous comlumn on this row was not coppied
					{
						x = j - range;
					}

					// find the y value to use
					if (k < range + topShift)			//if we are too close to the top bound
					{
						y = topShift;
					}
					else if (rowMem[j] == true)			//Looks at the previous row in that column, if 1 then we dont need to copy some of that image bcause it was done on the last row
					{
						y = k + (range - gap);
					}
					else								//if we are away from the top bound and previous row in this column was not coppied
					{
						y = k - range;
					}

					// find the width to use
					if ((inputImage.cols - j) <= range)	//if we are too close the the right bound
					{
						if (rowMem[j - gap] == true)		//looks at previous column in that row
						{
							w = 0;
						}
						else
						{
							w = inputImage.cols - j + range;
						}
					}
					else if (rowMem[j - gap] == true)	//looks at previous column in that row
					{
						w = gap;
					}
					else
					{
						w = range * 2;
					}

					// find the height to use
					if ((heightSift - k) <= range)		//if we are too close to the bottom bound
					{
						if (rowMem[j] == true)			//Looks at the previous row in that column
						{
							h = 0;
						}
						else
						{
							h = heightSift - k + range;
						}
					}
					else if (rowMem[j] == true)			//Looks at the previous row in that column
					{
						h = gap;
					}
					else
					{
						h = range * 2;
					}

					// if the width and height are greater than 0 copy the chunk from the original on to the blank image
					if ((w > 0) && (h > 0))
					{
						part = inputImage(cv::Rect(x, y, w, h));
						part.copyTo(outPutBMDIT(cv::Rect(cv::Rect(x, y, w, h))));
					}

					rowMem[j] = true;	//Saves 1 if it currenly just did a copy for its position
				}
				else
				{
					rowMem[j] = false;	//Saves 0 if it currenly did NOT copy anything for its position
				}
			}
		}



		//////////////////////////////////////////////////////////////////////////////////////////
		//Digital Zoom																			//
		//////////////////////////////////////////////////////////////////////////////////////////

		outPutBMDIT(cv::Rect(ZoomX, ZoomY, ZoomWidth, ZoomHeight)).copyTo(portionToZoom);	// Creates the portion to zoom from the BMDIT image

		cv::resize(portionToZoom, zoomedInPortion, cv::Size(portionToZoom.cols * ZOOM_FACTOR, portionToZoom.rows * ZOOM_FACTOR));



		//////////////////////////////////////////////////////////////////////////////////////////
		//Creating reduced images for processing												//
		//////////////////////////////////////////////////////////////////////////////////////////

		// Create reduced imaged to work with
		cv::Mat matReduced(
			outPutBMDIT,
			cv::Range(topShift, heightSift),			//rows
			cv::Range(widthSift, inputImage.cols));		// cols

		cv::Mat matReducedOriginal(
			inputImage,
			cv::Range(topShift, heightSift),			//rows
			cv::Range(widthSift, inputImage.cols));		// cols



		//////////////////////////////////////////////////////////////////////////////////////////
		//Finding valid contours and adding them to a vector									//
		//////////////////////////////////////////////////////////////////////////////////////////

		// convert to grayscale
		cv::cvtColor(matReduced, matGrayscale, CV_BGR2GRAY);         

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

		//cv::imshow("contours", matThreshCopy);



		//////////////////////////////////////////////////////////////////////////////////////////
		//Looking for a key input																//
		//////////////////////////////////////////////////////////////////////////////////////////

		// Break out of forever loop or save a snapshot from the video before being drawn on
		int keyInput = cv::waitKey(10);
		if (keyInput == 27)
		{
			break;
		}
		else if (keyInput == 32)
		{
			char str[1024];
			sprintf(str, "parkingLot%d.png", imageNum);
			imwrite(str, matReducedOriginal);
			imageNum++;
		}



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
				strFinalString = strFinalString + char(int(fltCurrentChar));        // append current char to full string

				contourWithData.contourChar = int(fltCurrentChar);
				contourWithData.boundingRect = validContoursWithData[i].boundingRect;
				stopSignContoursWithDat.push_back(contourWithData);
			}

			// If a STOP contour was found save it and its letter to a vector of STOP contours
			if ((int(fltCurrentChar) == 'S') || int(fltCurrentChar) == 'T' || int(fltCurrentChar) == 'O' || int(fltCurrentChar) == 'P')
			{ 
				contourWithData.contourChar = int(fltCurrentChar);
				contourWithData.boundingRect = validContoursWithData[i].boundingRect;
				STOPContoursWithDat.push_back(contourWithData);

				strFinalString = strFinalString + char(int(fltCurrentChar));        // append current char to full string

				// Set the variables STOP to 1 if they were found. This is to remember what letters we have seen in a single frame
				if (int(fltCurrentChar) == 'S')
				{
					S = 1;
				}
				if (int(fltCurrentChar) == 'T')
				{
					T = 1;
				}
				if (int(fltCurrentChar) == 'O')
				{
					O = 1;
				}
				if (int(fltCurrentChar) == 'P')
				{
					P = 1;
				}
			}
		}



		//////////////////////////////////////////////////////////////////////////////////////////
		//Outlining stop signs and keeping track of there locations								//
		//////////////////////////////////////////////////////////////////////////////////////////

		// Loop though every stop sign contour and add the components
		for (int q = 0; q < stopSignContoursWithDat.size(); q++)
		{
			//adding each of the stop sign componets together
			SSaverageX += stopSignContoursWithDat[q].boundingRect.x + widthSift;
			SSaverageY += stopSignContoursWithDat[q].boundingRect.y + topShift;
			SSaverageWidth += stopSignContoursWithDat[q].boundingRect.width;
			SSaverageHeight += stopSignContoursWithDat[q].boundingRect.height;					
		}

		//if at least one stop sign was found 
		if (stopSignContoursWithDat.size() > 0)
		{
			//calculating the acutal averages of all the stop signs found
			SSaverageX = std::round(SSaverageX / stopSignContoursWithDat.size()) - widthSift;
			SSaverageY = std::round(SSaverageY / stopSignContoursWithDat.size()) - topShift;
			SSaverageWidth = std::round(SSaverageWidth / stopSignContoursWithDat.size());
			SSaverageHeight = std::round(SSaverageHeight / stopSignContoursWithDat.size());

			//draw the stop sign
			cv::rectangle(matReduced,                           // draw rectangle on reduced BMDIT image
				cv::Point(SSaverageX, SSaverageY),
				cv::Point(SSaverageWidth+SSaverageX, SSaverageHeight+SSaverageY),
				cv::Scalar(0, 255, 0),							// green
				2);												// thickness

			cv::rectangle(matReducedOriginal,                   // draw rectangle on reduced original image
				cv::Point(SSaverageX, SSaverageY),
				cv::Point(SSaverageWidth + SSaverageX, SSaverageHeight + SSaverageY),
				cv::Scalar(0, 255, 0),							// green
				2);												// thickness

			//save the stop sign data
			SSxLocation[0] = SSaverageX;
			SSyLocation[0] = SSaverageY;
			SSwidth[0] = SSaverageWidth;
			SSheight[0] = SSaverageHeight;
		}
		else
		{
			//if there was not a stop sign in that frame save -1 
			SSxLocation[0] = -1;
			SSyLocation[0] = -1;
			SSwidth[0] = -1;
			SSheight[0] = -1;
		}

		int numSSinPastFrames = 0;

		for (int i = 0; i < SSMemSize; i++)
		{
			if (SSxLocation[i] > -1)
			{
				numSSinPastFrames += 8;
			}
			
			//SSyLocation[i]
			//SSwidth[i]
			//SSheight[i]
		}



		//////////////////////////////////////////////////////////////////////////////////////////
		//Find and outlining valid STOP countours if three were found in a frame				//
		//////////////////////////////////////////////////////////////////////////////////////////

		// If at least three of the four letters were found a frame run this code
		if ((S + T + O + P) >= 3)
		{
			// This loop determind if the found letters are valid (if they all are close enough to each other to be considered on a single stop sign)
			for (int q = 0; q < STOPContoursWithDat.size() - 1; q++)
			{
				//Checks the x points of the current letter and the next letter to see if they are with a range of each other
				if (abs(STOPContoursWithDat[q].boundingRect.x - STOPContoursWithDat[q + 1].boundingRect.x) < STOPContoursWithDat[q].boundingRect.width * 2.15)
				{
					//Checks the y points of the current letter and the next letter to see if they are with a range of each other
					if (abs(STOPContoursWithDat[q].boundingRect.y - STOPContoursWithDat[q + 1].boundingRect.y) < STOPContoursWithDat[q].boundingRect.height * 0.5)
					{
						// If the current letter is a S the the next one must be a T or an O
						if (STOPContoursWithDat[q].contourChar == 'S')
						{
							if ((STOPContoursWithDat[q + 1].contourChar == 'T') || (STOPContoursWithDat[q + 1].contourChar == 'O'))
							{
								saveValidContours = 1;
							}
						}
						// If the current letter is an T the the next one must be an O or a P
						if (STOPContoursWithDat[q].contourChar == 'T')
						{
							if ((STOPContoursWithDat[q + 1].contourChar == 'O') || (STOPContoursWithDat[q + 1].contourChar == 'P'))
							{
								saveValidContours = 1;
							}
						}
						// If the current letter is an O the the next one must ba a P
						if (STOPContoursWithDat[q].contourChar == 'O')
						{
							if (STOPContoursWithDat[q + 1].contourChar == 'P')
							{
								saveValidContours = 1;
							}
						}
						// If the order of the two letters being comparied makes sense save them to valedSTOPContoursWithData
						if (saveValidContours == 1)
						{
							// If the previous set of countours were saved dont save the current one because it was already save last time
							if (savedPrevValidSTOPContours == 0)
							{
								contourWithData.boundingRect = STOPContoursWithDat[q].boundingRect;
								validSTOPContoursWithDat.push_back(contourWithData);
							}

							contourWithData.boundingRect = STOPContoursWithDat[q + 1].boundingRect;
							validSTOPContoursWithDat.push_back(contourWithData);

							savedPrevValidSTOPContours = 1;		// Set this to a one for next valed STOP contour
						}
						else
						{
							savedPrevValidSTOPContours = 0;		// Set this to a one for next valed STOP contour
						}
						saveValidContours = 0;	// Rest for next STOP contour
					}
				}
			}

			if (validSTOPContoursWithDat.size() >= 3)
			{		
				strFinalString = strFinalString + "'z'";
				numSSinPastFrames += 20;
			}

			// Loop though every valid letter contour and draw blue box around it
			for (int q = 0; q < validSTOPContoursWithDat.size(); q++)
			{
				cv::rectangle(matReduced,                           // draw rectangle on reduced BMDIT image
					validSTOPContoursWithDat[q].boundingRect,       // rect to draw
					cv::Scalar(255, 0, 0),							// blue
					2);												// thickness

				cv::rectangle(matReducedOriginal,                   // draw rectangle on reduced original image
					validSTOPContoursWithDat[q].boundingRect,       // rect to draw
					cv::Scalar(255, 0, 0),							// blue
					2);												// thickness
			}
		}




		//////////////////////////////////////////////////////////////////////////////////////////
		//End stuff and resting vars for next frame												//
		//////////////////////////////////////////////////////////////////////////////////////////

		// Draw out lines on redueced images
		cv::rectangle(matReduced,							// draw outline of the reduced BMDIT image
			cv::Point(0,0),									
			cv::Point(matReduced.cols, matReduced.rows),
			cv::Scalar(0, 0, 255),							// red
			2);												// thickness

		cv::rectangle(matReducedOriginal,                   // draw outline of the reduced original image
			cv::Point(0, 0),
			cv::Point(matReduced.cols, matReduced.rows),
			cv::Scalar(0, 0, 255),							// red
			2);												// thickness


		// Print and Show things
		//std::cout << "\n\n" << "Stop sign x location=";
		//std::cout << SSxLocation[0] << ", " << SSxLocation[1] << ", " << SSxLocation[2] << ", " << SSxLocation[3] << ", " << SSxLocation[4] << ", "
		//	<< SSxLocation[5] << ", " << SSxLocation[6] << ", " << SSxLocation[7] << ", " << SSxLocation[8] << ", " << SSxLocation[9] << "\n";

		std::cout << " Confident Percentage: " << numSSinPastFrames << "%" <<"\n\n";

		//std::cout << "\n\n" << "numbers read = " << strFinalString << "\n\n";       // show the full string of character found

		//cv::imshow("BMDIT", outPutBMDIT);						// show BMDIT image with green boxes around stop signs and blue boxes around letters
		cv::imshow("Original", inputImage);				// show input image with green boxes around stop signs and blue boxes around letters

		//cv::imshow("portion to zoom", portionToZoom);
		//cv::imshow("Zoomed in!!", zoomedInPortion);


		//Shifting stop sign memory
		for (int i = SSMemSize - 1; i > 0; i--)
		{
			SSxLocation[i] = SSxLocation[i - 1];
			SSyLocation[i] = SSyLocation[i - 1];
			SSwidth[i] = SSwidth[i - 1];
			SSheight[i] = SSheight[i - 1];
		}


		//Things to clear after every frame
		allContoursWithData.clear();
		validContoursWithData.clear();
		STOPContoursWithDat.clear();
		validSTOPContoursWithDat.clear();
		stopSignContoursWithDat.clear();

		outPutBMDIT *= 0;
		std::fill(std::begin(rowMem), std::end(rowMem), false);

		strFinalString = "";
		S = 0;
		T = 0;
		O = 0;
		P = 0;
		savedPrevValidSTOPContours = 0;

		SSaverageX = 0;
		SSaverageY = 0;
		SSaverageWidth = 0;
		SSaverageHeight = 0;


		Sleep(1);
	}

	return(0);
}
