#ifndef __ION_H__
#define __ION_H__

#include "OB39R16A6.h"

#define ION_CONTROL_PIN   P2_5
#define ION_PIN_PORTBIT   5
#define ION_PIN_PxM0      P2M0
#define ION_PIN_PxM1      P2M1


void ION_Pin_Init(void);
void ION_On(void);
void ION_Off(void);


#endif