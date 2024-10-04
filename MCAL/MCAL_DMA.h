#ifndef MCAL_DMA_H_
#define MCAL_DMA_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_DMA.h"

extern void MCAL_DMA_Init(void);
extern void DMA_Uart1Send( uint8_t* buffer, uint16_t len );
#endif
