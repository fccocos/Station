#include <time.h>

#include <stdlib.h>
#include <stdio.h>

/*将分解时间转换为格式化时间

char* asctime(struct tm* timeptr);

asctime是无法识别timeptr是本地时间还是GMT时间

想要获取本地时间，就必须先用localtime将time_t转换为struct tm
想要获取GMT时间， 就必须先用gmtime将time_t 转换为struct tm
*/

int main()
{
    time_t tv = time(NULL);
    struct tm* tm = localtime(&tv);
    char* timeformat = asctime(tm);
    printf("本地时间: %s\n", timeformat);
    tm = gmtime(&tv);
    timeformat = asctime(tm);
    printf("UTC时间: %s\n", timeformat);
}

/*asctime的可重入版*/
/*char* asctime(struct tm* timeptr, char* buf)*/

/*
本地时间: Fri Jun 17 17:24:21 2022

UTC时间: Fri Jun 17 09:24:21 2022
*/