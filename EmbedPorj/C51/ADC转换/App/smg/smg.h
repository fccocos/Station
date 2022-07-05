#ifndef _SMG_H
#define _SMG_H

#include "public.h"

#define SMG_A_DL_PORT P0
#define GSMG_CODE_SIZE 17
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

extern gsmg_code[GSMG_CODE_SIZE];

void display_smg(u8 dat[], u8 pos);


#endif