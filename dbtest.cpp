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


char * GetUserSalt(std::string username){
sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql;
   int nbyte;
   int thestep;
   char * salt="";
  	db->open("Testdb.db", &db);

    if( rc ){
//	if(debugmode)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   //   return false;
   }else{
//	if(debugmode)
      fprintf(stderr, "Opened database successfully\n");
   }

  sql = "SELECT salt FROM USERS WHERE USER_NAME == '" + username +"';";
//	char * sqlst= (char *)sql;
  nbyte = sql.length() + 1;

  sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
     
  /*   thestep = sqlite3_step( stmt );

    if( thestep != SQLITE_ROW)
     {
//	if(debugmode)
      fprintf(stdout, "Step failed I repeat step failed\n");
      sqlite3_close(db);
 //     return false;
     }
     else
     {
	//if(debugmode)
       printf("%s", "its in there");
     }

    if( rc != SQLITE_OK ){
//	if(debugmode)
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         sqlite3_close(db);
   //      return false;
      }else{
	//if(debugmode)
         fprintf(stdout, " user found in database successfully\n");

       }
	
    sqlite3_finalize(stmt);*/
	rc=sqlite3_exec(db,sql,NULL,NULL,&zErrMsg);

   sqlite3_close(db);

  return salt;
}


int main(){
	std::string username;
	std::cin>>username;

	char * salt=GetUserSalt(username);
	
	std::cout<<salt<<std::endl;


return 0;
}

