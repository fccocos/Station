#include "ldc12864.h"

static void ladc12864_write_cmd(u8 cmd);

static void ladc12864_write_data(u8 dat);


void ldc12864_init(void)
{
    ldc12864_PSB = 1; // 选择8位并行
    ladc12864_write_cmd(0x30); // 数据总线8位
    ladc12864_write_cmd(0x0c); // 整体显示关闭，游标显示关闭，游标正常显示
    ladc12864_write_cmd(0x06); // 写入新的数据后游标右移，显示屏不移动
    ladc12864_write_cmd(0x01); // 清屏 
}

void ldc12864_show_string(u8 x, u8 y, u8 *str)
{
    if(y<=0) y=0;
    if(y>3) y=3;

    x &= 0x0f; // 限制x, y 不能大于显示范围
    switch (y)
    {
    case 0: x |= 0x80; break;
    case 1: x |= 0x90; break;
    case 2: x |= 0x88; break;
    case 3: x |= 0x98; break;
    }
    ladc12864_write_cmd(x);
    while(*str!='\0')
    {
        ladc12864_write_data(*str);
        str++;
    }
}

static void ladc12864_write_cmd(u8 cmd)
{
    ldc12864_RS = 0;
    ldc12864_RW = 0;
    LDC12864_DATAPORT = cmd;

    delay_ms(1);
    ldc12864_E = 1; // 开始写入命令

    delay_ms(1);
    ldc12864_E = 0; // 写命令结束

}

static void ladc12864_write_data(u8 dat)
{
    ldc12864_RS = 1;
    ldc12864_RW = 0;
    LDC12864_DATAPORT = dat;

        delay_ms(1);
    ldc12864_E = 1; // 开始写入数据

    delay_ms(1);
    ldc12864_E = 0; // 写数据结束
}