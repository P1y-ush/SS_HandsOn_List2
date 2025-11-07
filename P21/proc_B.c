/*
===========================================================================================================================
Name : proc_B.c
Author : Piyush
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd1, fd2;
    char *fifo1 = "fifo_a"; // A → B
    char *fifo2 = "fifo_b"; // B → A
    char write_msg[] = "Hello from Process B\n";
    char read_msg[100];

    // Read from Process A
    fd1 = open(fifo1, O_RDONLY);
    if(fd1 == -1) { perror("open fifo_a"); exit(1);}
    read(fd1, read_msg, sizeof(read_msg));
    printf("Process B received: %s", read_msg);
    close(fd1);

    // Write to Process A
    fd2 = open(fifo2, O_WRONLY);
    if(fd2 == -1) { perror("open fifo_b"); exit(1);}
    write(fd2, write_msg, strlen(write_msg));
    close(fd2);

    return 0;
}

/*
===========================================================================================================================
Output is in Implementation.txt file.
===========================================================================================================================
*/

