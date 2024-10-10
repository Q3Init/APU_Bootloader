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
//        DMA_Enable((dmaSignalsCfgTable + dmaIndex)->channel);
    }
	
	DMA_Disable(DMA1_Channel4); // Tx
	DMA_Enable(DMA1_Channel5);  // Rx
}


