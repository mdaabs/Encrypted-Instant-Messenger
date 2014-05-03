//#include "Client.cpp"
#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include "client_new.cpp"
using namespace std;
int main(){
std::string ip="localhost";
std::string port="8080";
//int *socket;
int *socket=connectClient(ip,port);
char buffer[256];
	std::cout<<"address is: "<<&socket<<std::endl;
	//std::cout<<"socket ptr: "<<*socket<<std::endl;
	std::cout<<"socket is: "<<socket<<std::endl;
/*while(1){
char buffer[256];
	memset(buffer,0,sizeof(buffer));
std::cout<<"reading..."<<std::endl;
read(*socket,buffer,256);
std::cout<<"read"<<std::endl;
std::string input (buffer);
std::cout<<input<<std::endl;
}*/

while(1){
        char s[300];

        bzero(s, 301);
        std::cin.getline(s, 300);
	string message (s);        

        sendMessage(message, socket);


}

return 0;


}
