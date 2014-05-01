/*
 *	Server.cpp
 *	v. 0.3
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server3.cpp -std=gnu++0x -lpthread -w -o Server3

 *
 *
 *	Runtime Instructions: ./Server <Host Port>
 *
 *	LOGIN=username
 *	SENDMESSAGE=TO:theirname*MESSAGE:message
 *
 *
 *	To Do:
 *	needs dynamic user messages. gonna have to parse input string better
 *	error handling
 *	
 *	 
 *	plug in w. other parts
 *	safe/clean exits
 *	
 *
 *	can use pthread_detach(pthread_self()) at user logoff to detach thread
 *	and/or can use pthread_exit()
 *
 *	close(clientSocket); upon logoff request
 *
 *
 *	BUG LIST:
 *	everything
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
//C++ Standard data structures (included in std namespace)
#include <map>
#include <queue>
//Deprecated- may need to patch in the future
#include <unordered_map>

//#include <mutex>
//C++ Networking Libraries
#include <sstream>
#include <iomanip>

#include "User.h"

//HARDWARE DEPENDANT
#define MAXINCOMINGCLIENTS 50
#define BUFFERSIZE 256


std::unordered_map<std::string, int*> *username_sockets=new std::unordered_map<std::string, int*>();
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string star_delimiter="*";
std::string equal_delimiter="=";
int zombie_threads=0;


enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	INVALID
};

//MARIO FILL IN HERE
std::string DecryptInput(std::string input){

		
	return input;
}

std::string GetMessage(std::string input){

	std::string message=input.substr(input.find(message_delimiter)+(message_delimiter.length()));
	std::cout<<"message is: "<<message<<std::endl;
	return message;
}


std::string GetMessageReceiver(std::string input){

	std::string receiver=input.substr(input.find(to_delimiter)+(to_delimiter.length()));
	receiver=receiver.substr(0,receiver.find(star_delimiter));
	//receiver=receiver.substr(0,receiver.find(message_delimiter));
	//receiver=input.substr(input.find(to_delimiter)+1);
	std::cout<<"receiver is: "<<receiver<<std::endl;
	return receiver;
}

bool IsUserOnline(std::string username){
 	std::unordered_map<std::string,int *>::const_iterator contains=username_sockets->find(username);
	if(contains!=username_sockets->end())
		return true;
	else
		return false;
}

//IF at() is called and doesn't exist, shit goes HAM
//THROWS: terminate called after throwing an instance of 'std::out_of_range' what():  _Map_base::at

//need to error handle

void SendMessage(std::string sender, std::string receiver, std::string message){
	int *receiver_socket=username_sockets->at(receiver);
	write(*receiver_socket, message.c_str(), sizeof(message));

}

void LogUserOff(std::string username){
	std::cout<<"logoff called for "<<username<<std::endl;
	std::cout<<"mutex locking"<<std::endl;
	pthread_mutex_lock(&mutex);
	username_sockets->erase(username);
	pthread_mutex_unlock(&mutex);
	std::cout<<"mutex released"<<std::endl;
	std::cout<<"removed user: "<<username<<std::endl;
}

std::string LogUserOn(std::string input, int *client_socket){
	//std::string delimiter="=";
	std::string username=input.substr(input.find(equal_delimiter)+1);
	std::cout<<"mutex locking"<<std::endl;
	
	pthread_mutex_lock(&mutex);
	username_sockets->insert(std::map<std::string, int*>::value_type(username, client_socket));
	pthread_mutex_unlock(&mutex);
	std::cout<<"mutex released"<<std::endl;
	std::cout<<"logged user: "<<username<<" online"<<std::endl;
	//std::cout<<"user is on port address: "<<&(username_sockets["username"])<<std::endl; 
	return username;
}

//ONLY SUPPORTING LOGIN, LOGOFF AND SENDMESSAGE
messagetype ParseData(std::string input){

	std::string action=input.substr(0, input.find(equal_delimiter));
	if(action.compare("LOGIN")==0){
	std::cout<<"login"<<std::endl;
		return LOGIN;
	}
	if(action.compare("LOGOFF")==0){
	std::cout<<"logoff"<<std::endl;
		return LOGOFF;
	}
	if(action.compare("SENDMESSAGE")==0){
	std::cout<<"message"<<std::endl;
		return SENDMESSAGE;
	}
	else
		return INVALID;

}
	//mutex for adding to map
	/*pthread_mutex_lock(&mutex);
	username_sockets.insert(std::map<std::string, int>::value_type(username, client_socket));
	pthread_mutex_unlock(&mutex);*/
	
void *ThreadMain(void *clsk){

	char buffer[BUFFERSIZE];
	std::string username;
	//std::string* nameptr=&username;
	//pthread_detach(pthread_self());
	int client_socket=*((int*)clsk);
	std::cout<<"Successful thread, listening to client: "<<*((int*)clsk)<<std::endl;
	bool listening=true;
	while(listening){
	std::cout<<"Recieving input"<<std::endl;
	memset(buffer,0,BUFFERSIZE);
	read(client_socket, buffer, BUFFERSIZE);
	std::cout<<"Successfully received message"<<std::endl;
	std::string input(buffer);
	std::cout<<"decrypting input..."<<std::endl;
	//input=DecryptInput(input);	//waiting for mario's code.
	std::cout<<"converting message type"<<std::endl;
	messagetype action=ParseData(input);

	std::string receiver;
	std::string message;

	switch(action){
		case LOGIN:
			//add validation code
			username=LogUserOn(input, &client_socket);
			//*nameptr=LogUserOn(input, &client_socket);
			std::cout<<username<<std::endl;
			//std::cout<<*nameptr<<std::endl;

			break;

		
		case LOGOFF:
			//add validation code
		//	std::cout<<"checking for "<<*nameptr<<std::endl;
			std::cout<<IsUserOnline(username)<<std::endl;
		//	username=LogUserOn(input, &client_socket);
			std::cout<<"checking for "<<username<<std::endl;
		//	std::cout<<IsUserOnline(username)<<std::endl;
			LogUserOff(username);
			std::cout<<IsUserOnline(username)<<std::endl;
			close(client_socket);
			listening=false;
			break;
		
		case SENDMESSAGE:
			//add validation code

			receiver=GetMessageReceiver(input);
			message=GetMessage(input);
			SendMessage(username, receiver,message);
	
		default:
			break;
		

		}

	
	}	
	zombie_threads++;
	pthread_exit(0);



}

int main(int argc, char * argv[]){
	int server_socket, client_socket;
	struct sockaddr_in server_address, client_address;
	unsigned short server_port;
	unsigned int address_length;


	//Check for argument size
	if(argc != 2){
		std::cerr<<"Incorrect Syntax"<<std::endl;
		std::cerr<<"Runtime Instructions: ./Server <Host Port>"<<std::endl;
		exit(-1);
	}


	server_port = atoi(argv[1]);
	std::cout<<"Hosting on port: "<<server_port<<std::endl;


   	if((server_port > 65535) || (server_port < 2000)){
      		std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
    		exit(-1);
   	}

	//create socket

	server_socket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	if (server_socket<0){
		std::cerr<<"Failed to create socket"<<std::endl;
		exit(-1);
	}


	std::cout<<"Using socket: "<<server_socket<<std::endl;

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family=AF_INET;			//basic address family protocol
	server_address.sin_addr.s_addr=htonl(INADDR_ANY);	//take any incoming interface
	server_address.sin_port=htons(server_port);		//local port


	//bind socket to port
	std::cout<<"Binding socket to port"<<std::endl;
	if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address))<0){
        	std::cerr << "Cannot bind to socket" << std::endl;
       		exit (-1);
    	}
	//Listen for incoming connections
	std::cout<<"listen on port"<<std::endl;
	if(listen(server_socket, MAXINCOMINGCLIENTS)<0){
		std::cerr<<"failed to listen for connections"<<std::endl;
       		exit (-1);
	}


	bool finished=false;
	int thread_count=0;
	//Loops for clients, then threads off
	while(!finished){
		client_socket=accept(server_socket, (struct sockaddr *) &client_address, &address_length);
		pthread_t thread;
		pthread_create(&thread, NULL, ThreadMain, &client_socket);
		thread_count++;

	}




return 0;
}

