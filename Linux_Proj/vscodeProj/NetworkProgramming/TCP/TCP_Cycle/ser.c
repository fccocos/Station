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

int main(int argc, char *argv[])
{
    int ret;
    int lfd, cfd;
    struct sockaddr_in laddr, caddr;
    socklen_t len = sizeof(struct sockaddr);
    struct in_addr net_ip;
    char buf[BUFLEN] = {0};

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        return -1;
    }
    bzero(&laddr, sizeof(laddr));
    laddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP, &net_ip); // inet_pton时可重入函数，因此他为线程安全的函数
    if (ret == -1)
    {
        perror("inet_pton");
        return -1;
    }
    laddr.sin_addr = net_ip;
    laddr.sin_port = htons(SERV_PORT);

    ret = bind(lfd, (struct sockaddr *)&laddr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        perror("bind");
        return -1;
    }

    ret = listen(lfd, 5);
    if (ret == -1)
    {
        perror("listen");
        return -1;
    }

    while (1) //轮询处理客户端的请求
    {

        cfd = accept(lfd, (struct sockaddr *)&caddr, &len);
        if (cfd == -1)
        {
            perror("accept");
            return -1;
        }
        while (1)
        {
            /*接收数据*/
            int nrecvs = recv(cfd, buf, BUFLEN, 0);
            if (nrecvs > 0)
            {
                /*在服务器端显示接收到的数据*/
                write(1, buf, strlen(buf));
                if (!strncasecmp(buf, "time", 4))
                {
                    time_t now = time(NULL);
                    bzero(buf, BUFLEN);
                    sprintf(buf, "%24s\r\n", ctime(&now));
                    /*发送数据*/
                    send(cfd, buf, strlen(buf), 0);
                }
                else
                {
                    int buflen = strlen(buf);
                    bzero(buf, BUFLEN);
                    sprintf(buf, "%d total bytes altogther\r\n\r\n", buflen);
                    /*发送数据*/
                    send(cfd, buf, strlen(buf), 0);
                }
            }//if (nrecvs > 0)
        }//while(1)
        close(cfd);
    }//while(1)
    
    close(lfd);
}