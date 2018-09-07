#include "OB39R16A6.h"
#include "LVI_LVR.h"

#define d_LVI_EN    0x01
#define d_LVR_EN    0x01

void LVI_EN(void)
{
    LVC   |= 0x80;
    IELVI  = 1;
    EA     = 1;
}

void LVR_Disable(void)
{
    LVC &= 0xDF;
}

void LVI(void) interrupt d_LVI_Vector
{

}
