#include <time.h>

#include <stdio.h>
#include <stdlib.h>

/*
    struct tm* gmtime(const time_t* timep)
    将time_t类型的时间进行分割，将其放入到struct tm结构体当中
    struct tm{
        int tm_sec; // 0-60
        int tm_min; // 0-59
        int tm_hour; // 0-23
        int tm_mday; // 1 - 31
        int tm_mon; // 0 - 11
        int tm_year; // 自1900以来的年数
        int tm_wday; // sun=0 mon=1 .. sat=6
        int tm_yday; //
        int tm_isdst
    }
*/
/* gmtime 获取的GMT时间，即格林威治时间*/
int main()
{
    time_t t = time(NULL);

    struct tm *tm = gmtime(&t);
    printf("tm_sec:%d\ntm_min:%d\ntm_hour:%d\ntm_mday:%d\ntm_mon:%d\ntm_year:%d\ntm_wday:%d\ntm_yday:%d\n",
           tm->tm_sec,
           tm->tm_min,
           tm->tm_hour,
           tm->tm_mday,
           tm->tm_mon,
           tm->tm_year+1900,
           tm->tm_wday,
           tm->tm_yday);
}

/*
    可重入版本:
    struct tm* gmtime_r(const time_t* timep, struct tm* tp);
*/

/**
 * 测试结果
 * 
 *  tm_sec:6
 *  tm_min:38
 *  tm_hour:8
 *  tm_mday:17
 *  tm_mon:5
 *  tm_year:2022
 *  tm_wday:5
 *  tm_yday:167
 * 
 */