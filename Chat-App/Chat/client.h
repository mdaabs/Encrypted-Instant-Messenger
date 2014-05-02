
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
#include "tabdialog.h"

using namespace std;



#ifndef CLIENT_H
#define CLIENT_H




//enum messagetype {
//   ADDUSER,
//   CHANGEPASSWORD,
//   LOGIN,
//   LOGOFF,
//   SENDMESSAGE,
//   INVALID
//};

//messagetype ReceiveAction(){
//   return LOGIN;
//}

class client
{


public:
    client();
     bool SendMessage(string message , int* socket);
    int* ConnectClient(string IP, string port);
    string receiveMsg(int*socket);

};

#endif // CLIENT_H
