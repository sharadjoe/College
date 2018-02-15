https://gist.github.com/leehambley/5589953

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#incldue<sys/types.h>
#include<sys/wait.h>

void signal_handler(int signo)
{
    if(signo== SIGINT)
        printf("Recieved Sigint");
}

void handler(int sig)
{
    pid_t pid;    
}

int main(void)
{
    if(signal(SIGINT, signal_handler)== SIG_ERR)
        printf("can't catch SIGINT");
    while(5)
    {
        sleep(1);
        
    }
    return 0;
}
