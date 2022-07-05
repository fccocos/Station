/**
 * *********************************************
 *
 * Type: C51 Single Chip Macrocomputer
 * Name: Dynamical display of Digital tube
 * Chip: STC89C516RD+  74HC128 74HC245
 * PIN: P0.0~P0.7 P2.2 P2.4 P2.5
 * Author: Gunfire
 * Date: 2022.5.24
 * *********************************************
 */

#include "REG52.H"

#define SEGMENT_OF_LINE_SELECTION P0 //段选线

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

sbit A0 = P2 ^ 2; // low
sbit A1 = P2 ^ 3; // minor low
sbit A2 = P2 ^ 4; // high

void sleep(uint32_t timeout)
{
    while (timeout--)
        ;
}
/*  0     1     2     3     4     5    6     7    8      9     A    b     C    d     E     F    不显示*/
/*0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71, 0x00*/
void main()
{
    // 1st --> show 0   2nd --> show 1 ... last --> show 7
    // P2.4 --> A2  P2.3 --> A1  P2.2 --> A0    数码管位数     显示数字    P2.7   p2.6   p2.5   p2.4    p2.3  p2.2  p2.1 p2.0  十六进制
    /**                                                                    DP      g      f      e       d     c     b    a
     *          0            0            0     第0位数码管        0        0      0      1      1       1     1     1     1      0x3f
     *          0            0            1     第1位              1        0                                                     0x06
     *          0            1            0     第2位              2        0                                                     0x5b
     *          0            1            1     第3位              3        0                                                     0x4f
     *          1            0            0     第4位              4        0                                                     0x66
     *          1            0            1     第5位              5        0                                                     0x7d
     *          1            1            0     第6位              6        0                                                     0x07
     *          1            1            1     第7位              7        0                                                     0x7f
     */
    uint8_t smg_code[8] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07};

    int i;
    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            switch (i)
            {
            case 0:
                //点亮第0位数码管
                A2 = 0;
                A1 = 0;
                A0 = 0;
                break;
            case 1:
                //点亮第1位数码管
                A2 = 0;
                A1 = 0;
                A0 = 1;
                break;
            case 2:
                //点亮第2位数码管
                A2 = 0;
                A1 = 1;
                A0 = 0;
                break;
            case 3:
                //点亮第3位数码管
                A2 = 0;
                A1 = 1;
                A0 = 1;
                break;
            case 4:
                //点亮第4位数码管
                A2 = 1;
                A1 = 0;
                A0 = 0;
                break;
            case 5:
                //点亮第5位数码管
                A2 = 1;
                A1 = 0;
                A0 = 1;
                break;
            case 6:
                //点亮第6位数码管
                A2 = 1;
                A1 = 1;
                A0 = 0;
                break;
            case 7:
                //点亮第7位数码管
                A2 = 1;
                A1 = 1;
                A0 = 1;
                break;
            }
            SEGMENT_OF_LINE_SELECTION = smg_code[i];
            sleep(10);                        // 1000
            SEGMENT_OF_LINE_SELECTION = 0x00; //消音
        }
    }
}
