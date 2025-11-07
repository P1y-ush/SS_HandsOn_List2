/*
===========================================================================================================================
Name : 18.c
Author : Piyush
Description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];

    // First pipe: ls -l → grep
    if (pipe(fd1) == -1) {
        perror("pipe1");
        exit(1);
    }

    // Second pipe: grep → wc
    if (pipe(fd2) == -1) {
        perror("pipe2");
        exit(1);
    }

    // First child: ls -l
    if (fork() == 0) {
        dup2(fd1[1], STDOUT_FILENO);   // stdout → fd1 write
        close(fd1[0]); close(fd1[1]);
        close(fd2[0]); close(fd2[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    // Second child: grep ^d
    if (fork() == 0) {
        dup2(fd1[0], STDIN_FILENO);    // stdin ← fd1 read
        dup2(fd2[1], STDOUT_FILENO);   // stdout → fd2 write
        close(fd1[0]); close(fd1[1]);
        close(fd2[0]); close(fd2[1]);
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(1);
    }

    // Third child: wc -l
    if (fork() == 0) {
        dup2(fd2[0], STDIN_FILENO);    // stdin ← fd2 read
        close(fd1[0]); close(fd1[1]);
        close(fd2[0]); close(fd2[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(1);
    }

    // Parent closes everything and waits
    close(fd1[0]); close(fd1[1]);
    close(fd2[0]); close(fd2[1]);
    wait(NULL); wait(NULL); wait(NULL);

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P18$ vim 18.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P18$ cc 18.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P18$ ./a.out 
1
===========================================================================================================================
*/

