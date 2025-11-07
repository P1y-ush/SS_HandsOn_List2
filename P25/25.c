/*
===========================================================================================================================
Name : 25.c
Author : Piyush
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
		a. access permission
		b. uid, gid
		c. time of last message sent and received
		d. time of last change in the message queue
		d. size of the queue
		f. number of messages in the queue
		g. maximum number of bytes allowed
		h. pid of the msgsnd and msgrcv
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    // Generate unique key
    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get message queue details
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(1);
    }

    // Print attributes
    printf("Message Queue ID: %d\n", msgid);
    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);

    printf("Last msg sent time: %s", (buf.msg_stime ? ctime(&buf.msg_stime) : "Not set\n"));
    printf("Last msg received time: %s", (buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not set\n"));
    printf("Last change time: %s", ctime(&buf.msg_ctime));

    printf("Current number of bytes in queue: %lu\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", buf.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P25$ vim 25.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P25$ cc 25.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P25$ ./a.out 
Message Queue ID: 1
Access Permissions: 666
UID: 1000
GID: 1000
Last msg sent time: Not set
Last msg received time: Not set
Last change time: Wed Oct  1 16:28:56 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0


===========================================================================================================================
*/

