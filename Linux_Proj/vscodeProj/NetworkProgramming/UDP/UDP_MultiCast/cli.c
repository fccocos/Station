#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <unistd.h>

#define MCAST_PORT 8888
#define MCAST_IP "224.0.0.88"
#define MCAST_DATA "BROADCAST TEST DATA"
#define MCAST_INTERVAL 5
#define BUFLEN 256

int main(int argc, char* argv[])
{
    int s;
    struct sockaddr_in local_addr;
    int err = -1;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s == -1)
    {
        perror("socket");
        exit(0);
    }

    bzero(&local_addr, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(MCAST_PORT);

    err = bind(s, (struct sockaddr*)&local_addr, sizeof(local_addr));
    if(err == -1)
    {
        perror("bind");
        exit(0);
    }

    /*設置循環許可*/
    int loop=1;
    err = setsockopt(s, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
    if(err<0)
    {
        perror("setsockopt");
        exit(0);
    }

    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_IP);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    /*將本地地址加入到廣播組*/
    err = setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
    if(err < 0)
    {
        perror("setsockopt::IP_ADD_MULTICAST");
        exit(0);
    }

    int times =0;
    socklen_t addr_len = 0;
    char buf[BUFLEN];
    int n=0;
    /*循環接收廣播組的消息，5次后退出*/
    for(times = 0; times <5; times++)
    {
        addr_len = sizeof(local_addr);
        bzero(buf, BUFLEN);
        n = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&local_addr, &addr_len);
        if(n == -1)
            perror("reccfrom");
        printf("Recv %dst message from server: %s\n", times, buf);
        sleep(MCAST_INTERVAL);
    }

    err = setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    if(err == -1)
    {
        perror("setsockopt::IP_DROP_MEMBERSHIP");
        exit(0);
    }
    close(s);
    return 0;
}