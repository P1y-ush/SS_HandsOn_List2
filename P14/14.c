/*
===========================================================================================================================
Name : 14.c
Author : Piyush
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
              the monitor.
===========================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

	int fd[2];       // fd[0] for read, fd[1] for write
	char buffer[100];

	//create pipe
	if(pipe(fd)==-1){
		printf("Pipe creation failed\n");
		return 1;
	}

	//write to pipe
	write(fd[1], "Hello Everyone!", 15);

	//read from pipe
	read(fd[0], buffer, sizeof(buffer));

	// display on monitor
    	printf("Data from pipe: %s\n", buffer);

    	return 0;
}

===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P14$ vim 14.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P14$ cc 14.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P14$ ./a.out 
Data from pipe: Hello Everyone!

===========================================================================================================================
*/
