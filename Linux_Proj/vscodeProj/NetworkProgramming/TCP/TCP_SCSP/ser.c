/**
 * @file ser.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief 单客户端单进程，同一accept.主程序接收任务并进程任务分发，frok出来的子进程来处主进程分发的任务，最后的连接关闭在处理程序中进程
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

#define SERV_PORT 8888

#define LISTEN_QUE_LEN 5

#define BUFLEN 1024

static void handle_connect(int s);
static void handle_request(int s);

int main()
{
    int ss;
    int ret;
    struct sockaddr_in saddr;

    ss = socket(AF_INET, SOCK_STREAM, 0);
    if (ss == -1)
    {
        perror("socket");
        return -1;
    }

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(SERV_PORT);

    ret = bind(ss, (struct sockaddr *)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        perror("bind");
        return -1;
    }

    ret = listen(ss, LISTEN_QUE_LEN);

    handle_connect(ss);

    close(ss);

    return 0;
}
static void handle_connect(int s)
{
    int cs;
    struct sockaddr_in caddr;
    socklen_t socklen = sizeof(struct sockaddr);
    while (1)
    {
        cs = accept(s, (struct sockaddr *)&caddr, &socklen);
        if (cs == -1)
        {
            perror("accept");
            return;
        }
        if (fork() > 0) //父进程
        {
            //关闭cs
            close(cs);
        }
        else // 子进程
        {
            printf("进程[%d]:正在处理...\n", getpid());
            handle_request(cs);
            return;
        }
    }
}
static void handle_request(int s)
{
    while (1)
    {
        char buf[BUFLEN];
        int n = 0;
        /*接收数据*/
        bzero(buf, BUFLEN);
        n = recv(s, buf, BUFLEN, 0);
        /*显示数据*/
        write(1, buf, strlen(buf));

        time_t now = time(NULL);
        if (n > 0)
        {
            /*发送数据*/
            if (!strncasecmp(buf, "time", 4))
            {
                bzero(buf, BUFLEN);
                sprintf(buf, "%24s\r\n", ctime(&now));
                send(s, buf, sizeof(buf), 0);
            }
            else
            {
                int len = strlen(buf);
                bzero(buf, BUFLEN);
                sprintf(buf, "%d total bytes altogether\r\n\r\n", len);
                send(s, buf, strlen(buf), 0);
            }
        }
    }
}