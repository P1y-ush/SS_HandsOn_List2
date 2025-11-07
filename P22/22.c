/*
===========================================================================================================================
Name : 22.c
Author : Piyush
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
              system call with FIFO.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/select.h>

int main() {
    int fd;
    char *fifo = "myfifo";
    char buffer[100];
    fd_set readfds;
    struct timeval tv;
    int ret;

    // Create FIFO if not exists
    if (mkfifo(fifo, 0666) == -1) {
        perror("mkfifo");
    }

    printf("Opening FIFO for reading...\n");
    fd = open(fifo, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Initialize file descriptor set
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    // Timeout = 10 seconds
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for data for 10 seconds...\n");
    ret = select(fd + 1, &readfds, NULL, NULL, &tv);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);
    } else if (ret == 0) {
        printf("Timeout! No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int n = read(fd, buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Data received: %s\n", buffer);
            } else {
                printf("No data read.\n");
            }
        }
    }

    close(fd);
    return 0;
}
/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P22$ vim 22.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P22$ cc 22.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P22$ ./a.out
Opening FIFO for reading...
Waiting for data for 10 seconds...
Timeout! No data within 10 seconds.  // No data written in fifo file.

---------------------------------------------------------------------------------
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P22$ ./a.out
mkfifo: File exists
Opening FIFO for reading...
Waiting for data for 10 seconds...
Data received: Hello FIFO

#Terminal 2
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P22$ echo "Hello FIFO" > myfifo



===========================================================================================================================
*/


