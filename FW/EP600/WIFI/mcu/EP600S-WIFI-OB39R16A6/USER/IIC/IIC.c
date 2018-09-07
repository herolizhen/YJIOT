#include "OB39R16A6.h"
#include "IIC.h"

//===============================
//IIC DEFINITIONs
//===============================

#define d_BR32          0x00
#define d_BR64          0x01
#define d_BR128         0x02
#define d_BR256         0x03
#define d_BR512         0x04
#define d_BR1024        0x05
#define d_BR2048        0x06
#define d_BR4096        0x07
#define d_IIC_BR        d_BR128     // user modify

#define d_MASTER        0x40
#define d_SLAVE         0x00
#define d_MODE_SEL      d_MASTER    // use master mode
#define d_IIC_EN        0x80
#define d_NACK          1
#define d_ACK           0
#define d_WRITE         0
#define d_READ          1

#define d_BB_DIS        0x00
#define d_BB_EN         0x08
#define d_BUS_BUSY      d_BB_EN
#define d_AR_DIS        0x00
#define d_AR_EN         0x10
#define d_ARBITRATION   d_AR_EN

#define d_CMD_RW        0x40
#define d_CMD_Start     0x80
#define d_CMD_Stop      0xC0

//===============================================================
//OWNED SUBROUTINES
//===============================================================

unsigned char IIC_TxBuf[16] = {0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,0xC0,0xD0,0xE0,0xF0};//For example	

void Delay(unsigned int NTime)
{
    unsigned int i, j;
    for (i = 0; i < NTime; i++)
    {
        for (j = 0; j < 100; j++)
        {
            ;
        }
    }
}

void IIC_interrupt(void) interrupt d_IIC_Vector
{
    if(TXIF)
    {
        TXIF = 0;                   // Clear interrupt flag
    }
    if(RXIF)
    {
        RXIF = 0;                   // Clear interrupt flag
    }
    if(MPIF)
    {
        MPIF = 0;                   // Clear interrupt flag
    }
}

void IIC_Init_master(void)
{
    IICA1   = d_DEVICE_ID;
    IICS    = 0x00;                 // Clear IIC all status
    IEN0   |= 0x80;                 // Enable interrupt All
    IEN1   |= 0x20;                 // Enable interrupt IIC
    IICCTL  = d_IIC_EN | d_MODE_SEL | d_ARBITRATION | d_BUS_BUSY | d_IIC_BR;
}

void IIC_Disable(void)
{
    IICCTL   = 0x00;                // Disable IIC all function
    IEN1    &= 0xDF;                // Disable interrupt IIC
    IICS     = 0x00;                // Clear IIC all status
}

//===============================================================
//This function will send out the Start or Re-Start pulse and CONTROL byte.
//===============================================================
bit IIC_SendStart(unsigned char ControlByte)
{
    IICA1  = ControlByte;           // MAS = 0
        
    IICEBT = d_CMD_Start;           // generate a start condition
    while(IICEBT != 0x00)
    {
        ;
    }
    return RXAK;
}

//===============================================================
//This function will send out the Stop pulse
//===============================================================
void IIC_SendStop(void)
{
    IICEBT = d_CMD_Stop;            // generate a stop condition
    while(IICEBT != 0x00)           // waiting data recive finish
    {
        ;
    }
}
//===============================================================
//This function will wait and receive one byte, then feedback ACK or NACK.
//===============================================================
unsigned char IIC_ReceiveByte(bit ACKStatus)
{
    unsigned char temp;
    TXAK    = ACKStatus;            // Feedback ACK/d_NACK to slave
    IICEBT  = d_CMD_RW;             // Ready for receive

    while(IICEBT != 0x00)           // waiting data recive finish
    {
        ;
    }
    temp = IICRWD;
    Delay(100);                     // finetune by user
    return(temp);
}

void IIC_TransmitByte(unsigned char TxData)
{
    IICRWD = TxData;                // load data
    IICEBT = d_CMD_RW;              // trans. data
    while(IICEBT != 0x00)           // waiting data trans. finish
    {
        ;
    }
    Delay(100);                     // finetune by user
}

void IIC_Page_Write( unsigned char Crtl_byte, unsigned char Addr, unsigned char LEN)
{
    unsigned char counter;

    IIC_SendStart(Crtl_byte | d_WRITE);                 // -- Send CONTROL byte --

    if (RXAK == d_ACK)
    {
        IIC_TransmitByte( Addr );                       // -- Send ADDRESS --
                          
        for (counter = 0; counter < LEN; counter++)     // -- Write N bytes --
        {
            if (RXAK == d_ACK)
            {
                IIC_TransmitByte(IIC_TxBuf[counter]);   // -- Transmit one byte --
            }
        }
    }
    IIC_SendStop();                 // -- Send STOP -- MStart= 0
}


void IIC_Random_Read(unsigned char Crtl_byte, unsigned char Addr, unsigned char LEN)
{
    unsigned char counter;
    unsigned char Temp[16];
    
    IIC_SendStart(Crtl_byte | d_WRITE);             // -- Send CONTROL byte --
    if (RXAK == d_ACK)
    {
        IIC_TransmitByte(Addr);                     // -- Send ADDRESS --
    
        if (RXAK == d_ACK)
        {
            IIC_SendStart(Crtl_byte | d_READ);      // -- Send CONTROL byte --
            for (counter = 0; counter < LEN; counter++)         // -- Read N byte --
            {
                if (RXAK == d_ACK)
                {
                    if (counter < (LEN-1))
                    {
                        Temp[counter] = IIC_ReceiveByte(d_ACK); // Receive one byte
                    }
                    else
                    {
                        Temp[counter] = IIC_ReceiveByte(d_NACK);// Receive last byte
                    }
                }
            }
        }
    }
    IIC_SendStop();     // -- Send STOP -- MStart= 0 
}

void Check_Arbitration(void)    // multi-master use
{
    // arbitration lost, set by H/W
    // clear by S/W
    while(LAIF)
    {
        LAIF = 0;
    }
}

void Check_Busy(void)    // multi-master use
{
    // Bus busy, BB set by H/W
    // Bus ready, BB clear by H/W or S/W
    while(BB)
    {
        ;
    }
}

void IIC_Current_Address_Read(unsigned char Crtl_byte)
{
    unsigned char Temp;

    IIC_SendStart(Crtl_byte | d_READ);      // -- Send CONTROL byte --
    if (RXAK == d_ACK)
    {
        Temp = IIC_ReceiveByte(d_NACK);     // Receive one byte
    }

    IIC_SendStop();                         // -- Send STOP -- MStart= 0
}

void IIC_Byte_Write(unsigned char Crtl_byte,unsigned char Addr, unsigned char Data)
{
    IIC_SendStart(Crtl_byte | d_WRITE);     // -- Send CONTROL byte --

    if (RXAK == d_ACK)
    {
        IIC_TransmitByte(Addr);             // -- Send ADDRESS --
        if (RXAK == d_ACK)
        {
            IIC_TransmitByte(Data);         // -- Transmit one byte --
        }
    }
    IIC_SendStop();                         // -- Send STOP -- MStart = 0
}

void Sequential_Read(unsigned char Crtl_byte, unsigned char LEN)
{
    unsigned char Temp[16];
    unsigned char counter;

    IIC_SendStart(Crtl_byte | d_READ);      // -- Send CONTROL byte --
    for(counter=0; counter<LEN; counter++)  // -- Read N byte --
    {
        if(RXAK==d_ACK)
        {
            if(counter<(LEN-1))
            {
                Temp[counter] = IIC_ReceiveByte(d_ACK); // Receive one byte
            }
            else
            {
                Temp[counter] = IIC_ReceiveByte(d_NACK);// Receive last byte
            }
        }
    }
    IIC_SendStop();         // -- Send STOP -- MStart= 0
}

