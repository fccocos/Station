#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>

#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static ssize_t send_fd(int fd, void *data, size_t bytes, int senfd);

int main(int argc, char *argv[])
{
    int fd;
    ssize_t n;
    if (argc != 4)
        printf("socketpair error\n");
    if((fd = open(argv[2], atoi(argv[3])))<0)
        return 0;
    if((n = send_fd(atoi(argv[1]),"",1, fd))<0)
        return 0;
    return 0;
}

static ssize_t send_fd(int fd, void *data, size_t bytes, int sendfd)
{
    struct msghdr msghdr_send;
    struct iovec iov[1];
    union
    {
        struct cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];

    } control_un;
    struct cmsghdr *pcmsghdr = NULL;

    /*初始化msghdr_send*/
    msghdr_send.msg_control = control_un.control;
    msghdr_send.msg_controllen = sizeof(control_un.control);
    /*通过pcmsghdr指针来初始化msghdr_send的cmsghadr字段*/
    pcmsghdr = CMSG_FIRSTHDR(&msghdr_send); //获取第一个消息
    pcmsghdr->cmsg_len = CMSG_LEN(sizeof(int));
    pcmsghdr->cmsg_level = SOL_SOCKET;
    pcmsghdr->cmsg_type = SCM_RIGHTS;
    *((int *)CMSG_DATA(pcmsghdr)) = sendfd; // 讲述senfd打包到pcmsghdr指针所指向的cmsghdr结构体中
    msghdr_send.msg_name = NULL;
    msghdr_send.msg_namelen = 0;
    iov[0].iov_base = data;
    iov[0].iov_len = bytes;
    msghdr_send.msg_iov = iov;
    msghdr_send.msg_iovlen = 1;

    return (sendmsg(fd, &msghdr_send, 0));
}
