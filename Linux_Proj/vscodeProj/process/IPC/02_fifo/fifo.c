#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

    pid_t pid;
    int ret;
    int fifo_fd;
    const char *name = "/tmp/fifo5";
    int mode = 0666;

    //创建命名管道
    ret = mkfifo(name, mode);
    if (ret == -1)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    //以读写的方式打开命名管道文件
    fifo_fd = open(name, O_RDWR|O_APPEND);
    if (fifo_fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // fork子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        /*子进程写命名管道*/
        char wbuf[1024];
        memset(wbuf, 0, 1024);
        //从标准输入中获取数据
        printf("input>>>   ");
        int rret = read(STDIN_FILENO, wbuf, 1024);
        if (rret < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        else if (rret == 0)
        {
            fprintf(stderr, "The stdin has no any char.\n");
            exit(EXIT_FAILURE);
        }
        //循环写入到fifo中
        while (rret > 0)
        {
            printf("output<<<");
            int wret = write(fifo_fd, wbuf, rret);
            if (wret < 0)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
            rret = read(STDIN_FILENO, wbuf, 1024);
            //输入exit退出
            if(strcasecmp(wbuf,"exit")==0) break;
        }
        return 0;
    }
    else
    {
        /*父进程读命名管道*/
        char rbuf[1024];
        memset(rbuf, 0, 1024);

        //将内容写入到标准输出设备上
        while (1)
        {
            int rret = read(fifo_fd, rbuf, 1024);
            if (rret < 0)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }
            if (rret == 0)
            {
                fprintf(stderr, "没有字符可读，睡眠5s...\n");
                sleep(5);
                fprintf(stderr, "睡眠结束\n");
            }
            int wret = write(STDOUT_FILENO, rbuf, rret);
            if (wret < 0)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }
    }
}

