#pragma once
#include "StopSignFinder.h"
#include "LaneLineFinder.h"
#include <stdio.h>
#include <winsock.h>
#include "IFinder.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 1024  //Max length of buffer
#define LCL_PORT 12346
#define RMT_IP_ADDRESS "127.0.0.1"
#define LCL_IP_ADDRESS "0.0.0.0"

class DataTransmitter
{
public:
	DataTransmitter();
	~DataTransmitter();

	/* Data Transmission */
	//Launched the thread that will continually push and 
	void transmit(IFinder* finder);
	std::thread* getTransmitterThread(IFinder* finder);

	//Watch for threads stopping point
	bool isSending(IFinder* finder);

private:

	/* General private variable and methods */
	//Variables
	SOCKET openedSocket;
	struct sockaddr_in server;
	int slen, recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	//Methods
	int getDataOutPort(IFinder* finder);
	void changeSending(IFinder* finder, bool isSending);
	void transmitData(IFinder* finder);

	/* Stop sign related variables and methods */
	//Variables
	bool m_stopSignIsSending;
	std::thread stopSignTransmitterThread;

	/* Lane Line related variables and methods */
	//Variables
	bool m_laneLineIsSending;
	std::thread laneLineTransmitterThread;

	/* Pedestrian related variables and methods */
	bool m_pedestriansIsSending;
	std::thread pedestriansTransmitterThread;

	/* Vehicles related variables and methods */
	bool m_vehiclesIsSending;
	std::thread vehiclesTransmitterThread;

	/* Traffic Signals related variables and methods */
	bool m_trafficSignalsIsSending;
	std::thread trafficSignalsTransmitterThread;
};