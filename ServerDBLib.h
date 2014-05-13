#include "Server.h"
//#include "ServerDBLib.cpp"
#ifndef SERVERDBLIB_H_
#define SERVERDBLIB_H_

bool IsUserInDatabase(std::string username);

bool AddUserToDatabase(std::string username, std::string password, std::string salt);

bool ValidateUserInDatabase(std::string username, std::string password);

std::string GetUserSalt(std::string username);

bool UpdatePassword(std::string username, std::string newPassWord);

bool InitializeDatabase();



#endif
