/*
===========================================================================================================================
Name : 8d.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGALRM (use alarm system call) signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal SIGALRM (%d): Alarm expired!\n", sig);
}

int main() {
    signal(SIGALRM, handler);

    alarm(3);  // alarm after 3 seconds
    printf("Waiting for alarm...\n");
    pause();   // wait for signal

    return 0;
}
/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8d.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8d.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Waiting for alarm...
Caught signal SIGALRM (14): Alarm expired!
===========================================================================================================================
*/

