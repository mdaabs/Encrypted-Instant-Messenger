#include "Server.h"
//#include "ServerLib.cpp"
#ifndef SERVERLIB_H_
#define SERVERLIB_H_

std::string FormatKeyIV(std::string key, std::string iv);

std::string FormatOutGoingMessage(std::string username, std::string message);

std::string GetMessage(std::string input);

std::string GetMessageReceiver(std::string input);

bool IsUserOnline(std::string username);

std::string GetUserPassword(std::string input);

std::string GetUserName(std::string input);

bool SendMessage(std::string sender, std::string receiver, std::string message);

void LogUserOff(std::string username);

void StoreUserKeyIV(std::string username, std::string key_iv);

void LogUserOn(std::string username, int *client_socket);

std::string GetReceiversIV(std::string username);

std::string GetReceiversKey(std::string username);

std::string GetOldPassword(std::string input);

std::string GetNewPassword(std::string input);

std::string FormatCredReq(std::string key, std::string iv);

void WriteToLog(std::string filename, std::string message);

void GenerateCredentialFile(std::string filename, std::string credentials);

void endprocess();

#endif
