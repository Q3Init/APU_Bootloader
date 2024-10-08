#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_UART.h"
#include "MCAL_Cfg_DMA.h"
#include "MCAL_DMA.h"
//#include "freertos.h"
//#include "task.h"
//#include "semphr.h"

extern void MCAL_UART_Init(void);
extern void DMA_Uart1Send(const uint8_t* buffer, uint16_t len );
//extern SemaphoreHandle_t SendMutex;

#endif
