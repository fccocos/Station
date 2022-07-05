## 信号量数据结构

信号联合体

```c
union semun{
    int val;
    struct semun_ds* buf;
    unsigned short *array;
    struct seminfo *__buf;
};
```
以后使用信号量之前都需要自己定义类似于上面的联合体，即你定义的信号量联合体中的数据成员必须是上述联合中成员的一个或多个的组合。

信号缓冲结构体

```c
struct sembuf{
    unsigned short sem_num; //用户要处理的信号量编号
    short sem_op; // 信号量的操作(正，负或零)
    short sem_flg; // 信号量的操纵标志。如果信号量操作sem_op为负，则从信号量中减去值；如果信号量操作sem_op为正，则从信号量中加上值；如果为0，将进程设置为睡眠状态，直到信号量为0为止。
};
```

## 操作信号量的常用函数

1. `int semget(key_t key, int nsems, int semflg)`
  
   - `nsems`指定信号量集合中创建信号量的数目
   - `semflg`为打开或创建信号量集合的标志.`IPC_CREAT` 和`IPC_EXCL`

使用`semget()`函数实现一个创建信号量的封装

```c
typedef int sem_t;
union semun{
  int val;             // 一个信号量的值
  struct semid_t* buf; //一个信号量id数据结构的指针
  unsigned int* array; //所有信号量的值
};

sem_t CreateSem(int key, int value)
{
    union semun sem;
    sem_t id;
    sem.val = value;

    sem = semget(key, 0, IPC_CREAT|IPC_EXCL);
    if(sem==-1)
    {
        perror("semget_err");
        return sem;
    }
    semctl(semid,0,SETVAL, sem);
    return sem;
}

```

2. `int semop(int semid, struct sembuf *sops, unsigned short nsops)`

   - `sops`为`struct sembuf`结构体指针，用于指向将要在信号量集合上执行操作的一个数组
   - `nsops`为该数组中操作的个数。

用`semop`函数实现进程的P,V原语

```c
int sem_P(int semid)
{
    struct sembuf sops={0,+1, IPC_NOWAIT};
    return semop(semid, &sops, 1);
}

int sem_V(int semid)
{
    struct sembuf sops={0,-1,IPC_NOWAIT};
    return semop(semid, &sops, 1);
}
```

3. `int semctl(int semid, int semnum, int cmd, ...)`

   - `semnum`为要操作的信号量的编号
   - `cmd`为对信号量的控制方式
     -  `IPC_STAT`
     -  `IPC_SET`
     -  `IPC_RMID`
     -  `GETALL` 获取集合中所有信号的值，并将其存放到`struct semun`的成员变量`array`中
     -  `GETNCNT`  获取当前正在等待资源的进程数目
     -  `GETPID` 获取最后一次执行`semop`操作的进程的PID
     -  `GETVAL` 返回集合中某个信号量的值
     -  `GETZCNT` 获取正在等待资源利用率到达100%的进程数量
     -  `SETALL` 将集合中所有信号量的值都设为array中所对应的值
     -  `SETVAL` 将集合中某个信号量的值设置为val所指定的值。
  
设置某个信号量的值

```c
void SetvalueSem(sem_t semid, int value)
{
    union semun sem;
    sem.val = value;
    semctl(semid, SETVAL, sem);
}
```

获取某个信号量的值

```c
int GetvalueSem(sem_t semid)
{
    union semun sem;
    sem.val = 0;
    return semctl(semid,GETVAL,sem);
}
```

销毁信号量

```c
void DestorySem(sem_t semid)
{
    union semun sem;
    sem.val = 0;
    semctl(semid, IPC_RMID, sem);
}
```