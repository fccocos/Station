#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 函数原型: char* ctime(struct time_t *timep);
 * 
 * 函数功能： 将获取到的秒数格式化输出 
 * 
 * Week Month Ddy hh:mm:ss yyyy\n\0
 * 
 * 函数说明： 此函数不可重入
 */

/*格式化打印日历时间*/
int main()
{
    time_t t = time(NULL);
    char * timestr = ctime(&t);
    printf("before the second call, timestr: %s", timestr);
    char * timestr1 = ctime(&t);

    int len = strlen(timestr);
    printf("time string's len=%d\n", len);
    printf("timestr: %s", timestr);
    printf("timestr1: %s\n",timestr1);

}

/**
 * result:
 *      before the second call, timestr: Fri Jun 17 16:10:48 2022
        time string's len=25
        timestr: Fri Jun 17 16:10:48 2022
        timestr1: Fri Jun 17 16:10:48 2022
 * 
 */