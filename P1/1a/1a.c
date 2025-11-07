/*
===========================================================================================================================
Name : 1a.c
Author : Piyush
Description : Write a program to set an interval timer of 10 seconds and 10 microseconds using ITIMER_REAL.
             
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

// Signal handler
void handle_alarm(int sig) {
    printf("ITIMER_REAL: Signal received (SIGALRM)\n");
}

int main() {
    struct itimerval timer;

    // Install signal handler
    signal(SIGALRM, handle_alarm);

    // Set timer: first expiration = 10s, then repeat every 10µs
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    printf("ITIMER_REAL set: First after 10s, interval 10µs.\n");

    while (1) {
        pause(); // Wait for signal
	sleep(5);
    }
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1a$ vim 1a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1a$ cc 1a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P1/1a$ ./a.out 
ITIMER_REAL set: First after 10s, interval 10µs.
ITIMER_REAL: Signal received (SIGALRM)
ITIMER_REAL: Signal received (SIGALRM)
ITIMER_REAL: Signal received (SIGALRM)
ITIMER_REAL: Signal received (SIGALRM)

===========================================================================================================================
*/

