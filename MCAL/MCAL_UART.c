#include "MCAL_UART.h"
#include "BSW_InterTp.h"
#include "BSW_UartIf.h"

// SemaphoreHandle_t SendMutex = NULL;
/*!
 * @brief       Configures UART port.
 *
 * @param       None
 *
 * @retval      None
 */
void MCAL_UART_Init( void )
{
    uint8 uartIndex;

    RCM_EnableAPB2PeriphClock( RCM_APB2_PERIPH_USART1 );

    RCM_EnableAPB1PeriphClock( RCM_APB1_PERIPH_USART2 );

    for ( uartIndex = 0; uartIndex < UART_SIGNALS_CNT; uartIndex++ )
    {
        /* USART configuration */
        USART_Config( ( uartSignalsCfgTable + uartIndex )->uart, (USART_Config_T*)&( ( uartSignalsCfgTable + uartIndex )->mcal_config_uart ) );

        if ( ( uartSignalsCfgTable + uartIndex )->irq_type != 0 )
        {
            USART_EnableInterrupt( ( uartSignalsCfgTable + uartIndex )->uart, (USART_INT_T)( uartSignalsCfgTable + uartIndex )->irq_type );
            USART_ClearStatusFlag( ( uartSignalsCfgTable + uartIndex )->uart, USART_FLAG_RXBNE );
            NVIC_EnableIRQRequest( ( uartSignalsCfgTable + uartIndex )->irq,
                                   ( uartSignalsCfgTable + uartIndex )->preemptionPriority, ( uartSignalsCfgTable + uartIndex )->subPriority );
        }
        /* Enable USART */
        USART_Enable( ( uartSignalsCfgTable + uartIndex )->uart );
    }

    USART_EnableDMA( USART1, USART_DMA_TX_RX );
}

void DMA_Uart1Send( const uint8_t* buffer, uint16_t len )
{
    DMA_ConfigDataNumber( DMA1_Channel4, len );  // ����TXͨ���ڴ����

    DMA1_Channel4->CHCFG |= ( 1 << 7 );

    DMA1_Channel4->CHMADDR = (uint32_t)buffer;

    DMA_Enable( DMA1_Channel4 );
}

/**
 * @brief
 * @param
 * @retval
 */
void USART1_IRQHandler( void )
{
    // �����ж�
    uint16 dataLen = 0;
    if ( USART_ReadStatusFlag( uartSignalsCfgTable[ 0 ].uart, USART_FLAG_TXC ) != RESET )
    {
        DMA_Disable( DMA1_Channel4 );
        DMA_ClearStatusFlag( DMA1_FLAG_TC4 );
        USART_ClearStatusFlag( uartSignalsCfgTable[ 0 ].uart, USART_FLAG_TXC );
    }
    // �����ж�
    if ( USART_ReadStatusFlag( uartSignalsCfgTable[ 0 ].uart, USART_FLAG_IDLE ) != RESET )
    {
        uartSignalsCfgTable[ 0 ].uart->STS;
        uartSignalsCfgTable[ 0 ].uart->DATA;

        DMA_Disable( DMA1_Channel5 );

        DMA_USART1_RxMsg.DMA_USART_Len = 512 - DMA_ReadDataNumber( DMA1_Channel5 );

        DMA_ConfigDataNumber( DMA1_Channel5, 512 );  // ����RXͨ���ڴ����

        DMA1_Channel5->CHCFG |= ( 1 << 7 );

        DMA1_Channel5->CHMADDR = (uint32_t)DMA_USART1_RxMsg.DMA_USART_Buf;

        dataLen                = (uint16)( DMA_USART1_RxMsg.DMA_USART_Buf[ 3 ] << 8 ) + (uint16)( DMA_USART1_RxMsg.DMA_USART_Buf[ 4 ] );

        // InterTp_UartRxIndication( BUS_UART1,DMA_USART1_RxMsg.DMA_USART_Buf,DMA_USART1_RxMsg.DMA_USART_Len);
        //  HEAD+ID+CMD+DLC+CRC = 7BYTE
        if ( DMA_USART1_RxMsg.DMA_USART_Len == ( dataLen + 7 ) )
        {
			UartIf_RxIndicaiton(DMA_USART1_RxMsg.DMA_USART_Buf,DMA_USART1_RxMsg.DMA_USART_Len ,0 );
        }
        DMA_Enable( DMA1_Channel5 );
    }
}
