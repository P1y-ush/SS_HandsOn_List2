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
    int sockfd;
    struct sockaddr_in server;
    char msg[100];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // connect to server (replace with server IP)
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    // send message
    char hello[] = "Hello from client!";
    write(sockfd, hello, strlen(hello));

    // receive reply
    read(sockfd, msg, sizeof(msg));
    printf("Server says: %s\n", msg);

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

