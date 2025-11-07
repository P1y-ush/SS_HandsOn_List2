/*
===========================================================================================================================
Name : 8f.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGVTALRM (use setitimer system call) signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGVTALRM (%d): Virtual timer expired!\n", sig);
}

int main() {
    signal(SIGVTALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
        // consume CPU so virtual timer decreases
    }
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8f.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8f.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Caught SIGVTALRM (26): Virtual timer expired!
Caught SIGVTALRM (26): Virtual timer expired!
Caught SIGVTALRM (26): Virtual timer expired!
Caught SIGVTALRM (26): Virtual timer expired!
===========================================================================================================================
*/


