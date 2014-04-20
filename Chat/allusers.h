#ifndef ALLUSERS_H
#define ALLUSERS_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class allUsers
{
public:
   allUsers(){}

    string username;
    string password;
    string status;
    string ip;
    string port;


    void setusername(string);
    void setpassword(string);
    void setstatus(string);
    void setip(string);
    void setport(string);

    string getusername();
    string getpassword();
    string getstatus();
    string getip();
    string getport();

};


#endif // ALLUSERS_H
