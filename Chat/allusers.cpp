#include "allusers.h"



allUsers user;

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
