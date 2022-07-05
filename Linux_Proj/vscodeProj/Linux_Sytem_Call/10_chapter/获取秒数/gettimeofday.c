
/**
 * @file gettimeofday.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief 测试gettimeofday系统调用
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 函数功能： 获取日历时间，即Epoch(通用协调时间) UTC GMT
 * 从1970-1-1 00:00:00 到当前时间的秒数
 * 
 * 函数原型： int getimeofday(struct timeval *tv, struct timezone *tz);
 * 需要注意的是：tz参数已被废弃，此参数只需填写NULL即可
 * 
 * struct timeval结构体
 * struct timeval{
 *  time_t tv_sec; // 从1970-1-1 00:00:00 到当前时间的秒数
 *  suseconds_t tv_usec; // 微妙
 * };
 */

#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
int main()
{

    struct timeval t;
    int ret = gettimeofday(&t, NULL);
    if(ret == -1)
    {
        perror("gettimeofday");
        return -1;
    }
    printf("times_s=%ld\ntimes_us=%ld\n", t.tv_sec, t.tv_usec);

    return 0;

}

/*
测试结果：
    times_s=1655451554
    times_us=895186
*/