/*
 *	Server.cpp
 *	v. 1.0
 *
 *	Compile Instructions: Standard g++
 *	g++ Server.cpp Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lsqlite3 -lcrypto -ldl -o Server
 *
 *
 *
 *
 *	Runtime Instructions: ./Server -p <Host Port> -b <database>
 *
 *	LOGIN=username*PASS:password
 *	LOGOFF=username
 *	SENDMESSAGE=TO:theirname*MESSAGE:message
 *	ADDUSER=username*PASS:password
 *	CHANGEPASSWORD=username*PASS:password*NEWPASS:newpassword
 *
 *	To Do:
 *	Dynamic logoff
 *	RSA
 *	 
 *	safe/clean exits (handle client drop) (turn reads into if statements that handle disconnects) / daemonkill
 *	
 *
 *
 *	BUG LIST:
 *	everything involving the database
 *	no dynamic log offs
 *
 *	FLAGS:
 *	mandatory:
 *	-p portnumber	
 *	-b database
 *	optional:
 *	-d debug
 *	-D daemonize
 *	-o logfile 
 *	-i initialize database (doesnt work)
 *
 *
 *	
 *	
 */

/*void login::getkeyandiv(string t){
    int pos=t.find("*IV");

    string key=t.substr(4,pos-4);

    string iv=t.substr((pos+4));




}*/

#include "Server.h"
#include "ServerLib.cpp"
#include "ServerDBLib.cpp"
//std::unordered_map<std::string, int*> *username_sockets=new std::unordered_map<std::string, int*>();
//std::unordered_map<std::string, std::string> *username_keyiv=new std::unordered_map<std::string, std::string>();

pthread_mutex_t db_mutex = PTHREAD_MUTEX_INITIALIZER;
//	pthread_mutex_lock(&db_mutex);
//	pthread_mutex_unlock(&db_mutex);

//std::ofstream logfile;
//std::string outfile;    

char * database;
std::string outfile;
//int zombie_threads=0;
bool daemonize=false;
bool debugmode=false;
bool portspecified=false;
bool dbspecified=false;
bool outfilespecified=false;
bool initializedatabase=false;
bool threadsspecified=false;
std::string credentialfile="Credentials.txt";
int max_threads=30;
std::string cred_key;
std::string cred_iv;

void GetCredentials(std::string t){
    int pos=t.find("*IV");

    cred_key=t.substr(4,pos-4);

    cred_iv=t.substr((pos+4));

}

std::string LoadFile(){
    std::ifstream in(credentialfile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string test = buffer.str();
    std::cout << test << std::endl << std::endl;
}


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
	if(action.compare("CHANGEPASSWORD")==0){
		if(debugmode)
			std::cout<<"password change attempt"<<std::endl;
		return CHANGEPASSWORD;
	}
	else
		return INVALID;

}


void *ThreadMain(void *clsk){
	pthread_detach(pthread_self());
	time_t curr_time = time(0);   // get time now
   	struct tm * now = localtime( & curr_time );
	char buffer[BUFFERSIZE];
	char pingbuffer[BUFFERSIZE];
	std::string username, password, salt, iv, key, key_iv;
	std::string cred="CRED=";
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
	/*if(loggedon){
		memset(pingbuffer,0,BUFFERSIZE);
		int response=write(client_socket, ping.c_str(), ping.size());
		if(response<0){
			LogUserOff(username);
			close(client_socket);
			loggedon=false;
			listening=false;
			pthread_exit(0);
			}

		if(read(client_socket,pingbuffer,BUFFERSIZE)<0){
				LogUserOff(username);
				close(client_socket);
				loggedon=false;
				listening=false;
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
			}
		}*/
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
			/*
			unsigned char* char_key=convertString(key);
			unsigned char* char_iv=convertString(iv);

			unsigned char *decrypt = NULL;
			//   Encryption crypto;

			cryptobject.DecryptAes(( unsigned char*)message.c_str(), message.size() + 1, &decrypt, ( unsigned char*)char_key, ( unsigned char*)char_iv);

			if(debugmode)
				std::cout<<"decrypt: "<<(const char *) decrypt<<"\n";
			password=(const char *) decrypt;
*/


			pthread_mutex_lock(&db_mutex);
			salt=GetUserSalt(username);
			pthread_mutex_unlock(&db_mutex);

			if(debugmode)
				std::cout<<"salt returned as: "<<salt<<std::endl;
			password=generateHash(salt, password);
			if(debugmode)
				std::cout<<"hashed pass: "<<password<<std::endl;

			pthread_mutex_lock(&db_mutex);
			loggedon=ValidateUserInDatabase(username, password);
			pthread_mutex_unlock(&db_mutex);



			if(!loggedon){
				if(debugmode)
					std::cout<<"invalid login credentials"<<std::endl;
			if(outfilespecified){
				std::ostringstream stream;
				stream<<"unauthorized logon"<<std::endl;
				std::string logmessage=stream.str();
				WriteToLog(outfile, logmessage);
			}
				//SendMessage(username, username,f);
				write(client_socket, f.c_str(), f.size());
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
				//SendMessage(username, username,key_iv);
				{

	unsigned char* auth_key=convertString(cred_key);

	unsigned char* auth_iv=convertString(cred_iv);

	unsigned char *encrypted_creds = NULL;
				std::string formattedcreds=FormatCredReq(key, iv);

	cryptobject.EncryptAes((const unsigned char*)formattedcreds.c_str(), formattedcreds.size() + 1, &encrypted_creds, ( unsigned char*)auth_key, ( unsigned char*)auth_iv);
		std::string sendcreds=cred+(const char*)encrypted_creds;

				SendMessage(username, username,sendcreds);
				}
			}
			if(outfilespecified){
			std::ostringstream stream;
			stream<<username<<" logged on"<<std::endl;
			std::string logmessage=stream.str();
			WriteToLog(outfile, logmessage);
			}

			break;


		case LOGOFF:

			if(!loggedon){
				if(debugmode)
					std::cout<<"user not logged in"<<std::endl;
					write(client_socket, f.c_str(), f.size());
				//close(client_socket);
				//pthread_exit(0);
				//listening=false;
				break;
			}

			else{
			if(outfilespecified){
				std::ostringstream stream;
				stream<<username<<" logged off"<<std::endl;
				std::string logmessage=stream.str();
				WriteToLog(outfile, logmessage);
			}
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
				pthread_mutex_lock(&db_mutex);
				bool user_exists=IsUserInDatabase(username);
				pthread_mutex_unlock(&db_mutex);
				if(user_exists){
					if(debugmode)
						std::cout<<"user: "<<username<<"username taken"<<std::endl;
						std::string error=f;
						write(client_socket, f.c_str(), f.size());
					//SendMessage(username, username,f);
					pthread_exit(0);

				}
			}
			salt=generateSalt();
			//		password=generateHash(salt, password);
			if (debugmode)
				std::cout<<"salt generated: "<<salt<<std::endl;

			pthread_mutex_lock(&db_mutex);
			AddUserToDatabase(username, password, salt);
			pthread_mutex_unlock(&db_mutex);
			write(client_socket, t.c_str(), t.size());
			close(client_socket);
			pthread_exit(0);
			break;

		case CHANGEPASSWORD:{
			//add validation code
			//IsUserInDatabase(username);
			std::string username=GetUserName(input);
			std::string oldpassword=GetOldPassword(input);

			pthread_mutex_lock(&db_mutex);
			salt=GetUserSalt(username);
			pthread_mutex_unlock(&db_mutex);

			oldpassword=generateHash(salt, oldpassword);
			if(debugmode)
				std::cout<<"hashed oldpass: "<<oldpassword<<std::endl;

			pthread_mutex_lock(&db_mutex);
			bool validated=ValidateUserInDatabase(username, oldpassword);
			pthread_mutex_unlock(&db_mutex);

			if(!validated){
				if(outfilespecified){
					std::ostringstream stream;
					stream<<"unauthorized password change"<<std::endl;
					std::string logmessage=stream.str();
					WriteToLog(outfile, logmessage);
				}
				if(debugmode)
					std::cout<<"invalid credentials"<<std::endl;
				write(client_socket, f.c_str(), f.size());
				close(client_socket);
				pthread_exit(0);

			}
			std::string newpassword=GetNewPassword(input);
			newpassword=generateHash(salt, newpassword);
			pthread_mutex_lock(&db_mutex);
			bool updated=UpdatePassword(username, newpassword);
			pthread_mutex_unlock(&db_mutex);
			if(updated){
				if(outfilespecified){
					std::ostringstream stream;
					stream<<"password changed for: "<<username<<std::endl;
					std::string logmessage=stream.str();
					WriteToLog(outfile, logmessage);
				}
			//SendMessage(username, username,t);
			write(client_socket, t.c_str(), t.size());
			close(client_socket);
			pthread_exit(0);
			break;
			}
			else{
			write(client_socket, f.c_str(), f.size());
			close(client_socket);
			pthread_exit(0);
			break;
			}
		}
		case INVALID:
			if(debugmode)
				std::cout<<"invalid command received"<<std::endl;
				if(outfilespecified){
					std::ostringstream stream;
					stream<<"invalid signal received"<<std::endl;
					std::string logmessage=stream.str();
					WriteToLog(outfile, logmessage);
				}		
			write(client_socket, f.c_str(), f.size());
			close(client_socket);
			pthread_exit(0);
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
	if(outfilespecified){
//		logfile.close();
	}
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
		if(argv[i]==initializeflag){
			initializedatabase=true;
			database = argv[i+1];
		}
		if(argv[i]==outflag){
			outfilespecified=true;
			outfile = argv[i+1];
		}
		if(argv[i]==threadflag){
			threadsspecified=true;
			max_threads= atoi(argv[i+1]);
		}
		if(argv[i]==credflag){
			std::ostringstream stream;
			stream<<"generated new credentials"<<std::endl;
			std::string logmessage=stream.str();
			WriteToLog(outfile, logmessage);
			std::string key, iv;
			Encryption cryptobject;	
			key=cryptobject.printKey();
			iv=cryptobject.printIV();
			std::string formattedcreds=FormatCredReq(key, iv);
			GenerateCredentialFile(credentialfile, formattedcreds);
			exit(0);
		}

	}
	std::string t=LoadFile();
	GetCredentials(t);

	if(debugmode){
		std::cout<<"outfile: "<<outfile<<std::endl;
	}

	if(initializedatabase&&(daemonize||portspecified||dbspecified)){
		std::cerr<<"Can't initialize database with these flags set"<<std::endl;
		exit(-1);
	}

	
	if(initializedatabase){
	bool init=InitializeDatabase();
	if(init){
		std::cout<<"Database initialized"<<std::endl;
		exit(0);
	}
	else{
		std::cerr<<"Failed to initialize database"<<std::endl;
		exit(-1);
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
	if(listen(server_socket, max_threads)<0){
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

