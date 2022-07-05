#ifndef _SMG_H
#define _SMG_H

#include "public.h"

#define SMG_SLECT_LINE P0

#define SMG_CODE_SIZE 17

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

extern uchar smg_code[SMG_CODE_SIZE];

void smg_display(uchar buf[], uchar pos);

#endif