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

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>

using namespace std;

#define BUFSIZE 1024

//void sendlogin(string username, string password, int server);
bool connect(string serverIP, unsigned short port);
void sendUsername(string username, int server);
void sendPassword(string password, int server);
void sendkey(char *key, int server);
void getkey();

int main()
{
//    connect("127.0.0.1", 8080);
}

bool connect(string serverIP, unsigned short port){

    // server IP is converted from string to char
    char *IP = new char[serverIP.size() + 1];
    copy(serverIP.begin(), serverIP.end(), IP);
    IP[serverIP.size()] = '\0';

    // setup socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP); /* Server IP address */ 
    server_addr.sin_port = htons(port);
    //memcpy(&server_addr.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

      // create socket
    int server = socket(PF_INET,SOCK_STREAM,0);
    if (server < 0) {
        perror("socket");
        exit(-1);
    }

      // connect to server
    if (connect(server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
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

void sendkey(char *key, int server) {
    key = new char[BUFSIZE+1];
    send(server, key.c_str(), key.length(), 0);
    memset(key,0,BUFSIZE);
    recv(server,key,BUFSIZE,0);
}

/*void sendlogin(string username, string password, int server){
    char* usernameBuff = new char[BUFSIZE+1];
    send(server, username.c_str(), username.length(), 0);
    memset(usernameBuff,0,BUFSIZE);
    recv(server,usernameBuff,BUFSIZE,0);

    char* passwordBuff = new char[BUFSIZE+1];
    send(server, password.c_str(), password.length(), 0);
    memset(passwordBuff,0,BUFSIZE);
    recv(server,passwordBuff,BUFSIZE,0);

}*/