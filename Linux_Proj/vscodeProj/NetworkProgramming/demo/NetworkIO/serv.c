#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include "data_handle.h"

#define SERV_PORT 8888
#define IP "172.26.139.219"
#define LISTEN_QUE_LEN 5

void sig_proccess(int signo);

int main()
{
    int ret;
    int local,client;
    struct sockaddr_in laddr, caddr;
    char netstr[4];
    pid_t pid;
    
    signal(SIGPIPE, sig_proccess);
    signal(SIGINT, sig_proccess);

    local = socket(AF_INET, SOCK_STREAM, 0);
    if(local == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    ret = inet_pton(AF_INET, IP, netstr);
    if(ret == 0)
    {
        fprintf(stderr,"src does not contain a string representing a valid network address in the specified address family\n");
    }
    else if(ret == -1)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    laddr.sin_addr.s_addr = netstr;
    laddr.sin_family = AF_INET;
    laddr.sin_port = SERV_PORT;
    bzero(laddr.sin_zero, sizeof(laddr.sin_zero));
    ret = bind(local, (struct sockaddr*)&laddr, (sizeof(struct sockaddr)));
    if(ret == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(local, LISTEN_QUE_LEN);
    if(ret == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for(;;)
    {
        socklen_t len = sizeof(struct sockaddr);
        client = accept(local, (struct sockadrr*)&caddr, &len);
        if(client == -1)
        {
            perror("accpect");
            continue;
        }

        pid = fork();
        if(pid == 0)//子进程, 只处理客户端的socket
        {
            close(local); // 关闭本地socket
            handle_conn_server_sr(client); 
        }
        else if(pid > 0)//父进程,只维护本地socket
        {
            close(client); // 关闭客户端socket
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }


    }
    
}

void sig_proccess(int signo)
{
    printf("Catch a exit signal\n");
    _exit(0);
}