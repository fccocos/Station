#include "Myshm.h"
#include <sys/shm.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

//创建共享内存
shm_t CreateShm(key_t key, size_t size)
{
   shm_t shmid = shmget(key, size, IPC_CREAT|0666);
   return shmid;
}

//获取共享内存的地址
void* getShmaddr(shm_t shmid, int shmflg)
{
   void* addr = shmat(shmid, 0, 0);
   if(addr == NULL)
   {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
   }

   return addr;
}

//断开进程与进程的连接
void deleteShm(const void* shmaddr)
{
    int ret = shmdt(shmaddr);
    if(ret == -1)
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

//在共享内容中读数据
void readInShm(void* shmaddr, void* buf)
{
    if(shmaddr != NULL)
    {
        memcpy(buf, shmaddr, strlen(shmaddr));
    }
}

//在共享内存中写数据
void writeInshm(void* shmaddr, void* buf)
{
    memcpy(shmaddr, buf, strlen(buf));
}
