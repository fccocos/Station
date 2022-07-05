#include "smg.h"

uchar smg_code[SMG_CODE_SIZE]={
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, //0-7
    0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71  //8-F
    };

void smg_display(uchar buf[], uchar pos)
{
    uchar tmp_pos = pos-1;
    int i;
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
        SMG_SLECT_LINE = buf[i-tmp_pos];
        delay_10us(10);
        SMG_SLECT_LINE =0x00;//消音
    }
}