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

#define BUFSIZE 1024

using namespace std;

string to_delimiter="TO:";
string from_delimiter="FROM:";
string message_delimiter="MESSAGE:";
string star_delimiter="*";
string equal_delimiter="=";

enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	INVALID
};

messagetype ReceiveAction(){
	return LOGIN;
}

bool SendMessage(string message, int* socket){

	if(write(*socket, message.c_str(), sizeof(message))<0)
		return false;
	else
		return true;
}

int *ConnectClient(string IP, string port)
{
	unsigned short server_port;
	unsigned int address_length;
   
	/*if(argc != 3){
		cerr << "Incorrect Syntax" << endl;
		cerr << "Runtime Instructions: ./Server <Host Port>" << endl;
		exit(-1);
	}*/

	
	//Display the hosting port number
	//server_port = atoi(argv[1]);
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
	int *client_socket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	
	if (server < 0){
		cerr << "Failed to create socket" << endl;
		exit(-1);
	} 
	
	cout << "Using socket: " << client_socket << endl;

	//connect to server
	if(connect(*client_socket,(struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		cerr << "Failed to connect to server" << endl;
		exit(-1);
	}
	
	//UserAction(&client_socket)

	//return socketptr;
	return client_socket;
}

void sendUsername(string username, int server) {
    char* usernameBuff = new char[BUFSIZE+1];
    send(server, username.c_str(), username.length(), 0);
    memset(usernameBuff,0,BUFSIZE);
    recv(server,usernameBuff,BUFSIZE,0);
}

void sendPassword(string password, int server) {
    char* passwordBuff = new char[BUFSIZE+1];
    send(server, password.c_str(), password.length(), 0);
    memset(passwordBuff,0,BUFSIZE);
    recv(server,passwordBuff,BUFSIZE,0);
}

