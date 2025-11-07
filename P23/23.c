/*
===========================================================================================================================
Name : 23.c
Author : Piyush
Description : Write a program to print the maximum number of files can be opened within a process and
              size of a pipe (circular buffer).
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    struct rlimit rl;
    int pipefd[2];
    long pipe_size;

    // Get max number of open files
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(1);
    }
    printf("Maximum number of open files per process: %ld\n", (long)rl.rlim_cur);

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Get pipe size using pathconf (portable)
    pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
    if (pipe_size == -1) {
        perror("fpathconf");
        exit(1);
    }
    printf("Size of a pipe (circular buffer): %ld bytes\n", pipe_size);

    // Close pipe
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P23$ cc 23.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P23$ ./a.out 
Maximum number of open files per process: 1024
Size of a pipe (circular buffer): 4096 bytes

===========================================================================================================================
*/

