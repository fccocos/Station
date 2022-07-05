#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;
typedef char s8;

//定义按键
/*第四列按键*/
#define S16 0xEE
#define S12 0xDE
#define S8  0xBE
#define S4  0x7E

/*第三列按键*/
#define S15 0xED
#define S11 0xDD
#define S7  0xBD
#define S3  0x7D

/*第二列按键*/
#define S14 0xEB
#define S10 0xDB
#define S6  0xBB
#define S2  0x7B

/*第一列按键*/
#define S13 0xE7
#define S9  0xD7
#define S5  0xB7
#define S1  0x77

//定义数码管的段选端口P0
#define  DITIGALTUBE_ZERO_PORT P0

//定义数码管未选线
sbit A2 = P2^4;
sbit A1 = P2^3;
sbit A0 = P2^2;

//定义矩阵按键端口P1
#define MATRIX_KEYS P1



void delay_10ms(u16 timecout)
{
    while (timecout--);
}

/*使用行列扫描法*/
s8 matrix_keys_ranks_scan()
{
    s8 value_index=-1;
    //将第4根列线为低电平1111 1110 0xFE
    MATRIX_KEYS = 0xFE;
    if(MATRIX_KEYS!=0xFE)//判断第一列是否有按键按下
    {
        delay_10ms(1000);//消抖
        
        switch(MATRIX_KEYS)
        {
            case S16:
                value_index = 15;
                break;
            case S12:
                value_index = 11;
                break;
            case S8:
                value_index = 7;
                break;
            case S4:
                value_index = 3;
                break;
        }
    }//0XFE

    //将第三根列线为低电平1111 1101 0xFD
    MATRIX_KEYS = 0xFD;
    if(MATRIX_KEYS!=0xFD)//判断第一列是否有按键按下
    {
        delay_10ms(1000);//消抖
        
        switch(MATRIX_KEYS)
        {
            case S15:
                value_index = 14;
                break;
            case S11:
                value_index = 10;
                break;
            case S7:
                value_index = 6;
                break;
            case S3:
                value_index = 2;
                break;
        }
    }//0XFD

    //将第二根列线为低电平1111 1011 0xFB
    MATRIX_KEYS = 0xFB;
    if(MATRIX_KEYS!=0xFB)//判断第一列是否有按键按下
    {
        delay_10ms(1000);//消抖
        
        switch(MATRIX_KEYS)
        {
            case S14:
                value_index = 13;
                break;
            case S10:
                value_index = 9;
                break;
            case S6:
                value_index = 5;
                break;
            case S2:
                value_index = 1;
                break;
        }
    }//0XFB

    //将第一根列线为低电平1111 0111 0xF7
    MATRIX_KEYS = 0xF7;
    if(MATRIX_KEYS!=0xF7)//判断第一列是否有按键按下
    {
        delay_10ms(1000);//消抖
        
        switch(MATRIX_KEYS)
        {
            case S13:
                value_index = 12;
                break;
            case S9:
                value_index = 8;
                break;
            case S5:
                value_index = 4;
                break;
            case S1:
                value_index = 0;
                break;
        }
    }//0XF7

    return value_index;
}

/*使用反转法进行按键检测*/
s8 matrix_keys_flap_scan()
{
    static s8 value_index = -1;
    
    //将所有的行线置为低电平0000 1111 0x0F
    MATRIX_KEYS = 0x0F;
    if(MATRIX_KEYS != 0x0F)
    {
        delay_10ms(1000);
        //检测列
        MATRIX_KEYS = 0x0F;
        switch(MATRIX_KEYS)//获取列线 第一列 0 第二列 1 第三列2 第四列 3
        {
            case 0x07: value_index = 0; break;
            case 0x0B: value_index = 1; break;
            case 0x0D: value_index = 2; break;
            case 0x0E: value_index = 3; break;
        }
        //进行反转，检测行
        MATRIX_KEYS = 0xF0;
        switch(MATRIX_KEYS)//获取行线 第一不变， 第二行 +4， 第三行 +8， 第四行 +12
        {
            case 0x70: value_index = value_index; break;
            case 0xB0: value_index = value_index+4; break;
            case 0xD0: value_index = value_index+8; break;
            case 0xE0: value_index = value_index+12; break;
        }
    }else value_index = -1;

    return value_index;
}

u8 smg_code[]={
        0x3f, 0x06, 0x5b, 0x4f, //0 1 2 3
        0x66, 0x6d, 0x7d, 0x07, //4 5 6 7
        0x7f, 0x6f, 0x77, 0x7c, //8 9 A B
        0x39, 0x5e, 0x79, 0x71  //C D E F
        };

void main(void)
{
    s8 index = -1;
    
    while(1)
    {
        index = matrix_keys_flap_scan();
        A2 = 1; A1= 0; A0 = 1;
        if(index !=-1)
        {
            DITIGALTUBE_ZERO_PORT = smg_code[index];
        }
    }

}



