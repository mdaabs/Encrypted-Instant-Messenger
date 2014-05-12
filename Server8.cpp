/*
 *	Server.cpp
 *	v. 0.7
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server8.cpp Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lcrypto -ldl -o Server8
 *
 *
 *
 *
 *	Runtime Instructions: ./Server <Host Port>
 *
 *	LOGIN=username
 *	SENDMESSAGE=TO:theirname*MESSAGE:message
 *
 *
 *	To Do:
 *	needs dynamic user messages. gonna have to parse input string better
 *	error handling
 *	
 *	 
 *	plug in w. other parts
 *	safe/clean exits
 *	
 *
 *	can use pthread_detach(pthread_self()) at user logoff to detach thread
 *	and/or can use pthread_exit()
 *
 *	close(clientSocket); upon logoff request
 *
 *
 *	BUG LIST:
 *	everything
 *	
 *	
 */

//Standard C libraries
#include "Server.h"
#include "ServerLib.cpp"

std::string database;
std::string outfile;
//int zombie_threads=0;
bool daemonize=false;
bool debugmode=false;
bool portspecified=false;
bool dbspecified=false;
bool outfilespecified=false;



//DEMITRIOUS FILL IN HERE
bool IsUserInDatabase(std::string username){

	return true;
}
//DEMITRIOUS FILL IN HERE
bool AddUserToDatabase(std::string username, std::string password, std::string salt){


	return true;
}

bool ValidateUserInDatabase(std::string username, std::string password){

return false;
}



//ONLY SUPPORTING LOGIN, LOGOFF AND SENDMESSAGE
messagetype ParseData(std::string input){

	std::string action=input.substr(0, input.find(equal_delimiter));
	if(action.compare("LOGIN")==0){
		if(debugmode)
			std::cout<<"login"<<std::endl;
		return LOGIN;
	}
	if(action.compare("LOGOFF")==0){
		if(debugmode)
			std::cout<<"logoff"<<std::endl;
		return LOGOFF;
	}
	if(action.compare("SENDMESSAGE")==0){
		if(debugmode)
			std::cout<<"message"<<std::endl;
		return SENDMESSAGE;
	}
	if(action.compare("ADDUSER")==0){
		if(debugmode)
			std::cout<<"adduser"<<std::endl;
		return ADDUSER;
	}
	else
		return INVALID;

}

	
void *ThreadMain(void *clsk){
	pthread_detach(pthread_self());

	char buffer[BUFFERSIZE];
	std::string username, password, salt, iv, key, key_iv;

	if(debugmode)
		std::cout<<"Encryption object being created: "<<std::endl;

	Encryption cryptobject;	
	if(debugmode)
		std::cout<<"object size: "<<sizeof(cryptobject)<<std::endl;
	key=cryptobject.printKey();
	iv=cryptobject.printIV();
	key_iv=FormatKeyIV(key, iv);

	if(debugmode){
		std::cout<<"Key generated as: "<<std::endl;
		std::cout<<key<<std::endl;
		std::cout<<"IV generated as: "<<std::endl;
		std::cout<<iv<<std::endl;

	}

	int client_socket=*((int*)clsk);

	if(debugmode)
		std::cout<<"Successful thread, listening to client: "<<*((int*)clsk)<<std::endl;

	bool listening=true;
	while(listening){
		if(debugmode)
			std::cout<<"Recieving input"<<std::endl;
		memset(buffer,0,BUFFERSIZE);
		read(client_socket, buffer, BUFFERSIZE);
		if(debugmode)
			std::cout<<"Successfully received message"<<std::endl;
		std::string input(buffer);
		if(debugmode)
		//	std::cout<<"decrypting input..."<<std::endl;
		if(debugmode)
			std::cout<<"converting message type"<<std::endl;
		messagetype action=ParseData(input);

		std::string receiver;
		std::string message;
		std::string confirmation;


		switch(action){
		case LOGIN:
			//add validation code


			username=GetUserName(input);
			password=GetUserPassword(input);
			if(ValidateUserInDatabase(username, password)){
				if(debugmode)
					std::cout<<"invalid login"<<std::endl;
				SendMessage(username, username,f);
				pthread_exit(0);

			}
			LogUserOn(username, &client_socket);
			StoreUserKeyIV(username, key_iv);
			SendMessage(username, username,t);
			memset(buffer,0,BUFFERSIZE);
			read(client_socket, buffer, BUFFERSIZE);
			{
				std:: string credreq (buffer);
				if(!(credreq.compare("CREDREQ")==0)){
					close(client_socket);
					//loggedon=false;
					listening=false;
					pthread_exit(0);
			}
			SendMessage(username, username,key_iv);
			}
			if(debugmode)
				std::cout<<username<<std::endl;

			break;

			
		case LOGOFF:
			//add validation code

			if(debugmode)
				std::cout<<IsUserOnline(username)<<std::endl;

			if(debugmode)
				std::cout<<"checking for "<<username<<std::endl;

			LogUserOff(username);
			if(debugmode)
				std::cout<<IsUserOnline(username)<<std::endl;

			close(client_socket);
			//loggedon=false;
			listening=false;
			pthread_exit(0);
			break;
		/*had to encsapulate in brackets due to scoping limitations*/
		case SENDMESSAGE:{

			receiver=GetMessageReceiver(input);
			message=GetMessage(input);
            //george's testing for encrypt and decrypt

                       unsigned char* char_key=convertString(key);
                       // key="1";
                       unsigned char* char_iv=convertString(iv);
                       // iv="1";


                        unsigned char *decrypt = NULL;
                        unsigned char *encmsg = NULL;
                    //   Encryption crypto;

                       cryptobject.DecryptAes(( unsigned char*)message.c_str(), message.size() + 1, &decrypt, ( unsigned char*)char_key, ( unsigned char*)char_iv);

                      	if(debugmode)
                       		std::cout<<"decrypt: "<<(const char *) decrypt<<"\n";
			
			message=(const char *) decrypt;

			std::string recv_key=GetReceiversKey(receiver);
			std::string recv_iv=GetReceiversIV(receiver);

			unsigned char* char_recv_key=convertString(recv_key);
			unsigned char* char_recv_iv=convertString(recv_iv);

                        cryptobject.EncryptAes((const unsigned char*)message.c_str(), message.size() + 1, &encmsg, ( unsigned char*)char_recv_key, ( unsigned char*)char_recv_iv);

                      	if(debugmode)
				std::cout<<"encrypt: "<<(const char *) encmsg<<"\n";

                        message=(const char *) encmsg;

            message=FormatOutGoingMessage(username, message);
            SendMessage(username, receiver,message);

            break;
			}

		case ADDUSER:

			username=GetMessageReceiver(input);

			if(IsUserInDatabase(username)){
				if(debugmode)
				std::cout<<"user: "<<username<<"username taken"<<std::endl;
				SendMessage(username, username,f);
				pthread_exit(0);

			}

			salt=generateSalt();
			if (debugmode)
				std::cout<<"salt generated: "<<salt<<std::endl;
			AddUserToDatabase(username, password, salt);
			//close(client_socket);
			//pthread_exit(0);
			break;

		case CHANGEPASSWORD:

			IsUserInDatabase(username);
			
			break;

		case INVALID:
			if(debugmode)
				std::cout<<"invalid command received"<<std::endl;			
			break;
		default:
			break;
		

		}

	
	}	
	//zombie_threads++;
	pthread_exit(0);



}
void endprocess(){
	if (debugmode)
		std::cout<<"terminating"<<std::endl;
	delete username_sockets;
	delete username_keyiv;
}

void signal_callback_handler(int signum){
	//std::cout<<"handled sig exit"<<std::endl;
	endprocess();
	exit(signum);

}

int main(int argc, char * argv[]){
	int server_socket, client_socket;
	struct sockaddr_in server_address, client_address;
	unsigned short server_port;
	unsigned int address_length;

	pid_t pid;
	signal(SIGINT,signal_callback_handler);
//if (typeid(a) == typeid(int()))
	int i=1;
	for(i=1;i<argc;i++){
		if(argv[i]==daemonflag){
			daemonize=true;
		}
		if(argv[i]==debugflag){
			debugmode=true;
		}
		if(argv[i]==portflag){
			portspecified=true;
			server_port = atoi(argv[i+1]);
		}
		if(argv[i]==dbflag){
			dbspecified=true;
			database = argv[i+1];
		}
		if(argv[i]==outflag){
			outfilespecified=true;
			outfile = atoi(argv[i+1]);
		}


	}

	if(!dbspecified){
		std::cerr<<"No database specified"<<std::endl;
		exit(-1);
	}
	if(!portspecified){
		std::cerr<<"no port specified"<<std::endl;
    		exit(-1);
	}

	if(daemonize&&debugmode){
		std::cerr<<"Can't debug and daemonize"<<std::endl;
		exit(-1);
	}


	if(debugmode)
		std::cout<<"Hosting on port: "<<server_port<<std::endl;


   	if((server_port > 65535) || (server_port < 2000)){
      		std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
    		exit(-1);
   	}

	//create socket

	server_socket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	if (server_socket<0){
		std::cerr<<"Failed to create socket"<<std::endl;
		exit(-1);
	}

	if(debugmode)
		std::cout<<"Using socket: "<<server_socket<<std::endl;

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family=AF_INET;			//basic address family protocol
	server_address.sin_addr.s_addr=htonl(INADDR_ANY);	//take any incoming interface
	server_address.sin_port=htons(server_port);		


	//bind socket to port
	if(debugmode)
		std::cout<<"Binding socket to port"<<std::endl;
	if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address))<0){
        	std::cerr << "Cannot bind to socket" << std::endl;
       		exit (-1);
    	}
	//Listen for incoming connections
	if(debugmode)
		std::cout<<"listening on port"<<std::endl;
	if(listen(server_socket, MAXINCOMINGCLIENTS)<0){
		std::cerr<<"failed to listen for connections"<<std::endl;
       		exit (-1);
	}


	bool finished=false;
	int thread_count=0;

	if(daemonize){
		pid=fork();
		if(pid>0){
			exit(0);
		}
	}
		
	//Loops for clients, then threads off
	while(!finished){
		client_socket=accept(server_socket, (struct sockaddr *) &client_address, &address_length);
		pthread_t thread;
		pthread_create(&thread, NULL, ThreadMain, &client_socket);
		thread_count++;

	}

	endprocess();

return 0;
}

