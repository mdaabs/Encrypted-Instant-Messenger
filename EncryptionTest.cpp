#include <stdio.h>
#include <iostream>
#include <string>

#include "b64.h"
#include "Encryption.h"

using namespace std;

int main() {
	Encryption crypto;

	#ifdef PRINT_KEYS
		crypto.writeKeyToFile(stdout, KEY_SERVER_PRIVATE);
		crypto.writeKeyToFile(stdout, KEY_SERVER_PUB);
		crypto.writeKeyToFile(stdout, KEY_CLIENT_PUB);

		unsigned char *aesKey;
		size_t aesLength = crypto.getAesKey(&aesKey);
		printf("AES Key: ");
		for (unsigned int i = 0; i < aesLength, i++) {
			printf("%x", aesKey[i]);
		}

		printf("\n");
	#endif

	string msg;
	unsigned char *encMsg = NULL;
	char *decMsg = NULL;
	int encMsgLen;
	int decMsgLen;

/*
	unsigned char *ek;
	unsigned char *iv;
	size_t ekl;
	size_t ivl;
*/

	while (!cin.eof()) {
		// AES message encryption
		printf("AES message to encrypt: ");
		fflush(stdout);
		getline(cin, msg);

		if ((encMsgLen = crypto.EncryptAes((const unsigned char*)msg.c_str(), msg.size() + 1, &encMsg)) == -1) {
			fprintf (stderr, "Encryption Failed");
			return 1;
		}

	//	char* b64String = base64Encode(encMsg, encMsgLen);
    //    printf("Encrypted message: %s\n", b64String);

		if ((decMsgLen = crypto.DecryptAes(encMsg, (size_t)encMsgLen, (unsigned char**)&decMsg)) == -1) {
			fprintf (stderr, "Decryption Failed");
			return 1;
		}

		printf("%d bytes decrypted\n", decMsgLen);
		printf("Decrypted message: %s\n", decMsg);

		free(encMsg);
        free(decMsg);
        //free(b64String);
        encMsg    = NULL;
        decMsg    = NULL;
       // b64String = NULL;
	}

	return 0;
}