#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void signal_handler_parent(int signo)
	{
	printf("Handling Interrupt exiting Application parent\n");
	exit(0);
	}

void signal_handler_child(int signo)
	{
	printf("Handling interrupt Exiting Application \n");
	exit(0);
	}

void signal_handler_child_dead(int signo)
	{
	printf("Child dead \n");
	}

int main()
	{
	int i,p1,p2;
	p1=fork();
	if(p1==0)
		{
		for(i=0;i<=3;i++)
			{
			sleep(1);
			printf("Child Exicuting \n");
			signal(SIGINT,signal_handler_child);
			}
		}
	else 
		{
		for(;;)
			{
			sleep(1);
			printf("Parent Executing \n");
			signal(SIGINT,signal_handler_parent);
			signal(SIGCHLD,signal_handler_child_dead);
			}
		}
	return 0;
	}



