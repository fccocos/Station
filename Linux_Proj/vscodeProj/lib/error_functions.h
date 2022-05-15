#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H
/**
 * @brief 在标准错误设备上打印消息，打印出与当前errno值相对应的错误文本，并格式化输出
 * 
 * @param format 
 * @param ... 
 */
void errMsg(const char* format, ...);

#ifdef __GNUC__
//这个宏用于阻止gcc -Wall 报告 ”控制抵达非空函数的末尾“的警告
//如果我们使用下面的函数去终结man()或者一些其他的非空函数
#define NORETURN __attribute__((__noreturn__))
#else
#define NOERTURN
#endif /*gnuc*/

/**
 * @brief 在标准错误设备上打印消息，打印出与当前errno值相对应的错误文本,
 * 并以exit()退出或将环境变量EF_DUMPCORE定义为非空字符串调用abort()退出于此同时
 * 生成核心转储(core dump)文件，共调试器调试用
 * 
 * @param format 
 * @param ... 
 */
void errExit(const char* format, ...) NORETURN;

/**
 * @brief 在标准错误设备上打印消息，打印出与当前errno值相对应的错误文本,
 * 但在打印错误消息之前，err_exit()不会刷新标准输出，err_exit()终止进程使用的是
 * _exit()，它略去了对stdio缓冲区的刷新以及退出处理程序(exit handler)的调用
 * 
 * @param format 
 * @param ... 
 */
void err_exit(const char* format, ...) NORETURN;

void errExitEN(int errnum, const char* format, ...) NORETURN;

void fatal(const char* format, ...) NORETURN;

void usageErr(const char* format, ...) NORETURN;

void cmdLineErr(const char* format, ...) NORETURN;

#endif