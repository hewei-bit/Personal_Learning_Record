#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <strings.h>
#include <sys/types.h>

int main(int argc,char **argv)
{
    if(argc != 2)
    {
        printf("Usage:%s <target-PID>\n",argv[0]);
    }

    int i ;
    for(i = SIGHUP;i<SIGRTMAX;i++)
    {
        if(i == SIGKILL|| i == SIGSTOP || i == 32 || i == 33)
        {
            continue;
        }
        kill(atoi(argv[1]),i);
    }


}