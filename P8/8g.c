/*
===========================================================================================================================
Name : 8g.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGPROF (use setitimer system call) signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("\nCaught SIGPROF (%d): Profiling timer expired!\n", sig);
    fflush(stdout); // flush output immediately
}

int main() {
    signal(SIGPROF, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    // Busy loop to consume CPU time
    while (1) {
        for (volatile int i = 0; i < 100000000; i++); // CPU work
        write(1, ".", 1);
    }

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8g.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8g.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
....
Caught SIGPROF (27): Profiling timer expired!
....
Caught SIGPROF (27): Profiling timer expired!
......
Caught SIGPROF (27): Profiling timer expired!
.....
Caught SIGPROF (27): Profiling timer expired!
===========================================================================================================================
*/


