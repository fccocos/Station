#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/*ctime的不可重入版本*/
/**
 * 函数原型：char* time_r(const time_t* timep, );
 */

int main()
{
    char *buf[40] = {0};
    char *buf2[40]={0};

    time_t t;
    time(&t);
    for (int i = 0; i < 5; i++)
    {
        ctime_r(&t, buf);
        printf("%s", buf);
        fflush(stdout);
        sleep(1);
    }
    ctime_r(&t, buf);
    printf("%s", buf);
    fflush(stdout);
}