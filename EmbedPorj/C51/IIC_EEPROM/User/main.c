#include <public.h>
#include <iic.h>
#include <24c02.h>
#include <key.h>
#include <smg.h>

#define EEPROM_ADDRESS 0

int main()
{
    u8 key_tmp = 0;
    u8 save_value = 0;
    u8 save_buf[3] = 0;
    while (1)
    {
        key_tmp =key_scan(0);
        if(key_tmp == KEY1_PRESS)
        {
            at24c02_write_one_byte(EEPROM_ADDRESS,save_value);
        }
        if(key_tmp == KEY2_PRESS)
        {
            save_value = at24c02_read_one_byte(EEPROM_ADDRESS);

        }
        if(key_tmp == KEY3_PRESS)
        {
            save_value++;
            if(save_value == 256) save_value = 255;
        }
        if(key_tmp == KEY4_PRESS)
        save_value=0;

        save_buf[0] = save_value/100;
        save_buf[1] = save_value%100/10;
        save_buf[2] = save_value%100%10;
        smg_display(save_buf,6);
    }
}