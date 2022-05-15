#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    if(argc!=3||strcmp(argv[1],"--help")==0)
    {
        fprintf(stderr, "Useage:\n\t%s filename string\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    int flags = O_WRONLY|O_APPEND;
    int fd;
    //打开文件
    if((fd=open(argv[1],flags))==-1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    //将文件位置指针偏移到文件开头
    if(lseek(fd, 0, SEEK_SET)==-1)
    {
        perror("lseek");
        exit(EXIT_FAILURE);
    }
    
    //开始写文件
    printf("argv[3]=%s, argv[3]_len=%ld\n", argv[2], strlen(argv[2]));
    if(write(fd,argv[2],strlen(argv[2]))==-1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    //关闭文件
    if(close(fd)==-1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_FAILURE);
}