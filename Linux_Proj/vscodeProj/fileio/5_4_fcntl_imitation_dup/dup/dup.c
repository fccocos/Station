#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    int fd;
    int newfd;
    //打开文件
    if ((fd = open("file.txt", O_RDWR)) == -1)
    {
        if (errno != ENONET)
        {
            if ((fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
            {
                perror("open");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
    }
    newfd = fcntl(fd, F_DUPFD, 0);
    if(newfd == -1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }else{
        printf("oldfd=%d newfd=%d\n",fd, newfd);
    }
}