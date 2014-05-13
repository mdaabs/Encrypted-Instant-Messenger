/*
 *	Server.cpp
 *	v. 0.8
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server8.cpp Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lsqlite3 -lcrypto -ldl -o Server8
 *
 *
 *
 *
 *	Runtime Instructions: ./Server <Host Port>
 *
 *	LOGIN=username*PASS:password
 *	LOGOFF=username
 *	SENDMESSAGE=TO:theirname*MESSAGE:message
 *	ADDUSER=username*PASS:password
 *
 *
 *	To Do:
 *	sql mutex
 *	Change Password 
 *
 *	RSA
 *	log file
 *	 
 *	safe/clean exits (handle client drop) (turn reads into if statements that handle disconnects) / daemonkill
 *	
 *
 *
 *	BUG LIST:
 *	everything
 *
 *
 *	FLAGS:
 *	mandatory:
 *	-p portnumber	
 *	-b database
 *	optional:
 *	-d debug
 *	-D daemonize
 *	-o logfile (uninmplemented)
 *
 *
 *	
 *	
 */

//Standard C libraries
#include "Server.h"
#include "ServerLib.cpp"
#include "ServerDBLib.cpp"
//std::unordered_map<std::string, int*> *username_sockets=new std::unordered_map<std::string, int*>();
//std::unordered_map<std::string, std::string> *username_keyiv=new std::unordered_map<std::string, std::string>();


char * database;
std::string outfile;
//int zombie_threads=0;
bool daemonize=false;
bool debugmode=false;
bool portspecified=false;
bool dbspecified=false;
bool outfilespecified=false;



messagetype ParseData(std::string input){

	std::string action=input.substr(0, input.find(equal_delimiter));
	if(action.compare("LOGIN")==0){
		if(debugmode)
			std::cout<<"login attempt"<<std::endl;
		return LOGIN;
	}
	if(action.compare("LOGOFF")==0){
		if(debugmode)
			std::cout<<"logoff attempt"<<std::endl;
		return LOGOFF;
	}
	if(action.compare("SENDMESSAGE")==0){
		if(debugmode)
			std::cout<<"message attempt"<<std::endl;
		return SENDMESSAGE;
	}
	if(action.compare("ADDUSER")==0){
		if(debugmode)
			std::cout<<"adduser attempt"<<std::endl;
		return ADDUSER;
	}
	else
		return INVALID;

}


void *ThreadMain(void *clsk){
	pthread_detach(pthread_self());

	char buffer[BUFFERSIZE];
	std::string username, password, salt, iv, key, key_iv;

	bool loggedon=false;

	if(debugmode)
		std::cout<<"Encryption object being created: "<<std::endl;

	Encryption cryptobject;	

	//	key=cryptobject.printKey();
	//	iv=cryptobject.printIV();
	//	key_iv=FormatKeyIV(key, iv);

	/*	if(debugmode){
		std::cout<<"Key generated as: "<<std::endl;
		std::cout<<key<<std::endl;
		std::cout<<"IV generated as: "<<std::endl;
		std::cout<<iv<<std::endl;

	} */

	int client_socket=*((int*)clsk);

	if(debugmode)
		std::cout<<"Successful thread, listening to client: "<<*((int*)clsk)<<std::endl;

	bool listening=true;
	while(listening){
		if(debugmode)
			std::cout<<"waiting for input"<<std::endl;
		memset(buffer,0,BUFFERSIZE);
		if(read(client_socket, buffer, BUFFERSIZE)<0){
			if(debugmode)
				std::cout<<"client dropped"<<std::endl;
			close(client_socket);
			pthread_exit(0);
		}
		if(debugmode)
			std::cout<<"Successfully received data"<<std::endl;
		std::string input(buffer);

		if(debugmode)
			std::cout<<"parsing data"<<std::endl;
		messagetype action=ParseData(input);

		std::string receiver;
		std::string message;
		std::string confirmation;


		switch(action){
		case LOGIN:
			if(loggedon){
				if(debugmode)
					std::cout<<"user already logged in"<<std::endl;
				SendMessage(username, username,f);
				close(client_socket);
				pthread_exit(0);
				listening=false;
				break;
			}

			username=GetUserName(input);
			password=GetUserPassword(input);
			salt=GetUserSalt(username);
			if(debugmode)
				std::cout<<"salt returned as: "<<salt<<std::endl;
			password=generateHash(salt, password);
			if(debugmode)
				std::cout<<"hashed pass: "<<password<<std::endl;
			loggedon=ValidateUserInDatabase(username, password);
			if(!loggedon){
				if(debugmode)
					std::cout<<"invalid login credentials"<<std::endl;
				SendMessage(username, username,f);
				close(client_socket);
				pthread_exit(0);
				listening=false;
				break;

			}

			key=cryptobject.printKey();
			iv=cryptobject.printIV();
			key_iv=FormatKeyIV(key, iv);

			if(debugmode){
				std::cout<<"Key generated as: "<<std::endl;
				std::cout<<key<<std::endl;
				std::cout<<"IV generated as: "<<std::endl;
				std::cout<<iv<<std::endl;

			}

			LogUserOn(username, &client_socket);
			StoreUserKeyIV(username, key_iv);
			SendMessage(username, username,t);
			memset(buffer,0,BUFFERSIZE);
			if(read(client_socket, buffer, BUFFERSIZE)<0){
				if(debugmode)
					std::cout<<"client dropped"<<std::endl;
				close(client_socket);
				pthread_exit(0);
			}
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

			break;


		case LOGOFF:

			if(!loggedon){
				if(debugmode)
					std::cout<<"user not logged in"<<std::endl;
				SendMessage(username, username,f);
				//close(client_socket);
				//pthread_exit(0);
				//listening=false;
				break;
			}

			else{
				LogUserOff(username);
				close(client_socket);
				loggedon=false;
				listening=false;
				pthread_exit(0);
				break;
			}
			/*had to encsapulate in brackets due to scoping limitations*/
		case SENDMESSAGE:{
			if(!loggedon){
				if(debugmode)
					std::cout<<"not logged on"<<std::endl;
				SendMessage(username, username,f);
				close(client_socket);
				pthread_exit(0);
				listening=false;
				break;

			}
			receiver=GetMessageReceiver(input);
			message=GetMessage(input);

			unsigned char* char_key=convertString(key);

			unsigned char* char_iv=convertString(iv);

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
			bool found_receiver=SendMessage(username, receiver,message);
			if(!found_receiver){
				if(debugmode)
					std::cout<<"couldn't find: "<<receiver<<std::endl;
				SendMessage(username, username,f);

			}
			break;
		}

		case ADDUSER:

			username=GetUserName(input);
			password=GetUserPassword(input);
			{
				bool user_exists=IsUserInDatabase(username);
				if(user_exists){
					if(debugmode)
						std::cout<<"user: "<<username<<"username taken"<<std::endl;
					SendMessage(username, username,f);
					pthread_exit(0);

				}
			}
			salt=generateSalt();
			//		password=generateHash(salt, password);
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

