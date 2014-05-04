//#include "Client.cpp"
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
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include "client.h"
using namespace std;
int main(){
string ip="localhost";
string port="8080";
int *socket = *connectToServer(ip,port);
char buffer[256];
cout<<"address is: "<<&socket<<endl;
cout<<"socket is: "<<socket<<endl;
/*while(1){
char buffer[256];
	memset(buffer,0,sizeof(buffer));
cout<<"reading..."<<endl;
read(*socket,buffer,256);
cout<<"read"<<endl;
string input (buffer);
cout<<input<<endl;
}*/

/*while(1){
        char s[300];

        bzero(s, 301);
        cin.getline(s, 300);
	string message (s);        

        sendMessage(message, &socket);


}*/

return 0;


}
