#include "ldc12864.h"
#include "public.h"


int main(void)
{
    ldc12864_init();

    ldc12864_show_string(0,1, "Hello World!");
    ldc12864_show_string(0,2, "你好中国!");
    ldc12864_show_string(0,3, "欢迎使用51单片机");
    ldc12864_show_string(0,4, "好好学习天天向上");

    while(1);
}