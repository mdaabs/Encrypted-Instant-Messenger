#include "allusers.h"



allUsers user;
//setter for user
void allUsers::setusername(string x){
    user.username=x;
}
void allUsers::setpassword(string y){
    user.password=y;
}
void allUsers::setstatus(string z){
    user.status=z;
}
void allUsers::setip(string w){
    user.ip=w;
}
void allUsers::setport(string p){
    user.port=p;
}
void allUsers::setsocket(int* s){
    user.socket=s;
}
void allUsers::setsalt(char * salt){
    user.salt=salt;
}
void allUsers::setkey(string key){
    user.key=key;
}


//getter
string allUsers::getusername(){
    return user.username;
}
string allUsers::getpassword(){
    return user.password;
}
string allUsers::getstatus(){
    return user.status;
}
string allUsers::getip(){
    return user.ip;
}
string allUsers::getport(){
    return user.port;
}
int* allUsers::getsocket(){
    return user.socket;
}
char* allUsers::getsalt(){
   return user.salt;
}
string allUsers::getkey(){
    return user.key;
}
