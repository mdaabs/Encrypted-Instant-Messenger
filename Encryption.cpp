#include "Encryption.h"

Encryption::Encryption() {
	localKeyPair = NULL;
	remotePubKey = NULL;

	#ifdef PSUEDO_CLIENT
		genTestClientKey();
	#endif

	init();
}

Encryption::~Encryption() {
	EVP_PKEY_free(remotePubKey);
	
	EVP_CIPHER_CTX_cleanup(rsaEncryptCtx);
	EVP_CIPHER_CTX_cleanup(aesEncryptCtx);

	EVP_CIPHER_CTX_cleanup(rsaDecryptCtx);
	EVP_CIPHER_CTX_cleanup(aesDecryptCtx);

	free(rsaEncryptCtx);
	free(aesEncryptCtx);
	
	free(rsaDecryptCtx);
	free(aesDecryptCtx);
	
	free(aesKey);
	free(aesIV);
}

int Encryption::init() {
	// initialize
	rsaEncryptCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));
	aesEncryptCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));

	rsaDecryptCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));
	aesDecryptCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));

	// malloc check
	if (rsaEncryptCtx == NULL || aesEncryptCtx == NULL || rsaDecryptCtx == NULL || aesDecryptCtx == NULL) {
		return FAILURE;
	}

	// Init these here to make valgrind happy
    	EVP_CIPHER_CTX_init(rsaEncryptCtx);
    	EVP_CIPHER_CTX_init(aesEncryptCtx);
 
    	EVP_CIPHER_CTX_init(rsaDecryptCtx);
    	EVP_CIPHER_CTX_init(aesDecryptCtx);

	//init RSA
	EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);  // create pkey algorithm context for RSA

	if(EVP_PKEY_keygen_init(ctx) <= 0) { // initialize the keygen
		return FAILURE;
	}

	if(EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, RSA_KEYLEN) <= 0) { // set length of key
		return FAILURE;
	}

	if(EVP_PKEY_keygen(ctx, &localKeyPair) <= 0) { // generate key
		return FAILURE
	}

	// free context
	EVP_PKEY_CTX_free(ctx);

	// init AES
	aesKey = (unsigned char*)malloc(AES_KEYLEN/8);
	aesIV = (unsigned char*)malloc(AES_KEYLEN/8);

	unsigned char *aesPass = (unsigned char*)malloc(AES_KEYLEN / 8);
	unsigned char *aesSalt = (unsigned char*)malloc(8);
	
	if(aesKey == NULL || aesIV == NULL || aesPass == NULL || aesSalt == NULL) {
		return FAILURE;
	}

	// Can use password based key derivation for AES, or random data, this uses
	// random data here, can be changed later to fit to project

	#ifdef USE_PBKDF
	
	// Get some random data to use as the AES pass and salt
        if(RAND_bytes(aesPass, AES_KEYLEN/8) == 0) { 
            return FAILURE;
        }

        if(RAND_bytes(aesSalt, 8) == 0) {
            return FAILURE;
        }
     
	// generate 256 bit key
        if(EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), aesSalt, aesPass, AES_KEYLEN/8, AES_ROUNDS, aesKey, aesIV) == 0) {
            return FAILURE;
        }
    #else
        if(RAND_bytes(aesKey, AES_KEYLEN/8) == 0) {
            return FAILURE;
        }

        if(RAND_bytes(aesIV, AES_KEYLEN/8) == 0) {
            return FAILURE;
        }
    #endif

   	free(aesPass);
    	free(aesSalt);
 
    	return SUCCESS;
}

