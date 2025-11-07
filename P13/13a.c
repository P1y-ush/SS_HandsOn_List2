/*
===========================================================================================================================
Name : 13a.c
Author : Piyush
Description : Program that tries to catch SIGSTOP using sigaction().
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    // Try to catch SIGSTOP
    if (sigaction(SIGSTOP, &sa, NULL) == -1) {
        perror("sigaction");
    }

    printf("Process PID = %d. Waiting for SIGSTOP...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}

=========================================================
Output is in Implementation.txt file. 
=========================================================
