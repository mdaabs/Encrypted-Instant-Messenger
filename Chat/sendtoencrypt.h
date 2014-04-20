#ifndef SENDTOENCRYPT_H
#define SENDTOENCRYPT_H
#include <string>
using namespace std;
class sendToEncrypt
{
public:
    void sendToEncrypter(string message);
    string encryptMessage(string x);
    void sendOverInternet(string encrypted);
};

#endif // SENDTOENCRYPT_H
