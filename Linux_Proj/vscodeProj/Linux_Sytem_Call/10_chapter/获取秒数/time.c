/**
 * @file time.c
 * @author gunfire (gunfirefc70@domain.com)
 * @brief  测试time系统调用函数
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 函数原型 ：time_t time(time_t *timep);
 * 
 * 函数参数：timep是一个输出参数，用于获取自Epoch时间以来的秒数
 * 
 * 函数功能：获取自Epoch时间以来的秒数
 * 
 * 函数特性：返回值和参数都可以返回自Epoch时间以来的秒数
 * 
 * 函数特殊说明：一般使用该函数都不用传递参数，设置为NULL即可
 * 
 */

#include <time.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    time_t ret, time_contain;
    ret = time(&time_contain);
    if(ret == -1)
    {
        perror("time");
        return -1;
    }
    if(ret == time_contain)
    {
        printf("ret == time_contain: %ld\n", ret);
    }else
    {
        printf("ret != time_contain\n");
    }
    return 0;
}

/*
测试结果：
    ret == time_contain: 1655452199
*/