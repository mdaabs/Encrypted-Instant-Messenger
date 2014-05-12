/*
 *	Server.cpp
 *	v. 0.7
 *	#2scoopz
 *
 *	Compile Instructions: Standard g++
 *	g++ Server7.cpp Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lcrypto -ldl -o Server7
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
//#include "Encryption.h"
//#include "Hash.h"
//#define PRINT_KEYS

std::unordered_map<std::string, int*> *username_sockets=new std::unordered_map<std::string, int*>();
std::unordered_map<std::string, std::string> *username_keyiv=new std::unordered_map<std::string, std::string>();

pthread_mutex_t socket_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t keyiv_mutex = PTHREAD_MUTEX_INITIALIZER;

std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string password_delimiter="PASS:";
std::string star_delimiter="*";
std::string equal_delimiter="=";
std::string colon_delimiter=":";
std::string t="TRUE";
std::string f="FALSE";

//int zombie_threads=0;
bool daemonize=false;
bool debugmode=false;
bool portspecified=false;



std::string FormatKeyIV(std::string key, std::string iv){
	std::string formatted_string=key+colon_delimiter+iv;
	if(debugmode)
		std::cout<<"formatted message: "<<formatted_string<<std::endl;
	return formatted_string;

}

std::string FormatOutGoingMessage(std::string username, std::string message){
	std::string formatted_message=from_delimiter+username+star_delimiter+message;
	if(debugmode)
		std::cout<<"formatted message: "<<formatted_message<<std::endl;
	return formatted_message;

}

std::string GetMessage(std::string input){

	std::string message=input.substr(input.find(message_delimiter)+(message_delimiter.length()));
	if(debugmode)
		std::cout<<"message is: "<<message<<std::endl;
	return message;
}


std::string GetMessageReceiver(std::string input){

	std::string receiver=input.substr(input.find(to_delimiter)+(to_delimiter.length()));
	receiver=receiver.substr(0,receiver.find(star_delimiter));
	//receiver=receiver.substr(0,receiver.find(message_delimiter));
	//receiver=input.substr(input.find(to_delimiter)+1);
	if(debugmode)
		std::cout<<"receiver is: "<<receiver<<std::endl;
	return receiver;
}

bool IsUserOnline(std::string username){
 	std::unordered_map<std::string,int *>::const_iterator contains=username_sockets->find(username);
	if(contains!=username_sockets->end()){
		if(debugmode)
			std::cout<<"user: "<<username<<" is currently logged on"<<std::endl;
		return true;
	}
	else{
		if(debugmode)
			std::cout<<"user: "<<username<<" is currently logged off"<<std::endl;
		return false;
	}
}

//DEMITRIOUS FILL IN HERE
bool IsUserInDatabase(std::string username){

	return true;
}
//DEMITRIOUS FILL IN HERE
bool AddUserToDatabase(std::string username, std::string password, std::string salt, std::string iv, std::string key){


	return true;
}

bool ValidateUserInDatabase(std::string username, std::string password){

return false;
}

std::string GetUserPassword(std::string input){
	std::string password=input.substr(input.find(star_delimiter)+((password_delimiter.length())+star_delimiter.length()));

	if(debugmode)
		std::cout<<"password parsed: "<<password<<std::endl;
	return password;

}

std::string GetUserName(std::string input){

	std::string username=input.substr(input.find(equal_delimiter)+(equal_delimiter.length()));
	username=username.substr(0,username.find(star_delimiter));

	if(debugmode)
		std::cout<<"username parsed as "<<username<<std::endl;
	return username;
}
//IF at() is called and doesn't exist, shit goes HAM
//THROWS: terminate called after throwing an instance of 'std::out_of_range' what():  _Map_base::at

//need to error handle

void SendMessage(std::string sender, std::string receiver, std::string message){
	if(debugmode)
		std::cout<<"about to try message sending"<<std::endl;
	try{	
		if(debugmode)
			std::cout<<"getting name"<<std::endl;
		int *receiver_socket=username_sockets->at(receiver);
		write(*receiver_socket, message.c_str(), message.size());
		if(debugmode)
			std::cout<<"sent"<<std::endl;
	}
	catch (std::exception e){
		if(debugmode)
			std::cout<<"error occured on lookup"<<std::endl;
	}
}

void LogUserOff(std::string username){
	if(debugmode)
		std::cout<<"logoff called for "<<username<<std::endl;
	if(debugmode)
		std::cout<<"mutex locking"<<std::endl;

	pthread_mutex_lock(&socket_mutex);
	username_sockets->erase(username);
	pthread_mutex_unlock(&socket_mutex);
	if(debugmode)
		std::cout<<"mutex released"<<std::endl;
	if(debugmode)
		std::cout<<"mutex locking"<<std::endl;
	pthread_mutex_lock(&keyiv_mutex);
	username_keyiv->erase(username);
	pthread_mutex_unlock(&keyiv_mutex);
	if(debugmode)
		std::cout<<"mutex released"<<std::endl;	

	if(debugmode)
		std::cout<<"removed user: "<<username<<std::endl;
}
void StoreUserKeyIV(std::string username, std::string key_iv){

	if(debugmode)
		std::cout<<"mutex locking"<<std::endl;
	
	pthread_mutex_lock(&keyiv_mutex);
	username_keyiv->insert(std::map<std::string, std::string>::value_type(username, key_iv));
	if(debugmode)
		std::cout<<"map username: "<<username<<std::endl;
	if(debugmode)
		std::cout<<"map keyiv: "<<key_iv<<std::endl;
	pthread_mutex_unlock(&keyiv_mutex);
	if(debugmode)
		std::cout<<"mutex released"<<std::endl;
	if(debugmode)
		std::cout<<"successfully stored: "<<username<<"'s credentials"<<std::endl;
	if(debugmode)
		std::cout<<"testing lookup: "<<username_keyiv->at(username)<<std::endl;
}
void LogUserOn(std::string username, int *client_socket){

	if(debugmode)
		std::cout<<"mutex locking"<<std::endl;
	
	pthread_mutex_lock(&socket_mutex);
	username_sockets->insert(std::map<std::string, int*>::value_type(username, client_socket));
	pthread_mutex_unlock(&socket_mutex);
	if(debugmode)
		std::cout<<"mutex released"<<std::endl;
	if(debugmode)
		std::cout<<"logged user: "<<username<<" online"<<std::endl;

}
std::string GetReceiversIV(std::string username){
//	std::string receiver=input.substr(input.find(to_delimiter)+(to_delimiter.length()));
//	receiver=receiver.substr(0,receiver.find(star_delimiter));
	std::string keyiv;
	std::string iv;
	if(debugmode)
		std::cout<<"about to try lookup key"<<std::endl;
	try{	
		if(debugmode)
			std::cout<<"getting keyiv(iv) string"<<std::endl;
	
		keyiv=username_keyiv->at(username);
		if(debugmode)
			std::cout<<"got keyiv string"<<std::endl;
		iv=keyiv.substr(keyiv.find(colon_delimiter)+colon_delimiter.length());
		iv=iv.substr(0, iv.find(colon_delimiter));
		if(debugmode)
			std::cout<<"parsed iv as string "<<iv<<std::endl;
	}
	catch (std::exception e){
		if(debugmode)
			std::cout<<"error occured on lookup"<<std::endl;
	}
	return iv;
}
std::string GetReceiversKey(std::string username){
//	std::string receiver=input.substr(input.find(to_delimiter)+(to_delimiter.length()));
//	receiver=receiver.substr(0,receiver.find(star_delimiter));
	std::string keyiv;
	std::string key;
	if(debugmode)
		std::cout<<"about to try lookup key"<<std::endl;
	try{	
		if(debugmode)
			std::cout<<"getting keyiv(key) string"<<std::endl;
	
		keyiv=username_keyiv->at(username);
		if(debugmode)
			std::cout<<"got keyiv string"<<std::endl;
		//key=keyiv.substr(keyiv.find(colon_delimiter)+colon_delimiter.length());
		key=keyiv.substr(0, keyiv.find(colon_delimiter));
		if(debugmode)
			std::cout<<"parsed key as string "<<key<<std::endl;
	}
	catch (std::exception e){
		if(debugmode)
			std::cout<<"error occured on lookup"<<std::endl;
	}
	return key;
}

/*std::string EncryptMessage(Encryption cryptobject, std::string message, char * key, char * iv){
	unsigned char * encrypt;
	cryptobject.EncryptAes((unsigned char*)message.c_str(), message.size()+1, &encrypt, (unsigned char*)key, (unsigned char *)iv);
	message=(char*)encrypt;

	return message;
}

std::string DecryptMessage(Encryption cryptobject, std::string message, char * key, char * iv){
	//cryptobject.DecryptAes
	unsigned char * decrypt;
	cryptobject.DecryptAes((unsigned char*)message.c_str(), message.size()+1, &decrypt, (unsigned char*)key, (unsigned char *)iv);
	message=(char*)decrypt;
	return message;
}*/

/*std::string EncryptMessage(Encryption cryptobject, std::string message, std::string input_key, std::string input_iv){
	if(debugmode)
		std::cout<<"encrypt function: "<<message<<std::endl;
	char * key=(char*)input_key.c_str();
	char * iv=(char*)input_iv.c_str();
	unsigned char * encrypt=NULL;
	cryptobject.EncryptAes((unsigned char*)message.c_str(), message.size()+1, &encrypt, (unsigned char*)key, (unsigned char *)iv);
	if(debugmode)
		std::cout<<"encrypt function: "<<encrypt<<std::endl;
	message=(char*)encrypt;
	std::string retmess(message);
	return retmess;
}

char* DecryptMessage(Encryption cryptobject, std::string message, std::string input_key, std::string input_iv){
	if(debugmode)
		std::cout<<"decrypt function: "<<message<<std::endl;
	char * key=(char*)input_key.c_str();
	if(debugmode)
		std::cout<<"key casted as: "<<key<<std::endl;
	char * iv=(char*)input_iv.c_str();
	unsigned char * decrypt=NULL;
	cryptobject.DecryptAes((unsigned char*)message.c_str(), message.size()+1, &decrypt, (unsigned char*)key, (unsigned char *)iv);
	//message=(char*)decrypt;
//	std::string retmess(message);
	return (const char*) decrypt;
}*/

std::string EncryptMessage(Encryption cryptobject, std::string message, std::string input_key, std::string input_iv){
    char * key=(char*)input_key.c_str();
    char * iv=(char*)input_iv.c_str();
    unsigned char * encrypt;
    cryptobject.EncryptAes((unsigned char*)message.c_str(), message.size()+1, &encrypt, (unsigned char*)key, (unsigned char *)iv);
    message=(char*)encrypt;

    return message;
}

std::string DecryptMessage(Encryption cryptobject, std::string message, std::string input_key, std::string input_iv){
    char * key=(char*)input_key.c_str();
    char * iv=(char*)input_iv.c_str();
    unsigned char * decrypt;
    cryptobject.DecryptAes((unsigned char*)message.c_str(), message.size()+1, &decrypt, (unsigned char*)key, (unsigned char *)iv);
    message=(char*)decrypt;
    return message;
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
	//mutex for adding to map
	/*pthread_mutex_lock(&mutex);
	username_sockets.insert(std::map<std::string, int>::value_type(username, client_socket));
	pthread_mutex_unlock(&mutex);*/
	
void *ThreadMain(void *clsk){
	pthread_detach(pthread_self());
	//bool loggedon=false;
	char buffer[BUFFERSIZE];
	std::string username, password, salt, iv, key, key_iv;
	//std::string* nameptr=&username;
	//pthread_detach(pthread_self());
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
		//std::string credreq;

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
				/*if(!(credreq.compare("CREDREQ")==0)){
					close(client_socket);
					//loggedon=false;
					listening=false;
					pthread_exit(0);
			}*/
			SendMessage(username, username,key_iv);
			}
			if(debugmode)
				std::cout<<username<<std::endl;
		//	loggedon=true;
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
			/*
			receiver=GetMessageReceiver(input);
			message=GetMessage(input);
			if(debugmode)
				std::cout<<"calling decrypt for incoming"<<std::endl;
			message=DecryptMessage(cryptobject,message,key,iv);
			if(debugmode)
				std::cout<<"decrypted message: "<<message<<std::endl;
			std::string recv_key=GetReceiversKey(receiver);
			std::string recv_iv=GetReceiversIV(receiver);
			if(debugmode)
				std::cout<<"calling encrypt for outgoing"<<std::endl;
			message=EncryptMessage(cryptobject,message,recv_key, recv_iv);

			message=FormatOutGoingMessage(username, message);
			SendMessage(username, receiver,message);

			break;*/

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
			AddUserToDatabase(username, password, salt, iv, key);
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

		if(daemonize&&debugmode){
			std::cerr<<"Can't debug and daemonize"<<std::endl;
			exit(-1);
		}
	}

	//Check for argument size
	/*if(argc < 2){
		std::cerr<<"Incorrect Syntax"<<std::endl;
		std::cerr<<"Runtime Instructions: ./Server <Host Port>"<<std::endl;
		exit(-1);
	}*/
	if(!portspecified){
		std::cerr<<"no port specified"<<std::endl;
    		exit(-1);
	}

	//server_port = atoi(argv[1]);
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
	server_address.sin_port=htons(server_port);		//local port


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

