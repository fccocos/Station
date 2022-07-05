#include "public.h"
#include "ds18b20.h"
#include "msg.h"

void main(void)
{
    u8 i = 0;
    long tempur = 0;
    long dotNumber = 0;
    u8 tempur_smg[8];

    ds18b20_init();
    while (1)
    {
        //每隔一段时间获取一次温度值
        i++;
        if (i % 50 == 0)
            tempur = ds18b20_get_tempurature() * 10000;
        if (tempur < 0)
        {
            tempur = -tempur;
            tempur_smg[0] = 0x40;
        }
        else
        {
            tempur_smg[0] = 0x00;
        }
        //获取百位
        tempur_smg[1] = gmsg_code[tempur / 1000000];
        //获取十位
        tempur_smg[2] = gmsg_code[tempur % 1000000 / 100000];
        //获取个位
        tempur_smg[3] = gmsg_code[tempur % 1000000 % 100000 / 10000] | 0x80;
        dotNumber = tempur % 1000000 % 100000 % 10000;
        //小数点后一位
        tempur_smg[4] = gmsg_code[dotNumber/1000];
        //小数点后第二位
        tempur_smg[5] = gmsg_code[dotNumber % 1000/100];
        //小数点后第三位
        tempur_smg[6] = gmsg_code[dotNumber% 1000%100/10];
        //小数点后第四位
        tempur_smg[7] = gmsg_code[dotNumber% 1000%100%10];
        msg_display(tempur_smg, 1);
    }
}
