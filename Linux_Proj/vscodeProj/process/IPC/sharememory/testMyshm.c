#include "mysem.h"
#include "Myshm.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
     char write_buf[80] = "欢迎来到对抗路！！！";
     char read_buf[80];
     char *shmaddr, *shmaddrc;

     memset(read_buf, 0, sizeof(read_buf));
     const char *path = "./ipc/sem";
     key_t key = ftok(path, 'a');
     if (key == -1)
     {
          perror("ftok");
          exit(EXIT_FAILURE);
     }
     //创建一个信号量
     sem_t semid = CreateSem(key, 10);
     if (semid == -1)
     {
          perror("CreateSem");
          exit(EXIT_FAILURE);
     }

     // create a shm
     shm_t shmid = CreateShm(key, 1024);
     if (semid == -1)
     {
          perror("CreateShm");
          exit(EXIT_FAILURE);
     }

     // fork进程
     pid_t pid = fork();
     if (pid > 0) //父进程
     {
          //获取shm addr
          shmaddr = (char *)getShmaddr(shmid, 0);
          //在shm中写数据
          writeInshm(shmaddr, write_buf);
          //等待10s，让另一个进程来读数据
          sleep(10);
          // P操作
          Sem_P(semid);
          deleteShm(shmaddr); // 将当前进程和shm的链接断开

          DestorySem(semid); // 销毁信号量
     }
     else if (pid == 0) //子进程
     {
          shmaddrc = (char *)getShmaddr(shmid, 0);
          //在shm中读数据
          readInShm(shmaddrc, read_buf);
          Sem_V(semid);
          printf("共享内存中的值为: %s", read_buf);

          deleteShm(shmaddrc);
     }
     else
     {
          perror("fork");
          exit(EXIT_FAILURE);
     }

     return 0;
}
