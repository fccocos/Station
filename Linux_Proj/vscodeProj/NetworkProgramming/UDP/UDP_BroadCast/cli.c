#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>

#include <errno.h>
#include <sys/time.h>
#include <sys/select.h>

#define IP_FOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"
#define IFNAME "eth0" // 接口名字

#define BUFLEN 64
#define MCAST_PORT 8888

int main()
{
    int ret = -1;
    int sock = -1;
    int so_broadcast = -1;
    struct ifreq ifr; // 網絡接口
    struct sockaddr_in broadcast_addr;
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    fd_set readfd;
    char buf[BUFLEN];
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
        perror("socket"), exit(0);
    strcpy(ifr.ifr_name, IFNAME);
    /*發送命令，獲得網絡接口的廣播地址*/
    if (ioctl(sock, SIOCGIFBRDADDR, &ifr) == -1)
        perror("ioctl"), exit(0);
    /*將獲取到的廣播地址複製到broadcast*/
    memcpy(&broadcast_addr, &ifr.ifr_broadaddr, sizeof(struct sockaddr));
    broadcast_addr.sin_port = htons(MCAST_PORT);

    /*設置套接字文件描述符sock為可以進行廣播操作*/
    ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &so_broadcast, sizeof(so_broadcast));

    /*住處理過程*/
    int times = 10;
    int i = 0;
    for (i = 0; i < times; i++)
    {
        ret = sendto(sock, IP_FOUND, strlen(IP_FOUND), 0, (struct sockaddr *)&broadcast_addr, sizeof(struct sockaddr));
        if (ret == -1)
            continue;
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
            printf("出錯誤了......\n");
            break;
        default:
            if (FD_ISSET(sock, &readfd))
            {
                /*接收數據*/
                bzero(buf, BUFLEN);
                recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *)&from_addr, &from_len);
                printf("Rev msg is %s\n", buf);
                if (strstr(buf, IP_FOUND_ACK))
                {
                    printf("found server, IP is %s\n", inet_ntoa(from_addr.sin_addr));
                }
                else
                {
                    printf("no found server IP\n");
                }
            }
            break;
        }
    }
}