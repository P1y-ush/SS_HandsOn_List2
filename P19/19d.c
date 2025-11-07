/*
===========================================================================================================================
Name : 19d.c
Author : Piyush
Description : Create a FIFO file using mknod system call
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    if (mknod("myfifo_syscall", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(1);
    }
    printf("FIFO created using mknod system call.\n");
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ vim 19d.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ cc 19d.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ ./a.out 
FIFO created using mknod system call.

===========================================================================================================================
*/

