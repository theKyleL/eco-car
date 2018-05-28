#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <conio.h>

#include <iostream>
#include <sstream>
#include <string>
#include "GlobalStructures.h"

#include "IFinder.h"

const int RESIZED_IMAGE_WIDTH = 30;
const int RESIZED_IMAGE_HEIGHT = 30;

//General contour restrictments
const int MIN_CONTOUR_WIDTH = 20;
const int MAX_CONTOUR_WIDTH = 150;
const int WIDTH_HEIGHT_DIFF = 20;

//Stop sign contour restrictments
//const int SS_WIDTH_HEIGHT_DIFF = 5;

//These are used to reduce the size of frame that is being procesed.
const double RIGHT_PORTION = 0.55; //percentage of the top right of the image to look for things
const double TOP_PORTION = 0.6; //percentage of the top right of the image to look for things
const double BOTTOM_PORTION = 0.9; //percentage of the bottom of the image to look for things

const int FRAME_WIDTH = 1280;
const int FRAME_HEIGHT = 720;


class PedestrianFinder : public IFinder
{
public:
	PedestrianFinder();
	~PedestrianFinder();

	virtual void find(cv::Mat* frame1, cv::Mat* frame2, unsigned int frameSeqNum);

	//for the transmitter
	//virtual FinderType enumId()
	//{
	//	return speed_limit_signs;
	//};
	//virtual char* getDataByteArray()
	//{
	//	return (char*)&speedLimitSignData;
	//};
	//virtual int getStructSize()
	//{
	//	return sizeof(SpeedLimitSignData);
	//};

private:

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

	//KNN object 
	cv::Ptr<cv::ml::KNearest>  kNearest;

	//These are used to produce the reduced image to process
	//They use constants that define the percentage of the desired image
	int widthSift = cvRound((FRAME_WIDTH)*(1 - RIGHT_PORTION));
	int heightSift = cvRound((FRAME_HEIGHT)*TOP_PORTION);
	int topShift = cvRound((FRAME_HEIGHT)*(1 - BOTTOM_PORTION));

	//Stop sign memory
	int PMemSize = 10;
	cv::Rect pedestrianMemFrame1[10];
	cv::Rect pedestrianMemFrame2[10];
	int confidenceFrame1 = 0;
	int confidenceFrame2 = 0;

	//Transmit data
	StopSignData pedestrianData;
	int confidence = 0; // The average confidence percentage that there is a stop sign in view
	cv::Rect pedestrianToTransmit; // The location of the stop sign in the right frame (frame1) because that is the one being displayed as of now.
	double distanceToP = -1;

	int frameConfidenceToTransmit = 10; // If the average confidence is above 10% transmit data
	bool foundPedestrian = false;


	virtual void finder(int frameNum);
	void processFrame1and2();
};
