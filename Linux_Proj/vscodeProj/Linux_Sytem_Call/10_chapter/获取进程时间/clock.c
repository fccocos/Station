#include <stdio.h>

#include <time.h>

int main(void)
{
    clock_t t = clock();

    printf("%ld\n",t);
}