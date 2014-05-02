/*
*Compile:
*Client
*g++ Client.cpp -o Client
*./Client localhost <port number>
*/

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
#include <time.h>
#include <vector>


std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string star_delimiter="*";
std::string equal_delimiter="=";



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

/*void UserAction(int* client_socket){

	action=





}*/

//int main (int argc, char* argv[])
int ConnectClient(std::string IP, std::string port)
{
	int server_socket, client_socket, connection;
	struct sockaddr_in server_address, client_address;
	unsigned short server_port;
	unsigned int address_length;
   
	/*if(argc != 3){
		std::cerr<<"Incorrect Syntax"<<std::endl;
		std::cerr<<"Runtime Instructions: ./Server <Host Port>"<<std::endl;
		exit(-1);
	}*/


	//server_port = atoi(argv[1]);
	server_port=atoi(port.c_str());
	std::cout<<"Hosting on port: "<<server_port<<std::endl;


   	if((server_port > 65535) || (server_port < 2000)){
      		std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
    		exit(-1);
   	}

	//create socket

	client_socket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	int *socketptr=&client_socket;
	if (client_socket<0){
		std::cerr<<"Failed to create socket"<<std::endl;
		exit(-1);
	}


	std::cout<<"Using socket: "<<server_socket<<std::endl;

	memset(&client_address, 0, sizeof(client_address));
	client_address.sin_family=AF_INET;			//basic address family protocol
	client_address.sin_addr.s_addr=htonl(INADDR_ANY);	//take any incoming interface
	client_address.sin_port=htons(server_port);		//local port


	connection = connect(client_socket,(struct sockaddr *) &client_address, sizeof(client_address));
	if(connection<0){
		std::cerr<<"failed to connect to server"<<std::endl;
		exit(-1);
	}

	//UserAction(&client_socket)


return *socketptr;
}




