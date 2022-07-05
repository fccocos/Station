#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct timeval tv;
    tv.tv_sec = 1000000;
    tv.tv_usec = 86339;

    settimeofday(&tv, NULL);

    struct timeval tv1;

    gettimeofday(&tv, NULL);

    printf("sec = %ld; usec = %ld\n", tv1.tv_sec, tv1.tv_usec);
    
}