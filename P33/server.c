/*
======================================================================================
Name        : 33.c
Author      : Piyush
Description :  Write a program to communicate between two machines using socket.
======================================================================================
*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, newfd;
    struct sockaddr_in server, client;
    char msg[100];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;   // listen on any IP
    server.sin_port = htons(8080);         // port 8080

    // bind
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    // listen
    listen(sockfd, 3);
    printf("Server waiting for connection...\n");

    // accept
    int c = sizeof(client);
    newfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t*)&c);

    // read from client
    read(newfd, msg, sizeof(msg));
    printf("Client says: %s\n", msg);

    // send reply
    char reply[] = "Hello from server!";
    write(newfd, reply, strlen(reply));

    close(newfd);
    close(sockfd);
    return 0;
}
/*
======================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P33$ cc server.c -o server
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P33$ cc client.c -o client
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P33$ ./server
Server waiting for connection...
Client says: Hello from client!

# Terminal 2
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P33$ ./client
Server says: Hello from server!
======================================================================================
*/
