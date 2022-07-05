#ifndef _DS1302_H
#define _DS1302_H
#include "public.h"

sbit ds1302_SCLK = P3^6;
sbit ds1302_IO = P3^4;
sbit ds1302_RST = P3^5;

extern uchar gDS1302_TIME[7];

void ds1302_write_byte(uchar addr, uchar dat);

uchar ds1302_read_byte(uchar addr);

void ds1302_read_time();

void ds1302_intial();

#endif // _DS1302_H
