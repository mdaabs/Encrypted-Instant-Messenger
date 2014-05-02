#ifndef SENDTOCLIENT_H
#define SENDTOCLIENT_H
//#include "client.h"
#include <string.h>
#include "string"
#include "iostream"
#include "fstream"
#include "settings.h"
#include "client.h"
//#include <boost/lexical_cast.hpp>


using namespace std;




class sendToClient
{
public:
    sendToClient();
    //Client thisClient;
    client thisClient;
    int* connect(string ip, string port);
    bool validusername(string username);
    void storesalt(string salt, string username);
    string getsalt(string username);
    bool validpassword(string username, string password);
    void sendmsg(string msg, int*sock);

};

#endif // SENDTOCLIENT_H
