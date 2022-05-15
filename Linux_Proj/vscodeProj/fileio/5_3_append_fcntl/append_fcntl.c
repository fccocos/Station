/**
 * @file append_fcntl.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief Linux-Unix系统编程习题5-3练习
 * @version 0.1
 * @date 2022-05-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int fd;
    if (argc < 4 || argc > 5)
    {
        fprintf(stderr, "Usage:\n\r %s filename num-bytes string [x]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //打开并创建文件
    if ((fd = open(argv[1], O_WRONLY | O_APPEND)) == -1)
    {
        if (errno != ENONET)
        {
            fprintf(stderr, "%s file is no exist\n", argv[1]);
            fprintf(stderr, "Starting to create a new file: %s\n", argv[1]);
            if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0600)) == -1)
            {
                perror("open");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("Created a new file: %s\n", argv[1]);
            }
        }
        else
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("\"%s\" file was exist\n", argv[1]);
    }
    //判断命令行最后一个参数x，如果存在，则通过fcntl系统调用来修改文件的状态标志，并使用lseek来偏移文件
    if (argc == 5 && strcmp(argv[4], "x") == 0)
    {
        // 使用fcntl来获取当前文件的状态标志
        int flags = fcntl(fd, F_GETFL);
        if (flags == -1)
        {
            perror("fcntl_F_GETFL");
            exit(EXIT_FAILURE);
        }
        //使用fcntl来设置文件的状态标志位只写
        flags = O_WRONLY;
        flags = fcntl(fd, F_SETFL, flags);
        if (flags == -1)
        {
            perror("fcntl_F_SETFL");
            exit(EXIT_FAILURE);
        }
        //将文件位置偏移到文件末尾
        int ret = lseek(fd, 0, SEEK_END);
        if (ret == -1)
        {
            perror("lseek");
            exit(EXIT_FAILURE);
        }
    }
    //开始循环写入一个字节，循环argv[2]次
    //先将argv[2]转换位数字

    long num_bytes = atol(argv[2]);
    for (long i = num_bytes; i > 0; --i)
    {
        int w = write(fd, argv[3], strlen(argv[3]));
        if (w == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        if (i % 30 == 0)
        {
            w = write(fd, "\n", 1);
            if (w == -1)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }
    }

    exit(EXIT_SUCCESS);
}
