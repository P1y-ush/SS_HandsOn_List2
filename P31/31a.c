/*
===========================================================================================================================
Name : 31a.c
Author : Piyush
Description : Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore
            b. create a counting semaphore
===========================================================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key;
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } sem_attr;

    key = ftok(".", 'B');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    sem_attr.val = 1;
    if (semctl(semid, 0, SETVAL, sem_attr) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Binary semaphore created and initialized to 1\n");
    return 0;
}

/*
=====OUTPUT================================================================================================================
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P31$ vim 31a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P31$ cc 31a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P31$ ./a.out
Binary semaphore created and initialized to 1

===========================================================================================================================
*/
