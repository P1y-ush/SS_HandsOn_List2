/*
===========================================================================================================================
Name : 1c.c
Author : Piyush
Description : Write a program to set an interval timer of 10 seconds and 10 microseconds using ITIMER_PROF.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_prof(int sig) {
    printf("ITIMER_PROF: Signal received (SIGPROF)\n");
}

int main() {
    struct itimerval timer;

    /* Install handler */
    signal(SIGPROF, handle_prof);

    /* First expiration = 10s + 10us (user + kernel time) */
    timer.it_value.tv_sec  = 10;
    timer.it_value.tv_usec = 10;

    /* Repeat every 10s + 10us (user + kernel time) */
    timer.it_interval.tv_sec  = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    printf("ITIMER_PROF set: first after 10s+10us of user+kernel time, interval 10s+10us\n");

    /* Loop mixing user work and syscalls to consume both user+kernel time */
    while (1) {
        getpid(); /* syscall to add kernel time */
    }

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1c$ vim 1c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1c$ cc 1c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1c$ ./a.out 
ITIMER_PROF set: first after 10s+10us of user+kernel time, interval 10s+10us
ITIMER_PROF: Signal received (SIGPROF)
ITIMER_PROF: Signal received (SIGPROF)
ITIMER_PROF: Signal received (SIGPROF)
ITIMER_PROF: Signal received (SIGPROF)

===========================================================================================================================
*/
