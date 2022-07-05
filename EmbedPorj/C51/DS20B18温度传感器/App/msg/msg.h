#ifndef _MSG_H
#define _MSG_H
#include "public.h"

#define GMSG_CODE_SIZE 17

#define SMG_A_DL_PORT P0 //段选线


/*位选线*/
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;


extern u8 gmsg_code[GMSG_CODE_SIZE];
void msg_display(u8 dat[], u8 pos);


#endif
