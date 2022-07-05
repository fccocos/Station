#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include "data_handle.h"

void sig_process(int sig);

int main(int argc, char *argv[])
{
    int sockfd;
    int ret;
    struct sockaddr_in serv_addr;

    if (argc == 3)
    {
        signal(SIGINT, sig_process);
        signal(SIGPIPE, sig_process);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1)
        {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(atoi(argv[2]));

        ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
        if(ret == -1)
        {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        handle_conn_client_sr(sockfd);
    }
    else
    {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

void sig_process(int sig)
{
    printf("Catch a exit signal\n");
    _exit(0);
}