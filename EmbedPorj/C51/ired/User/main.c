#include "public.h"
#include "smg.h"
#include "ired.h"

void main(void)
{
    u8 ired_buf[3];
    ired_init();
    for(;;)
    {
        ired_buf[0] = gsmg_code[gired_data[2]/16]; // 控制码的第四位转换为数码管数据
        ired_buf[1] = gsmg_code[gired_data[2]%16]; // 控制码的高四位转换为数据管数据显示
        ired_buf[2] = 0x76;  // 数码管上显示H

        smg_display(ired_buf, 6);
    }
}