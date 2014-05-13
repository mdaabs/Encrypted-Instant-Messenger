#include "sendtoclient.h"
#include "client.h"
#include <QTcpServer>
sendToClient::sendToClient(){
}

int* sendToClient::connectto(string ip,string port){

    int *j;
    int* connected;


    j=thisClient.ConnectClient(ip ,port);
        connected=j;

    return connected;
}
bool sendToClient::validusername(string username){

    bool valid=false;



    return valid;

}
void sendToClient::storesalt(string salt, string username){




}
void sendToClient::sendlogin(string msg, int* sock){


    if(thisClient.SendMessage(msg, sock))
    ;

}
void sendToClient::sendmsg(string msg, int* sock){


    if(thisClient.SendMessage(msg, sock))
    ;

}
string sendToClient::receivemsg(int* socket){

    string received="";

      received=thisClient.receiveMessage(socket);

    return received;
}
string sendToClient::getsalt(string username){
    string salt;


    return salt;

}
bool sendToClient::validpassword(string username, string password){

    bool valid=false;



    return valid;


}
//sendToClient::~sendToClient(){}
