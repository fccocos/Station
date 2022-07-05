#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <signal.h>

#include <errno.h>

#include <time.h>
#include <unistd.h>

#define SERV_PORT 8888
#define BUFLEN 1024
#define PIDNUM 2

static 
void handle_connect(int s)
{
    char buf[BUFLEN];
    int n=0;
    struct sockaddr_in from;
    socklen_t len = sizeof(struct sockaddr);
    time_t now;

    /*客户端连接处理*/
    while(1)
    {
        bzero(buf, BUFLEN);
        /*接收数据*/
        n = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&from, &len);
        if(n>0)
        {
            /*将数据显示到终端上*/
            write(1, buf, strlen(buf));

            if(!strncasecmp(buf, "time", 4))
            {
                bzero(buf, BUFLEN);
                now = time(NULL);
                sprintf(buf, "%24s\r\n", ctime(&now));
                /*发送数据到客户端*/
                sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&from, len);
            }
            else
            {
                int buflen = strlen(buf);
                bzero(buf,BUFLEN);
                sprintf(buf, "%d total bytes altogether\r\n\r\n", buflen);
                sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&from, len);
            }
        }
    }

}

void signal_handler(int  arg)
{
    exit(1);
}

/*udp 没有listen和accept*/
int main()
{
   pid_t pids[PIDNUM];
   int ss;
   int ret;
   struct sockaddr_in saddr;

   ss = socket(AF_INET, SOCK_STREAM, 0);
   if(ss==-1)
   {
    perror("socket");
    return -1;
   }
   
   /*初始化sockaddr*/
   bzero(&saddr, sizeof(saddr));
   saddr.sin_family = AF_INET;
   saddr.sin_addr.s_addr = htonl(INADDR_ANY);
   saddr.sin_port = htons(SERV_PORT);
   
   /*绑定socket*/
   ret = bind(ss, (struct sockaddr*)&saddr, sizeof(saddr));
   if(ret == -1)
   {
    perror("bind");
    return -1;
   }

   /*信号SIGINT处理*/
   signal(SIGINT, signal_handler);
   
   printf("当前进程为%d\n",getpid());
   /*预先创建多个进程*/
   for(int i = 0; i<PIDNUM; i++)
   {
     pids[i] = fork();
     if(pids[i] == 0)
     {
        printf("启动了%d进程", getpid());
        handle_connect(ss);
     }
   }
    while(1);

    return 0;   
}