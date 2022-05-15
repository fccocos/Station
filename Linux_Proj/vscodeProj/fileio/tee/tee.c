/**
 * @file tee.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief  实现tee命令，从标准输入中读取数据，直至文件结尾，
 * 随后将数据写入到标准输出和命令行所指定的文件，如果文件已存在对文件中的内容进行覆盖
 * 也可以使用-a命令选项在文件结尾处追加数据
 * @version 0.1
 * @date 2022-05-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

static void
usageError(char *progName, char *msg, int opt)
{
    if (msg != NULL && opt != 0)
        fprintf(stderr, "%s (-%c)\n", msg, (unsigned char)opt);
    fprintf(stderr, "Usage: %s [-a] filename\n", progName);
    exit(EXIT_FAILURE);
}

static void
writeFile(const char *filename, const char *buf, size_t bufSize, int nflags1, int nflag2, int nmodes)
{
    int fd = open(filename, nflags1);
    int nwrite;
    if (fd == -1)
    {
        fprintf(stderr, "no the file for name of %s", filename);
        fd = open(filename, nflag2, nmodes);
        if (fd == -1)
            err_exit("open");
        nwrite = write(fd, buf, bufSize);
        if (nwrite == -1)
            err_exit("write");
    }
    else
    {
        nwrite = write(fd, buf, bufSize);
        if (nwrite == -1)
            err_exit("write");
    }
}

int main(int argc, char *argv[])
{
#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

    char rbuf[BUF_SIZE];
    memset(rbuf, 0, BUF_SIZE);
    ssize_t nread, nwrite;

    int opt = 0;
    char *pstr = NULL;
    int xfnd; //用于计数没有参数选项的个数
    while ((opt = getopt(argc, argv, ":a:")) != -1)
    {
        switch (opt)
        {
        case 'a':
            pstr = optarg;
            break;
        case ':':
            usageError(argv[0], "Missing argument", optopt);
            break;
        case '?':
            usageError(argv[0], "Unrecognized option", optopt);
            break;
        default:
            fatal("Unexcepted case in switch()");
        }
    }

    nread = read(STDIN_FILENO, rbuf, BUF_SIZE);
    if (nread == -1)
        err_exit("read");
    nwrite = write(STDOUT_FILENO, rbuf, nread);
    if (nwrite == -1)
        err_exit("write");

    if (pstr != NULL)
    {
        printf("带有选项\n");
        int nflags1 = O_WRONLY | O_APPEND;
        int nflag2 = O_CREAT | O_WRONLY | O_TRUNC;
        int nmodes = 0666;
        writeFile(pstr, rbuf, nread, nflags1, nflag2, nmodes);
    }
    else if (optind < argc)
    {
        printf("没有选项");
        pstr = argv[optind];
        int nflags1 = O_WRONLY | O_TRUNC;
        int nflag2 = O_CREAT | O_WRONLY | O_TRUNC;
        int nmodes = 0666;
        writeFile(pstr, rbuf, nread, nflags1, nflag2, nmodes);
    }
    else 
    {
        usageError(argv[0], "Missing argument", optopt);
    }

    exit(EXIT_SUCCESS);
}