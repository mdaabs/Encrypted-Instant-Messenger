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

// Establishes a connection to the server, returns a socket pointer
int *connectClient(string IP, string port);

// Send username and password to the server, and return true or false
bool sendLogin(string login, int *socket);

// Receive a validation response from the server regarding username and password;
// return true or false
bool receiveLogin(int *socket);

// Send a user's message to the server; return true or false
bool sendMessage(string message, int* socket);

// Receive a user's message, and return the message
string receiveMessage(int *socket);
#endif
 
