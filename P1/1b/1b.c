/*
===========================================================================================================================
Name : 1b.c
Author : Piyush
Description : Write a program to set an interval timer of 10 seconds and 10 microseconds using ITIMER_VIRTUAL.
        
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_vtalarm(int sig) {
    printf("ITIMER_VIRTUAL: Signal received (SIGVTALRM)\n");
}

int main() {
    struct itimerval timer;

    /* Install handler */
    signal(SIGVTALRM, handle_vtalarm);

    /* First expiration = 10s + 10us (of user CPU time) */
    timer.it_value.tv_sec  = 10;
    timer.it_value.tv_usec = 10;

    /* Repeat every 10s + 10us (of user CPU time) */
    timer.it_interval.tv_sec  = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    printf("ITIMER_VIRTUAL set: first after 10s+10us of CPU time, interval 10s+10us\n");

    /* Busy loop to consume user CPU time so the timer decrements */
    while (1) {
        /* do some computation to burn user CPU */
        volatile unsigned long i;
        for (i = 0; i < 1000000UL; ++i) { /* empty loop */ }
    }

    return 0;
}


/*
====================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1b$ vim 1b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1b$ cc 1b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1b$ ./a.out
ITIMER_VIRTUAL set: first after 10s+10us of CPU time, interval 10s+10us
ITIMER_VIRTUAL: Signal received (SIGVTALRM)
ITIMER_VIRTUAL: Signal received (SIGVTALRM)
ITIMER_VIRTUAL: Signal received (SIGVTALRM)

====================================================================================================================
*/
