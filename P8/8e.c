/*
===========================================================================================================================
Name : 8e.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGALRM (use setitimer system call) signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (%d): setitimer alarm expired!\n", sig);
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   // first alarm after 2s
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2; // repeat every 2s
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) pause();
    return 0;
}
/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8e.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8e.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Caught SIGALRM (14): setitimer alarm expired!
Caught SIGALRM (14): setitimer alarm expired!
Caught SIGALRM (14): setitimer alarm expired!
Caught SIGALRM (14): setitimer alarm expired!
Caught SIGALRM (14): setitimer alarm expired!
...
===========================================================================================================================
*/


