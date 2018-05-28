#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include "LaneLineFinder.h"
#include "StopSignFinder.h"
#include "DataTransmitter.h"
#include "IFinder.h"

#define CAMERA_2_ENABLED 0

class StereoVideoCapture
{
public:

	StereoVideoCapture(int type);  //Constructor
	~StereoVideoCapture(); //Destructor
	void StopLoop();
	static void OnClick(int event, int x, int y, int flags, void* userdata);
	static void StereoVideoCapture::printPoints(StereoVideoCapture* thisCapObj);

	bool isDone();
	std::thread stereoThread;

	// processor objects

	/////////////////////////////////////////////////////////////////////////////
	//							FINDER STUFF								   //
	//Individual objects
	StopSignFinder stopSign;
	LaneLineFinder laneLine;

	//Inheiritance pointers for objects
	IFinder* stopSignFinder = &stopSign;
	IFinder*  laneLineFinder = &laneLine;

	int finderCount = 2; //TODO: INCREMENT UPON AN ADDITION OF A NEW FINDER ABOVE
	/////////////////////////////////////////////////////////////////////////////

	//Transmitter
	DataTransmitter dataTransmitter;

	cv::Mat frame_out;
	bool frameReady;

private:
	bool recordHeld;
	bool m_running;
	cv::VideoCapture capA, capB;
	cv::VideoWriter vidWriter1, vidWriter2;

	void processFrame(cv::Mat* frame1, cv::Mat* frame2);
	void checkFinder(IFinder* finder, cv::Mat* frame1, cv::Mat* frame2, int index);

	bool m_done;

	/* For getting points for transform */
	cv::Point2f pointsClicked[4];
	int pointsIndex;


	void RecordLoop();
	void ProcessFromFileLoop();
	void ProcessFromCapLoop();

	void visionProcessorSetup();
	void threadSetup(bool record);

	int frameSeqNum = 0;
};
