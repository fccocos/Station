#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>

#include <time.h>

#define SERV_PORT 8888
#define IP "172.26.117.209"
#define BUFLEN 1024

int main()
{
    int serfd;
    struct sockaddr_in seraddr;
    int ret;
    struct in_addr net_ip;
    char buf[BUFLEN];

    serfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serfd == -1)
    {
        perror("serfd");
        return -1;
    }

    bzero(&seraddr, sizeof(struct sockaddr));
    ret = inet_pton(AF_INET, IP, &net_ip);
    seraddr.sin_addr = net_ip;
    seraddr.sin_port = htons(SERV_PORT);
    seraddr.sin_family = AF_INET;

    /*连接服务器*/
    ret = connect(serfd, (struct sockaddr *)&seraddr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        perror("connect");
        return -1;
    }

    while (1)
    {
        /*发送数据到服务器*/
        bzero(buf, BUFLEN);
        read(0, buf, BUFLEN);
        send(serfd, buf, strlen(buf), 0);

        /*接收来自服务器的数据*/
        bzero(buf, BUFLEN);
        int n = recv(serfd, buf, BUFLEN, 0);
        if (n > 0)
        {
            write(1, buf, strlen(buf));
        }
    }

    close(serfd);
}