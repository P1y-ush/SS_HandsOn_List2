/*
===========================================================================================================================
Name : 19e.c
Author : Piyush
Description : Create a FIFO file using mkfifo library function
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo_lib", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    printf("FIFO created using mkfifo library function.\n");
    return 0;
}

/*
===========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ vim 19e.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ cc 19e.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P19$ ./a.out 
FIFO created using mkfifo library function.

===========================================================================================================================
*/
