/*
===========================================================================================================================
Name : 17c.c
Author : Piyush
Description : Write a program to execute ls -l | wc using fcntl.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child 1: run "ls -l"
        close(fd[0]);
        close(1);
        fcntl(fd[1], F_DUPFD, 1);   // duplicate fd[1] into stdout
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) {
        // Child 2: run "wc"
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, 0);   // duplicate fd[0] into stdin
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ vim 17c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ cc 17c.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ ./a.out 
      5      38     217
===========================================================================================================================
*/
