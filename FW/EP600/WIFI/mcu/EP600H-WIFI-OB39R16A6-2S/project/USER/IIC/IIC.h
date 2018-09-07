/*--------------------------------------------------------------------------
Header file for IIC Master.
Modify on 02/24/2014.
--------------------------------------------------------------------------*/

#ifndef __IIC_MASTER_H__
#define __IIC_MASTER_H__

// Example Code
/*
void main()
{
    IIC_Init_master();
    Check_Arbitration();    // multi-master use
    Check_Busy();           // multi-master use
    while(1)
    {
        Delay(100);
        IIC_Current_Address_Read(d_DEVICE_ID);
        Delay(100);
        IIC_Byte_Write(d_DEVICE_ID, 0x00, 0x55);
        Delay(100);
        IIC_Page_Write(d_DEVICE_ID, 0x01, 5);
        Delay(100);
        IIC_Random_Read(d_DEVICE_ID, 0x01, 5);
        Delay(100);
        Sequential_Read(d_DEVICE_ID, 5);
    }
}

*/

#define d_DEVICE_ID     0xA0      // user modify

void IIC_Init_master(void);
void IIC_Disable(void);
//void IIC_SendStart(unsigned char ControlByte);  //Start & Re-Start
bit IIC_SendStart(unsigned char ControlByte);     //Start & Re-Start
void IIC_SendStop(void);
unsigned char IIC_ReceiveByte(bit ACKStatus);
void IIC_TransmitByte(unsigned char TxData);
void IIC_Page_Write(unsigned char Crtl_byte, unsigned char Addr, unsigned char LEN);
void IIC_Random_Read(unsigned char Crtl_byte, unsigned char Addr, unsigned char LEN);
void Check_Arbitration(void);       // multi-master use
void Check_Busy(void);              // multi-master use
void IIC_Current_Address_Read(unsigned char Crtl_byte);
void Delay(unsigned int NTime);
void IIC_Byte_Write(unsigned char Crtl_byte,unsigned char Addr, unsigned char Data);
void Sequential_Read(unsigned char Crtl_byte, unsigned char LEN);

#endif
