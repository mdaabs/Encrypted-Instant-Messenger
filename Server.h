#ifndef SERVER_H_
#define SERVER_H_


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
#include <signal.h>
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
#include <exception>
//C++ Standard data structures (included in std namespace)
#include <map>
#include <queue>
//Deprecated- may need to patch in the future
#include <unordered_map>

//#include <mutex>
//C++ Networking Libraries
#include <sstream>
#include <iomanip>

//Custom files
//#include "Encryption.cpp"
#include "Encryption.h"
#include "Hash.h"
//#define PRINT_KEYS

//HARDWARE DEPENDANT
#define MAXINCOMINGCLIENTS 50
#define BUFFERSIZE 256


enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	INVALID
};

std::string daemonflag="-D";
std::string debugflag="-d";
std::string portflag="-p";
std::string dbflag="-b";
std::string outflag="-o";

std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string password_delimiter="PASS:";
std::string star_delimiter="*";
std::string equal_delimiter="=";
std::string colon_delimiter=":";
std::string t="TRUE";
std::string f="FALSE";

extern std::string database;
extern std::string outfile;

/*std::string DecryptInput(std::string input);

std::string FormatOutGoingMessage(std::string username, std::string message);

std::string GetMessage(std::string input);

std::string GetMessageReceiver(std::string input);

bool IsUserOnline(std::string username);

bool IsUserInDatabase(std::string username);

bool AddUserToDatabase(std::string username);

std::string GetUserName(std::string input);

void SendMessage(std::string sender, std::string receiver, std::string message);

void LogUserOff(std::string username);

void LogUserOn(std::string username, int *client_socket);

messagetype ParseData(std::string input);

void *ThreadMain(void *clsk);

void signal_callback_handler(int signum);*/




#endif

