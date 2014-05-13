#ifndef USER_H
#define USER_H

#include <string>


class User{

	std::string username;
	bool loggedOn;

	public:
	User(std::string, bool loggedOn){
		this->username=username;
		this->loggedOn=loggedOn;
	}

	void setUserName(std::string username){
		this->username=username;
	}

	void setLoginStatus(bool status){
		this->loggedOn=status;
	}


	std::string getUserName(){
		return username;
	}

	bool isLoggedOn(){
		return loggedOn;
	}


} ;

#endif
