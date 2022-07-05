#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

static void sig_handle_cb(int signal)
{
    if (signal == SIGSTOP)
        printf("接收到信号SIGSTOP\n");
    else if (signal == SIGKILL)
        printf("接收到信号SIGKILL\n");
    else if (signal == SIGCONT)
        printf("接收到信号SIGCONT\n");
    else
        printf("接收到的信号为%d\n", signal);
}


int main()
{
    sighandler_t ret;
    ret = signal(SIGSTOP, sig_handle_cb);
    if (SIG_ERR == ret)
    {
        printf("父进程【%d】: 为SIGSTOP挂在信号处理函数失败\n", getpid());
        return -1;
    }
    ret = signal(SIGKILL, sig_handle_cb);
    if (SIG_ERR == ret)
    {
        printf("父进程【%d】:为SIGKILL挂载信号处理函数失败\n", getpid());
        return -1;
    }
    // pid_t pid = fork();

    // if (pid > 0) // 父进程
    // {
    //     while (1)
    //     {
    //         sighandler_t ret;
    //         ret = signal(SIGSTOP, sig_handle_cb);
    //         if (SIG_ERR == ret)
    //         {
    //             printf("父进程【%d】: 为SIGSTOP挂在信号处理函数失败\n", getpid());
    //         }
    //         sleep(5);
    //         ret = signal(SIGKILL, sig_handle_cb);
    //         if (SIG_ERR == ret)
    //         {
    //             printf("父进程【%d】:为SIGKILL挂载信号处理函数失败\n", getpid());
    //         }
    //         sleep(5);
    //     }
    // }
    // else if (pid == 0) //子进程
    // {
    //     while (1)
    //     {
    //         printf("子进程【%d】: 向父进程【%d】发送一个SIGSTOP信号\n", getpid(), getppid());
    //         kill(getppid(), SIGSTOP);
    //         printf("子进程【%d】: 睡眠5s......\n", getpid());
    //         sleep(5);
    //         printf("子进程【%d】: 向父进程【%d】发送一个SIGKCONT信号\n", getpid(), getppid());
    //         kill(getppid(), SIGCONT);
    //         printf("子进程【%d】: 睡眠5s......\n", getpid());
    //         sleep(5);
    //     }
    // }
}
