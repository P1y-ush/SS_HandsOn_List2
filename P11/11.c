/*
===========================================================================================================================
Name : 11.c
Author : Piyush
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
===========================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    printf("Ignoring SIGINT for 5 seconds. Press Ctrl+C now.\n");

    // Ignore SIGINT
    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    sleep(5);

    printf("Resetting SIGINT to default. Press Ctrl+C now to terminate.\n");

    // Reset SIGINT to default
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);

    sleep(5);

    printf("Program finished normally.\n");
    return 0;
}
/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P11$ vim 11.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P11$ cc 11.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P11$ ./a.out
Ignoring SIGINT for 5 seconds. Press Ctrl+C now.
Resetting SIGINT to default. Press Ctrl+C now to terminate.
Program finished normally.
===========================================================================================================================
*/

