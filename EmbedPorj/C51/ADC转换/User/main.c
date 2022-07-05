#include "smg.h"
#include "xpt2046.h"
#include "public.h"

#define RESOLUTION  4096
#define VREF 5


void main()
{
    u16 adc_value = 0;
    float adc_vol; //ADC电压值
    u8 adc_buf[3];

    while(1)
    {
        adc_value = xpt2046_read_adc_value(0x94);//0x94表示测量电位器
        /*U = Vref*ADC_Value/Resolution*/
        adc_vol = VREF*adc_value/RESOLUTION; // 计算出电压
        adc_value = adc_vol*10;

        adc_buf[0] = gsmg_code[adc_value/10]|0x80;
        adc_buf[1] = gsmg_code[adc_value%10];
        adc_buf[2] = 0x3e;

        display_smg(adc_buf, 6);
    }
}