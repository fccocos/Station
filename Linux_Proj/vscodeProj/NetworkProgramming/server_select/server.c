#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>

#define LOCAL_PORT 8080
#define LISTEN_QUE_LEN 5

#define CLIENT_LEN 5

int main()
{
    int ret, ready;
    int lfd, cfd;
    struct sockaddr_in laddr, caddr;

    int maxfd = -1;
    fd_set scanfd; // 监听的文件描述符集合
    FD_ZERO(&scanfd);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    char buf[1024] = {0};
    /*初始化socket*/
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    /*初始化local socket地址*/
    laddr.sin_family = AF_INET;
    laddr.sin_addr.s_addr = htonl(INADDR_ANY);
    laddr.sin_port = htons(LOCAL_PORT);
    bzero(laddr.sin_zero, sizeof(laddr.sin_zero)); // size_zero占用8个字节

    /*绑定套接字*/
    ret = bind(lfd, (struct sockaddr *)&laddr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    /*监听套接字*/
    ret = listen(lfd, LISTEN_QUE_LEN);
    if (ret == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "服务器启动了......\n");

    /*处理客户端的连接*/
    while (1) // 采用select的轮询方式处理客户端的连接
    {
        /*接收客户端的请求*/
        socklen_t socklen = sizeof(struct sockaddr);
        cfd = accept(lfd, (struct sockaddr *)&caddr, &socklen);
        if (cfd == -1)
        {
            perror("socklen");
            break;
        }
        for (;;)
        {
            /*将客户端的socket fd加入到scanfd*/
            maxfd = -1;
            FD_ZERO(&scanfd);
            FD_SET(cfd, &scanfd);
            if (cfd > maxfd)
                maxfd = cfd;
            tv.tv_sec = 5;
            tv.tv_usec = 0;
            ret = select(maxfd + 1, &scanfd, NULL, NULL, &tv);
            switch (ret)
            {
            case 0:
                printf("超时了......\n");
                break;
            case -1:
                perror("select");
                break; //有错误发生
            default:
                if (FD_ISSET(cfd, &scanfd))
                {
                    bzero(buf, sizeof(buf));
                    ready = recv(cfd, buf, sizeof(buf), 0);
                    if (ready > 0)
                    {
                        /*显示客户端发送过来的数据*/
                        fprintf(stdout, "%s", buf);

                        char *pstr = strchr(buf, ':');
                        //移动pstr,直到没有空格
                        while (*(++pstr) == ' ')
                            ;
                        if (!strncasecmp(pstr, "time", 4))
                        {
                            time_t now = time(NULL);
                            bzero(buf, sizeof(buf));
                            sprintf(buf, "%24s\r\n", ctime(&now));
                            /*发送数据*/
                            send(cfd, buf, strlen(buf), 0);
                        }
                    }
                } // FD_ISSET

                cfd = -1;
                close(cfd);
                break;
            } // switch
        }// for

    } // while
}