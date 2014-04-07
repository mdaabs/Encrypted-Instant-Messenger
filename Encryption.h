#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_

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
