#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>

int main()
{
    char* args[]={"/bin/ls",NULL};
    printf("系统分配的当前进程号: %ld\n", getpid());
    if(execve("/bin/ls",args, NULL)==-1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}