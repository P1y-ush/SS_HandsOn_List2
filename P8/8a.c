/*
===========================================================================================================================
Name : 8a.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGSEGV signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught signal SIGSEGV (%d): Segmentation fault!\n", sig);
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);

    int *p = NULL;   // NULL pointer
    *p = 10;         // causes segmentation fault

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8a.c 
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Caught signal SIGSEGV (11): Segmentation fault!

===========================================================================================================================
*/

