/*
===========================================================================================================================
Name : 16.c
Author : Piyush
Description : Write a program to send and receive data from parent to child vice versa. Use two way
              communication.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe1[2], pipe2[2];
    char buffer[100];

    pipe(pipe1); // parent -> child
    pipe(pipe2); // child -> parent

    if (fork() == 0) {
        // ---- Child ----
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child got: %s\n", buffer);

        write(pipe2[1], "Hello Parent, I got your msg!", 30);
    } else {
        // ---- Parent ----
        write(pipe1[1], "Hello Child, this is your Parent!", 33);

        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent got: %s\n", buffer);
    }

    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P16$ vim 16.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P16$ cc 16.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P16$ ./a.out 
Child got: Hello Child, this is your Parent!
Parent got: Hello Parent, I got your msg!
===========================================================================================================================
*/


