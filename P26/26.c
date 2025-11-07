/*
=====================================================================
Name        : 26.c
Author      : Piyush
Description : Write a program to send messages to the message queue. Check $ipcs -q
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// message structure
struct msg_buffer {
    long mtype;          // message type (must be >0)
    char mtext[100];     // message text
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate unique key
    key = ftok(".", 'B');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create message queue (or get if it already exists)
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Prepare message
    message.mtype = 1;   // message type must be >0
    printf("Enter message to send: ");
    fgets(message.mtext, sizeof(message.mtext), stdin);

    // Send message
    if (msgsnd(msgid, &message, strlen(message.mtext)+1, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue (id=%d).\n", msgid);

    return 0;
}


/*
===============================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P26$ vim 26.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P26$ cc 26.c 
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P26$ ./a.out 
Enter message to send: Hi! This is Piyush.
Message sent to queue (id=2).

// Check message queue status
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41051cc7 0          piyush     666        0            0           
0x41052385 1          piyush     666        0            0           
0x42052387 2          piyush     666        21           1           


==============================================================================
*/

