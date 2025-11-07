/*
===========================================================================================================================
Name : 17a.c
Author : Piyush
Description : Write a program to execute ls -l | wc using dup.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child 1: run "ls -l"
        close(fd[0]);               // close unused read end
        close(1);                   // close stdout
        dup(fd[1]);                 // duplicate write end to stdout
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) {
        // Child 2: run "wc"
        close(fd[1]);               // close unused write end
        close(0);                   // close stdin
        dup(fd[0]);                 // duplicate read end to stdin
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    // Parent
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}
/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ vim 17a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ cc 17a.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ ./a.out 
      3      20     113
===========================================================================================================================
*/



