#ifndef GUNFIRE_C51_DCSTEPMOTOR_FUNC_H
#define GUNFIRE_C51_DCSTEPMOTOR_FUNC_H

#define GUNFIRE_C51_DCSTEPMOTOR_MAXSPEED 1
#define GUNFIRE_C51_DCSTEPMOTOR_MINSPEED 5
#define GUNFIRE_C51_DCSTEPMOTOR_PULSES_SIZE 8

/*
初始化
*/
void G_DCStepMotor_Initial();

/**
 * @brief 步进电机运行
 */
void G_DCStepMotor_Run();
/**
 * @brief 步进电机暂停运行
 * 
 */
void G_DCStepMotor_Stop();

/**
 * @brief 将步进电机的脉冲序列逆置，用于实现电机的反向
 */
void  G_Reverse_Pluses();

/**
 * @brief 电机加速。
 * 实质是控制脉冲的频率，通过delay函数来实现
 */
void G_DCStepMotor_SpeedUp();

/**
 * @brief 电机减速
 * 实质是控制脉冲的频率，通过delay函数来实现
 * @param down 一次减速多少
 */
void G_DCStepMotor_SpeedDown();

/**
 * @brief 电机转向反转
 */
void G_DCStepMotor_Reverse();

void G_IndependentKey_Control();

#endif