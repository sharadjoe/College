#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int signo)
{
    if(signo== SIGINT)
        printf("Recieved Sigint");
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
