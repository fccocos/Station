#include "smg.h"

u8 gsmg_code[GSMG_CODE_SIZE]={
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

void display_smg(u8 dat[], u8 pos)
{
    u8 tmp_pos = pos -1;
    u8 i;
    for(i=tmp_pos; i<8; i++)
    {
        switch(i)
        {
            case 0: LSC=1;LSB=1;LSA=1;break;
            case 1: LSC=1;LSB=1;LSA=0;break;
            case 2: LSC=1;LSB=0;LSA=1;break;
            case 3: LSC=1;LSB=0;LSA=0;break;
            case 4: LSC=0;LSB=1;LSA=1;break;
            case 5: LSC=0;LSB=1;LSA=0;break;
            case 6: LSC=0;LSB=0;LSA=1;break;
            case 7: LSC=0;LSB=0;LSA=0;break;
        }
        SMG_A_DL_PORT = dat[i-tmp_pos];
        delay_ms(1);// 延时1ms，使数码管稳定显示
        SMG_A_DL_PORT = 0x00;//消音
    }
}
/*
  a
f|g_|b
e|  |c .h
  d  
        h g f e   d c b a
0       0 0 1 1   1 1 1 1
1       
*/