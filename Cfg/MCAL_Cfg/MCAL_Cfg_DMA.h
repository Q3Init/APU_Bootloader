#ifndef __MCAL_CFG_DMA_H_
#define __MCAL_CFG_DMA_H_

#include "MCAL_CfgList.h"

#define DMA_SIGNALS_CNT 2

#define USART_BUFF_LEN 128

/* USART1 data register address */
#define USART1_DR_ADDRESS   ((uint32_t)USART1_BASE+0x04)

typedef struct {
    uint32 clock;
    DMA_Channel_T* channel;
    DMA_Config_T mcal_config_dma;
} DMASignalsCfg;

typedef struct {
	uint8  DMA_USART_Buf[USART_BUFF_LEN];
	uint16 DMA_USART_Len;
} USART_BuffMsg_t;

extern USART_BuffMsg_t DMA_USART1_RxMsg;
extern USART_BuffMsg_t DMA_USART1_TxMsg;

extern const DMASignalsCfg dmaSignalsCfgTable[];

#endif
