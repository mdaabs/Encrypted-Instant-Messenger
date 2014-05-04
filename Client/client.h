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
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

// Establishes a connection to the server, returns a socket pointer
int *connectToServer(string serverIP, string port);

// Send username and password to the server, and return true or false
bool sendLogin(string login, int *socket);

// Receive a validation response from the server regarding username and password;
// return true or false
bool receiveLogin(int *socket);

// Send a user's message to the server; return true or false
bool sendMessage(string message, int *socket);

// Receive a user's message, and return the message
string receiveMessage(int *socket);

// Get the IV
string getIV(int *socket);

// Get the Key
string getKey(int *socket);
#endif
 
