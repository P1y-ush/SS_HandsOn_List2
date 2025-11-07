/*
===========================================================================================================================
Name : 8c.c
Author : Piyush
Description : Write a program using signal system call to catch the SIGFPE signal.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught signal SIGFPE (%d): Floating point exception (divide by zero)!\n", sig);
    exit(1);
}

int main() {
    signal(SIGFPE, handler);

    int x = 1, y = 0;
    int z = x / y;   // divide by zero
    printf("%d\n", z);

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ vim 8c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ cc 8c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P8$ ./a.out 
Caught signal SIGFPE (8): Floating point exception (divide by zero)!
===========================================================================================================================
*/

