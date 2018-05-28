#include "stdafx.h"
#include "DataTransmitter.h"
#include <iostream>
#include <conio.h>
#include <winsock.h>
#include <windows.h>
#include <stdio.h>
#include "IFinder.h"
#include "GlobalStructures.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define STOP_SIGN_PORT 12345
#define LANE_LINE_PORT 12347
#define PEDESTRIANS_PORT 12348
#define	VEHICLES_PORT 12349
#define	TRAFFIC_SIGNALS_PORT 12350

/* Socket Code referenced at http://www.binarytides.com/udp-socket-programming-in-winsock/ */

/* Thread controls */
bool DataTransmitter::isSending(IFinder* finder)
{
	switch (finder->enumId())
	{
	case stop_signs:
		return m_stopSignIsSending;
		break;
	case lane_lines:
		return m_laneLineIsSending;
		break;
	case pedestrians:
		return m_pedestriansIsSending;
		break;
	case vehicles:
		return m_vehiclesIsSending;
		break;
	case traffic_signals:
		return m_trafficSignalsIsSending;
		break;
	default:
		break;
	}

	return false;
}

void DataTransmitter::changeSending(IFinder* finder, bool isSending)
{
	switch (finder->enumId())
	{
	case stop_signs:
		m_stopSignIsSending = isSending;
		break;
	case lane_lines:
		m_laneLineIsSending = isSending;
		break;
	case pedestrians:
		m_pedestriansIsSending = isSending;
		break;
	case vehicles:
		m_vehiclesIsSending = isSending;
		break;
	case traffic_signals:
		m_trafficSignalsIsSending = isSending;
		break;
	default:
		break;
	}
}

int DataTransmitter::getDataOutPort(IFinder* finder)
{
	switch (finder->enumId())
	{
	case stop_signs:
		return STOP_SIGN_PORT;
		break;
	case lane_lines:
		return LANE_LINE_PORT;
		break;
	case pedestrians:
		return PEDESTRIANS_PORT;
		break;
	case vehicles:
		return VEHICLES_PORT;
		break;
	case traffic_signals:
		return TRAFFIC_SIGNALS_PORT;
		break;
	default:
		break;
	}
}
/* End Thread controls */

/* Externally accessed methods */
void DataTransmitter::transmit(IFinder* finder)
{
	//TODO: Streamline this down to a few lines...get rid of switch
	
	//Decide which transmit thread to use
	switch (finder->enumId())
	{
	case stop_signs:
		//Notify watcher we are starting to transmit
		changeSending(finder, true);

		//Makes the hasData flag false
		finder->takeData(); 

		//Spin off thread to transmit
		*getTransmitterThread(finder) = std::thread(&DataTransmitter::transmitData, this, finder);
		break;
	case lane_lines:
		//Notify watcher we are starting to transmit
		//changeSending(finder, true);

		//Makes the hasData flag false
		finder->takeData(); //Makes the hasData flag false
		
		//Spin off transmit thread
		//*getTransmitterThread(finder) = std::thread(&DataTransmitter::transmitData, this, finder);
		break;
	case pedestrians:
		//Notify watcher we are starting to transmit
		//changeSending(finder, true);

		//Makes the hasData flag false
		finder->takeData(); //Makes the hasData flag false

		//Spin off transmit thread
		//*getTransmitterThread(finder) = std::thread(&DataTransmitter::transmitData, this, finder);
		break;
	case vehicles:
		//Notify watcher we are starting to transmit
		//changeSending(finder, true);

		//Makes the hasData flag false
		finder->takeData(); //Makes the hasData flag false

		//Spin off transmit thread
		//*getTransmitterThread(finder) = std::thread(&DataTransmitter::transmitData, this, finder);
		break;
	case traffic_signals:
		//Notify watcher we are starting to transmit
		//changeSending(finder, true);

		//Makes the hasData flag false
		finder->takeData(); //Makes the hasData flag false

		//Spin off transmit thread
		//*getTransmitterThread(finder) = std::thread(&DataTransmitter::transmitData, this, finder);
		break;
	default:
		break;
	}
}
std::thread* DataTransmitter::getTransmitterThread(IFinder* finder)
{

	//Decide which transmit thread to use
	switch (finder->enumId())
	{
	case stop_signs:
		//Return this thread
		return &stopSignTransmitterThread;
		break;
	case lane_lines:
		//Return this thread
		return &laneLineTransmitterThread;
		break;
	case pedestrians:
		return &pedestriansTransmitterThread;
		break;
	case vehicles:
		return &vehiclesTransmitterThread;
		break;
	case traffic_signals:
		return &trafficSignalsTransmitterThread;
		break;
	default:
		break;
	}
}
/* End Externally accessed methods */

/* Threading methods */
void DataTransmitter::transmitData(IFinder* finder)
{
	/* TRANSMIT THE BYTES */
	//Set up destination data
	struct sockaddr_in dst_location;
	memset(&dst_location, 0, sizeof(dst_location));
	dst_location.sin_family = AF_INET;
	dst_location.sin_port = htons(getDataOutPort(finder));
	dst_location.sin_addr.s_addr = inet_addr(RMT_IP_ADDRESS);

	//Take a byte buffer reference, a length, and a port and transmit the data
	if (sendto(openedSocket, finder->getDataByteArray(), finder->getStructSize(), 0, (struct sockaddr*) &dst_location, sizeof(dst_location)) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//Once done, notify watcher
	changeSending(finder, false);
}
/* End Threading methods */

/* Constructors */
DataTransmitter::DataTransmitter()
{
	//Do any setup needed
	m_stopSignIsSending = false;
	m_laneLineIsSending = false;

	//Setup UDP socket
	//slen = sizeof(dst_location);
	//char broadcast = 'a';

	//Initialise winsock
	printf("\nInitializing Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d\n", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialized.\n");

	//Create a socket
	if ((openedSocket = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR)
	{
		printf("Could not create socket : %d\n", WSAGetLastError());
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(LCL_PORT);
	server.sin_addr.s_addr = inet_addr(LCL_IP_ADDRESS);

	//Prepare the sockaddr_in structure


	//Bind
	if (bind(openedSocket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d\n", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Bind done\n");
}


DataTransmitter::~DataTransmitter()
{
	//Take down socket
	closesocket(openedSocket);
	WSACleanup();
}
