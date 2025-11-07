/*
===========================================================================================================================
Name : 13b.c
Author : Piyush
Description : Program to send SIGSTOP to another process using kill().
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill");
        exit(1);
    }

    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}

=========================================================
Output is in Implementation.txt file. 
=========================================================
