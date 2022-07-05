#include <sys/times.h>

#include <stdio.h>

int main()
{
    /*
        struct tms{
            clock_t tms_utime; // 用户CPU时间
            clock_t tms_stime; // 系统CPU 
            clock_t tms_cutime;// 当前进程所有子进程的等待用户CPU时间
            clock_t tims_cstime;// 当前进程所有子进程的等待系统CPU时间
        }
    */

   struct tms* tms;
   
   times(tms);

   printf("%ld, %ld\n", tms->tms_utime, tms->tms_utime);


}