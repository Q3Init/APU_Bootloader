#ifndef BSW_INTERTP_CFG_H_
#define BSW_INTERTP_CFG_H_

#include "Platform_Types.h"

#define INTERTP_OTA 0
#define INTERTP_UART 1

#define BSW_UART0 0

#define INTERTP_PDU_RX 0
#define INTERTP_PDU_TX 1

#define INTERTP_RX_PDUID_ON_UART_11_DIAG_REQ 0
#define INTERTP_TX_PDUID_ON_UART_22_DIAG_RSP 1
#define INTERTP_RX_PDUS_CNT 1
#define INTERTP_TX_PDUS_CNT 1
#define INTERTP_PDUS_CNT (INTERTP_RX_PDUS_CNT + INTERTP_TX_PDUS_CNT)

typedef struct 
{
    uint8 id;
    uint8 bus;
    uint8 src;
    uint8 dest;
    uint8 srcPduId;
    uint8 destPduId;
    uint8 dir;
}InterTpPduType;

extern const InterTpPduType interTpPdusCfgTable[];

#endif
