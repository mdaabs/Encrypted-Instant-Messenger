/*
 *	Server.cpp
 *	v. 0.1
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server.cpp -lpthread -o Server
 *	g++ -pthread -o Server Server.cpp
 *
 *	Runtime Instructions: ./Server <Host Port>
 *
 *	To Do:
 *	Create a user class that has:
 *	string for username, string for a hashed password, bool for online or not
 *	server main should contain a vector/dynamic array of users online
 *
 *	JSON 
 *	plug in w. other parts
 *	chat
 *	safe/clean exits
 *	
 *	
 *
 *	BUG LIST:
 *	
 *	
 *	
 */

//Standard C libraries
#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
//C Networking libraries
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//Standard C++ libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//C++ Networking Libraries
#include <sstream>
#include <iomanip>

#define MAXINCOMINGCLIENTS 10
#define BUFFERSIZE 256

enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN
};
	

//DEMITRIOUS FILL IN HERE
bool addUserToDatabase(std::string username, std::string password){
	return true;
}

//DEMITRIOUS FILL IN HERE
bool userInDatabase(std::string username, std::string password){
	return true;
}


//DEMITRIOUS FILL IN HERE
bool validateUserInDatabase(std::string username, std::string password){
	return true;
}


//MARIO FILL IN HERE
//Needs to be rewritten for JSON parsing
std::string decryptIncomingMessage(std::string encryptedMessage){
	return "inbound message";
}


//Needs to be rewritten for JSON parsing

messagetype parseMessage(std::string decryptedMessage){

return LOGIN;
}

//Needs to be rewritten for JSON parsing
//function will serve as the main for each thread
//methods called in an upwards fashion
void *parseData(void *clsk){
	char messageBuffer[BUFFERSIZE];

	std::cout<<"Successful thread, listening to client: "<<*((int*)clsk)<<std::endl;
	int clientSocket=*((int*)clsk);
	memset(messageBuffer,0,sizeof(messageBuffer));
	read(clientSocket, messageBuffer, BUFFERSIZE);

	std::string encryptedMessage (messageBuffer);
	std::string decipheredMessage;
	decipheredMessage=decryptIncomingMessage(encryptedMessage);
	messagetype action=parseMessage(decipheredMessage);
	std::string username="hardcoded username";
	std::string password="hardcoded password";
	switch (action){
		case LOGIN:{
			std::string loginattempt;
			if(validateUserInDatabase(username, password)){
				std::cout<<"user validated"<<std::endl;
				//will add a user class
				//then change bool loggedon to true
			
			loginattempt="successful login";
			write(clientSocket,&loginattempt ,sizeof(loginattempt));
			break;
			}
			else{
				std::cout<<"invalid credentials"<<std::endl;
				loginattempt="failed login";
				write(clientSocket,&loginattempt ,sizeof(loginattempt));
				break;
			}		
			break;
		}
		case CHANGEPASSWORD:{
			std::string changepassmessage;
			if(validateUserInDatabase("hardcodedname", "hardcodedpassword")){
				std::cout<<"user validated"<<std::endl;
				//MARIO
				//add methods to hash a new password,
				//DEMETRIOUS
				//rewrtie new hashed pass into the database
				//user remains logged off
				changepassmessage="password changed";
				write(clientSocket,&changepassmessage ,sizeof(changepassmessage));
				break;
			}
			else{
				std::cout<<"invalid credentials"<<std::endl;
				//user remains logged off
				changepassmessage="failed to change password";
				write(clientSocket,&changepassmessage ,sizeof(changepassmessage));
				break;
			}		
			break;
		}
		case ADDUSER:{
			if(!userInDatabase(username, password)){
				addUserToDatabase(username, password);
			}
		break;
		}

		default:{
		break;
		}
	}

}

int main(int argc, char * argv[]){
	int serverSocket, clientSocket;
	struct sockaddr_in serverAddress, clientAddress;
	unsigned short serverPort;
	unsigned int addressLength;


	//Check for argument size
	if(argc != 2){
		std::cerr<<"Incorrect Syntax"<<std::endl;
		std::cerr<<"Runtime Instructions: ./Server <Host Port>"<<std::endl;
		exit(-1);
	}


	serverPort = atoi(argv[1]);
	std::cout<<"Hosting on port: "<<serverPort<<std::endl;


   	if((serverPort > 65535) || (serverPort < 2000)){
      		std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
    		exit(-1);
   	}

	//create socket

	serverSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	if (serverSocket<0){
		std::cerr<<"Failed to create socket"<<std::endl;
		exit(-1);
	}


	std::cout<<"Using socket: "<<serverSocket<<std::endl;

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family=AF_INET;			//basic address family protocol
	serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);	//take any incoming interface
	serverAddress.sin_port=htons(serverPort);		//local port


	//bind socket to port
	std::cout<<"Binding socket to port"<<std::endl;
	if(bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress))<0){
        	std::cerr << "Cannot bind to socket" << std::endl;
       		exit (-1);
    	}
	//Listen for incoming connections
	std::cout<<"listen on port"<<std::endl;
	if(listen(serverSocket, MAXINCOMINGCLIENTS)<0){
		std::cerr<<"failed to listen for connections"<<std::endl;
       		exit (-1);
	}

	bool finished=false;
	int threadCount=0;
	//Loops for clients, then threads off
	while(!finished){
		clientSocket=accept(serverSocket, (struct sockaddr *) &clientAddress, &addressLength);
		pthread_t thread;
		pthread_create(&thread, NULL, parseData, &clientSocket);
		threadCount++;
	}
return 0;
}
