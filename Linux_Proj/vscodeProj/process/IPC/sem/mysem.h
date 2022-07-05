#ifndef _MYSEM_H_
#define _MYSEM_H_
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef unsigned short ushort;
typedef int sem_t;

union semun{
    int val;
    struct semun_ds* buf;
    ushort* arry;
};

// struct sembuf{
//   ushort sem_num;//信号量编号
//   short sem_op; //信号量操作
//   short sem_flg;//信号量操作标志  
// };

//创建信号
int CreateSem(int key, int value);

//信号量的P操作
void Sem_P(sem_t semid);
//信号量的V操作
void Sem_V(sem_t semid);

//设置信号量的值
void SetvalueSem(sem_t semid, int value);

//获取信号量的值
int GetvalueSem(sem_t semid);

// 销毁信号
void DestorySem(sem_t semid);   

#endif //_MYSEM_H_