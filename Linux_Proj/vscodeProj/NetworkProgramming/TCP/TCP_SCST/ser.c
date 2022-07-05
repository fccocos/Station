/**
 * @file ser.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief 单客户端单线程， 统一accept.在主线程中接收客户端的连接，当客户端连接到来的时候，创建一个子线程来处理客户端发送过来的数据并给予响应。
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>

#include <time.h>

#include <pthread.h>

#define SERV_PORT 8888
#define BACKLOG 5
#define IP "172.28.72.218"
#define BUFLEN 1024

static void handle_connect(int s);
static void handle_request(void *arg);

int main()
{
    int ret;
    int ss;
    struct sockaddr_in saddr;
    struct in_addr inet_ip;

    ss = socket(AF_INET, SOCK_STREAM, 0);
    if (ss == -1)
    {
        perror("socket");
        return -1;
    }

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP, &inet_ip);
    saddr.sin_addr = inet_ip;
    saddr.sin_port = htons(SERV_PORT);

    ret = bind(ss, (struct sockaddr *)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        perror("bind");
        return -1;
    }

    ret = listen(ss, BACKLOG);
    if (ret == -1)
    {
        perror("listen");
        return -1;
    }

    handle_connect(ss);

    close(ss);

    return 0;
}

static void handle_connect(int s)
{
    int cs;
    struct sockaddr_in caddr;
    socklen_t socklen = sizeof(caddr);
    pthread_t th_do;
    while (1)
    {
        cs = accept(s, (struct sockaddr *)&caddr, &socklen);
        if (cs == -1)
        {
            perror("accept");
            return;
        }

        if (cs > 0)
        {
            pthread_create(&th_do, NULL, (void*)handle_request, &cs);
        }
    }
}

static void handle_request(void *arg)
{
    char buf[BUFLEN];
    int cs = *((int *)arg);
    time_t now;
    int n;
    while (1)
    {
        /*接收数据*/
        bzero(buf, BUFLEN);
        n = recv(cs, buf, BUFLEN, 0);
        if (n > 0)
        {
            /*显示数据*/
            write(1, buf, strlen(buf));
            /*发送数据*/
            if(!strncasecmp(buf,"time", 4))
            {
                bzero(buf, BUFLEN);
                now = time(NULL);
                sprintf(buf, "%24s\r\n",ctime(&now));
                send(cs, buf, strlen(buf), 0);
            }
            else
            {
                int len = strlen(buf);
                bzero(buf,BUFLEN);
                sprintf(buf, "%d total bytes altogether\r\n\r\n",len);
                send(cs, buf, strlen(buf), 0);
            }
        }
    }
}