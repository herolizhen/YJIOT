/*--------------------------------------------------------------------------
Copyright (c) SyncMOS Technologies International, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef     __OB39R16A6_H__
#define     __OB39R16A6_H__

//-------------SYSTEM-----------------
sfr SP      = 0x81;
sfr ACC     = 0xE0;
sfr PSW     = 0xD0;
sfr B       = 0xF0;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr DPL1    = 0x84;
sfr DPH1    = 0x85;
sfr AUX     = 0x91; 
sfr PCON    = 0x87;
sfr CKCON   = 0x8E;
sfr PAGESEL = 0xBE;

//-------INTERRUPT & PRIORITY---------
sfr IRCON   = 0xC0;
sfr IRCON2  = 0x97;
sfr IEN0    = 0xA8;
sfr IEN1    = 0xB8;
sfr IEN2    = 0x9A;
sfr IP0     = 0xA9;
sfr IP1     = 0xB9;

//----------------UART-----------------
sfr SCON    = 0x98;       
sfr SBUF    = 0x99;
sfr SRELL   = 0xAA;
sfr SRELH   = 0xBA;
sfr PFCON   = 0xD9;
sfr S0CON   = 0x98;       
sfr S0BUF   = 0x99;
sfr S0RELL  = 0xAA;
sfr S0RELH  = 0xBA;

//----------------ADC------------------
sfr ADCC1   = 0xAB;
sfr ADCC2   = 0xAC;
sfr ADCDH   = 0xAD;
sfr ADCDL   = 0xAE;
sfr ADCCS   = 0xAF;

//----------------WDT------------------
sfr RSTS    = 0xA1;      
sfr WDTC    = 0xB6;
sfr WDTK    = 0xB7;
sfr TAKEY   = 0xF7;

//---------------PWM-------------------
sfr PWMTBC0         = 0xF9;
sfr PWMTBC1         = 0xFA;
sfr PWMOPMOD        = 0xFB;
sfr PERIODL         = 0xF1;
sfr PERIODH         = 0xF2;
sfr PWMEN           = 0xF5;
sfr PWMTBPOSTSCALE  = 0xEE;
sfr PWMINTF         = 0xBC;
sfr DEADTIME2       = 0xEB;
sfr DEADTIME3       = 0xEC;
sfr DUTY2L          = 0xD5;
sfr DUTY2H          = 0xD6;
sfr DUTY3L          = 0xD7;
sfr DUTY3H          = 0xC9;


//------------TIMER0/TIMER1--------------
sfr TCON    = 0x88;
sfr TMOD    = 0x89;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;

//-------------PCA(TIMER2)---------------
sfr CCEN    = 0xC1;
sfr CCL1    = 0xC2;
sfr CCH1    = 0xC3;
sfr CCL2    = 0xC4;
sfr CCH2    = 0xC5;
sfr CCL3    = 0xC6;
sfr CCH3    = 0xC7;
sfr T2CON   = 0xC8;
sfr CCCON   = 0xC9;
sfr CRCL    = 0xCA;
sfr CRCH    = 0xCB;
sfr TL2     = 0xCC;
sfr TH2     = 0xCD;
sfr CCEN2   = 0xD1;

sfr16   CC1 = 0xC2;
sfr16   CC2 = 0xC4;
sfr16   CC3 = 0xC6;
sfr16   CRC = 0xCA;
sfr16   T2  = 0xCC; // TH2 | TL2

//----------------GPIO-------------------
sfr P0      = 0x80;
sfr P1      = 0x90;
sfr P2      = 0xA0;
sfr P3      = 0xB0;
sfr P0M0    = 0XD2;
sfr P0M1    = 0XD3;
sfr P1M0    = 0XD4;
sfr P1M1    = 0XD5;
sfr P2M0    = 0XD6;
sfr P2M1    = 0XD7;
sfr P3M0    = 0XDA;
sfr P3M1    = 0XDB;

//-----------ISP/IAP/EEPROM--------------
sfr IFCON   = 0x8F;
sfr ISPFAH  = 0xE1;
sfr ISPFAL  = 0xE2;
sfr ISPFD   = 0xE3;
sfr ISPFC   = 0xE4;

//----------LVI/LVR/SOFTRESET------------
sfr RCON    = 0x86;
sfr LVC     = 0xE6;
sfr SWRES   = 0xE7;

//----------------SPI--------------------
sfr SPIC1   = 0xF1;
sfr SPIC2   = 0xF2;
sfr SPITXD  = 0xF3;
sfr SPIRXD  = 0xF4;
sfr SPIS    = 0xF5;

//----------------IIC--------------------
sfr IICS    = 0xF8;
sfr IICCTL  = 0xF9;
sfr IICA1   = 0xFA;
sfr IICA2   = 0xFB;
sfr IICRWD  = 0xFC;
sfr IICEBT  = 0xFD;

//----------------MDU--------------------
sfr MD0     = 0xE9;
sfr MD1     = 0xEA;
sfr MD2     = 0xEB;
sfr MD3     = 0xEC;
sfr MD4     = 0xED;
sfr MD5     = 0xEE;
sfr ARCON   = 0xEF;

//---------------------------------------
//---------------------------------------
//---------------------------------------

/*  P0  */
sbit P0_0   = P0^0;
sbit P0_1   = P0^1;
sbit P0_2   = P0^2;
sbit P0_3   = P0^3;
sbit P0_4   = P0^4;
sbit P0_5   = P0^5;
sbit P0_6   = P0^6;
sbit P0_7   = P0^7;

/*  P1  */  
sbit P1_0   = P1^0;
sbit P1_1   = P1^1;
sbit P1_2   = P1^2;
sbit P1_3   = P1^3;
sbit P1_4   = P1^4;
sbit P1_5   = P1^5;
sbit P1_6   = P1^6;
sbit P1_7   = P1^7;

/*  P2  */ 
sbit P2_0   = P2^0;
sbit P2_1   = P2^1;
sbit P2_2   = P2^2;
sbit P2_3   = P2^3;
sbit P2_4   = P2^4;
sbit P2_5   = P2^5;
sbit P2_6   = P2^6;
sbit P2_7   = P2^7;

/*  P3  */ 
sbit P3_0   = P3^0;
sbit P3_1   = P3^1;
sbit P3_2   = P3^2;
sbit P3_3   = P3^3;
sbit P3_4   = P3^4;
sbit P3_5   = P3^5;
sbit P3_6   = P3^6;
sbit P3_7   = P3^7;

/* IEN0 */
sbit EA    = IEN0^7;
sbit ET2   = IEN0^5;
sbit ES0   = IEN0^4;
sbit ET1   = IEN0^3;
sbit EX1   = IEN0^2;
sbit ET0   = IEN0^1;
sbit EX0   = IEN0^0;

/* SCON */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  IICS    */
sbit MPIF   = IICS^6;
sbit LAIF   = IICS^5;
sbit RXIF   = IICS^4;
sbit TXIF   = IICS^3;
sbit RXAK   = IICS^2;
sbit TXAK   = IICS^1;
sbit RW     = IICS^0;
sbit BB     = IICS^0;

/* TCON */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/* IEN1 */
sbit EXEN2 = IEN1^7;
sbit IEIIC = IEN1^5;
sbit IELVI = IEN1^4;
sbit IEADC = IEN1^2;
sbit IESPI = IEN1^1;

/* IRCON */
sbit EXF2   = IRCON^7;
sbit TF2    = IRCON^6;
sbit IICIF  = IRCON^5;
sbit LVIIF  = IRCON^4;
sbit ADCIF  = IRCON^2;
sbit SPIIF  = IRCON^1;



/*  Interrupt Defin */
#define         d_INT0_Vector           0   //0003h
#define         d_T0_Vector             1   //000Bh
#define         d_INT1_Vector           2   //0013h
#define         d_T1_Vector             3   //001Bh
#define         d_UART0_Vector          4   //0023h
#define         d_T2_Vector             5   //002Bh
#define         d_PWM_Vector            8   //0043h
#define         d_SPI_Vector            9   //004Bh
#define         d_ADC_Vector            10  //0053h
#define         d_LVI_Vector            12  //0063h
#define         d_IIC_Vector            13  //006Bh
#define         d_WDT_Vector            17  //008Bh


#endif
    