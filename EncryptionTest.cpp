#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

//#include "b64.h"
#include "Encryption.h"
//#include "CryptoDB.h"
#include "Hash.h"
#define PRINT_KEYS

Encryption crypto;
Encryption crypto2;

unsigned char * convertString(std::string str) {
  unsigned char *cstr = (unsigned char*)str.c_str();

  return cstr;
}

int main() {
  std::string key1 = crypto.printKey();
  std::string iv1 = crypto.printIV();
  std::string key2 = crypto2.printKey();
  std::string iv2 = crypto2.printIV();
  std::cout << "AES Key: " << key1 << std::endl;
  std::cout << "AES IV: " << iv1 << std::endl;
  std::cout << "AES Key2: " << key2 << std::endl;
  std::cout << "AES IV2: " << iv2 << std::endl;
  std::string salt = generateSalt();
  std::cout << salt << std::endl;
  std::cout << generateHash(salt, "test1") << std::endl;
  unsigned char *key1c = convertString(key1);
  unsigned char *iv1c = convertString(iv1);
  unsigned char *key2c = convertString(key2);
  unsigned char *iv2c = convertString(iv2);
  std::string msg;
	unsigned char *encMsg = NULL;
	char *decMsg = NULL;
	int encMsgLen;
	int decMsgLen;

	while (!std::cin.eof()) {
		// AES message encryption
		printf("AES message to encrypt: ");
		fflush(stdout);
		getline(std::cin, msg);

		if ((encMsgLen = crypto.EncryptAes((const unsigned char*)msg.c_str(), msg.size() + 1, &encMsg, key1c, iv1c)) == -1) {
			fprintf (stderr, "Encryption Failed");
			return 1;
		}

//     	char* b64String = base64Encode(encMsg, encMsgLen);
//      printf("Encrypted message: %s\n", b64String);

		if ((decMsgLen = crypto.DecryptAes(encMsg, (size_t)encMsgLen, (unsigned char**)&decMsg, key1c, iv1c)) == -1) {
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
