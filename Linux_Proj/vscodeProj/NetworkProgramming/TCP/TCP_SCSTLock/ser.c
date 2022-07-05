#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>

#include <time.h>

#include <pthread.h>

#define SERV_PORT 8888
#define BUFLEN 1024
#define BACKLOG 5
#define IP "172.30.144.194"
#define CLIENTNUM 2

pthread_mutex_t ALOCK = PTHREAD_MUTEX_INITIALIZER;

static void handle_connect(int s);
static void handle_require(void *arg);

int main()
{
    int ss;
    struct sockaddr_in saddr;
    struct in_addr net_ip;

    ss = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP, &net_ip);
    saddr.sin_addr = net_ip;
    saddr.sin_port = htons(SERV_PORT);

    bind(ss, (struct sockaddr *)&saddr, sizeof(struct sockaddr));

    listen(ss, BACKLOG);

    handle_connect(ss);

    close(ss);
}

static void handle_connect(int s)
{
    pthread_t thread_do[CLIENTNUM];
    int i;
    for (i = 0; i < CLIENTNUM; i++)
    {
        pthread_create(&thread_do[i], NULL, (void *)handle_require, (void *)&s);
    }
    for (i = 0; i < CLIENTNUM; i++)
        pthread_join(thread_do[i], NULL);
}
static void handle_require(void *arg)
{
    int ss = *((int *)arg);
    int sc;
    struct sockaddr_in from;
    socklen_t len = sizeof(from);
    while (1)
    {
        time_t now;
        char buf[BUFLEN];
        int n = 0;

        pthread_mutex_lock(&ALOCK);
        sc = accept(ss, (struct sockaddr *)&from, &len);
        pthread_mutex_unlock(&ALOCK);
        while (1)
        {
            bzero(buf, BUFLEN);
            n = recv(sc, buf, BUFLEN, 0);
            write(1, buf, strlen(buf));
            if (n > 0)
            {
                if (!strncasecmp(buf, "time", 4))
                {
                    bzero(buf, BUFLEN);
                    now = time(NULL);
                    sprintf(buf, "%24s\r\n", ctime(&now));
                    send(sc, buf, strlen(buf), 0);
                }else
                {
                    send(sc, buf, strlen(buf), 0);
                }
            }
        }
        close(sc);
    }
}