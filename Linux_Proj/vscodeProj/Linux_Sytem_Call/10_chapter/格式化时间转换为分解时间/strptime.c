#define _XOPEN_SOURCE
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define SBUF_SIZE 1024

int main(int argc, char *argv[])
{
    struct tm *tm = (struct tm *)malloc(sizeof(struct tm));
    char sbuf[SBUF_SIZE];
    char *ftime = "%Y年%m月%d日 %H:%M:%S\n";
    char *vtime = "2022年06月17日 17:55:12\n";
    tm->tm_isdst = -1;
    /*需要注意的是vtime和ftime的格式要一致*/
    strptime(vtime, ftime, tm);

    printf("tm_sec:%d\ntm_min:%d\ntm_hour:%d\ntm_mday:%d\ntm_mon:%d\ntm_year:%d\ntm_wday:%d\ntm_yday:%d\n",
           tm->tm_sec,
           tm->tm_min,
           tm->tm_hour,
           tm->tm_mday,
           tm->tm_mon,
           tm->tm_year + 1900,
           tm->tm_wday,
           tm->tm_yday);

    free(tm);
    tm = NULL;
}
/*
tm_sec:12
tm_min:55
tm_hour:17
tm_mday:17
tm_mon:5
tm_year:2022
tm_wday:5
tm_yday:167
*/