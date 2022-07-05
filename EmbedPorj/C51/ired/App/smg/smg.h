#ifndef _SMG_H
#define _SMG_H

#include "public.h"

#define GSMG_CODE_SIZE 17

#define SMG_A_DL_PORT P0 // 段选线

/*位选线*/

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

extern u8 gsmg_code[GSMG_CODE_SIZE];

void smg_display(u8 dat[], u8 pos);

#endif 