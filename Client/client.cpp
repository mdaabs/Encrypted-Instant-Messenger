/********************************************************
*
* CS 410
* Encrypted Instant Messenger
* Team 7, #2scoops
*
* File: client.cpp
*
* Set up communication for the client with the server.
*
********************************************************/

#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include "client.h"
#define BUFSIZE 256

using namespace std;

/*enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	INVALID
};

messagetype ReceiveAction(){
	return LOGIN;
}*/

int *connectToServer(string IP, string port)
{
	unsigned short server_port;
	unsigned int address_length;

	//Display the hosting port number
	server_port=atoi(port.c_str());
	cout << "Hosting on port: " << server_port << endl;


   	if((server_port > 65535) || (server_port < 2000)){
      		cerr << "Please enter a port number between 2000 - 65535" << endl;
    		exit(-1);
   	}

	// setup socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;		    //basic address family protocol
    server_addr.sin_addr.s_addr = htonl(server_port);    //take any incoming interface
    server_addr.sin_port = htons(server_port);	    //local port

	//create socket
    int *client_socket = new int;	
	*client_socket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	
	if (client_socket < 0){
		cerr << "Failed to create socket" << endl;
		exit(-1);
	} 
	
	cout << "Using socket: " << client_socket << endl;

	//connect to server
	if(connect(*client_socket,(struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		cerr << "Failed to connect to server" << endl;
		exit(-1);
	}

	//return socketptr;
	return client_socket;
}

bool sendLogin(string login, int *socket) {
    if(write(*socket, login.c_str(), sizeof(login)) < 0) {
    	cerr << "Failed to send login" << endl;
    	return false;
    } else
    	return true;
}

bool receiveLogin(int *socket) {
	//Hold response from the server
	char* validator = new char[BUFSIZE];
	if(read(*socket,validator,BUFSIZE) < 0) {
    	cerr << "Failed to read login response" << endl;
    	return false;
    } else if (validator == "TRUE")
    	return true;
    else
    	return false;
}

bool sendMessage(string message, int *socket){

	if(write(*socket, message.c_str(), sizeof(message))<0) {
		cerr << "Failed to send user message" << endl;
		return false;
	} else
		return true;
}

string receiveMessage(int *socket) {
	char* messageBuf = new char[BUFSIZE];
	if(read(*socket,messageBuf,BUFSIZE) < 0) {
    	cerr << "Failed to read login response" << endl;
    	exit(-1);
    }
    return messageBuf;
}

int main()
{

	int *socket = connectToServer("127.0.0.1","8080");
	char buffer[256];
	cout<<"address is: "<<&socket<<endl;
	cout<<"socket is: "<<socket<<endl;
    return 0;
}