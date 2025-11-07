/*
===========================================================================================================================
Name : reader.c
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
    char buffer[100];

    // Open FIFO for reading
    fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s", buffer);
    close(fd);

    return 0;
}

/*
===========================================================================================================================
Output:

Check Implementation.txt file.
===========================================================================================================================
*/

