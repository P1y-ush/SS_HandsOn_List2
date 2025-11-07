/*
===========================================================================================================================
Name : 4.c
Author : Piyush
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
              system call. Use time stamp counter.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

// Function to read timestamp counter
unsigned long long rdtsc(){
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main(){
    unsigned long long start, end;
    int i;

    // Read TSC before loop
    start = rdtsc();

    // Execute 100 getppid() system calls
    for(i=0; i<100; i++){
        getppid();
    }

    // Read TSC after loop
    end = rdtsc();

    printf("CPU cycles taken for 100 getppid() calls: %llu\n", (end - start));
    printf("Average cycles per call: %llu\n", (end - start)/100);

    return 0;
}

/*
==========================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P4$ vim 4.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P4$ cc 4.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P4$ ./a.out
CPU cycles taken for 100 getppid() calls: 552626
Average cycles per call: 5526
==========================================================================================
*/



