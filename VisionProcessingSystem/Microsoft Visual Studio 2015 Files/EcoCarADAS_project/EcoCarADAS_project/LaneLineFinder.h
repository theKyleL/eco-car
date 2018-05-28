#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include <queue>
#include "IFinder.h"
#include "GlobalStructures.h"

#define HORIZON 350 //Defines the horizon from the top left corner in a 1280x720 size frame


class LaneLineFinder: public IFinder
{
public:
	LaneLineFinder();
	~LaneLineFinder();

	//Overidden methods
	virtual void find(cv::Mat* frame1, cv::Mat* frame2, unsigned int frameSeqNum);

	virtual FinderType enumId()
	{
		return lane_lines; //For the data transmitter
	}

	virtual int getStructSize()
	{
		return sizeof(LaneLineData);
	};

	// Local var/methods
	void initLambda();

	cv::Mat perspective;
	cv::Mat dilated;


	cv::Mat warped_section1;

private:

	
	std::vector<std::vector<cv::Vec2f>> lineGroupVector; //This queue is used for filtering the lines found from frame to frame

	cv::Mat lambda;

	virtual void finder(int frameNum);
	void filterOutput();
};

