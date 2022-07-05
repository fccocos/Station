#include "ds1302.h"
#include <intrins.h>

uchar gREAD_RTC_ADDR[7]={0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d};
uchar gWRITE_RTC_ADDR[7]={0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

//初始化时间 存储顺序为秒分时日月周年，存储格式为BCD码
//2022年6月3日 星期五 9:10:20
uchar gDS1302_TIME[7] = {0x20, 0x10, 0x09, 0x03, 0x06, 0x05, 0x22};

void ds1302_write_byte(uchar addr, uchar dat)
{
    /**
     *          11    22    33    44    55    66    77    88    11    22    33    44    55    66    77    88
     *           __    __    __    __    __    __    __    __    __    __    __    __    __    __    __    __    
     *SCLK _____|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__________ 
     * 
     *         ________________________________________________________________________________________________   
     *RST  ___|                                                                                                \________ 
     * 
     *                        register_address                                data/command
     * 
     * 上升沿----写
     * RST为正脉冲时，才能够开始读写数据
     */ 
    //写地址
    int i;
    //RST为高电平时才可以开始读写数据
    ds1302_RST=0;
    _nop_();
    ds1302_SCLK =0;
    _nop_();
    ds1302_RST=1;
    _nop_();

    for(i=0;i<8;++i)
    {
        //从低位开始写地址
        ds1302_IO = addr&0x01;
        addr>>=1;
        ds1302_SCLK = 1;
        _nop_();
        ds1302_SCLK=0;
        _nop_();
    } 
    for(i=0;i<8;++i)
    {
        ds1302_IO = dat&0x01;
        dat>>=1;
        ds1302_SCLK = 1;
        _nop_();
        ds1302_SCLK=0;
        _nop_();
    }  
    ds1302_RST=0;//STC为低电平结束数据的读写
    _nop_();
}

uchar ds1302_read_byte(uchar addr)
{
    /**
     *          11    22    33    44    55    66    77    8811    22    33    44    55    66    77    88
     *           __    __    __    __    __    __    __    __    __    __    __    __    __    __    __   
     *SCLK _____|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \__|  \____________ 
     * 
     *         ________________________________________________________________________________________________   
     *RST  ___|                                                                                                \________ 
     * 
     *                        register_address                              data/command
     * 
     * 上升沿----写
     * RST为正脉冲时，才能够开始读写数据
     */ 
    uchar tmp,value;
    uchar i;
    //RST为高电平时才可以开始读写数据
    ds1302_RST=0;
    _nop_();
    ds1302_SCLK =0;
    _nop_();
    ds1302_RST=1;
    _nop_();

    for(i=0;i<8;++i)
    {
        //从低位开始写地址
        ds1302_IO = addr&0x01;
        addr>>=1;
        ds1302_SCLK = 1;
        _nop_();
        ds1302_SCLK=0;
        _nop_();
    }
    for(i=0;i<8;++i)
    {
        tmp=ds1302_IO;
        value=(tmp<<7)|(value>>1);
        ds1302_SCLK=1;
        _nop_();
        ds1302_SCLK=0;
        _nop_();
    } 
    ds1302_RST = 0;
    _nop_();
    
    //由于读数据要比写数据少一个正脉冲，所以后天要加一个正向买脉冲，可以不写数据
    ds1302_SCLK = 1;//对于实物中，P3.4 口没有外接上拉电阻的，此处代码需要添加，使数据口有一个上升沿脉冲
    _nop_();
    ds1302_IO=0;
    _nop_();
    ds1302_IO=1;//在数据读取完后，要将IO设置给高阻态
    _nop_();
    
    return value;
}

void ds1302_intial()
{
    uchar i=0;
    ds1302_write_byte(0x8E,0x00);
    for(i=0;i<7;i++)
        ds1302_write_byte(gWRITE_RTC_ADDR[i],gDS1302_TIME[i]);
    ds1302_write_byte(0x8E, 0x01);
}

void ds1302_read_time()
{
    uchar i=0;
    for(i=0;i<7;i++)
        gDS1302_TIME[i]=ds1302_read_byte(gREAD_RTC_ADDR[i]);
}