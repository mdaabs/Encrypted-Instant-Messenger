#basic makefile to compile or clean

Server: CompileFile/Server.cpp CompileFile/Encryption.cpp
	g++ CompileFile/Server.cpp CompileFile/Encryption.cpp -std=gnu++0x -lpthread -Wall -Wextra -w -lsqlite3 -lcrypto -ldl -o Server

clean:
	rm Server


