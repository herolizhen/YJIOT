#ifndef __ION_H__
#define __ION_H__

#include "OB39R32T1.h"

//wifi board
//#define ION_CONTROL_PIN   P2_5
//#define ION_PIN_PORTBIT   5
//#define ION_PIN_PxM0      P2M0
//#define ION_PIN_PxM1      P2M1

//m26 board
#define ION_CONTROL_PIN   P2_3
#define ION_PIN_PORTBIT   3
#define ION_PIN_PxM0      P2M0
#define ION_PIN_PxM1      P2M1


void ION_Pin_Init(void);
void ION_On(void);
void ION_Off(void);


#endif