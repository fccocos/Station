#include "mysem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//创建信号
int CreateSem(key_t key, int value)
{
    union semun sem;
    sem.val = value;
    sem_t semid = semget(key, 1, IPC_CREAT|0666);
    if(semid == -1)
    {
        perror("msg_err");
        return semid;
    }
    semctl(semid, 0, SETVAL, sem);
    
    return semid;
}

//信号量的P操作
void Sem_P(sem_t semid)
{
   struct sembuf sops = {0,+1,IPC_NOWAIT};

   semop(semid, &sops, 1);
}
//信号量的V操作
void Sem_V(sem_t semid)
{
    struct sembuf sops = {0,-1,IPC_NOWAIT};
    semop(semid, &sops, 1);
}

//设置信号量的值
void SetvalueSem(sem_t semid, int value)
{
    union semun sem;
    sem.val = value;
    semctl(semid, 0, SETVAL, sem);
}

//获取信号量的值
int GetvalueSem(sem_t semid)
{
   union semun sem;
   return semctl(semid, 0,GETVAL, sem);
}

// 销毁信号
void DestorySem(sem_t semid)
{
   union semun sem;
   sem.val = 0;//信号量值初始化
   semctl(semid, 0, IPC_RMID, sem);
}