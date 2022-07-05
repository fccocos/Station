#include <time.h>

#include <stdlib.h>
#include <stdio.h>

/*将分解时间转换为time_t*/
/*
mktime可能会修改参数timeptr所指向的结构体struct tm

tm.tm_idst = 0, 将当前时间作为标准时间
tm.tm_idst > 0, 将当前时间视作夏令时
tm.tm_idst < 0, 试图判定DTS在每年的这一事件是否生效
*/
int main(void)
{
    struct tm* tm = (struct tm*)malloc(sizeof(struct tm));
    tm->tm_sec = 10;
    tm->tm_min = 58;
    tm->tm_hour = 4;
    tm->tm_year = (2022-1900);
    tm->tm_mon = 6-1;
    tm->tm_mday = 17;
    tm->tm_wday = 5;
    tm->tm_yday = 167;
    tm->tm_isdst = -1;
    time_t tv = mktime(tm);
    printf("tv = %ld\n", tv);

    free(tm);
    tm = NULL;
}