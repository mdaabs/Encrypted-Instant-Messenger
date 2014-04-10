#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#include <stdio.h>
#include <string>
#include <string.h>

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_

#define RSA_KEYLEN 2048
#define AES_KEYLEN 256
#define AES_ROUNDS 6

#define KEY_SERVER_PRIVATE 0
#define KEY_SERVER_PUB 	   1
#define KEY_CLIENT_PUB     2
#define KEY_AES            3
#define KEY_AES_IV         4

class Encryption {
public:
	Encryption();
	virtual ~Encryption();
private:
	static EVP_PKEY *localKeyPair;
	EVP_PKEY *remotePubKey;

	EVP_CIPHER_CTX *rsaEncryptCtx;
	EVP_CIPHER_CTX *aesEncryptctx;

	EVP_CIPHER_CTX *rsaDecryptCtx;
	EVP_CIPHER_CTX *aesDecryptCtx;

	unsigned char *aesKey;
	unsigned char *aesIV;

};

#endif /* ENCRYPTION_H_ */
