 #pragma once
#include <opencv2\opencv.hpp>
#include <thread>
#include "GlobalStructures.h"


class IFinder
{
public:

	virtual ~IFinder()																/* Must Implement */
	{
		printf("Please Implement this deconstructor.\n");
	};

	//virtual Methods
	virtual void find(cv::Mat* frame1, cv::Mat* frame2, unsigned int frameSeqNum)			/* Must Implement */
	{
		printf("Please Implement this find(Mat* frame1, Mat* frame2).\n");
	};
	virtual FinderType enumId()														/* Must Implement */
	{
		return unknown_type;
	};
	virtual char* getDataByteArray()												/* Must Implement */
	{
		printf("Please implement getDataArray()");
		return NULL;
	};
	virtual int getStructSize()														/* Must Implement */
	{
		printf("Please implement getStructSize()");
		return 0;
	};


	/* Standard handshake calls below: Requires no implementation in children */

	//Non virtual methods
	std::thread* getThread()
	{
		return &finderThread;
	};

	cv::Mat* getDbgFrame1()
	{
		return &output_dbg_frame1;
	};

	cv::Mat* getDbgFrame2()
	{
		return &output_dbg_frame2;
	};

	//Call from Child to tell Stereo Capture thread that we are starting processing and not to give us another frame.
	void initProcessing()
	{
		m_hasData = false;
		m_done = false;
	};

	//Call from child to tell Stereo Capture thread to refeed or to transmit then refeed a frame.
	void doneProcessing(bool transmitData)
	{
		m_hasData = transmitData;
		m_done = true;
	};

	bool isDone()
	{
		return m_done;
	};

	bool hasData()
	{
		return m_hasData;
	};

	//CAlled from transmitter to notify stereo capture that this Finder no longer has data, and that it is transmitting data.
	void takeData()
	{
		m_hasData = false;
	};


protected:

	//Input Frames
	cv::Mat local_frame1;
	cv::Mat local_frame2;

	//Debug frames
	cv::Mat output_dbg_frame1;
	cv::Mat output_dbg_frame2;

	//Finder Threads
	std::thread finderThread;

	//Handshake variables
	bool m_done;
	bool m_hasData;

	//Finder method: This is where the vision processing code is held
	virtual void finder(int frameNum)  {};											/* Must Implement */

	int processType;

};

