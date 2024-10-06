/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "BSW_InterTpCfg.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
const InterTpPduType interTpPdusCfgTable[INTERTP_PDUS_CNT] =
{
    {.id = 0x11,.bus = BSW_UART0,.src = INTERTP_UART,.dest = INTERTP_OTA,  .srcPduId = 0xFF,                                .destPduId = INTERTP_RX_PDUID_ON_UART_11_DIAG_REQ,   .dir = INTERTP_PDU_RX},
    {.id = 0x22,.bus = BSW_UART0,.src = INTERTP_OTA, .dest = INTERTP_UART, .srcPduId = INTERTP_TX_PDUID_ON_UART_22_DIAG_RSP,.destPduId = 0xFF,                                   .dir = INTERTP_PDU_TX},
};
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/**
* InterTp_UartTransmit
*
* @param datas: tx datas
* @param dlc: Data length
* @param uartIndex: Number of serial drivers
* @return   ret: TRUE or FALSE
*
* @brief  Intertp maps new modules
*/
boolean InterTp_UartTransmit(const uint8 *datas,uint16 dlc,uint8 uartIndex)
{
    boolean ret = FALSE;
    return ret;
}

/**
* InterTp_OTA_Rxindication
*
* @param pduId: rx datas
* @param pduInfoPtr: common data info
* @return   none
*
* @brief  The parsed data is uploaded to the upper-layer module
*/
void InterTp_OTA_Rxindication(uint16 pduId,const PduInfoType *pduInfoPtr)
{

}

/**
* InterTp_IsOTARxEnable
*
* @return   none
*
* @brief  ota data This link is enabled
*/
boolean InterTp_IsOTARxEnable(void)
{
    boolean ret = TRUE;
    return ret;   
}
