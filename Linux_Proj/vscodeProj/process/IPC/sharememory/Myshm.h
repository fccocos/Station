#ifndef _MYSHM_H_
#define _MYSHM_H_

#include <sys/ipc.h>
#include <stddef.h>

typedef int shm_t;
typedef int status;
//创建共享内存
shm_t CreateShm(key_t key, size_t size);
//获取共享内存的地址
void* getShmaddr(shm_t shmid, int shmflg);

//断开进程与进程的连接
void deleteShm(const void* shmaddr);

//在共享内容中读数据
void readInShm(void* shmaddr, void* buf);
//在共享内存中写数据
void writeInshm(void* shmaddr, void* buf);


#endif // _MYSHM_H_