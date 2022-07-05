#include "gunfire_C51_DCStepMotor_func.h"

void main(void)
{   
    G_DCStepMotor_Initial();
    while(1)
    {
        G_DCStepMotor_Run();
    }
    
    
}