#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // 从环境变量中获取地区的设置
    char* location = setlocale(LC_ALL, "");

    printf("location: %s\n", location);

}

// location: C.UTF-8
