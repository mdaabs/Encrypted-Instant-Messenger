#ifndef SENDTOCLIENT_H
#define SENDTOCLIENT_H
//#include "client.h"
#include "QObject"
#include <string.h>
#include "string"
#include "iostream"
#include "fstream"
#include "settings.h"
#include "client.h"

//#include <boost/lexical_cast.hpp>


using namespace std;




class sendToClient/* : public QObject*/
{
   //Q_OBJECT
public:
    sendToClient();
    //~sendToClient();
    //Client thisClient;
    client thisClient;
    int* connectto(string ip, string port);
    bool validusername(string username);
    void storesalt(string salt, string username);
    string getsalt(string username);
    bool validpassword(string username, string password);
    void sendmsg(string msg, int*sock);
    string receivemsg(int* socket);
    void sendlogin(string m, int* sock);
//signals:
//    void receivesig(string*);
//public slots:




};

#endif // SENDTOCLIENT_H
