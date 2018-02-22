#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
int pipe1[2],pipe2[2],p;
char buff[100],buff2[100],a1[100],a2[100];
pipe(pipe1);
pipe(pipe2);
p=fork();

if(p==0){
	printf("This is child process\n");
	close(pipe1[1]);
	close(pipe2[0]);
	printf("Enter input from child process : ");
	scanf("%s", a2);
	printf("Writing %s from child process\n",a2);
	write(pipe2[1],a2,sizeof(a2));
	read(pipe1[0],buff,sizeof(buff));
	printf("Child process read %s\n", buff);
	close(pipe1[0]);	
	close(pipe2[1]);
}
else{
	printf("This is parent process\n");
	close(pipe1[0]);
	close(pipe2[1]);
	printf("Enter input from parent process : ");
	scanf("%s", a1);
	printf("Writing %s from parent process\n",a1);
	write(pipe1[1],a1,sizeof(a1));
	read(pipe2[0],buff2,sizeof(buff2));
	printf("Parent process read %s\n",buff2);
	close(pipe1[1]);
	close(pipe2[0]);
}


}


