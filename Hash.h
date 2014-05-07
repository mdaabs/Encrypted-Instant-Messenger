#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <openssl/sha.h>

// create new account; gui calls generateSalt
std::string generateSalt() {
	int salt = rand();
	std::stringstream saltString;
	saltString << salt;
	return saltString.str();
}

// generates hash from salt and password
std::string generateHash(std::string salt, std::string pass) {

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt.c_str(), salt.size());
    SHA256_Update(&sha256, pass.c_str(), pass.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
      ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();

}

unsigned char * convertString(std::string str) {
  unsigned char *cstr = (unsigned char*)str.c_str();

  return cstr;
}

