/*
===========================================================================================================================
Name : 9.c
Author : Piyush
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGINT for 5 seconds. Press Ctrl+C now.\n");

    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);
    sleep(5);

    printf("Resetting SIGINT to default. Press Ctrl+C now to terminate.\n");

    // Reset to default action
    signal(SIGINT, SIG_DFL);
    sleep(5);

    printf("Program finished.\n");
    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P9$ vim 9.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P9$ cc 9.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P9$ ./a.out 
Ignoring SIGINT for 5 seconds. Press Ctrl+C now.
Resetting SIGINT to default. Press Ctrl+C now to terminate.
Program finished.

===========================================================================================================================
*/


