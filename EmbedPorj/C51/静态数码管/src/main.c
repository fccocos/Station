#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define SMG_A_DP_PORT P0

//静态数码管的控制端口P0

// 数码管显示数字的字码0-F
u8 gsmg_code[17]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71};

void sleep(u16 timeout)
{
    while(timeout--);
}

int main()
{
    int i;
    while(1)
    {
        for(i=0;i<17; ++i)
        {
            SMG_A_DP_PORT = gsmg_code[i];
            sleep(300000);
            SMG_A_DP_PORT = 0x00;
        }
    }
}
