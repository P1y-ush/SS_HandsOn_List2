/*
===========================================================================================================================
Name : 15.c
Author : Piyush
Description : Write a simple program to send some data from parent to the child process.
===========================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	char buffer[100];

	//create pipe
	pipe(fd);

	if(fork() == 0){
		//Child process
		read(fd[0], buffer, sizeof(buffer));
		printf("Child received: %s\n", buffer);
	}else{
		//Parent process
		write(fd[1],"Hello from parent",18);
	}
	return 0;
}

/*
===========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P15$ vim 15.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P15$ cc 15.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/List2/P15$ ./a.out 
Child received: Hello from parent


===========================================================================================================================
*/
