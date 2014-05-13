#ifndef SENDTOENCRYPT_H
#define SENDTOENCRYPT_H
#include <string>
#include "Encryption.h"
using namespace std;
class sendToEncrypt
{
public:
    string hashPass(string pass, string salt);
    string encryptMessage(string x, char* key, char*iv);
    string decryptMessage(string x, char* key, char*iv);
    void sendMessagetoClient(string encrypted);
    void sendLogintoClient(string usrn, string passw);
    string getSalt();
};

#endif // SENDTOENCRYPT_H
