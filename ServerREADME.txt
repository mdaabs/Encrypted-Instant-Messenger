Compile instructions:

g++ Server.cpp Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lsqlite3 -lcrypto -ldl -o Server



database schema (sqlite3):
CREATE TABLE USERS(USER_NAME CHAR(120) PRIMARY KEY NOT NULL, PASSWORD_HASH CHAR(120) NOT NULL, SALT CHAR(120) NOT NULL);


How to run it:
./Server -p <Host Port> -b <database>
optional flags:
	-d debug	prints every step
	-D daemonize	runs in the background
	-o logfile 	prints notable actions to a logfile
 	-i initialize database (doesnt work)

./Server -g
 	-g generate credentials into Credentials.txt

How it Works:
SUMMARY:
The server runs on a port, listening for incoming clients.  When a client connects, the server spawns a new thread.  This thread is detached from the main, so there is no zombie catching, it will kill itself.  When a client tries to connect to do anything, their credentials are checked and validated in the database before they are permitted to perform any functions.  

On login, they are validated, and then sent a unique session key iv pair needed to properly encrypt messages, and they are stored as an online user.
Once logged on, they are permitted to send messages to other users who are online.  The client sends an encrypted message with the user name of the person they wish to send it to.  The server will decrypt the message, and then re-encrypt it with the key iv pair of the person who is supposed to receive the message, and then send it to the receiver, who upon receiving it can decrypt the message.
To logoff, they simply press a client side button that sends a signal to the server to log them off.

To add a user, the client sends a request to add a username and password pair.  The name is checked in the database to see if it isn't taken, and if it is available, hashes the password and stores the username, hashed password, salt of the client.

Changing a password is performed similarly to adding a user, except after being validated a query is ran to update the row in the database instead of adding to it.

SECURITY:
This application uses two layers of AES symmetric key encryption.  When the server is ran with the -g flag, it will generate a key iv pair and store them in a file.  These credentials are static, and too be distributed to each user.  The best format for this is either via thumb drive, or by using the VSFTP protocal to distribute the credential file.  This decision is left up to the network administrator.  This credential file is loaded into both the server and client, and used to encrypt the session key iv pair that is distributed to clients upon login.  This protects the session kery iv pair from man in the middle attacks or snooping, as anyone listening on the wire will get an encrypted string, which they won't be able to decrypt without the credential file.  If the credential file or system itself becomes compromised, the network admin just needs to run ./Server -g to generate a brand new set of credentials, and then the admin just has to distribute them in whatever secure format they see fit.



