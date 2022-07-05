#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <arpa/inet.h>

#define SERV_PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("scoket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    bzero(serv_addr.sin_zero, sizeof(serv_addr.sin_zero));

    ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
    if(ret == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    //处理来自服务器的响应
    char buffer[1024]={0};
    while(1)
    {
        char tmp[1024]={0};
        bzero(tmp,sizeof(tmp));
        fprintf(stdout, "client[%d]:", getpid());
        bzero(buffer,sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(tmp, buffer);
        bzero(buffer, sizeof(buffer));
        pid_t p =getpid();
        sprintf(buffer, "client[%d] 's message: %s", p, tmp);
        write(sockfd, buffer, strlen(buffer)+1);

        fprintf(stdout, "\n================收到响应================\n");
        bzero(buffer, sizeof(buffer));
        read(sockfd,buffer,sizeof(buffer));
        fputs(buffer, stdout);
        fprintf(stdout, "================末尾================\n");

        if(strcasecmp(tmp,"exit")==0)
        {
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
        
    }
    

}