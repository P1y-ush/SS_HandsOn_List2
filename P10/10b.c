/*
===========================================================================================================================
Name : 10b.c
Author : Piyush
Description : Write a program using sigaction system call to catch SIGINT signal.
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    printf("\nCaught SIGINT (%d): Interrupt from keyboard!\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("Running... Press Ctrl+C to stop.\n");
        sleep(2);
    }

    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ vim 10b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ cc 10b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ ./a.out
Running... Press Ctrl+C to stop.
Running... Press Ctrl+C to stop.
Running... Press Ctrl+C to stop.
Running... Press Ctrl+C to stop.
^C
Caught SIGINT (2): Interrupt from keyboard!

===========================================================================================================================
*/

