//#include "Server.h"
#include "ServerLib.h"


pthread_mutex_t socket_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t keyiv_mutex = PTHREAD_MUTEX_INITIALIZER;



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

bool SendMessage(std::string sender, std::string receiver, std::string message){
	if(debugmode)
		std::cout<<"about to try message sending"<<std::endl;
	try{	
		if(debugmode)
			std::cout<<"getting name"<<std::endl;
		int *receiver_socket=username_sockets->at(receiver);
		write(*receiver_socket, message.c_str(), message.size());
		if(debugmode)
			std::cout<<"sent"<<std::endl;
	return true;
	}
	catch (std::exception e){
		if(debugmode)
			std::cout<<"error occured on lookup"<<std::endl;
	return false;
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

void endprocess(){
	if (debugmode)
		std::cout<<"terminating"<<std::endl;
	delete username_sockets;
	delete username_keyiv;
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
}*/

