#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

#define BUFSIZE 1024

void sendlogin(String username, String password){
	char* bufUser = new char[buflen+1];
	char* bufPass = new char[buflen+1];
	send(server, username.c_str(), username.length(), 0);
	send(server, password.c_str(), password.length(), 0);

}