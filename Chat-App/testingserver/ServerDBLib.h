#include "Server.h"
#include "ServerDBLib.cpp"

bool IsUserInDatabase(std::string username);

bool AddUserToDatabase(std::string username, std::string password, std::string salt);

bool ValidateUserInDatabase(std::string username, std::string password);
