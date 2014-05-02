#include "Client.cpp"

int main(){
std::string ip="localhost";
std::string port="5314";
//int *socket;
int *socket=ConnectClient(ip,port);
char buffer[256];
	std::cout<<"address is: "<<&socket<<std::endl;
	//std::cout<<"socket ptr: "<<*socket<<std::endl;
	std::cout<<"socket is: "<<socket<<std::endl;
while(1){
char buffer[256];
	memset(buffer,0,sizeof(buffer));
std::cout<<"reading..."<<std::endl;
read(*socket,buffer,256);
std::cout<<"read"<<std::endl;
std::string input (buffer);
std::cout<<input<<std::endl;
}
return 0;


}
