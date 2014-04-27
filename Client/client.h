/********************************************************
*
* CS 410
* Encrypted Instant Messenger
* Team 7, #2scoops
*
* File: client.h
*
* Header file for functions found in client.cpp
*
********************************************************/

#ifndef CLIENT_H
#define CLIENT_H

// Send username and password to the server
//void sendlogin(string username, string password, int server);

// Establishes a connection to the server, returns true if connected, false otherwise
bool connect(string serverIP, unsigned short port);

// Send username to the server
void sendUsername(string username, int server);

// Send password to the server
void sendPassword(string password, int server);

// Send the hash key
void sendkey(char *key, int server);

// Get the hash key
void getkey();

#endif
