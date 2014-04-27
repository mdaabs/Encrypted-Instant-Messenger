#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
using namespace std;

// create new account; gui calls generateSalt
string generateSalt() {
	int salt = rand();
	string saltString =
			static_cast<ostringstream*>(&(ostringstream() << salt))->str();
	return saltString;
}

// use generated salt as parameter
string generateHash(string salt, string pass) {

	unsigned char digest[SHA512_DIGEST_LENGTH];
	char string[] = salt + pass;

	SHA512((unsigned char*) &string, strlen(string), (unsigned char*) &digest);

	char mdString[SHA512_DIGEST_LENGTH * 2 + 1];

	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
		sprintf(&mdString[i * 2], "%02x", (unsigned int) digest[i]);

	printf("SHA512 digest: %s\n", mdString);

	return mdString;
}

int main() {
	string salt = generateSalt();
	string pass = "test";
	string hash = generateHash(salt, pass);
	cout << hash << endl;

	return 0;
}
