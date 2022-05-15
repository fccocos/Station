#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include <errno.h>

#define k 1024
#define m 1024 * k
#define g 1024 * m

//.prog string wsize read_size
static long long argtoll(const char *arg)
{
    char unit;
    int len = strlen(arg);
    char tmp[len];
    memset(tmp, 0, len);
    memcpy(tmp, arg, len);
    unit = tmp[len - 1];
    switch(unit)
    {
        case 'k':
        case 'K':
        case 'm':
        case 'M':
        case 'g':
        case 'G':
            tmp[len - 1] = '\0';
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        default:
            fprintf(stderr,"%c is a illegal unit\n", unit);
            return -1;
    }
    long long number = atoll(tmp);
    switch(unit)
    {
        case 'k':
        case 'K':
            return number*k;
        case 'm':
        case 'M':
            return number*m;
        case 'g':
        case 'G':
            return number*g;
        default:
            return number;
    }
}
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage:\t%s string wsize rsize\n", program_invocation_short_name);
        fprintf(stderr, "size--n(k/K/m/M/g/G),10k/K/m/M/g/G\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    int ret;
    int fds[2];              //管道
    int *write_fd = &fds[1]; //管道的写端
    int *read_fd = &fds[0];  //管道的读端

    //创建半双工管道
    ret = pipe(fds);
    if(ret == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    //fork进程
    pid = fork();
    if(pid == -1)
    {
        perror("pid");
        exit(EXIT_FAILURE);
    }
    if(pid==0)
    {
        /*子进程写管道*/
        //关闭读端
        close(*read_fd);
        
        int wret;
        int wsize=argtoll(argv[2]);
        char* wbuf = (char*)malloc(wsize);
        memset(wbuf, 0, wsize);
        memcpy(wbuf, argv[1], strlen(argv[1])+1);
        //开始将内容写如管道
        while(wsize>0)
        {
            wret = write(*write_fd, wbuf, wsize);

            if(wret<=0)
            {
                sleep(10);
                break;
            }else{
                wsize-=wret;
                printf("写入%d个数据，剩余%d个数据\n", wret, wsize);
            }
        }

        //释放动态内存
        if(wbuf!=NULL)
        {
            free(wbuf);
            wbuf=NULL;
        }
        //关闭写端
        close(*write_fd);
        return 0;
        
    }else{
        /*父进程读管道*/
        //关闭写端
        close(*write_fd);
        long long rsize = argtoll(argv[3]);
        char * rbuf = (char*)malloc(rsize);
        memset(rbuf,'0',rsize);
        int rret;
        while(1)
        {
            rret = read(*read_fd, rbuf, rsize);
            if(rret<=0)
            {
                printf("没有可读了\n");
                break;
            }
            printf("接受到了%d个数据，内容为：\"%s\"\n", rret, rbuf);
        }

        //释放动态内存
        if(rbuf!=NULL)
        {
            free(rbuf);
            rbuf=NULL;
        }
        //关闭读端
        close(*read_fd);
    }
    return 0;
}