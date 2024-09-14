#include "RTE.h"
#include "Os_EvtHdl.h"
#include "Os_TimerHdl.h"
#include "Os_TaskHdl_Lv0.h"

static volatile boolean rteBswRdyFlg = FALSE;
void RTE_Init(void)
{
    __DISENBLE_IRQ(); /* chip disable irq */
    /* System Tick */
    // SystemInit();
    // SysTick_Config(SystemCoreClock / 1000);
    /* OS Init */
#ifdef EASY_OS
    OsEvt_Init();
    OsTimer_Init();
#endif
    /* MCAL Init */
    MCAL_GPIO_Init();
    MCAL_UART_Init();


    rteBswRdyFlg = TRUE; /* Init complete flag */
    __ENABLE_IRQ(); /* chip enable irq */
}


boolean Get_rteBswRdyFlg(void)
{
	return(rteBswRdyFlg);
}


