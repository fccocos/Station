#include "public.h"
#include "smg.h"
#include "ds1302.h"

void main()
{
    uchar time_buf[8];
    ds1302_intial();

    while (1)
    {
        ds1302_read_time();
        time_buf[0] = smg_code[gDS1302_TIME[2] / 16];
        time_buf[1] = smg_code[gDS1302_TIME[2] & 0x0f];
        time_buf[2] = 0x40;
        time_buf[3] = smg_code[gDS1302_TIME[1] / 16];
        time_buf[4] = smg_code[gDS1302_TIME[1] & 0x0f];
        time_buf[5] = 0x40;
        time_buf[6] = smg_code[gDS1302_TIME[0] / 16];
        time_buf[7] = smg_code[gDS1302_TIME[0] & 0x0f];
        smg_display(time_buf, 1);
    }
}