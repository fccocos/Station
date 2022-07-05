#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>
#define BUFLEN 1024
#define SERV_PORT 8888

int main()
{
    int s;
    struct sockaddr_in serv;
    char buf[BUFLEN] = {0};
    int n = 0;
    socklen_t len = 0;

    s = socket(AF_INET, SOCK_DGRAM, 0);

    /*初始化套接字*/
    memset(&serv, 0, sizeof(struct sockaddr));
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(SERV_PORT);
    serv.sin_family = AF_INET;
    while (1)
    {
        memset(buf, 0, BUFLEN);
        read(0, buf, BUFLEN);
        sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&serv, sizeof(serv));

        memset(buf, 0, BUFLEN);
        len = sizeof(serv);
        n = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&serv, &len);
        if (n > 0)
        {
            fprintf(stdout, "%s", buf);
        }
    }
    close(s);

    return 0;
}