/*
======================================================================================
Name        : 32.c
Author      : Piyush
Description :  Write a program to implement semaphore to protect any critical section.
                  a. rewrite the ticket number creation program using semaphore
                  b. protect shared memory from concurrent write access
                  c. protect multiple pseudo resources ( may be two) using counting semaphore
                  d. remove the created semaphore
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    key_t key;
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } sem_attr;

    key = ftok(".", 'T');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    sem_attr.val = 1;  // binary semaphore
    semctl(semid, 0, SETVAL, sem_attr);

    int ticket = 0;

    for (int i = 0; i < 5; i++) {
        struct sembuf p = {0, -1, 0};  // wait
        struct sembuf v = {0, 1, 0};   // signal

        semop(semid, &p, 1);   // enter critical section
        ticket++;
        printf("Process %d issued ticket number: %d\n", getpid(), ticket);
        sleep(1);               // simulate work in critical section
        semop(semid, &v, 1);   // leave critical section
    }

    semctl(semid, 0, IPC_RMID); // remove semaphore
    return 0;
}

/*
======================================================================================
OUTPUT:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P32$ vim 32.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P32$ cc 32.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P32$ ./a.out 
Process 22096 issued ticket number: 1
Process 22096 issued ticket number: 2
Process 22096 issued ticket number: 3
Process 22096 issued ticket number: 4
Process 22096 issued ticket number: 5



======================================================================================
*/

