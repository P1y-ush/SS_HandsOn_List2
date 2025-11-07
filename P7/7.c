/*
===========================================================================================================================
Name : 7.c
Author : Piyush
Description : Write a simple program to print the created thread ids.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg) {
    printf("Thread created with ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];

    printf("Main thread ID: %lu\n", pthread_self());

    // Create 3 threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P7$ vim 7.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P7$ cc 7.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P7$ ./a.out 
Main thread ID: 129988694034240
Thread created with ID: 129988690966208
Thread created with ID: 129988682573504
Thread created with ID: 129988674180800
===========================================================================================================================
*/
