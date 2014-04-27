/*
 *	Server.cpp
 *	v. 0.1
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server.cpp -lpthread -o Server
 *
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
#include <map>

//C++ Networking Libraries
#include <sstream>
#include <iomanip>

#include "User.h"

#define MAXINCOMINGCLIENTS 10
#define BUFFERSIZE 256

std::map<std::string, bool> logged_in_users;
std::map<std::string, int> username_sockets;


enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	DEFAULT
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
	if(!decryptedMessage.find("LOGIN"))
		return LOGIN;
	else if(!decryptedMessage.find("SENDMESSAGE"))
		return SENDMESSAGE;
	else
		return DEFAULT;
	
}

/*std::string stringbreakdown(std::string messageinstruct)
{
    std::string array[6];
    int startpoint = 0;
    int stoppoit = 0;
    int i, k;
    k = 0;
    for(i = 0; i < messageinstruct.length(); i++)
    {
        if(messageinstruct.at(i) == ':')
        {
            array[k] = messageinstruct.substr(startpoint, stoppoit);
            std::cout << array[k] << '\n';
            k++;
        }

        if(messageinstruct.length() == i + 1)
                {
                    array[k] = messageinstruct.substr(startpoint, stoppoit + 1);
                    std::cout << array[k] << '\n';
                    k++;
                }
        stoppoit++;

        if(messageinstruct.at(i) == ':')
        {
            startpoint += stoppoit;
            stoppoit = 0;
        }
    }

        return array;
}*/

void sendMessage(int &clientSocket){


}

//Needs to be rewritten for JSON parsing
//function will serve as the main for each thread
//methods called in an upwards fashion
void *parseData(void *clsk){
	bool running=true;
	while(running){
	char messageBuffer[BUFFERSIZE];

	std::cout<<"Successful thread, listening to client: "<<*((int*)clsk)<<std::endl;
	int clientSocket=*((int*)clsk);
	memset(messageBuffer,0,sizeof(messageBuffer));
	read(clientSocket, messageBuffer, BUFFERSIZE);
	std::string decipheredMessage (messageBuffer);
	//std::string encryptedMessage (messageBuffer);
	//std::string decipheredMessage;
	//decipheredMessage=decryptIncomingMessage(encryptedMessage);
	std::cout<<decipheredMessage<<std::endl;
	messagetype action=parseMessage(decipheredMessage);
	std::string delimiter = "=";
	std::string username = decipheredMessage.substr(decipheredMessage.find(delimiter)+1);
	std::cout<<username<<std::endl;
	//std::string username="hardcoded username";
	std::string password="hardcoded password";

	//std::string usernametest="hardcoded username1";
	//std::string passwordtest="hardcoded password1";
	//User* testclient=new User(username1, true1);
	//username_sockets.insert(std::map<std::string, int>::value_type(usernametest, clientSocket));

	switch (action){
		case LOGIN:{
			std::string loginattempt;
			if(validateUserInDatabase(username, password)){
				std::cout<<"user validated"<<std::endl;
				//will add a user class
				//then change bool loggedon to true
				User* client=new User(username, true);
			username_sockets.insert(std::map<std::string, int>::value_type(username, clientSocket));
			std::cout<<"client is "<<username_sockets["username"]<<std::endl;
			loginattempt="successful login";
			//parseData((void*)clientSocket);
			//write(clientSocket,&loginattempt ,sizeof(loginattempt));
			//sendMessage(clientSocket);
			//exit(1);
			break;
			}
			else{
				std::cout<<"invalid credentials"<<std::endl;
				loginattempt="failed login";
				write(clientSocket,&loginattempt ,sizeof(loginattempt));
				close(clientSocket);
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
		case SENDMESSAGE:{
		//std::string tosend="sending"
			//if(logged_in_users["username"]){
//				write(username_sockets["username"],&tosend,sizeof(tosend));
//
//			}
		break;
		}

		default:{
		break;
		}
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
