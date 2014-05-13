//#include "Server.h"
#include "ServerDBLib.h"

std::string GetUserSalt(std::string username)
{
  sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql, hashedpassword;
   int nbyte;
   int thestep;
   const unsigned char * text;

   rc = sqlite3_open(database, &db);

    if( rc ){
	if(debugmode)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
	if(debugmode)
      fprintf(stderr, "Opened database successfully\n");
   }

   sql = "SELECT SALT FROM USERS WHERE USER_NAME == '" + username + "';";

    nbyte = sql.length() + 1;

  sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);

  thestep = sqlite3_step( stmt );

  if (thestep == SQLITE_ROW)
  {
    text = sqlite3_column_text (stmt, 0);
    //hashedpassword = text;
    //printf("%s", text);
    /* text = sqlite3_column_text (stmt, 1);
     printf("%s", text);
     text = sqlite3_column_text (stmt, 2);
     printf("%s", text);
     printf("%s", "we got a row!");*/
  }
  else
  {
	if(debugmode)
    fprintf(stdout, "SOmthing went wrong");
  }
  std::string salt((char *) text);//=((reinterpret_cast<char*>(text));
  return salt;

}

bool IsUserInDatabase(std::string username){
sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql;
   int nbyte;
   int thestep;
	
   rc = sqlite3_open(database, &db);

    if( rc ){
	if(debugmode)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
      return false;
   }else{
	if(debugmode)
      fprintf(stderr, "Opened database successfully\n");
   }

  sql = "SELECT * FROM USERS WHERE USER_NAME == '" + username +"';";

  nbyte = sql.length() + 1;

  sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
     
     thestep = sqlite3_step( stmt );

     if( thestep != SQLITE_ROW)
     {
	if(debugmode)
      fprintf(stdout, "Step failed I repeat step failed\n");
      sqlite3_close(db);
      return false;
     }
     else
     {
	if(debugmode)
       printf("%s", "its in there");
     }

    if( rc != SQLITE_OK ){
	if(debugmode)
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         sqlite3_close(db);
         return false;
      }else{
	if(debugmode)
         fprintf(stdout, "user found in database successfully\n");
       }
    sqlite3_finalize(stmt);

   sqlite3_close(db);

  return true;
}
//DEMITRIOUS FILL IN HERE
bool AddUserToDatabase(std::string username, std::string password, std::string salt){

  sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql;
   int nbyte;
password=generateHash(salt, password);
   rc = sqlite3_open(database, &db);

    if( rc ){
	if(debugmode)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
      return false;
   }else{
	if(debugmode)
      fprintf(stderr, "Opened database successfully\n");
   }

   //Insert statment
   sql = "INSERT INTO USERS (USER_NAME, PASSWORD_HASH, SALT) VALUES ('" + username + "','" + password + "','" + salt +"');";

nbyte = sql.length() + 1;
printf("%d", nbyte);

    sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
     
     if( sqlite3_step( stmt ) != SQLITE_DONE)
     {
	if(debugmode)
      fprintf(stdout, "Step failed I repeat step failed2\n");
      sqlite3_close(db);
      return false;
     }

    if( rc != SQLITE_OK ){
	if(debugmode)
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         sqlite3_close(db);
         return false;
      }else{
	if(debugmode)
         fprintf(stdout, "Records created successfully\n");
       }
    sqlite3_finalize(stmt);

   sqlite3_close(db);

return true;

	return true;
}

bool ValidateUserInDatabase(std::string username, std::string password){


   sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql, hashedpassword;
   int nbyte;
   int thestep;

   //MARIO!!! hashedpassword = hasfunction(password) SO FIX BELOW;

   hashedpassword = password;

   rc = sqlite3_open(database, &db);

    if( rc ){
	if(debugmode)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
      return false;
   }else{
	if(debugmode)
      fprintf(stderr, "Opened database successfully\n");
   }

  sql = "SELECT * FROM USERS WHERE USER_NAME == '" + username +"' AND PASSWORD_HASH == '" + hashedpassword + "';";

  nbyte = sql.length() + 1;

  sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
     
     thestep = sqlite3_step( stmt );

     if( thestep != SQLITE_ROW)
     {
	if(debugmode)
      fprintf(stdout, "Step failed I repeat step failedz\n");
      sqlite3_close(db);
      return false;
     }
     else
     {
	if(debugmode)
       printf("%s", "its in there");
     }

    if( rc != SQLITE_OK ){
	if(debugmode)
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         sqlite3_close(db);
         return false;
      }else{
	if(debugmode)
         fprintf(stdout, "user found in database successfully\n");
       }
    sqlite3_finalize(stmt);

   sqlite3_close(db);

  return true;
}

bool UpdatePassword(std::string username, std::string newPassWord)
{
   sqlite3 *db;
   sqlite3_stmt * stmt;
   char *zErrMsg = 0;
   int rc;
   std::string sql;
   int nbyte;

   rc = sqlite3_open("CryptChat.db", &db);

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
     
     if( sqlite3_step( stmt ) != SQLITE_DONE)
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



