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
#include <pthread.h>
#include <sys/time.h>

#define SERV_PORT 8888
#define BUFLEN 5
#define BACKLOG 5
#define CLIENTMAX 5
#define IP "172.30.153.59"



int connect_host[CLIENTMAX] = {-1};
int connect_number = 0;

static void handle_connect(void *arg);

static void handle_request(void *arg);

int main(int agrc, char *argv[])
{
    int serfd;
    struct sockaddr_in saddr;
    struct in_addr net_ip;

    serfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP, &net_ip);
    saddr.sin_addr = net_ip;
    saddr.sin_port = htons(SERV_PORT);

    bind(serfd, (struct sockaddr *)&saddr, sizeof(saddr));
    listen(serfd, BACKLOG);

    pthread_t th_do[2];
    pthread_create(&th_do[0], NULL, (void *)handle_connect, (void *)&serfd);
    pthread_create(&th_do[1], NULL, (void *)handle_request, NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(th_do[i], NULL);

    close(serfd);

    return 0;
}

static void handle_connect(void *arg)
{
    int s = *((int *)arg);
    struct sockaddr_in caddr;
    socklen_t len = sizeof(caddr);
    for (;;)
    {
        int cs = accept(s, (struct sockaddr *)&caddr, &len);

        /*接收客户端的请求*/
        fprintf(stdout, "a client connect, from: %s\n", inet_ntoa(caddr.sin_addr));
        /*查找合适的位置，将客户端的文件描述符放入*/
        for (int i = 0; i < CLIENTMAX; i++)
        {
            if (connect_host[i] == -1)
            {
                /*放入到连接池中*/
                connect_host[i] = cs;
                /*客户端数据+1*/
                connect_number++;
                break;
            }
        }
    }
}

static void handle_request(void *arg)
{
    time_t now;
    char buf[BUFLEN];
    int n = 0;
    fd_set scanfd;  //需要扫描的文件描述符集合
    int maxfd = -1; // 最大文件描述符
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int i = 0;
    int err = -1;
    for (;;)
    {
        maxfd = -1;
        FD_ZERO(&scanfd);
        /*将服务器获取到的文件描述符添加到集合中进行监听*/
        for (i = 0; i < CLIENTMAX; i++)
        {
            if (connect_host[i] != -1)
            {
                FD_SET(connect_host[i], &scanfd);
                /*更新最大文件描述符的值*/
                if (connect_host[i] > maxfd)
                {
                    maxfd = connect_host[i];
                }
            }
        }

        //开始监听文件描述符
        err = select(maxfd + 1, &scanfd, NULL, NULL, &timeout);
        switch (err)
        {
        case 0:
            printf("超时了\n");
            break;
        case -1:
            printf("发生错误了\n");
            break;
        default:
            if (connect_number <= 0)
                break;
            for (i = 0; i < CLIENTMAX; i++)
            {
                /*查找激活的文件描述符*/
                if (connect_host[i] != -1)
                    if (FD_ISSET(connect_host[i], &scanfd))
                    {
                        /*开始接收数据并发送响应*/
                        memset(buf, 0, BUFLEN);
                        n = recv(connect_host[i], buf, BUFLEN, 0);
                        if (n > 0 && !strncmp(buf, "TIME", 4))
                        {
                            now = time(NULL);
                            bzero(buf, BUFLEN);
                            sprintf(buf, "%24s\r\n", ctime(&now));
                            send(connect_host[i], buf, strlen(buf), 0);
                        }
                        /*更新连接池*/
                        int tmpfd = connect_host[i];
                        connect_host[i] = -1;
                        connect_number--;
                        /*关闭*/
                        close(tmpfd);
                    } // if(FD_ISSET(connect_host[i], &scanfd))
            }         // for(i=0; i<CLIENTMAX; i++)
            break;
        } // switch(err)
    }
}