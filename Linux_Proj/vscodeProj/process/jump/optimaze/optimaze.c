#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

static void
doJump(int nvar, int rvar, int vvar)
{
    printf("Inside doJump: nvar=%d, rvar=%d, vvar=%d\n", nvar, rvar, vvar);
    longjmp(env, 1);
}

int main(int argc, char* argv[])
{
    int nvar;
    register int rvar;//寄存器变量
    volatile int vvar;//易变变量，防止编译器优化

    nvar=111;
    rvar=222;
    vvar=333;

    if(setjmp(env)==0)
    {
        nvar = 777;
        rvar = 888;
        vvar = 999;
        doJump(nvar, rvar, vvar);
    }else{
        printf("after longJump(): nvar=%d, rvar=%d, vvar=%d\n", nvar, rvar, vvar);
    }
    exit(EXIT_SUCCESS);
}

/**
 * 不优化编译，程序执行结果
 * Inside doJump: nvar=777, rvar=888, vvar=999
 * after longJump(): nvar=777, rvar=888, vvar=999
 */
/**
 * 优化编译后，程序执行结果
 * Inside doJump: nvar=777, rvar=888, vvar=999
 * after longJump(): nvar=111, rvar=222, vvar=999
*/