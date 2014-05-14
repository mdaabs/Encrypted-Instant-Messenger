#include "sqlite3.h"

//Standard C libraries
#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
//C Networking libraries
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//Standard C++ libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
//C++ Standard data structures (included in std namespace)
#include <map>
#include <queue>
//Deprecated- may need to patch in the future
#include <unordered_map>

//#include <mutex>
//C++ Networking Libraries
#include <sstream>
#include <iomanip>

#include "Hash.h"
#include "Encryption.h"
bool UpdatePassword(std::string username, std::string newPassWord)
{
   sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql;
   int nbyte;

   rc = sqlite3_open("Testdb.db", &db);

    if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
      return false;
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   //Insert statment
   sql = "UPDATE USERS SET PASSWORD_HASH = '"+ newPassWord + "' WHERE USER_NAME == '" + username + "';";

nbyte = sql.length() + 1;


    sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
     
     if( sqlite3_step( stmt ) != SQLITE_BUSY)
     {
      fprintf(stdout, "Step failed I repeat step failed2\n");
      sqlite3_close(db);
      return false;
     }

    if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         sqlite3_close(db);
         return false;
      }else{
         fprintf(stdout, "Records created successfully\n");
       }
    sqlite3_finalize(stmt);

   sqlite3_close(db);

return true;
}

int main(){
	std::string username, password;
	std::cin>>username;
	std::cin>>password;
	const char * salt="1804289383";
	password=generateHash(password, salt);
	bool updated=UpdatePassword(username, password);
	
	std::cout<<updated<<std::endl;


return 0;
}

