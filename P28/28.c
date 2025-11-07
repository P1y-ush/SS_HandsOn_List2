/*
===========================================================================================================================
Name        : 28.c
Author      : Piyush
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("test.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds info;
    msgctl(msgid, IPC_STAT, &info);
    info.msg_perm.mode = 0644;
    msgctl(msgid, IPC_SET, &info);
    printf("Permissions changed to 0644\n");
    return 0;
}
/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P28$ touch test.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P28$ vim 28.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P28$ cc 28.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P28$ ./a.out
Permissions changed to 0644

===========================================================================================================================
*/
