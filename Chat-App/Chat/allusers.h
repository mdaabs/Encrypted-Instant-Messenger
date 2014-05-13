#ifndef ALLUSERS_H
#define ALLUSERS_H
#include <iostream>
#include <string>
#include <fstream>
//#include <sendtoclient.h>
#include <QtNetwork>
using namespace std;

//creates a user class with the users variables

class allUsers
{
public:
   allUsers(){}
    //creates a user class with the users variables

    string username;
    string password;
    string status;
    string ip;
    string port;
    int*socket;
    string iv;
    string key;

//    sendToClient clientInfo;


    void setusername(string);
    void setpassword(string);
    void setstatus(string);
    void setip(string);
    void setport(string);
    void setsocket(int*);
    void setiv(string iv);
    void setkey(string key);
  //  void setclient(sendToClient c);

    string getusername();
    string getpassword();
    string getstatus();
    string getip();
    string getport();
    int* getsocket();
    string getiv();
    string getkey();
  //  sendToClient getclient();

};


#endif // ALLUSERS_H
