/*
===========================================================================================================================
Name : 12.c
Author : Piyush
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
              the parent process from the child process.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        printf("Child: My PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Kill parent process
        kill(getppid(), SIGKILL);
        printf("Child: Sent SIGKILL to parent.\n");

        sleep(2); // Give time for parent to terminate

        printf("Child: Now my new Parent PID = %d (should be 1 -> init)\n", getppid());

    } else {  // Parent process
        while (1) {
            printf("Parent: My PID = %d, Child PID = %d\n", getpid(), pid);
            sleep(1);
        }
    }

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P12$ vim 12.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P12$ cc 12.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P12$ ./a.out 
Parent: My PID = 18377, Child PID = 18378
Child: My PID = 18378, Parent PID = 18377
Child: Sent SIGKILL to parent.
Killed
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P12$ Child: Now my new Parent PID = 2237 (should be 1 -> init)
===========================================================================================================================
*/

