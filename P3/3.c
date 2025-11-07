/*
===========================================================================================================================
Name : 3.c
Author : Piyush
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    // Get current limit
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Before change -> Soft limit: %ld, Hard limit: %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    // Change soft limit to 2048 (must be <= hard limit)
    limit.rlim_cur = 2048;

    if (setrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("setrlimit");
        exit(1);
    }

    // Verify new limit
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("After change  -> Soft limit: %ld, Hard limit: %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P3$ vim 3.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P3$ cc 3.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P3$ ./a.out 
Before change -> Soft limit: 1024, Hard limit: 1048576
After change  -> Soft limit: 2048, Hard limit: 1048576

===========================================================================================================================
*/

