/*
===========================================================================================================================
Name : 24.c
Author : Piyush
Description : Write a program to create a message queue and print the key and message queue id.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate unique key using ftok
    key = ftok(".", 'A');   // "." = current directory, 'A' = project identifier
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create message queue with read & write permissions
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue created successfully!\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P24$ vim 24.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P24$ cc 24.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P24$ ./a.out 
Message Queue created successfully!
Key: 1090854087
Message Queue ID: 0

// Verify the message queue is created:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P24$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41051cc7 0          piyush     666        0            0        
===========================================================================================================================
*/

