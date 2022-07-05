#include <gunfire_condefine.h>

void hc595_write(gu8 dat)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        GUNFIRE_HC595_SER = dat >> 7;
        dat <<= 1;
        GUNFIRE_HC595_SRCLK = 0;
        delay_10us(1);
        GUNFIRE_HC595_SRCLK = 1;
        delay_10us(1);
    }
    GUNFIRE_HC595_RCLK = 0;
    delay_10us(1);
    GUNFIRE_HC595_RCLK = 1;
}

gu8 words_lib_row[][8] = {
    //行
    // {0x00, 0x7C, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00},  // 0
    // {0x30, 0x48, 0x44, 0x22, 0x44, 0x48, 0x30, 0x00},//love
    {0x10, 0x32, 0x55, 0xFF, 0x10, 0xFE, 0x15, 0x53}, //我
    {0x30, 0x48, 0x44, 0x22, 0x44, 0x48, 0x30, 0x00}, // love
    {0x20, 0x7F, 0xA0, 0x44, 0xC9, 0x7F, 0x48, 0x74}, //你
    {0x38, 0x28, 0x28, 0xFF, 0x28, 0x28, 0x38, 0x00}, //中
    {0xFF, 0x85, 0xD5, 0xFD, 0xD5, 0x8D, 0xFF, 0x00}  //国
};
gu8 words_lib_col[][8] = {
    //列
    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}};

int main()
{
    gu8 j, i, k;
    GUNFIRE_LED_MAXTRIX_K = 0x00;
    while (1)
    {
        for (k = 0; k < 5; k++)
            for (i = 0; i < 50; i++)
                for (j = 0; j < 8; ++j)
                {
                    GUNFIRE_LED_MAXTRIX_K = words_lib_col[0][j];
                    hc595_write(words_lib_row[k][j]);
                    delay_10us(100);
                    hc595_write(0x00);
                }
    }
}