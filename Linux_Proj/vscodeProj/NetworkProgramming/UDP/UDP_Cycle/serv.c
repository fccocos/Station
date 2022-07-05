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

#define BUFLEN 1024
#define SERV_PORT 8080

int main()
{
    int s;
    struct sockaddr_in laddr, caddr;
    time_t now;
    char buf[BUFLEN]={0};
    int n=0;
    socklen_t socklen = sizeof(struct sockaddr);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&laddr, sizeof(struct sockaddr));
    laddr.sin_family = AF_INET;
    laddr.sin_addr.s_addr = htonl(INADDR_ANY);
    laddr.sin_port = htons(SERV_PORT);
    
    bind(s, (struct sockaddr*)&laddr,sizeof(struct sockaddr));

    printf("启动了UDP服务器端......\n");

    while(1)
    {
        bzero(buf, BUFLEN);
        // 接收数据
        n = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&caddr, &socklen);
        if(n>0)
        {
            write(1, buf, strlen(buf));

            if(!strncasecmp(buf, "time", 4))
            {
                bzero(buf, BUFLEN);
                now = time(NULL);
                sprintf(buf, "%24s\r\n", ctime(&now));
                sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&caddr, socklen);
                
            }else{
                int len = strlen(buf);
                bzero(buf, BUFLEN);
                sprintf(buf, "%d total bytes\r\n\r\n", len);
                sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&caddr, socklen);
            }
        }
    }
    close(s);
}