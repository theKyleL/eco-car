/* Server class will receive objects from dataTransmitter c++.
 * DataTransmitter will send information about one object along 
 * with its position.
 * Data is sent via UDP through the localhost.
 * 
 * 
 * 
 * identifiable objects:
 *
 *  stop sign
 *  
 *  traffic signal 	(not yet implemented)
 *  lane lines 		(not yet implemented)
 *  pedestrians		(not yet implemented)
 *  other vehicles	(not yet implemented)
 *  
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
//import java.text.SimpleDateFormat;
//import java.util.Calendar;

public class DataReceiver {	 

	byte signData;
	ServerSocket serverSocket;
	boolean ServerOn = true;
	IdentifiedObject foundObject;


	public DataReceiver() { 
		try {
			serverSocket = new ServerSocket(12345); 
			System.out.println("Sign server created");
		} 
		catch(IOException e) { 
			System.out.println("Failed to create server on port 12345. Quitting."); 
			System.exit(-1); 
		} 

		// Successfully created Server Socket. Now wait for connections. 
		while(ServerOn) {                        
			try { 
				// Accept incoming connections. 
				System.out.println("Waiting for client message...");
				Socket clientSocket = serverSocket.accept(); 
				System.out.println("message received on port " + serverSocket.getLocalPort());

				// accept() will block until a client connects to the server. 

				// For each client, start a service thread to 
				// service the requests. Supports a 
				// Multi-Threaded server. Starting a thread also lets our 
				// MultiThreadedSocketServer accept multiple connections simultaneously. 

				// begin thread 

				ClientServiceThread clientThread = new ClientServiceThread(clientSocket);
				clientThread.start(); 

			} 
			catch(IOException e) {
				System.out.println("Exception encountered on accept."); 
				e.printStackTrace(); 
			} 
		}

		try {
			serverSocket.close(); 
			System.out.println("Server Stopped"); 
		} 
		catch(Exception ioe) {
			System.out.println("Problem stopping server socket"); 
			System.exit(-1); 
		} 
	} 

// 	
//	public static void main (String[] args) {
//		new DataReceiver();        
//	} 


	class ClientServiceThread extends Thread {
		Socket clientSocket;		
		boolean threadIsActive = true; 

		public ClientServiceThread() {
			super(); 
		} 

		public ClientServiceThread(Socket s) {
			clientSocket = s; 
		} 

		public void run() {           
			// grab the input stream for the socket
			BufferedReader in = null; 

			// Print out details of this connection 
			System.out.println("Accepted Client Address - " + clientSocket.getInetAddress().getHostName()); 

			try {
				in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 

				// Run in a loop until m_bRunThread is set to false 
				while(threadIsActive) {
					// read incoming stream 
					String packetStringData = in.readLine(); 
					System.out.println("Packet contents: " + packetStringData);
					
					// needs a better way to parse the string!!!!!
					signData = Byte.parseByte(packetStringData);

					if(!ServerOn) {
						System.out.print("Server has already stopped");
						threadIsActive = false;   
					} 

					if(packetStringData.equalsIgnoreCase("end")) { 
						// Special command. Quit this thread and Stop the Server
						threadIsActive = false;   
						System.out.print("Stopping client thread for client : "); 
						ServerOn = false;
					}
					
					else {
						// pass data and location to be drawn on video
					}
				} 
			} 
			catch(Exception e) {
				e.printStackTrace(); 
			} 
			finally {
				// Clean up 
				try {
					in.close(); 
					clientSocket.close(); 
					System.out.println("...Stopped"); 
				} 
				catch(IOException e) {
					e.printStackTrace(); 
				} 
			} 
		} 
	} 
	
	class IdentifiedObject {
		int posX, posY, radius;
		
		public IdentifiedObject(){
			
		}
		
		public IdentifiedObject(int posX, int posY, int radius){
			this.posX = posX;
			this.posY = posY;
			this.radius = radius;
		}

	}
	
	public IdentifiedObject getIdentifiedObject(){
		
		return null;
		
	}
}

