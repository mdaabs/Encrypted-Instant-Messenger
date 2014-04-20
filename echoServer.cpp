#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int
main(int argc, char **argv)
{
    struct sockaddr_in server_addr,client_addr;
    socklen_t clientlen = sizeof(client_addr);
    int option, port, reuse;
    int server, client;
    char *buf;
    int buflen;
    int nread;

    // setup default arguments
    port = 3000;

    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"p:")) != -1) {
        switch (option) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                cout << "server [-p port]" << endl;
                exit(EXIT_FAILURE);
        }
    }

      // setup socket address structure
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

      // create socket
    server = socket(PF_INET,SOCK_STREAM,0);
    if (!server) {
        perror("socket");
        exit(-1);
    }
    else cout << "Creating socket\n" << endl;

      // set socket to immediately reuse port when the application closes
    reuse = 1;
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt");
        exit(-1);
    }
    else cout << "Setting socket for reuse port when app closes\n" << endl;

      // call bind to associate the socket with our local address and
      // port
    if (bind(server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }
    else cout << "Binding socket\n" << endl;

      // convert the socket to listen for incoming connections
    if (listen(server,SOMAXCONN) < 0) {
        perror("listen");
        exit(-1);
    }
    else cout << "Listening...\n" << endl;

    // allocate buffer
    buflen = 1024;
    buf = new char[buflen+1];

      // accept clients
    while ((client = accept(server,(struct sockaddr *)&client_addr,&clientlen)) > 0) {
		cout << "Accepting client\n" << endl;
          // loop to handle all requests
        while (1) {
        	cout << "Reading...\n" << endl;
              // read a request
            memset(buf,0,buflen);
            nread = recv(client,buf,buflen,0);
            cout << "Read the following message: " << nread << endl << endl;
            for (int i=0; i<buflen; i++)
                cout << buf[i];
            cout << endl << endl;
            if (nread == 0)
                break;

            // send a response
            send(client, buf, nread, 0);
        }
        close(client);
        cout << "client closed\n" << endl;
    }
    
    close(server);
    cout << "Server closed\n" << endl;
}
