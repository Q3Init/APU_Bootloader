#ifndef _BSW_PDUR_H
#define _BSW_PDUR_H

#include "Platform_Types.h"
#include "ComStack_Types.h"
#include "BSW_PduRCfg.h"

extern void PduR_RxIndication(uint16 pduId, const PduInfoType *pduInfoPtr);
extern void PduR_Transmit(uint16 pduId, const PduInfoType *pduInfoPtr);
extern void PduR_TxConfirmation(void);

#endif
