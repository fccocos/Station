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
    printf("输入一个新的文件描述:");
    scanf("%d", &newfd);
    //判断新描述符和旧描述符是否相等
    if (newfd == fd)
    {
        if (fcntl(fd, F_GETFL) == -1)
        {
            errno = EBADE;
            return -1;
        }
        printf("oldfd=%d newfd=%d\n", fd, newfd);
    }
    else
    {
        //判断新描述是否打开，如果打开关闭
        if (fcntl(newfd, F_GETFL) == -1)
        {
            printf("新文件描述符%d未打开\n", newfd);
        }
        else
        {
            printf("新文件描述符%d已打开, 需要关闭\n", newfd);
            if (close(newfd) == -1)
            {
                perror("close");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("文件描述符%d关闭完成\n", newfd);
            }
        }
        //通过fcntl复制描述符的副本到新的文件描述符
        newfd = fcntl(fd, F_DUPFD, newfd);
        if (newfd == -1)
        {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("oldfd=%d newfd=%d\n", fd, newfd);
        }
    }

    exit(EXIT_SUCCESS);
}