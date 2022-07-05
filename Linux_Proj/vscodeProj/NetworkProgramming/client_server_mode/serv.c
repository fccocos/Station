#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <signal.h>

#define LOCAL_PORT 8080
#define LISTEN_QUE_LEN 5

int main()
{
    int local_sockfd, client_sockfd;
    struct sockaddr_in local_addr, client_addr;
    int ret;
    char buffer[1024] = {0};

    local_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (local_sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //初始化sockaddr
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY); //本地回环接口
    local_addr.sin_port = htons(LOCAL_PORT);

    // 绑定端口和ip地址
    ret = bind(local_sockfd, (struct sockaddr *)&local_addr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // 监听套接字
    ret = listen(local_sockfd, LISTEN_QUE_LEN);
    if (ret == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "服务器启动了......\n");
    /*事件处理循环*/
    while (1)
    {
        // 接收客户端的连接请求
        socklen_t socklen = sizeof(struct sockaddr);
        client_sockfd = accept(local_sockfd, (struct sockaddr *)&client_addr, &socklen);

        // fork一个子进程来处理与客户端的交互,父进程用于维护本地套接字
        pid_t p = fork(), cp;
        if (p > 0) // 父进程
        {
            //如果监听出现意外，则关闭本地监听
            if (client_sockfd == -1)
            {
                perror("accept");
                close(local_sockfd);
                exit(EXIT_FAILURE);
            }

            if (strcasecmp(buffer, "exit") == 0)
            {
                const char *over = "收到了要关闭连接的消息，我会立马结束当前连接\n";
                write(client_sockfd, over, sizeof(over));
                close(client_sockfd);
                //杀死子进程
                kill(cp, SIGKILL);
            }
        }
        else if (p == 0) // 子进程
        {
            while (1)
            {
                // 处理来自客户端的求情
                // 读取客户端的请求
                cp = p;
                ret = read(client_sockfd, buffer, sizeof(buffer));
                if (ret == -1)
                    perror("read");
                printf("%s\n", buffer);

                // 给客户端发送响应
                size_t len = strlen(buffer);
                bzero(buffer, sizeof(buffer));
                sprintf(buffer, "%ld bytes altogether\n", len);
                ret = write(client_sockfd, buffer, strlen(buffer) + 1);
                if (ret == -1)
                    perror("write");

                if (strcasecmp(buffer, "exit") == 0)
                {
                    const char *over = "收到了要关闭连接的消息，我会立马结束当前连接\n";
                    write(client_sockfd, over, sizeof(over));
                    close(client_sockfd);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}
