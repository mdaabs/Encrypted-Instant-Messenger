#include "sendtoclient.h"
#include "client.h"
sendToClient::sendToClient(){};

int* sendToClient::connect(string ip,string port){
//    string serverIP="10.0.2.15";
//   unsigned short testport=5432;
    int *j;
    int* connected;

    //int temp=atoi(port.c_str());

    //unsigned short intport= (unsigned short)(*port.c_str());
//    if(testport == port ){

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
void sendToClient::sendmsg(string msg, int* sock){

    if(thisClient.SendMessage(msg, sock))
    ;

}
string sendToClient::getsalt(string username){
    string salt;


    return salt;

}
bool sendToClient::validpassword(string username, string password){

    bool valid=false;



    return valid;


}
