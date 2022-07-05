#include "gunfire_condefine.h"


/*实现LED点阵按行案列滚动*/

//the chip 74hc595 controls maxtrix led's positive pole,
//so high level  is effective.
gu8 hc595_buf[8] = {
    0x01,0x02,0x04,0x08,
    0x10,0x20,0x40,0x80
    };

void gunfire_hc595_wirte(gu8 dat)
{
    //Writing data into the chip 74hc595 by serial SER
    gu8 i;
    //writing data into the chip 74hc595 ,one by one
    for(i=0;i<8;i++)
    {
        //put data into shift register by serial from high to low
        GUNFIRE_HC595_SER = dat>>7;//0000 0001->0
        dat<<=1;//0000 0001 -> 0000 0010
        // High level is effective
        GUNFIRE_HC595_SRCLK =0;
        delay_10us(1);
        GUNFIRE_HC595_SRCLK = 1;
        delay_10us(1);
    }
    //Deta from shift register to memory registers
    //high level is effective
    GUNFIRE_HC595_RCLK = 0;
    delay_10us(1);
    GUNFIRE_HC595_RCLK = 1;
}


int main()
{
    gu8 i;
    //setting the negative pole of the matrix LED to low 
    GUNFIRE_LED_MAXTRIX_K = 0x00;
    while(1)
    {
        for(i=0;i<8; i++)
        {
            //clear data
            gunfire_hc595_wirte(0x00);
            // get date from memory registers of 74hc595 chip
            gunfire_hc595_wirte(hc595_buf[i]);
            delay_ms(500);
        }
    }
}

