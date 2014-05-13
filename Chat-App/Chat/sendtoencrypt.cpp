  #include "sendtoencrypt.h"


string sendToEncrypt::encryptMessage(string pass, char* key, char*iv){

     unsigned char *encmsg = NULL;

    Encryption crypto;
    crypto.EncryptAes((const unsigned char*)pass.c_str(), pass.size() + 1, &encmsg, ( unsigned char*)key, ( unsigned char*)iv);


    return (const char *) encmsg;
}
string sendToEncrypt::decryptMessage(string pass, char* key, char*iv){

     unsigned char *decrypt = NULL;

    Encryption crypto;
    crypto.DecryptAes(( unsigned char*)pass.c_str(), pass.size() + 1, &decrypt, ( unsigned char*)key, ( unsigned char*)iv);


    return (const char *) decrypt;
}
string sendToEncrypt::getSalt(){
    string salt;


    return salt;

}

string sendToEncrypt::hashPass(string pass, string salt){

    //function to encrypt string x

    string encPass;



//    if ((encMsgLen = crypto.EncryptAes((const unsigned char*)x.c_str(), x.size() + 1, &encMsg)) == -1) {
//                fprintf (stderr, "Encryption Failed");
//                return 1;
//            }


//          x=encMsg;



    return encPass;

}



void sendToEncrypt::sendMessagetoClient(string encrypted){

    //function to send over internet
    //


}
void sendToEncrypt::sendLogintoClient(string usrn, string passw){

    //function to send over internet


}
