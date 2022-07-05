#ifndef _24C02_H
#define _24C02_H

#include "public.h"

void at24c02_write_one_byte(u8 addr, u8 dat);
u8 at24c02_read_one_byte(u8 addr);

#endif