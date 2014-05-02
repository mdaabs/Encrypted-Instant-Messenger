#ifndef ALLUSERS_H
#define ALLUSERS_H
#include <iostream>
#include <string>
#include <fstream>
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
    char* salt;
    string key;


    void setusername(string);
    void setpassword(string);
    void setstatus(string);
    void setip(string);
    void setport(string);
    void setsocket(int*);
    void setsalt(char *);
    void setkey(string key);

    string getusername();
    string getpassword();
    string getstatus();
    string getip();
    string getport();
    int* getsocket();
    char* getsalt();
    string getkey();

};


#endif // ALLUSERS_H
