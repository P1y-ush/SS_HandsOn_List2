/*
===========================================================================================================================
Name        : 29.c
Author      : Piyush
Description : Write a program to remove the message queue.
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("test.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Failed to create or access the message queue.\n");
        return 1;
    }
    else{
        printf("Message queue created with ID: %d\n", msgid);
    }   
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue removed.\n");
    return 0;
}
/*
=====OUTPUT================================================================================================================
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P29$ touch test.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P29$ ls
29.c  test.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P29$ cc 29.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P29$ ./a.out 
Message queue created with ID: 6
Message queue removed.

===========================================================================================================================
*/
