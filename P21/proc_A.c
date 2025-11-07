/*
===========================================================================================================================
Name : proc_A.c
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
    char write_msg[] = "Hello from Process A\n";
    char read_msg[100];

    // Create FIFOs if they don't exist
    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    // Write to Process B
    fd1 = open(fifo1, O_WRONLY);
    if(fd1 == -1) { perror("open fifo_a"); exit(1);}
    write(fd1, write_msg, strlen(write_msg));
    close(fd1);

    // Read from Process B
    fd2 = open(fifo2, O_RDONLY);
    if(fd2 == -1) { perror("open fifo_b"); exit(1);}
    read(fd2, read_msg, sizeof(read_msg));
    printf("Process A received: %s", read_msg);
    close(fd2);

    return 0;
}

/*
===========================================================================================================================
Output is in Implementation.txt file.
===========================================================================================================================
*/

