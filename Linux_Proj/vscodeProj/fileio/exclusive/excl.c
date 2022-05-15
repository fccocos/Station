/**
 * @file excl.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief 
 *  该程序的主要功能是打开文件，如果文件存在直接打开，如果文件不存在，就新建文件。
 *  首先以非独占的方式打开文件，然后以独占的方式打开文件，并输出相应的进程号，对比两个的区别
 *  以非独占方式打开的函数为non_excl()
 *  以独占方式打开的程序为excl()
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//打开文件
static void Open(const char *name, int flags1, int flags2, int modes);

//以独占的方式打开文件
void excl(const char *name);
//以非独占的方式打开文件
void non_excl(const char *name);
int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, ":n:e:h")) != -1)
    {
        switch (opt)
        {
        case 'n': //以非独占的方式打开文件
            if (optarg != NULL)
            {
                non_excl(optarg);
            }
            else
            {
                fprintf(stderr, "%s -%c 为有参选项\n", argv[0], (unsigned char)opt);
                exit(EXIT_FAILURE);
            }
            break;
        case 'e': //以独占的方式打开文件
            if (optarg != NULL)
            {
                excl(optarg);
            }
            else
            {
                fprintf(stderr, "%s -%c 为有参选项\n", argv[0], (unsigned char)opt);
                exit(EXIT_FAILURE);
            }
            break;
        case 'h':
            fprintf(stdout, "Usage:\n\t%s -n filename\n\t%s -e filename\n\t%s -h\n", argv[0], argv[0], argv[0]);
            fprintf(stdout, " -e exclusive  以独占的方式打开文件并显示相关信息\n");
            fprintf(stdout, " -n non-excluse 以非独占的方式打开文件并显示相关信息\n");
            fprintf(stdout, " -h help  帮助命令\n");
            exit(EXIT_FAILURE);
            break;
        case ':':
                fprintf(stderr, "%s (-%c)选项为有参选项\n", argv[0], (unsigned char)optopt);
                exit(EXIT_FAILURE);
        case '?':
                fprintf(stderr, "%s (-%c)选项无法识别\n", argv[0], (unsigned char)opt);
                exit(EXIT_FAILURE);    
        default:
            fprintf(stderr, "there is no argument in switch()\n");
            exit(EXIT_FAILURE);
        }
    }
    //命令没有参数的错误处理
    if (argc == 1 && opt == -1 && optind == 1)
    {
        fprintf(stderr, "%s must have some arguments\n", argv[0]);
        fprintf(stderr, "Usage:\n\t%s -n filename\n\t%s -e filename\n\t%s -h\n", argv[0], argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }
    //命令行只有一个无选项的参数也是不合法的
    if (argc == 2 && optind < argc)
    {
        fprintf(stderr, "It is illegal that %s command just have a non-option argument\n", argv[0]);
        fprintf(stderr, "Usage:\n\t%s -n filename\n\t%s -e filename\n\t%s -h\n", argv[0], argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

//以独占的方式打开文件
void excl(const char *name)
{
    int flags1 = O_RDWR|O_EXCL;
    int flags2 = O_WRONLY|O_CREAT|O_TRUNC|O_EXCL;
    int modes = 0600;
    Open(name, flags1, flags2, modes);
}
//以非独占的方式打开文件
void non_excl(const char *name)
{
    int flags1 = O_RDWR;
    int flags2 = O_WRONLY|O_CREAT|O_TRUNC;
    int modes = 0600;
    Open(name, flags1, flags2, modes);
}

void Open(const char *name, int flags1, int flags2, int modes)
{
    int fd;
    if ((fd = open(name, flags1)) != -1)
    {
        printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(), name);
        close(fd);
    }else
    {
        if (errno != ENOENT)
        {
            perror("open");
        }
        else
        {
            printf("[PID %ld] \"%s\" file no exists yet.\n", (long)getpid(), name);
            printf("Please wait for 5s ...\n");
            sleep(5);
            printf("Done sleeping ... \n");
            printf("[PID %ld] starting to create \"%s\" file.\n", (long)getpid(), name);
            fork();
            if((fd = open(name, flags2, modes))==-1)
                perror("open");
            else
                printf("[PID %ld] Created a new file \"%s\".\n", (long)getpid(), name);
            close(fd);
        }
    }
}