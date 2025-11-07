/*
===========================================================================================================================
Name : 2.c
Author : Piyush
Description : Write a program to print the system resource limits. Use getrlimit system call.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("%s -> Soft limit: %ld, Hard limit: %ld\n", 
           name, (long)limit.rlim_cur, (long)limit.rlim_max);
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "Maximum file size (bytes)");
    print_limit(RLIMIT_DATA, "Data segment size (bytes)");
    print_limit(RLIMIT_STACK, "Stack size (bytes)");
    print_limit(RLIMIT_CORE, "Core file size (bytes)");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space (bytes)");
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P2$ vim 2.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P2$ cc 2.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P2$ ./a.out 
CPU time (seconds) -> Soft limit: -1, Hard limit: -1
Maximum file size (bytes) -> Soft limit: -1, Hard limit: -1
Data segment size (bytes) -> Soft limit: -1, Hard limit: -1
Stack size (bytes) -> Soft limit: 8388608, Hard limit: -1
Core file size (bytes) -> Soft limit: 0, Hard limit: -1
Open files -> Soft limit: 1024, Hard limit: 1048576
Address space (bytes) -> Soft limit: -1, Hard limit: -1

===========================================================================================================================
*/

