#include "MCAL_DMA.h"

void MCAL_DMA_Init(void)
{
    uint8 dmaIndex;
    for (dmaIndex = 0; dmaIndex < DMA_SIGNALS_CNT; dmaIndex++) {
        /* Enable DMA Clock */
        RCM_EnableAHBPeriphClock((dmaSignalsCfgTable + dmaIndex)->clock);

        /* Enable DMA channel */
        DMA_Config((dmaSignalsCfgTable + dmaIndex)->channel, (DMA_Config_T*)&((dmaSignalsCfgTable + dmaIndex)->mcal_config_dma));

        /* Enable DMA */
        DMA_Enable((dmaSignalsCfgTable + dmaIndex)->channel);
    }
}

void DMA_Uart1Send( uint8_t* buffer, uint16_t len )
{
	DMA_ConfigDataNumber(DMA1_Channel4,len); //设置TX通道内存宽度
	
    DMA1_Channel4->CHCFG |= (1<<7);
	
    DMA1_Channel4->CHMADDR = (uint32_t)buffer;
	
	DMA_Enable(DMA1_Channel4);
}

