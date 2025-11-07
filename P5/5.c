/*
===========================================================================================================================
Name : 5.c
Author : Piyush
Description : Write a program to print the system limitation of
              a. maximum length of the arguments to the exec family of functions.
              b. maximum number of simultaneous process per user id.
              c. number of clock ticks (jiffy) per second.
              d. maximum number of open files
              e. size of a page
              f. total number of pages in the physical memory
              g. number of currently available pages in the physical memory.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    long val;

    // a. Maximum length of arguments to exec
    val = sysconf(_SC_ARG_MAX);
    if (val == -1) perror("sysconf(_SC_ARG_MAX)");
    else printf("Maximum length of arguments to exec: %ld\n", val);

    // b. Maximum number of simultaneous processes per user id
    val = sysconf(_SC_CHILD_MAX);
    if (val == -1) perror("sysconf(_SC_CHILD_MAX)");
    else printf("Maximum number of processes per user id: %ld\n", val);

    // c. Number of clock ticks per second
    val = sysconf(_SC_CLK_TCK);
    if (val == -1) perror("sysconf(_SC_CLK_TCK)");
    else printf("Number of clock ticks per second: %ld\n", val);

    // d. Maximum number of open files
    val = sysconf(_SC_OPEN_MAX);
    if (val == -1) perror("sysconf(_SC_OPEN_MAX)");
    else printf("Maximum number of open files: %ld\n", val);

    // e. Size of a page
    val = sysconf(_SC_PAGESIZE);
    if (val == -1) perror("sysconf(_SC_PAGESIZE)");
    else printf("Page size: %ld bytes\n", val);

    // f. Total number of pages in physical memory
    val = sysconf(_SC_PHYS_PAGES);
    if (val == -1) perror("sysconf(_SC_PHYS_PAGES)");
    else printf("Total number of pages in physical memory: %ld\n", val);

    // g. Number of currently available pages in physical memory
    val = sysconf(_SC_AVPHYS_PAGES);
    if (val == -1) perror("sysconf(_SC_AVPHYS_PAGES)");
    else printf("Currently available pages in physical memory: %ld\n", val);

    return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P5$ vim 5.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P5$ cc 5.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P5$ ./a.out 
Maximum length of arguments to exec: 2097152
Maximum number of processes per user id: 30856
Number of clock ticks per second: 100
Maximum number of open files: 1024
Page size: 4096 bytes
Total number of pages in physical memory: 2009347
Currently available pages in physical memory: 918708
===========================================================================================================================
*/




