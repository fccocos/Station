# exec函数族
## exec函数族的作用

用一个可执行文件来替换调用进程的内容，即在原有的进程中运行这个可执行文件

## exec函数族原型

```c++
#include <unistd.h>
extern char** eviron;//执行程序的环境变量列表
int execl(const char* path, const char* arg, ...);
int execlp(const char* file, const char* arg, ...);
int execle(const char* path, const char* arg, ..., char* const envp[]);
int execv(const char* path, char* const argv[]);
int execvp(const char* path, const char* argv[]);
```
## exec函数族的返回值

exec函数族，调用成功后，并不会返回，因为通过exec函数族进入的执行程序占用了原来进程的系统资源，如进程虚拟空间、时间片等。调用失败返回-1和设置errno

## exec函数族的应用场景

在调用fork函数后，使用exec函数族，此时系统不会进行系统复制，而是用exec函数族指定的文件来覆盖原有进程，这就是Linux系统的"写时复制"。

写时复制：只有造成系统内容改变的时候才会进行进程的真正更新

## execve的简单使用

```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char* args[] = {"/bin/ls", NULL};
    printf("系统分配的进程号为%ld", getpid());
    if(execve("/bin/ls",args,NULL)<0)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}
```
