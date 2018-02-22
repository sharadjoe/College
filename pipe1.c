#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
int pipefd[2],n,n1,p1,p2;
char buff[100];
pipe(pipefd);
p1=fork();
if(p1==0){
	printf("This is child process\n");
	close(pipefd[1]);
	n = read(pipefd[0],buff,sizeof(buff));
	printf("Child process read %s", buff);
}
else{
	printf("This is parent process\n");
	close(pipefd[0]);
	printf("Writing hello world to parent process\n");
	write(pipefd[1],"hello world\n",12);
}
}


