#include <setjmp.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

static void
f2()
{
    longjmp(env,2);
}

static void
f1(int argc)
{
    if(argc==1)
        longjmp(env,1);
    f2();
}

int main(int argc, char* argv[])
{
    switch(setjmp(env))
    {
        case 0:
            f1(argc);
            break;
        case 1:
            fprintf(stdout,"从函数f1()跳回\n");
            break;
        case 2:
            fprintf(stdout,"从函数f2()跳回\n");
            break;
    }
}