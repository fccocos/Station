## pthread的基本函数

1. `int pthread_create(pthread_t *thread, pthread_attr_t *attr, void* (*start_routine)(void*), void* arg)` 创建线程
    - `thread`为一个`pthread_t`类型的指针，用于返回创建的线程的线程号
    - `atrr`为一个`pthread_atrr_t`类型的指针，用于修改或返回线程的属性
    - `void* (*start_routine)(void*)` 为一个带有一个参数的函数指针，用于加载当前创建的线程的运行程序
    - `arg`为一个空指针，用于存放`start_routine`的参数，如果没有则设为NULL

2. `int pthread_join __p((pthread_t __th, void **__thread_return))` 等待一个线程结束，回收该线程的资源
   - `__th`线程号
   - `__thread_return` 线程返回值，为一个输出参数

3. `void pthread_exit __P((void* __retval)) __attribute__((__noreturn__));`
   - `retval`函数的返回值，这个值可以被`pthread_join`函数捕获，通过`_thread_return`参数来获得此值
  

## pthread的常用数据结构和数据类型

- `pthread_t`
-  `pthread_atrr_t`
-  `pthread_mutex_t`
-  `struct sched_param`

## 线程属性设置
### 线程属性结构
```c
typedef struct __pthread_attr_s
{
    int __detachstate;//线程终止状态
    int __schedpolicy;//调度策略
    struct __sched_param __schedparam;//调度参数
    int __inheritshed;//继承调度
    int __scope;//调度分配域
    size_t guardsize;//线程栈末尾的警戒缓冲区大小
    int starckaddr_set;
    void* statckaddr; //线程栈的位置
    size_t statcksize; //线程栈的大小
}pthread_attr_t;
```
线程的属性设置不能直接通过为线程属性赋值来实现，需要通过调用相对的函数才能做。

### 线程的优先级

- `int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);` 设置线程的优先级
- `int pthread_attr_getschedparam(pthread_attr_t *attr, struct sched_param *param)` 获取线程的优先级

### 线程的调度分配域

- `int pthread_attr_setscope(pthread_attr_t *attr, int scope)` 设置线程的调度分配域
- `int thread_attr_getscope(const pthread_attr_t *attr, int* scope)` 获取线程的调度分配域
- 其中`scope`可以为`PTHREAD_SCOPE_SYSTEM`或`PTHREAD_SCOPE_PROCESS`
- `PTHREAD_SCOPE_SYSTEM` 该线程与系统中位于同一调度分配域中(一组一个或多个处理器)的所有进程中的所有其他线程竞争资源。`PTHREAD_SCOPE_SYSTEM`线程根据它们的调度策略和优先级相对于其他线程进行调度。
- `PTHREAD_SCOPE_PROCESS` 该线程与同样使用PTHREAD_SCOPE_PROCESS竞争作用域创建的同一进程中的所有其他线程竞争资源。根据PTHREAD_SCOPE_PROCESS线程的调度策略和优先级，它们相对于进程中的其他线程进行调度。POSIX.1没有指定这些线程如何与系统上其他进程中的其他线程进行竞争，或者如何与使用PTHREAD_SCOPE_SYSTEM竞争作用域创建的同一进程中的其他线程进行竞争。
- POSIX.1要求实现至少支持这些争用中的一种范围。Linux支持PTHREAD_SCOPE_SYSTEM，但不支持PTHREAD_SCOPE_PROCESS。
- 在支持多个争用范围的系统上，为了让`pthread_attr_setscope()`在调用`pthread_create`时设置的参数生效，调用者必须使用`pthread_attr_setinheritsched`来设置`PTHREAD_EXPLICIT_SCHED`属性对象attr的继承调度器属性。

### 线程的分离状态

线程分离状态决定了线程的终止方式

- 如果线程是非分离的，则需要在`pthread_join`调用后，线程才能够算终止，并释放相应的资源，
- 如果线程是分离的，当线程运行结束后立马结束，并立刻释放资源
- `int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)` 设置线程的分离状态
- `int phtread_attr_getdetachstate(const pthread_attr_t *attr, int detachstate)` 获取线程的分离状态
- 参数`detachstate`可以为`PTHREAD_CREATE_DETACHED`和`PTHREAD_CREATE_JOINABLE`

## 线程互斥

- `int pthread_mutex_lock(pthread_mutex_t *mutex);`
- `int pthread_mutex_trylock(pthread_mutex_t *mutex);`
- `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
- `pthread_mutex_destroy(pthread_mutex_t *mutex);`

## 线程的信号量
- `int sem_init __p((sem_t* __sem, int __pshared, unsigned int __value))`
- `int sem_post(sem_t *__sem)`
- `int sem_wait(sem_t* __sem)`
- `int sem_destroy(sem_t* __sem)` 

## __P

### __P是什么
__P是系统定义的宏

### 为什么定义__P

ANSI C之前的老编译器不支持函数原型定义，使用__P宏为ANSI和非ANSI的编译器提供了一种可移植的方案。

### __P的定义

```c
#if defined(__STDC__)||defined(__GUNC__)
#define __P(x) x
#else
#define __P(x) ()
#endif
```

例如上面的`void pthread_join _P((pthread_t __th,void **__thread_return))`函数在ANSI C的编译器中会编译成为`void pthread_join(pthread_t __th,void **__thread_return)`,而在非ANSI C的编译器中会编译成为`void pthread_join()`

### __P的作用

1. 增强编译器的兼容性
2. 增加代码的可移植性

