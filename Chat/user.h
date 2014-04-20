#ifndef USER_H
#define USER_H
#include "mainwindow.h"
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
const int MAX=100;
#define Delim '|'

struct thisuser
{

     string username;
     string online;


};
thisuser splitter(string x);
QStringList getusers();
QStringList getOffline();


#endif // USER_H
