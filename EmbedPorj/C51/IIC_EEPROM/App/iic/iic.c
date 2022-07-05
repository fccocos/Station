#include "iic.h"

void iic_start(void)
{
    IIC_SDA = 1;
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SDA = 0;
    delay_10us(1);
    IIC_SCL = 0;
    delay_10us(1);
}
void iic_stop(void)
{
    IIC_SDA = 0;
    delay_10us(1);

    IIC_SCL = 1;
    delay_10us(1);

    IIC_SDA = 1;
    delay_10us(1);
}
void iic_write_byte(u8 txd)
{
    u8 i;
    IIC_SCL = 0;
    for (i = 0; i < 8; i++)
    {
        if (txd & 0x80)
            IIC_SDA = 1;
        else
            IIC_SDA = 0;
        txd <<= 1;
        delay_10us(1);
        IIC_SCL = 1;
        delay_10us(1);
        IIC_SCL = 0;
        delay_10us(1);
    }
}
u8 iic_read_byte(u8 ack)
{
    u8 i, receive;
    for (i = 0; i < 8; i++)
    {
        IIC_SCL = 0;
        delay_10us(1);
        IIC_SCL = 1;
        receive <<= 1;
        if (IIC_SDA)
            receive++;
        delay_10us(1);
    }
    if (!ack)
        iic_nack();
    else
        iic_ack();

    return receive;
}
u8 iic_wait_ack(void)
{
    u8 time_tmp = 0;
    IIC_SCL = 0;
    delay_10us(1);
    while (IIC_SDA)
    {
        time_tmp++;
        if (time_tmp > 100)
        {
            iic_stop();
            return 1;
        }
    }
    IIC_SCL = 0;
    return 0;
}
void iic_ack(void)
{
    IIC_SCL = 0;
    IIC_SDA = 0;
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SCL = 0;
}
void iic_nack(void)
{
    IIC_SCL = 0;
    IIC_SDA = 1;
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SCL = 0;
}