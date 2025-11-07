/*
===========================================================================================================================
Name : writer.c
Author : Piyush
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "myfifo";
    char *message = "Hello from writer program!\n";

    // Create FIFO if it does not exist
    if (mkfifo(fifo, 0666) == -1) {
        perror("mkfifo");
        // exit not needed if already exists
    }

    // Open FIFO for writing
    fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    write(fd, message, 27);
    close(fd);

    printf("Message sent through FIFO.\n");
    return 0;
}

/*
===========================================================================================================================
Output:

Check Implementation.txt file.
===========================================================================================================================
*/

