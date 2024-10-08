/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "BSW_BootSelect.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef void (*pFunction)(void);
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void Bsw_JumpToApp(void);
static void Bsw_BootScanAppEntry(void);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static pFunction Jump_To_Application;
static uint32 bootEnterAppFlag __attribute__((at(0x2001FFE0))) = ENTERED_WAY_POWERON;
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/**
* Bsw_BootSelectInit
*
* @return   none
*
* @brief  Check whether to jump according to the app flag
*/
void Bsw_BootSelectInit(void)
{
//    if (bootEnterAppFlag == APP_JUMP_TO_BOOT_REQ1) {
//        bootEnterAppFlag = 0;
        (void)RTE_Init();
//    } else {
//        bootEnterAppFlag = 0;
//        Bsw_BootScanAppEntry();
//    }
}

/**
* Bsw_BootScanAppEntry
*
* @return   none
*
* @brief  Check app crc and integrity
*/
static void Bsw_BootScanAppEntry(void)
{
    Bsw_JumpToApp();
}

/**
* Bsw_JumpToApp
*
* @return   none
*
* @brief  Jump to the app slot
*/
static void Bsw_JumpToApp(void)
{
    uint32 jumpAddress;
    uint32 appAddress = flashSlotInfoTable[FLASH_SLOTA_APP_A].startAddr;
    
    __DISENBLE_IRQ();
    if (((*(__IO uint32 *)appAddress) & 0x2FFE0000) == 0x20000000) {
        jumpAddress = *(__IO uint32 *)(appAddress + 4); /* Jump to user application */ 
        Jump_To_Application = (pFunction)jumpAddress; /* Initialize user application's Stack Pointer */
        __set_MSP(*(__IO uint32*)appAddress);
        Jump_To_Application();  /* jump to app */
    } else {
        __ENABLE_IRQ(); /* enable global interrupt and ramain at boot */
    }
    
}
