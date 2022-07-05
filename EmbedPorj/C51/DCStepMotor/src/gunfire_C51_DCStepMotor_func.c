#include "gunfire_C51_DCStepMotor_func.h"

#include <gunfire_condefine.h>



/*直流步进电机28BYJ-48*/
// 脉冲序列（正向旋转）
static gu8 gunfire_DCStepMotor_pulses[GUNFIRE_C51_DCSTEPMOTOR_PULSES_SIZE]={0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09};

//步进电机的初始速度
static gu8 gunfire_DCStepMotor_Speed;

//
static gu8 gunfire_DCStepMotor_isRunning;

static gu8 G_IndependentKey_Scan(gu8 mode);


void G_IndependentKey_Control()
{
    gu8 key = G_IndependentKey_Scan(0);
    if(key == GUNFIRE_INDEPENDENTKEY1_PRESSED)//反向
        G_DCStepMotor_Reverse();
    if(key == GUNFIRE_INDEPENDENTKEY2_PRESSED)//加速
        G_DCStepMotor_SpeedUp();
    if(key==GUNFIRE_INDEPENDENTKEY3_PRESSED)//减速
        G_DCStepMotor_SpeedDown();
    if(key ==GUNFIRE_INDEPENDENTKEY4_PRESSED)//暂停
        G_DCStepMotor_Stop();
}


/*
初始化
*/
void G_DCStepMotor_Initial()
{
    GUNFIRE_DC_STEP_MOTOR_CONTROL = 0x00;
    gunfire_DCStepMotor_Speed = GUNFIRE_C51_DCSTEPMOTOR_MAXSPEED;
    gunfire_DCStepMotor_isRunning = 1;
}


/**
 * @brief 步进电机运行
 * 
 */
void G_DCStepMotor_Run()
{
    int i;
    G_IndependentKey_Control();
    while(gunfire_DCStepMotor_isRunning)
    {
        for(i = 0; i < GUNFIRE_C51_DCSTEPMOTOR_PULSES_SIZE; i++)
        {
            GUNFIRE_DC_STEP_MOTOR_CONTROL = gunfire_DCStepMotor_pulses[i];
            delay_ms(gunfire_DCStepMotor_Speed);
            GUNFIRE_DC_STEP_MOTOR_CONTROL = 0x00;
            G_IndependentKey_Control();
        }
        
    }
}

/**
 * @brief 步进电机暂停运行
 * 
 */
void G_DCStepMotor_Stop()
{
        gunfire_DCStepMotor_isRunning = !gunfire_DCStepMotor_isRunning;
}

/**
 * @brief 将步进电机的脉冲序列逆置，用于实现电机的反向
 * 
 */
void  G_Reverse_Pluses()
{
    gu8 i,j;
    for(i=0,j=7;i<j;i++,j--)
    {
        G_Swap(&gunfire_DCStepMotor_pulses[i],&gunfire_DCStepMotor_pulses[j]);
    }
}

/**
 * @brief 电机加速。
 * 实质是控制脉冲的频率，通过delay函数来实现
 */
void G_DCStepMotor_SpeedUp()
{
    if(gunfire_DCStepMotor_Speed>GUNFIRE_C51_DCSTEPMOTOR_MAXSPEED)
        gunfire_DCStepMotor_Speed--;
}

/**
 * @brief 电机减速
 * 实质是控制脉冲的频率，通过delay函数来实现
 * @param down 一次减速多少
 */
void G_DCStepMotor_SpeedDown()
{
    if(gunfire_DCStepMotor_Speed < GUNFIRE_C51_DCSTEPMOTOR_MINSPEED)
        gunfire_DCStepMotor_Speed++;
}

/**
 * @brief 电机转向反转
 * 
 */
void G_DCStepMotor_Reverse()
{
    G_Reverse_Pluses();
}

static gu8 G_IndependentKey_Scan(gu8 mode)
{
    static gu8 key = 1;
    if(mode) key = 1;
    if(key==1&&(GUNFIRE_independentKey1==0||
                GUNFIRE_independentKey2==0||
                GUNFIRE_independentKey3==0||
                GUNFIRE_independentKey4==0))
    {
        delay_10us(1000);
        key=0;
        if(GUNFIRE_independentKey1==0)
        return GUNFIRE_INDEPENDENTKEY1_PRESSED;
        if(GUNFIRE_independentKey2==0)
        return GUNFIRE_INDEPENDENTKEY2_PRESSED;
        if(GUNFIRE_independentKey3==0)
        return GUNFIRE_INDEPENDENTKEY3_PRESSED;
        if(GUNFIRE_independentKey4)
        return GUNFIRE_INDEPENDENTKEY4_PRESSED;
    }
    else if(GUNFIRE_independentKey1==1&&
            GUNFIRE_independentKey2==1&&
            GUNFIRE_independentKey3==1&&
            GUNFIRE_independentKey4==1)
    {
        key =1;
    }
    
    return GUNFIRE_INDEPENDENTKEY_UNPRESS;
}


