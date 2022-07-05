#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <errno.h>

#define MCAST_PORT 8888
#define MCAST_IP "224.0.0.88"
#define MCAST_DATA "BROADCAST TEST DATA"
#define MCAST_INTERVAL 5

int main(int argc, char* argv[])
{
    int s;
    struct sockaddr_in mcast_addr;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s == -1)
    {
        perror("socket");
        exit(1);
    }

    bzero(&mcast_addr, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_IP);
    mcast_addr.sin_port=htons(MCAST_PORT);

    /*向多播地址發送數據*/
    while(1)
    {
        int n = sendto(s, MCAST_DATA, sizeof(MCAST_DATA), 0, (struct sockaddr*)&mcast_addr, sizeof(mcast_addr));
        if(n<0)
        {
            perror("sendto");
            exit(0);
        }

        sleep(MCAST_INTERVAL);
    }

    return 0;
}
