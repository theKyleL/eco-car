// EcoCarADAS_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "StereoVideoCapture.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "GlobalStructures.h"

using namespace cv;

/* 
PROCESS TYPE DEFINITION
- This allows us to switch the functionality of the main thread.
- 0: Will allow the program to capture video and save it to a file.
- 1: Will read video in from a file, and pass it through the vision processor.
- 2: Will capture video from two cameras and run it through the vision processor.
*/
#define PROCESS_TYPE 1

int main()
{

	/* Constructors, launch threads */
	StereoVideoCapture videoCap(PROCESS_TYPE);//Arguments: (record?, process?)
											 /* Main vars */
	int stop;
	stop = 0;

	//Keep Program Alive
	std::cout << "Press 1 to quit\n";
	while (1) {
		//Let the user stop the recording
		std::cin >> stop;
		if (stop == 1)
		{
			//Kill the video capture/saving thread
			videoCap.StopLoop();

			//Loop waiting for the videoCap to fully deconstruct itself
			while (!videoCap.isDone())
			{
				//Give some time for video capture thread to release captures/video writers
				Sleep(100);
			}
			//Stop looking for user input
			break;
		}
	}



	/* Join all threads below */
	videoCap.stereoThread.join();





    return 0;
}

