#include "client.h"

client::client()
{
}
bool client::SendMessage(string message, int *socket){

    if(write(*socket, message.c_str(), message.size())<0)
        return false;
    else
        return true;
}
//string client::receiveNewMsg(){
//    string name;

//    name = emit receiveNewMsg();
//    return name;

//}
string client::receiveMsg(int *socket){
    string line;
    //if(read(*socket, line, line.size())<0)
        return line;


}


int* client::ConnectClient(string IP, string port)
{
    int server_socket,  connection;
    int *client_socket=new int;
    struct sockaddr_in server_address, client_address;
    unsigned short server_port;
    unsigned int address_length;

    /*if(argc != 3){
        std::cerr<<"Incorrect Syntax"<<std::endl;
        std::cerr<<"Runtime Instructions: ./Server <Host Port>"<<std::endl;
        exit(-1);
    }*/


    //server_port = atoi(argv[1]);
    server_port=atoi(port.c_str());
    std::cout<<"Hosting on port: "<<server_port<<std::endl;


    if((server_port > 65535) || (server_port < 2000)){
            std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
            exit(-1);
    }

    //create socket
    *client_socket=socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
    //*client_socket = clsk;

    //int *socketptr=(int*)malloc(client_socket);
    if (client_socket<0){
        std::cerr<<"Failed to create socket"<<std::endl;
        exit(-1);
    }


    std::cout<<"Using socket: "<<server_socket<<std::endl;

    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family=AF_INET;			//basic address family protocol
    client_address.sin_addr.s_addr=htonl(INADDR_ANY);	//take any incoming interface
    client_address.sin_port=htons(server_port);		//local port


    connection = connect(*client_socket,(struct sockaddr *) &client_address, sizeof(client_address));
    if(connection<0){
        std::cerr<<"failed to connect to server"<<std::endl;
        exit(-1);
    }

    //UserAction(&client_socket)

    std::cout<<"address is: "<<&client_socket<<std::endl;
//return socketptr;
    return client_socket;
}


