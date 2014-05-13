//#include "Server.h"
#include "ServerDBLib.h"
//sqlite3 *db;
std::string GetUserSalt(std::string username)
{
	sqlite3 *db;
    //sqlite3_mutex_enter(sqlite3_db_mutex(db));

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
  //  sqlite3_mutex_leave(sqlite3_db_mutex(db));
	std::string salt((char *) text);//=((reinterpret_cast<char*>(text));
	return salt;

}

bool IsUserInDatabase(std::string username){
	sqlite3 *db;

//    sqlite3_mutex_enter(sqlite3_db_mutex(db));


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

 //   sqlite3_mutex_leave(sqlite3_db_mutex(db));

	return true;
}
//DEMITRIOUS FILL IN HERE
bool AddUserToDatabase(std::string username, std::string password, std::string salt){

	sqlite3 *db;

   // sqlite3_mutex_enter(sqlite3_db_mutex(db));
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

//	return true;
 //   sqlite3_mutex_leave(sqlite3_db_mutex(db));
	return true;
}

bool ValidateUserInDatabase(std::string username, std::string password){

  //  sqlite3_mutex_enter(sqlite3_db_mutex(db));
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

//    sqlite3_mutex_leave(sqlite3_db_mutex(db));

	return true;
}

bool UpdatePassword(std::string username, std::string newPassWord)
{

  //  sqlite3_mutex_enter(sqlite3_db_mutex(db));
	sqlite3 *db;
	sqlite3_stmt * stmt;
	char *zErrMsg = 0;
	int rc;
	std::string sql;
	int nbyte;

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
	sql = "UPDATE USERS SET PASSWORD_HASH = '"+ newPassWord + "' WHERE USER_NAME == '" + username + "';";

	nbyte = sql.length() + 1;

	if(debugmode)
			std::cout<<"preparing sql statement"<<std::endl;
	sqlite3_prepare(db, sql.c_str(), nbyte, &stmt, NULL);
	if(debugmode)
			std::cout<<"sql statement prepared"<<std::endl;

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
	if(debugmode)
			std::cout<<"sql finalizing statement"<<std::endl;
	sqlite3_finalize(stmt);
	if(debugmode)
			std::cout<<"sql close"<<std::endl;
	sqlite3_close(db);

  //  sqlite3_mutex_leave(sqlite3_db_mutex(db));

	return true;
}


bool InitializeDatabase(){


	sqlite3 *db;
	sqlite3_stmt * stmt;
	char *zErrMsg = 0;
	int rc;
	std::string sql, hashedpassword;
	int nbyte;
	int thestep;
	//const char * dbspec=dbname.c_str();
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
	std::string dbname (database);
	sql = "CREATE TABLE "+ dbname +"(USER_NAME CHAR(120) PRIMARY KEY NOT NULL, PASSWORD_HASH CHAR(120) NOT NULL, SALT CHAR(120) NOT NULL);";

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
