/*
===========================================================================================================================
Name : 10c.c
Author : Piyush
Description : Write a program using sigaction system call to catch SIGFPE signal.
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE (%d): Floating point exception (divide by zero)!\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGFPE, &sa, NULL);

    int x = 1, y = 0;
    int z = x / y; // Causes divide by zero

    printf("%d\n", z);
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ vim 10c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ cc 10c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P10$ ./a.out 
Caught SIGFPE (8): Floating point exception (divide by zero)!

===========================================================================================================================
*/

