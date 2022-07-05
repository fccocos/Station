## 共享内存的本质

多个进程映射到同一段物理内存，即使他们的逻辑地址不同

## 操作共享内存的函数

1. `int shmget(key_t key, size_t size, int shmflg)` 用于创建或打开一个共享内存。它与消息队列，信号量类似。`shmflg`可以为`IPC_CREAT`和`IPC_EXCL`
2. `void* shmat(int shmid, const void *shmaddr,int shmflg)` 获取一个共享内存的地址，当得到地址后，可以像操作通用内存一样操作共享内存。
   
   - `shmid` 共享内存的ID，通过`shmid`所获得
   - `shmaddr` 指定共享内存的地址.一般情况下，设置为0，表示由系统自动去查找一个未映射的区域。
   - `shmflg` 为共享内存指定行为方式。例如，可读可写。可以将`SHM_RND`与其他标志进行OR操作，这样可以让传递的地址页对齐。`SHM_READONLY`与其他标志进行OR操作，那么共享内存只读

3. `int shmdt(const void* shmaddr)` 断开某一进程和共享内容的映射。在成功的断开与共享内存的映射后，内核中的`shmid_ds`中的成员`shm_nattch`的值将会减1，如果这个成员的值为0，则内核才会真正的删除这一段共享内存。
4. `int shmctl(int shmid, int cmd,struct shmid_ds* buf)` 对共享内存属性或状态的获取或修改。其类似于`ioctl`函数


## 操作共享内存用到的数据结构

```c
struct shmid_ds{
    struct ipc_perm shm_perm;
    size_t shm_segsz;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
    pid_t shm_cpid;
    pid_t shm_lpid;
    shmatt_t shm_nattch;
    //......
    }

```