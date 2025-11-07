/*
===========================================================================================================================
Name        : 30.c
Author      : Piyush
Description : Write a program to create a shared memory.
            a. write some data to the shared memory
            b. attach with O_RDONLY and check whether you are able to overwrite.
            c. detach the shared memory
            d. remove the shared memory
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int key = ftok("test.txt", 65);
    int shared_id = shmget(key, 1024, 0666 | IPC_CREAT);
    char *text = (char*) shmat(shared_id, (void*)0, 0);
    strcpy(text, "Writing text to the shared memory");
    printf("Data written: %s\n", text);
    shmdt(text);
    text = (char*) shmat(shared_id, (void*)0, SHM_RDONLY);
    printf("Data in read-only mode: %s\n", text);
    strcpy(text, "Modified text");
    printf("Attempt to overwrite: %s\n", text);
    shmdt(text);
    shmctl(shared_id, IPC_RMID, NULL);
    return 0;
}
/*
=====OUTPUT================================================================================================================
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P30$ touch test.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P30$ cc 30.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P30$ ls
30.c  a.out  test.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P30$ ./a.out 
Data written: Writing text to the shared memory
Data in read-only mode: Writing text to the shared memory
Segmentation fault (core dumped)

===========================================================================================================================
*/
