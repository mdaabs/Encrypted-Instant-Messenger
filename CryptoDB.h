#include <stdio.h> 
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

#include "Encryption.h"
Encryption crypto;

void printKey() {
  unsigned char *aesKey;
  size_t aesLength = crypto.getAesKey(&aesKey);
  printf("AES Key: ");
  std::stringstream s;
  for (unsigned int i = 0; i < aesLength; i++) {
    printf("%x", aesKey[i]);
    s << aesKey[i];
  }
  std::string strAesKey = s.str();
  printf("%s", strAesKey.c_str());
}
