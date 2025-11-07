/*
===========================================================================================================================
Name : 17b.c
Author : Piyush
Description : Write a program to execute ls -l | wc using dup2.
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
        close(fd[0]);
        dup2(fd[1], 1);             // redirect stdout → pipe write end
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) {
        // Child 2: run "wc"
        close(fd[1]);
        dup2(fd[0], 0);             // redirect stdin ← pipe read end
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

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ vim 17b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ cc 17b.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P17$ ./a.out 
      4      29     165
===========================================================================================================================
*/

