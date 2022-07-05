#ifndef _PWM_H
#define _PWM_H

#include "public.h"

sbit pwm = P2^1;

void pwm_init(u8 time_h, u8 time_l, u16 time_scale, u8 duty);

void pwm__set_duty(u8 duty);

#endif //f _PWM_H
