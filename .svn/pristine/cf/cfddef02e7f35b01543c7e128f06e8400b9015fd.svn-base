#include "OB39R16A6.h"
#include "ADC.h"
#include "wifi_uart.h"
#include "TM1620.h"

//#define d_ADCnEN        0x01
//#define d_ADC_CLK_Sel   d_ADC_CLK_DIV64
unsigned int n_data;
bit ADCfinish = 0;

void ADCstart(unsigned char n_ADC_CH)
{  
    ADCC2 &= 0x7F;      //ADC stop conversion 
    ADCC2  = n_ADC_CH;  //Set a new channel
    ADCC2 |= (0x80 | (1 << 3));      //ADC start conversion
}

void ADCInit(unsigned char n_ADCnEN, unsigned char n_ADC_CLK)
{
    ADCC1 = n_ADCnEN;   //Set ADC channel 
    ADCCS = n_ADC_CLK;  //Select ADC clock
    IEADC = 1;          //Enable ADC interrupt.
    EA    = 1;
}

unsigned int ADC_Read10()//10-bit ADC
{
    unsigned int n_ADCD10 = 0x0000;
    n_ADCD10 = (ADCDH<<2)|ADCDL;    //10-bit ADC
    return n_ADCD10;
}

void ADCInterrupt(void) interrupt d_ADC_Vector  // ADC Interrupt Vector Address 0053h => interrupt 10
{
    n_data = ADC_Read10();  //Read ADC
    ADCfinish = 1;    
}

/*
void ADC_stop(void)
{
    ADCC2 &= 0x7F;  //ADC stop conversion
    IEADC = 0;      //Disable ADC interrupt
}
*/

/*
void ADC(void)
{ 
    if (d_ADCnEN & 0x01)
    {
        ADCstart(d_ADC_CH0_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x02)
    {
        ADCstart(d_ADC_CH1_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x04)
    {
        ADCstart(d_ADC_CH2_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x08)
    {
        ADCstart(d_ADC_CH3_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x10)
    {
        ADCstart(d_ADC_CH4_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x20)
    {
        ADCstart(d_ADC_CH5_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x40)
    {
        ADCstart(d_ADC_CH6_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
    if (d_ADCnEN & 0x80)
    {
        ADCstart(d_ADC_CH7_IN);
        while(!ADCfinish);
        ADCfinish = 0;
    }
}

void ADC_test(void)
{
    if(ADCfinish)
    {
    
    }
}
*/