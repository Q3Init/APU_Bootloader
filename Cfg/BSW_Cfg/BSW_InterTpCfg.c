#include "BSW_InterTpCfg.h"

const InterTpPduType interTpPdusCfgTable[INTERTP_PDUS_CNT] =
{
    {.id = 0x11,.bus = BSW_UART0,.src = INTERTP_UART,.dest = INTERTP_OTA,  .srcPduId = 0xFF,                                .destPduId = INTERTP_RX_PDUID_ON_UART_11_DIAG_REQ,   .dir = INTERTP_PDU_RX},
    {.id = 0x22,.bus = BSW_UART0,.src = INTERTP_OTA, .dest = INTERTP_UART, .srcPduId = INTERTP_TX_PDUID_ON_UART_22_DIAG_RSP,.destPduId = 0xFF,                                   .dir = INTERTP_PDU_TX},
};

