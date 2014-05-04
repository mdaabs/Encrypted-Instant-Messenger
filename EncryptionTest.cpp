#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

//#include "b64.h"
#include "Encryption.h"
#include "CryptoDB.h"
#include "Hash.h"
#define PRINT_KEYS

int main() {
  printKey();
  std::cout << std::endl;
  std::string salt = generateSalt();
  std::cout << salt << std::endl;
  std::cout << generateHash(salt, "test1") << std::endl;
//   Encryption crypto;

// #ifdef PRINT_KEYS
// 	unsigned char *aesKey;
// 	//crypto.writeKeyToFile(stdout, KEY_AES);
// 	size_t aesLength = crypto.getAesKey(&aesKey);
// 	printf("AES Key: ");
// 	for (unsigned int i = 0; i < aesLength; i++) {
// 		  printf("%x", aesKey[i]);
// 		}
// 		printf("\n");
// 	#endif

// 	string msg;
// 	unsigned char *encMsg = NULL;
// 	char *decMsg = NULL;
// 	int encMsgLen;
// 	int decMsgLen;

// 	while (!cin.eof()) {
// 		// AES message encryption
// 		printf("AES message to encrypt: ");
// 		fflush(stdout);
// 		getline(cin, msg);

// 		if ((encMsgLen = crypto.EncryptAes((const unsigned char*)msg.c_str(), msg.size() + 1, &encMsg)) == -1) {
// 			fprintf (stderr, "Encryption Failed");
// 			return 1;
// 		}

// 	//	char* b64String = base64Encode(encMsg, encMsgLen);
//     //    printf("Encrypted message: %s\n", b64String);

// 		if ((decMsgLen = crypto.DecryptAes(encMsg, (size_t)encMsgLen, (unsigned char**)&decMsg)) == -1) {
// 			fprintf (stderr, "Decryption Failed");
// 			return 1;
// 		}

// 		printf("%d bytes decrypted\n", decMsgLen);
// 		printf("Decrypted message: %s\n", decMsg);

// 		free(encMsg);
//         free(decMsg);
//         //free(b64String);
//         encMsg    = NULL;
//         decMsg    = NULL;
//        // b64String = NULL;
// 	}

	return 0;
}
