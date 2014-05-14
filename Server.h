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
#include <ctime>
#include <algorithm>
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

#include "sqlite3.h"

//#include "ServerLib.h"
//#include "ServerDBLib.h"
//#define PRINT_KEYS

//HARDWARE DEPENDANT
//#define MAXINCOMINGCLIENTS 50
#define BUFFERSIZE 256


enum messagetype {
	ADDUSER,
	CHANGEPASSWORD,
	LOGIN,
	LOGOFF,
	SENDMESSAGE,
	INVALID
};


extern std::unordered_map<std::string, int*> *username_sockets=new std::unordered_map<std::string, int*>();
extern std::unordered_map<std::string, std::string> *username_keyiv=new std::unordered_map<std::string, std::string>();

extern std::string daemonflag="-D";
extern std::string debugflag="-d";
extern std::string portflag="-p";
extern std::string dbflag="-b";
extern std::string outflag="-o";
extern std::string initializeflag="-i";
extern std::string threadflag="-t";
extern std::string credflag="-g";

extern std::string to_delimiter="TO:";
extern std::string from_delimiter="FROM:";
extern std::string message_delimiter="MESSAGE:";
extern std::string password_delimiter="PASS:";
extern std::string new_password_delimiter="NEWPASS:";
extern std::string star_delimiter="*";
extern std::string equal_delimiter="=";
extern std::string colon_delimiter=":";
extern std::string t="TRUE";
extern std::string f="FALSE";

extern char * database;
//extern std::string outfile;
extern bool debugmode;
//extern sqlite3 *db;

void GetCredentials(std::string t);



#endif

