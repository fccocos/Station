#include <reg52.h>

void UART_init(unsigned char botelv)
{
    
    TMOD |= 0x20; //启用定时器的工作方式2
    SCON = 0x50;  //启用串口通信的工作方式1
    PCON = 0x80;
    TH1 = botelv;
    TL1 = botelv;
    ES = 1;
    TR1 = 1;
    EA = 1;       // 启动CPU中断
}
void main()
{
    UART_init(0xFA);

    while (1){}
}

void UART_INT() interrupt 4
{
    unsigned char rec_data;
    RI = 0;
    rec_data = SBUF;
    SBUF = rec_data;
    while (!TI);
        TI = 0;
}