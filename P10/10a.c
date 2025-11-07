/*
===========================================================================================================================
Name : 10a.c
Author : Piyush
Description : Write a program using sigaction system call to catch SIGSEGV signal.

===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV (%d): Segmentation fault!\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;  // Causes segmentation fault

    return 0;
}
/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2$ vim 10a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2$ cc 10a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2$ ./a.out
Caught SIGSEGV (11): Segmentation fault!

===========================================================================================================================
*/

