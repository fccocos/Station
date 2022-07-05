#include <time.h>

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(void)
{
    char buf[BUF_SIZE];
    time_t tv;
    struct tm* tm;

    tv = time(NULL);
    tm = localtime(&tv);
    strftime(buf, BUF_SIZE,"时区:%Z %Y年%m月%d日 %H:%M:%S\n",tm);
    printf("%s", buf);

}

/*时区:CST 2022年06月17日 17:41:56*/