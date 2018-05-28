
#include "stdafx.h"
#include "StereoVideoCapture.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "DataTransmitter.h"
#include "GlobalStructures.h"


//#define CAMERA_2_ENABLED 0
#define WINDOWS 1 //1 is windows, 0 is linux (This is to switch between standard opencv {linux} and the CLEye driver {windows})
#define CAMERA1_FILENAME "D:/EcoCar Recordings/Clear Day 1/stop signs 3/Camera_1_capture.avi"
//#define CAMERA1_FILENAME "Lane Lines/Camera_1_capture.avi"
//#define CAMERA2_FILENAME "Lane Lines/Camera_1_capture 2.avi"
#define CAMERA2_FILENAME "D:/EcoCar Recordings/Clear Day 1/stop signs 3/Camera_2_capture.avi"

/*
!!!!!!!!!!!!!!
HEY AUSTIN: You should wrap your processing code that needs two images with #if CAMERA_2_ENABLED so it doesnt crash when I test :) -IAN
!!!!!!!!!!!!!!
*/

//Setup name space
using namespace cv;
using namespace std;

///////////////////////////////////////////////////////
//             General functions below               //
///////////////////////////////////////////////////////
void StereoVideoCapture::StopLoop()
{
	//Stop capture thread
	m_running = false;
	printf("Stopping...\n");

	//Wait for capture loop to end
	Sleep(3000);

	/* Kill any associated threads running */
	//Join stop sign threads if it needs to be joined
	if ((stopSignFinder->getThread())->joinable())
	{
		//Kill old thread
		(stopSignFinder->getThread())->join();
	}

	// Kill lane line finder
	if ((laneLineFinder->getThread())->joinable())
	{
		//Kill old thread
		(laneLineFinder->getThread())->join();
	}

	//Kill transmitter
	if (dataTransmitter.getTransmitterThread(laneLineFinder)->joinable())
	{
		//Kill old thread
		dataTransmitter.getTransmitterThread(laneLineFinder)->join();
	}
}

bool StereoVideoCapture::isDone()
{
	return m_done;
}

//A generic way to check up on a thread
void StereoVideoCapture::checkFinder(IFinder* finder, Mat* frame1, Mat* frame2, int index) //index used to have multiple video feeds that are different
{
	if (finder->isDone())
	{
		//Handle its data, if there
		if (finder->hasData())
		{
			//Send data to 127.0.0.1
			dataTransmitter.transmit(finder);

			/* ***** Debug ***** */
			Mat show1;
			Mat show2;

			finder->getDbgFrame1()->copyTo(show1);
			finder->getDbgFrame2()->copyTo(show2);

			imshow("Display window " + index, show1);
			//imshow("Display window " + index+1, show2);

			if (waitKey(30) >= 0)
				StopLoop();
			/* ***** Debug ***** */

			//Safely kill old threads
			if (finder->getThread()->joinable())
			{
				//Kill old thread
				finder->getThread()->join();
			}

		}
		else
		{
			//Join if it needs to be joined
			if (finder->getThread()->joinable())
			{
				//Kill old thread
				finder->getThread()->join();
			}

			//Make sure the transmitter is finished before processing next frame
			if (!dataTransmitter.isSending(finder))
			{
				//Join transmitter if joinable
				if (dataTransmitter.getTransmitterThread(finder)->joinable())
				{
					//Kill old thread
					dataTransmitter.getTransmitterThread(finder)->join();
				}

				//Launch thread to process the frame
				finder->find(frame1, frame2, frameSeqNum); //TODO: The 1 needs to be a frame sequence counter eventually
			}
		}
	}
}

void StereoVideoCapture::processFrame(Mat* frame1, Mat* frame2)
{
	//TODO: USE THIS PROCESS INSTEAD OF DUPLICATING CODE LIKE BELOW
	//checkFinder(stopSignFinder, frame1, frame2, 0);
	//checkFinder(laneLineFinder, frame1, frame2, 1);


	/* Stop Signs Stuff */
	if (stopSignFinder->isDone())
	{
		//Handle its data, if there
		if (stopSignFinder->hasData())
		{
			//Send data to 127.0.0.1
			dataTransmitter.transmit(stopSignFinder);

			/* ***** Debug ***** */
			if (CAMERA_2_ENABLED == 1)
			{
				Mat show1;
				Mat show2;

				stopSignFinder->getDbgFrame1()->copyTo(show1);
				stopSignFinder->getDbgFrame2()->copyTo(show2);

				imshow("Display window1", show1);
				imshow("Display window2", show2);
			}
			else
			{
				Mat show1;

				stopSignFinder->getDbgFrame1()->copyTo(show1);

				imshow("Display window1", show1);
			}

			
			if (waitKey(30) >= 0)
				StopLoop();
			/* ***** Debug ***** */

			//Safely kill old threads
			if (stopSignFinder->getThread()->joinable())
			{
				//Kill old thread
				stopSignFinder->getThread()->join();
			}
		}
		else
		{
			//Join if it needs to be joined
			if (stopSignFinder->getThread()->joinable())
			{
				//Kill old thread
				stopSignFinder->getThread()->join();
			}

			//Make sure the transmitter is finished before processing next frame
			if (!dataTransmitter.isSending(stopSignFinder))
			{
				//Join transmitter if joinable
				if (dataTransmitter.getTransmitterThread(stopSignFinder)->joinable())
				{
					//Kill old thread
					dataTransmitter.getTransmitterThread(stopSignFinder)->join();
				}

				//Launch thread to process the frame
				stopSignFinder->find(frame1, frame2, frameSeqNum); //TODO: The 1 needs to be a frame sequence counter eventually
			}
		}
	}
	/* End Stop Signs Stuff */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* Lane Lines Stuff */
	if (laneLineFinder->isDone())
	{
		//Handle its data, if there
		if (laneLineFinder->hasData())
		{
			//Send data to 127.0.0.1
			dataTransmitter.transmit(laneLineFinder);

			/* ***** Debug ***** */
			Mat show1;
			Mat show2;

			laneLineFinder->getDbgFrame1()->copyTo(show1);
			laneLineFinder->getDbgFrame2()->copyTo(show2);

			imshow("Normal", show1);
			imshow("Noise Removed", show2);

			if (waitKey(30) >= 0)
				StopLoop();
			/* ***** Debug ***** */

			//Safely kill old threads
			if (laneLineFinder->getThread()->joinable())
			{
				//Kill old thread
				laneLineFinder->getThread()->join();
			}
		}
		else
		{
			//Join if it needs to be joined
			if (laneLineFinder->getThread()->joinable())
			{
				//Kill old thread
				laneLineFinder->getThread()->join();
			}

			//Make sure the transmitter is finished before processing next frame
			if (!dataTransmitter.isSending(laneLineFinder))
			{
				//Join transmitter if joinable
				if (dataTransmitter.getTransmitterThread(laneLineFinder)->joinable())
				{
					//Kill old thread
					dataTransmitter.getTransmitterThread(laneLineFinder)->join();
				}

				//Launch thread to process the frame
				laneLineFinder->find(frame1, frame2, frameSeqNum); //TODO: The 1 needs to be a frame sequence counter eventually
			}
		}
	}
	/* End Lane Lines Stuff */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	/* UI Stuff */
	//Send frame to UI via 127.0.0.1
	imshow("UI View", *frame1);


}

//Used for recording video to a file
void StereoVideoCapture::RecordLoop()
{
	///////////////////////////////////////////////////////////////////////////////////
	//                                 Reference                                     //
	// http://docs.opencv.org/2.4/doc/tutorials/highgui/video-write/video-write.html //
	///////////////////////////////////////////////////////////////////////////////////
	m_running = true;
	recordHeld = false;

	Mat frame1;
	Mat frame2;

	namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display
	setMouseCallback("Display window", OnClick, this);


	//Open camera capture, check that it opened
	capA.open(-1);
	if (!(capA.isOpened()))  // check if we succeeded
	{
		printf("\nError: Could not open camera 1, thread going down...\n\n");
		m_done = true;
		return;
	}

	//Get the size of the input stream
	Size S1 = Size((int)capA.get(CV_CAP_PROP_FRAME_WIDTH),
		(int)capA.get(CV_CAP_PROP_FRAME_HEIGHT));

	//Open video writer, check that it opened
	vidWriter1.open("Camera_1_capture.avi",
		0,//VideoWriter::fourcc('M','P','G','4'),
		capA.get(CV_CAP_PROP_FPS), // 20 looks more real time
		S1,
		true);
	if (!vidWriter1.isOpened())
	{
		printf("\nError: Could not open video writer 1, thread going down...\n\n");
		capA.release();
		m_done = true;
		return;
	}

#if CAMERA_2_ENABLED
	//Open camera capture, check that it opened
	capB.open(-1);
	if (!capB.isOpened())  // check if we succeeded
	{
		printf("\nError: Could not open camera 2, thread going down...\n\n");
		capA.release();
		vidWriter1.release();
		m_done = true;
		return;
	}

	//Get the size of the input stream
	Size S2 = Size((int)capB.get(CV_CAP_PROP_FRAME_WIDTH),
		(int)capB.get(CV_CAP_PROP_FRAME_HEIGHT));

	//Open video writer, check that it opened
	vidWriter2.open("Camera_2_capture.avi",
		-1, //CV_FOURCC('M', 'J', 'P', 'G'),
		capB.get(CV_CAP_PROP_FPS), // 20 looks more real time
		S2,
		true);
	if (!vidWriter2.isOpened())
	{
		printf("\nError: Could not open video writer 2, thread going down...\n\n");
		capA.release();
		capB.release();
		vidWriter1.release();
		m_done = true;
		return;
	}
	/* END: Set up the capture and writer outside of thread, and pass in. */
#endif

	capA.read(frame1);
	printf("Starting Capture...\n");
	printf("\n\n\nClick on the video feed to start recording, click again to stop. \nWatch below for status of recorder.\n\n");

	//Loop capturing and saving while the thread should be active
	while (m_running)
	{


		//Tell cameras to take a photo
		capA.grab();

#if CAMERA_2_ENABLED
		capB.grab();
#endif

		//Tell Camera to transfer photo into memory
		capA.retrieve(frame1);

#if CAMERA_2_ENABLED
		capB.retrieve(frame2);
#endif	
		if (recordHeld)
		{
			//Save frame to file
			vidWriter1.write(frame1);
			//printf("record");

#if CAMERA_2_ENABLED
			vidWriter2.write(frame2);
#endif


		}
		//REPEAT//
		imshow("Display window", frame1);
		if ((char)waitKey(30) == 'q')
		{
			break;
		}
		//else
		//{
		//	recordHeld = false;

		//}


	}
	//Release cameras/writers
	printf("Releasing captures and video writers...\n");
	capA.release();

#if CAMERA_2_ENABLED
	capB.release();
#endif

	//vidWriter1.release();

#if CAMERA_2_ENABLED
	vidWriter2.release();
#endif

	//Let main thread know this thread has completed its takedown
	printf("Waiting on threads to be done...\n");
	m_done = true;
}

//Used for processing a video file
void StereoVideoCapture::ProcessFromFileLoop()
{
	///////////////////////////////////////////////////////////////////////////////////
	//                                 Reference                                     //
	// http://docs.opencv.org/2.4/doc/tutorials/highgui/video-write/video-write.html //
	///////////////////////////////////////////////////////////////////////////////////
	m_running = true;

	Mat frame1;
	Mat frame2;

	namedWindow("Normal", WINDOW_AUTOSIZE);// Create a window for display
	//namedWindow("Perspective", WINDOW_AUTOSIZE);// Create a window for display
	namedWindow("Noise Removed", WINDOW_AUTOSIZE);// Create a window for display
	//namedWindow("Original", WINDOW_AUTOSIZE);// Create a window for display

												   //set the callback function for any mouse event
	setMouseCallback("Display window", OnClick, this);

	//Open camera capture, check that it opened
	capA.open(CAMERA1_FILENAME);
	if (!(capA.isOpened()))  // check if we succeeded
	{
		printf("\nError: Could not open camera 1, thread going down...\n\n");
		m_done = true;
		return;
	}

#if CAMERA_2_ENABLED
	//Open camera capture, check that it opened
	capB.open(CAMERA2_FILENAME);
	if (!capB.isOpened())  // check if we succeeded
	{
		printf("\nError: Could not open camera 2, thread going down...\n\n");
		capA.release();
		vidWriter1.release();
		m_done = true;
		return;
	}
#endif

	//Loop capturing and saving while the thread should be active
	while (m_running)
	{
		//Tell cameras to take a photo
		capA.grab();
#if CAMERA_2_ENABLED
		capB.grab();
#endif

		//Tell Camera to transfer photo into memory
		capA.retrieve(frame1);

#if CAMERA_2_ENABLED
		capB.retrieve(frame2);
#endif
		//Process the frames
		processFrame(&frame1, &frame2);

		//Increment frame  counter (starts at 0)
		frameSeqNum++;

		//REPEAT//
		Sleep(20);
	}

	//Release cameras/writers
	printf("Releasing captures...\n");
	capA.release();

#if CAMERA_2_ENABLED
	capB.release();
#endif

	//Let main thread know this thread has completed its takedown
	printf("Waiting on threads to be done...\n");
	m_done = true;
}

//Below chunk is used in the video feed window to get coordinates of points
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StereoVideoCapture::printPoints(StereoVideoCapture* thisCapObj)
{
	printf("------------------------------------------------------------------------\n");
	//Print out the points, or how many points saved so far
	if (thisCapObj->pointsIndex < 3)
	{
		//Notify
		printf("You have captured only %d points so far.\n", thisCapObj->pointsIndex);
	}

	//Print all captured points
	int i;
	for (i = 0; i < thisCapObj->pointsIndex; i++)
	{
		printf("You captured: %d, %d\n", (int)(thisCapObj->pointsClicked[i].x), (int)(thisCapObj->pointsClicked[i].y));
	}

	printf("------------------------------------------------------------------------\n");
}

//Listener callback
void StereoVideoCapture::OnClick(int event, int x, int y, int flags, void* userdata)
{
	//Grab the reference to the location of this class insstance in memory
	StereoVideoCapture* thisCapObj = ((StereoVideoCapture*)userdata);

	//printf("Clicked");
	if (event == EVENT_LBUTTONDOWN)
	{
		/* Keep track of  the mouse clicks */ 		
		if (thisCapObj->recordHeld == false)
		{
			printf("Started Recording...\n");
			thisCapObj->recordHeld = true;
		}
		else
		{
			printf("Stopped Recording.\n");
			thisCapObj->recordHeld = false;
		}			

		//Make sure we dont step out of bounds
		if (thisCapObj->pointsIndex > 3) 
		{
			//Print resutls
			//printPoints(thisCapObj);

			//Reset index to 0
			thisCapObj->pointsIndex = 0;
		}

		//Save the values
		thisCapObj->pointsClicked[thisCapObj->pointsIndex] = Point2f(x, y);

		//Increment the counter for indexing
		thisCapObj->pointsIndex++;

		//Notify of the capture
		//printf("You captured: %d, %d\n", x, y);

	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		printPoints(thisCapObj);
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		//cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

	}
	else if (event == EVENT_MOUSEMOVE)
	{
		//cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
		//thisCapObj->recordHeld = true;
		//printf("Started Recording...\n");
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Used for realtime processing
void StereoVideoCapture::ProcessFromCapLoop()
{
	///////////////////////////////////////////////////////////////////////////////////
	//                                 Reference                                     //
	// http://docs.opencv.org/2.4/doc/tutorials/highgui/video-write/video-write.html //
	///////////////////////////////////////////////////////////////////////////////////
	m_running = true;

	Mat frame1;
	Mat frame2;

	namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display
	
	//set the callback function for any mouse event
	setMouseCallback("Display window", OnClick, this);

	//Open camera capture, check that it opened
	capA.open(0);
	if (!(capA.isOpened()))  // check if we succeeded
	{
		printf("\nError: Could not open camera 1, thread going down...\n\n");
		m_done = true;
		return;
	}

	capA.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	capA.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

#if CAMERA_2_ENABLED
	//Open camera capture, check that it opened
	capB.open(-1);
	if (!capB.isOpened())  // check if we succeeded
	{
		printf("\nError: Could not open camera 2, thread going down...\n\n");
		capA.release();
		vidWriter1.release();
		m_done = true;
		return;
	}

	capB.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	capB.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
#endif

	capA.read(frame1);

	//Loop capturing and saving while the thread should be active
	while (m_running)
	{
		//Tell cameras to take a photo
		capA.grab();

#if CAMERA_2_ENABLED
		capB.grab();
#endif

		//Tell Camera to transfer photo into memory
		capA.retrieve(frame1);

#if CAMERA_2_ENABLED
		capB.retrieve(frame2);
#endif

		//Process the frames
		processFrame(&frame1, &frame2);

		//Increment frame  counter (starts at 0)
		frameSeqNum++;

		//REPEAT//
	}

	//Release cameras/writers
	printf("Releasing captures...\n");
	capA.release();
#if CAMERA_2_ENABLED
	capB.release();
#endif
	//Let main thread know this thread has completed its takedown
	printf("Waiting on threads to be done...\n");
	m_done = true;
}


void StereoVideoCapture::threadSetup(bool record)
{
	//Instantiate video cap 1
	capA = VideoCapture();


#if CAMERA_2_ENABLED
	//Instantiate video cap 2
	capB = VideoCapture();
#endif

	if (record)
	{
		//Instantiate the video writer 1
		vidWriter1 = VideoWriter();
#if CAMERA_2_ENABLED

		//Instantiate the video writer 2
		vidWriter2 = VideoWriter();
#endif
	}

	//Init the clickable points params
	pointsIndex = 0;
}

void StereoVideoCapture::visionProcessorSetup()
{
	//Config the processors

}


///////////////////////////////////////////////////////
//                Windows ONLY below                 //
///////////////////////////////////////////////////////
#if WINDOWS
StereoVideoCapture::StereoVideoCapture(int type)
{
	//Decide what kind of thread to be
	if (type == 0)  //SAVE VIDEO TO FILE, DO NOT PROCESS
	{
		//Inititialize captures and video writers
		threadSetup(true);
		
		//Launch Thread
		stereoThread = std::thread(&StereoVideoCapture::RecordLoop, this);
	}
	else if(type == 1) // Load video from file, process 
	{
		//Inititialize captures
		threadSetup(false);

		//Setup processors
		visionProcessorSetup();

		//Launch Thread
		stereoThread = std::thread(&StereoVideoCapture::ProcessFromFileLoop, this);
	}
	else if (type == 2) //Cap realtime video and process
	{
		//Inititialize captures
		threadSetup(false);

		//Setup processors
		visionProcessorSetup();

		//Launch Thread
		stereoThread = std::thread(&StereoVideoCapture::ProcessFromCapLoop, this);
	}
	else
	{
		printf("Invalid option in StereoVideoCapture constructor.");
	}
	
	//Not done yet, this is so main doesnt prematurely end the program...wait for user and thread to agree.
	m_done = false;
}


StereoVideoCapture::~StereoVideoCapture() //Destructor
{

}
#endif


///////////////////////////////////////////////////////
//                  LINUX ONLY below                 //
///////////////////////////////////////////////////////
#if !WINDOWS
StereoVideoCapture::StereoVideoCapture() //Constructor
{

}


StereoVideoCapture::~StereoVideoCapture() //Destructor
{
}
#endif