#pragma once

//Gives a type for finder algorithms
enum FinderType : int
{
	unknown_type = 0,
	stop_signs = 1,
	lane_lines = 2,
	pedestrians = 3,
	vehicles = 4,
	traffic_signals = 5
};

struct DataHeader
{
	int type;				//Refers to the enum definded above
	unsigned int sequence;	//Refers to the count of the frame this data comes from 
};

struct StopSignData
{						//# of BITS	|     START INDEX		|			Description
	DataHeader header;	//32 bits   -   0x00 (0x00, 0x10)	-	This is the common header for all messages
	int confidence;		//16 bits   -		0x20			-	This is a value ranging from 0 to 100 (100 being most confident)
	int x_location;		//16 bits   -		0x30			-	This describes the x location of the center of the stop sign (in pixels)
	int y_location;		//16 bits   -		0x40			-	This describes the y location of the center of the stop sign (in pixels)
	int radius;			//16 bits   -		0x50			-	The radius of the circle around the stop sign (in pixels for a 1280x720 image)
	double distance;	//64 bits	-		0x80			-	The distance to the stop sign in Feet. Will be -1 if there is not a distance.

						//TOTAL LENGTH:	0x60
};

struct LaneLineData
{

};
//TODO: Add more data structures needed globally