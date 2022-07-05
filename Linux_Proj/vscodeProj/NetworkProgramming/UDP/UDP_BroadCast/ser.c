#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <sys/time.h>
#include <sys/select.h>

#define IP_FOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"

#define BUFLEN 64
#define MCAST_PORT 8888

int main()
{
    int sock;
    struct sockaddr_in saddr, caddr;
    socklen_t socklen = sizeof(caddr);
    int ret;
    int count = -1;
    fd_set readfd;
    char buf[BUFLEN];
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    printf("==>HandleIPFound\n");

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
        perror("socket"), exit(0);
    /*初始換saddr*/
    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(MCAST_PORT);

    ret = bind(sock, (struct sockaddr *)&saddr, sizeof(saddr));

    /*主處理過程*/
    while (1)
    {
        FD_ZERO(&readfd);
        FD_SET(sock, &readfd);

        ret = select(sock + 1, &readfd, NULL, NULL, &tv);
        switch (ret)
        {
        case 0:
            printf("超時了......\n");
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            break;
        case -1:
            printf("發生了錯誤\n");
            break;
        default:
            /*數據到來*/
            if (FD_ISSET(sock, &readfd))
            {
                bzero(buf, BUFLEN);
                count = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *)&caddr, &socklen);
                printf("Recv msg is %s\n", buf);
                if (strstr(buf, IP_FOUND))
                {
                    bzero(buf, BUFLEN);
                    memcpy(buf, IP_FOUND_ACK, sizeof(IP_FOUND_ACK));
                    count = sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&caddr, sizeof(caddr));
                }
            }
            break;
        }
    }
    printf("<==HandleIPFound\n");

    return 0;
}