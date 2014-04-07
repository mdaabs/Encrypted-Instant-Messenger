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
	
	EVP_CIPHER_CTX_cleanup(EncryptRsaCtx);
	EVP_CIPHER_CTX_cleanup(EncryptAesCtx);

	EVP_CIPHER_CTX_cleanup(DecryptRsaCtx);
	EVP_CIPHER_CTX_cleanup(DecryptAesCtx);

	free(EncryptRsaCtx);
	free(EncryptAesCtx);
	
	free(DecryptRsaCtx);
	free(DecryptAesCtx);
	
	free(aesKey);
	free(aesIV);
}

int Encryption::EncryptAes(const unsigned char *msg, size_t msgLen, unsigned char **encMsg) {
	size_t blockLen = 0;
	size_t encMsgLen = 0;
	
	*encMsg = (unsigned char*) malloc(msgLen + AES_BLOCK_SIZE);
	if (encMsg == NULL) {
		return FAILURE;
	}
	
	// setting up cipher context for AES CBC encryption
	if (!EVP_EncryptInit_ex(EncryptAesCtx, EVP_aes_256_cbc(), NULL, aesKey, aesIV)) {
		return FAILURE;
	}
	
	// encrypts a message of msgLen from msg to encMsg. Bytes written is blockLen
	if (!EVP_EncryptUpdate(EncryptAesCtx, *encMsg, (int*)&blockLen, (unsigned char*)msg, msgLen)) {
		return FAILURE;
	}
	encMsgLen += blockLen;
	
	// uses padding to finish off the remaining message to be encrypted
	if (!EVP_EncryptFinal_ex(EncryptAesCtx, *encMsg + encMsgLen, (int*)&blockLen)) {
		return FAILURE;
	}
	
	EVP_CIPHER_CTX_cleanup(EncryptAesCtx);
	
	return encMsgLen + blockLen;
}

// Initializes the keys that are going to be used
int Encryption::init() {
	// initialize
	EncryptRsaCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));
	EncryptAesCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));

	DecryptRsaCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));
	DecryptAesCtx = (EVP_CIPHER_CTX*)malloc(sizeof(EVP_CIPHER_CTX));

	// malloc check
	if (EncryptRsaCtx == NULL || EncryptAesCtx == NULL || DecryptRsaCtx == NULL || DecryptAesCtx == NULL) {
		return FAILURE;
	}

	// Init these here to make valgrind happy
    	EVP_CIPHER_CTX_init(EncryptRsaCtx);
    	EVP_CIPHER_CTX_init(EncryptAesCtx);
 
    	EVP_CIPHER_CTX_init(DecryptRsaCtx);
    	EVP_CIPHER_CTX_init(DecryptAesCtx);

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

