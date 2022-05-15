#include <stdarg.h>
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc"

#ifdef __GNUC__
__attribute__((__noreturn__))
#endif
/**
 * @brief  用于退出程序
 *
 * @param useExit3 为一个Boolean类型的值，用于设置是以exit()方式退出还是以_exit()方式退出
 */
static void
terminate(Boolean useExit3)
{
    char *s;
    //获取核心转储的环境变量，如果存在说明有错误，中断程序
    s = getenv("EF_DUMPCORE");
    if (s != NULL && *s != '\0')
        abort();
    else if (useExit3)
        exit(EXIT_FAILURE);
    else
        _exit(EXIT_FAILURE);
}

/**
 * @brief 格式化输出错误
 * 
 * @param useErr 用于设置是系统调用错误输出还是库函数调用错误输出
 * @param err 指代errno
 * @param flushStdout Boolen类型，用于设置是否对标准输出进行刷新
 * @param format 
 * @param ap 一个列表，用于存放命令行参数
 */
static void
outputError(Boolean useErr, int err, Boolean flushStdout,
            const char *format, va_list ap)
{
#define BUF_SIZE 500

    char buf[BUF_SIZE], userMsg[BUF_SIZE], errText[BUF_SIZE];

    vsnprintf(userMsg, BUF_SIZE, format, ap);

    if (useErr)
        snprintf(errText, BUF_SIZE, " [%s %s]",
                 (err > 0 && err <= MAX_ENAME) ? ename[err] : "?UNKNOWN", strerror(err));
    else
        snprintf(errText,BUF_SIZE,":");

        snprintf(buf, BUF_SIZE, "ERROR%s %s\n", errText, userMsg);

    if (flushStdout)
        fflush(stdout);
    fputs(buf, stderr);
    fflush(stderr);
}

void errMsg(const char *format, ...)
{
    va_list argList;
    int savedErrno;

    savedErrno = errno;

    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList);
    va_end(argList);

    errno = savedErrno;
}

/**
 * @brief 在标准错误设备上打印消息，打印出与当前errno值相对应的错误文本,
 * 但在打印错误消息之前，err_exit()不会刷新标准输出，err_exit()终止进程使用的是
 * _exit()，它略去了对stdio缓冲区的刷新以及退出处理程序(exit handler)的调用
 *
 * @param format
 * @param ...
 */
void errExit(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList);
    va_end(argList);

    terminate(TRUE);
}

/**
 * @brief 在标准错误设备上打印消息，打印出与当前errno值相对应的错误文本,
 * 并以exit()退出或将环境变量EF_DUMPCORE定义为非空字符串调用abort()退出于此同时
 * 生成核心转储(core dump)文件，共调试器调试用
 *
 * @param format
 * @param ...
 */
void err_exit(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errno, FALSE, format, argList);
    va_end(argList);

    terminate(FALSE);
}

void errExitEN(int errnum, const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errnum, TRUE, format, argList);
    va_end(argList);

    terminate(TRUE);
}

/**
 * @brief 用于诊断一般性的错误，
 * 其中包含没设置errno的库函数错误，其用法于printf相同，
 * 在标准错误上打印格式化输出，以_exit()终止程序
 *
 * @param format
 * @param ...
 */
void fatal(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(FALSE, 0, TRUE, format, argList);
    va_end(argList);

    terminate(TRUE);
}

/**
 * @brief 用于诊断命令行参数方面的错误。
 *
 * 其参数列表的风格与printf()相同，并在标准错误上打印字符串"Usage:",
 * 随之格式化输出，然后调用 exit()终止程序
 *
 * @param format
 * @param ...
 */
void usageErr(const char *format, ...)
{
    va_list argList;

    fflush(stdout);

    fprintf(stderr, "Usage: ");
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);

    fflush(stderr);
    exit(EXIT_FAILURE);
}

/**
 * @brief 用于诊断命令行参数方面的错误。
 *
 * 它与usageErr()类似，但其错误诊断是针对于特定程序的命令行参数
 *
 * @param format
 * @param ...
 */
void cmdLineErr(const char *format, ...)
{
    va_list argList;

    fflush(stdout);

    fprintf(stderr, "Command-line usage error: ");
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);

    fflush(stderr);
    exit(EXIT_FAILURE);
}
