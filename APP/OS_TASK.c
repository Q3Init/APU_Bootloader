#include "OS_TASK.h"
/* User define */
#include "BSW_UartIf.h"

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void)
{
    uint8 ret = OS_RET_OK;
    UartIf_MainFunction();
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;

    
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task2(void)
{
    uint8 ret = OS_RET_OK;
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void)
{
    uint8 ret = OS_RET_OK;
    
    return ret;
}

void OS_Delay_us(uint32 counter)
{
    counter *=9;
    while(counter--);
}

