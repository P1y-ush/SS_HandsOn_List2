/*
================================================================================
Name : 34.c
Author : Piyush
Description : Create a concurrent server
              a. using fork
              b. using pthread_create
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

// ---------------------- Part b: pthread handler ----------------------
void *handle_client(void *arg)
{
    int client_sock = *(int *)arg;
    free(arg);
    char buffer[1024] = {0};
    char *msg = "Hello from pthread server";

    read(client_sock, buffer, 1024);
    printf("Received from client: %s\n", buffer);
    send(client_sock, msg, strlen(msg), 0);
    close(client_sock);
    return NULL;
}

// ---------------------- Main Server ----------------------
int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Concurrent server running on port %d\n", PORT);

    while (1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0)
        {
            perror("accept failed");
            continue;
        }

        // ----------- Part a: fork-based concurrency -----------
        pid_t pid = fork();
        if (pid == 0)
        {
            char buffer[1024] = {0};
            char *msg = "Hello from forked process";
            read(new_socket, buffer, 1024);
            printf("Forked process received: %s\n", buffer);
            send(new_socket, msg, strlen(msg), 0);
            close(new_socket);
            exit(0);
        }
        else if (pid > 0)
        {
            close(new_socket);
        }
        else
        {
            perror("fork failed");
            close(new_socket);
        }

        // ----------- Part b: pthread-based concurrency -----------
        int *pclient = malloc(sizeof(int));
        *pclient = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, pclient);
        pthread_detach(tid);
    }

    close(server_fd);
    return 0;
}
/*
===========================================================================================================================
Output:

Server side :
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P34$ vim 34.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P34$ cc 34.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P34$ ./a.out
Concurrent server running on port 8080
Forked process received: Hello!

Received from client: Hi!

//Terminal 2
Client side :
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P34$ nc 127.0.0.1 8080
Hello!
Hello from forked process

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P34$ nc 127.0.0.1 8080
Hi! 
Hello from pthread server

===========================================================================================================================
*/

