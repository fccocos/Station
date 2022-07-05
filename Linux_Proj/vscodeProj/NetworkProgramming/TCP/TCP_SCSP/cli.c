#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>

#include <time.h>

#define SERV_PORT 8888
#define BUFLEN 1024

int main()
{
    int serfd;
    int ret;
    struct sockaddr_in seraddr;

    char buf[BUFLEN];

    serfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serfd == -1)
    {
        perror("socket");
        return -1;
    }

    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_port = htons(SERV_PORT);

    ret = connect(serfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (ret == -1)
    {
        perror("connect");
        return -1;
    }
    while (1)
    {
        /*发送数据*/
        bzero(buf, BUFLEN);
        read(0, buf, BUFLEN);
        sprintf(buf, "%spid[%d]\n", buf, getpid());
        send(serfd, buf, strlen(buf), 0);

        //接收数据
        bzero(buf, BUFLEN);
        recv(serfd, buf, sizeof(buf), 0);
        //打印数据
        write(1, buf, strlen(buf));
       
    }
     close(serfd);
}