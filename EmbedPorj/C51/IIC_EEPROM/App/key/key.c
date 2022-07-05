#include "key.h"

u8 key_scan(u8 mode)
{
    static u8 key = 1;

    if (mode)
        key = 1;

    if (key == 1 && (key1 == 0 || key2 == 0 || key3 == 0 || key4 == 0))
    {
        delay_10us(1000); //消抖
        key = 0;
        if (key1 == 0)
            return KEY1_PRESS;
        else if (key2 == 0)
            return KEY2_PRESS;
        else if (key3 == 0)
            return KEY3_PRESS;
        else if (key4 == 0)
            return KEY4_PRESS;
    }
    else if (key1 == 1 && key2 == 1 && key3 == 1 && key4 == 1)
        key = 1;
    return KEY_UNPRESS;
}