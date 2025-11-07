/*
===========================================================================================================================
Name : 8b.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGINT signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal SIGINT (%d): Interrupt from keyboard!\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, handler);

    while (1) {
        printf("Running... Press Ctrl+C to stop.\n");
        sleep(2);
    }
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Running... Press Ctrl+C to stop.
Running... Press Ctrl+C to stop.
Running... Press Ctrl+C to stop.
^CCaught signal SIGINT (2): Interrupt from keyboard!

===========================================================================================================================
*/
