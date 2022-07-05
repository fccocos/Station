#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "data_handle.h"



void handle_conn_server_rwv(int s)
{
    char buffer[30];
    ssize_t size = 0;
    struct iovec *v = (struct iovec*)malloc(3*sizeof(struct iovec));
    if(v==NULL) 
    {
        fprintf(stdout, "Not enough memory\n");
        return;
    }
    
    vs = v;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

   for(;;)
   {
        size =readv(s, v, 3);
        if(size == 0) return;
        else
        {
            for(int i=0; i<3; ++i)
            {
                fprinf(stdout, "%s", v[i].iov_base);
            }
        }
        sprintf(v[0].iov_base, "%d ", size);
        sprintf(v[1].iov_base, "bytes alt");
        sprintf(v[2].iov_base, "ogether\n");

        write(s, v, 3);

   }
}
void handle_conn_client_rwv(int s)
{
    char buffer[30];
    ssize_t size = 0;
    struct iovec *v = (struct iovec*)malloc(3*sizeof(struct iovec));
    if(v==NULL) 
    {
        fprintf(stdout, "Not enough memory\n");
        return;
    }
    
    vc = v;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

    for(;;)
    {
        size = read(0, buffer, sizeof(buffer));
        if(size>0)
        {
            writev(s,v,3);

            size = readv(s, v, 3);

            for(i = 0; i<3; i++)
            {
                write(stdout, v[i].iov_base, v[i].iov_len);
            }
        }
        
    }

}

void handle_conn_client_sr(int s)
{
    ssize_t size = 0;
    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    for(;;)
    {
        size = read(stdin, buffer, sizeof(buffer));
        if(size>0)
        {
            send(s, buffer, size, 0);
            size = recv(s, buffer, sizeof(buffer), 0);
            write(stdout, buffer, size);
        }

    }
}
void handle_conn_server_sr(int s)
{
    char buffer[1024];
    ssize_t size=0;
    for(;;)
    {
        size = recv(s, buffer, sizeof(buffer), 0);
        if(size == 0) return;
        else fprintf(stdout, "%s\n", buffer);
        sprintf(buffer, "%d bytes alotogether\n", size);
        send(s,buffer, strlen(buffer)+1, 0);
    }
}

void handle_conn_client_srmsg(int s)
{
    char buffer[30];
    ssize_t size = 0;
    struct iovec *v = (struct iovec*)malloc(3*sizeof(struct iovec));
    if(v==NULL) 
    {
        fprintf(stdout, "Not enough memory\n");
        return;
    }

    struct msghdr msg;

    msg.msg_name = NULL;
    msg.msg_control = NULL;
    msg.msg_controllen = 0;
    msg.msg_flags = 0;
    msg.msg_iov = v;
    msg.msg_iovlen = 3;
    msg.msg_namelen = 0;
    
    vs = v;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

    for(;;)
    {
        size = read(0, buffer, sizeof(buffer));
        if(size>0)
        {
            sendmsg(s, &msg, 0);

            size = recvmsg(s, &msg, 0);

            for(i = 0; i<3; i++)
            {
                write(stdout, v[i].iov_base, v[i].iov_len);
            }
        }
    }
}


void handle_conn_server_srmsg(int s)
{
    char buffer[30];
    ssize_t size = 0;
    struct iovec *v = (struct iovec*)malloc(3*sizeof(struct iovec));
    if(v==NULL) 
    {
        fprintf(stdout, "Not enough memory\n");
        return;
    }

    struct msghdr msg;

    msg.msg_name = NULL;
    msg.msg_control = NULL;
    msg.msg_controllen = 0;
    msg.msg_flags = 0;
    msg.msg_iov = v;
    msg.msg_iovlen = 3;
    msg.msg_namelen = 0;
    
    vs = v;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

    for(;;)
    {
        size = recvmsg(s, &smg, 0);
        if(size) return;
        else{
            for(int i=0; i<3; ++i)
            {
                sprintf(stdout, "%s", v[i].iov_base);
            }
        }

        sprintf(v[0].iov_base, "%d ", size);
        sprintf(v[1].iov_base, "bytes alt");
        sprintf(v[2].iov_base, "ogether\n");

        v[0].iov_len = strlen(v[0].iov_base);
        v[1].iov_len = strlen(v[1].iov_base);
        v[2].iov_len = strlen(v[2].iov_base);

        sendmsg(s, &msg, 0);
    }

}