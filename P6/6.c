/*
===========================================================================================================================
Name : 6.c
Author : Piyush
Description : Write a simple program to create three threads.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* thread_function(void* arg) {
    int id = *((int*)arg);
    printf("Hello from Thread %d (Thread ID: %lu)\n", id, pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    // Create 3 threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P6$ vim 6.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P6$ cc 6.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P6$ ./a.out 
Hello from Thread 1 (Thread ID: 127284715452096)
Hello from Thread 3 (Thread ID: 127284698666688)
Hello from Thread 2 (Thread ID: 127284707059392)
All threads finished execution.

===========================================================================================================================
*/



