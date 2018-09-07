#ifndef _OB39A08T1_H_
#define _OB39A08T1_H_

sfr   P0          = 0x80;
sfr   P1          = 0x90;
sfr   P2          = 0xA0;
sfr   P3          = 0xB0;

sfr   PSW         = 0xD0;
sfr   ACC         = 0xE0;
sfr   B           = 0xF0;
sfr   SP          = 0x81;
sfr   DPL         = 0x82;
sfr   DPH         = 0x83;
sfr   DPL1        = 0x84;
sfr   DPH1        = 0x85;
sfr   PCON        = 0x87;
sfr   TCON        = 0x88;
sfr   TMOD        = 0x89;
sfr   TL0         = 0x8A;
sfr   TL1         = 0x8B;
sfr   TH0         = 0x8C;
sfr   TH1         = 0x8D;
sfr   CKCON       = 0x8E;
sfr   IFCON       = 0x8f;
sfr   AUX         = 0X91;
sfr   IEN0        = 0xA8;
sfr   IEN1        = 0xB8;
sfr   IEN2        = 0x9A;
sfr   PFCON       = 0xD9;

sfr   P0M0        = 0xD2;
sfr   P0M1        = 0xD3;
sfr   P1M0        = 0xD4;
sfr   P1M1        = 0xD5;
sfr   P2M0        = 0xD6;
sfr   P2M1        = 0xD7;
sfr   P3M0        = 0xDA;
sfr   P3M1        = 0xDB;

sfr   IP0         = 0xA9;
sfr   IP1         = 0xB9;
sfr   LVC         = 0xE6;
sfr   ENHIT       = 0xE5;
sfr   IRCON       = 0xC0;
sfr   IRCON2      = 0x97;
sfr   RSTS        = 0xA1;
sfr   PERSD       = 0xBD;
//----------LCD----------------------
sfr   SCOMEN      = 0xF1;
sfr   SCOMDATA    = 0xF2;
//----------CCU----------------------
sfr   T2CON       = 0xC8;
sfr   CCEN        = 0xC1;
sfr   CCEN2       = 0xD1;
sfr   CRCL        = 0xCA;
sfr   CRCH        = 0xCB;
sfr16 CRC_16      = 0xCA;
sfr   TL2         = 0xCC;
sfr   TH2         = 0xCD;
sfr16 T2COUNT_16  = 0xCC;
sfr   CCL1        = 0xC2;
sfr   CCH1        = 0xC3;
sfr16 CC1_16      = 0xC2;
sfr   CCL2        = 0xC4;
sfr   CCH2        = 0xC5;
sfr16 CC2_16      = 0xC4;
sfr   CCL3        = 0xC6;
sfr   CCH3        = 0xC7;
sfr16 CC3_16      = 0xC6;
//----------WDT----------------------
sfr   WDTK        = 0xB7;
sfr   WDTC        = 0xB6;
//----------ISP----------------------
sfr   ISPFAH      = 0xE1;
sfr   ISPFAL      = 0xE2;
sfr   ISPFD       = 0xE3;
sfr   ISPFC       = 0xE4;
//----------MDU----------------------
sfr   MD0         = 0xE9;
sfr   MD1         = 0xEA;
sfr   MD2         = 0xEB;
sfr   MD3         = 0xEC;
sfr   MD4         = 0xED;
sfr   MD5         = 0xEE;
sfr   ARCON       = 0xEF;
sfr   SWRES       = 0xE7;
//-----------------------------------
sfr   TAKEY       = 0xF7;
//------------UART-------------------
sfr   S0RELL      = 0xAA;
sfr   S0RELH      = 0xBA;
sfr   S0CON       = 0x98;
sfr   S0BUF       = 0x99;
//-------------IIC-------------------
sfr   IICS        = 0xF8;
sfr   IICCTL      = 0xF9;
sfr   IICA1       = 0xFA;
sfr   IICA2       = 0xFB;
sfr   IICRWD      = 0xFC;
sfr   IICEBT      = 0xFD;
//----------Touch Pad----------------
sfr   TKEN0       = 0x93;
sfr   TKEN1       = 0x94;
sfr   TKEN2       = 0x95;
sfr   TKC1        = 0x9B;
sfr   TKC2        = 0x9C;
sfr   TKCHN       = 0x9D;
sfr   TKCDL       = 0x9E;
sfr   TKCDH       = 0x9F;
sfr16 TKCD_16     = 0x9E;
sfr   STATUS0     = 0xDC;
sfr   STATUS1     = 0xDD;
sfr   STATUS2     = 0xDE;
#define zTouchData       ((unsigned int volatile xdata*)0x0173)
#define zTouchAvgData    ((unsigned int volatile xdata*)0x012B)

//-----------------------------------
sbit  P0_0        = P0^0;
sbit  P0_1        = P0^1;
sbit  P0_2        = P0^2;
sbit  P0_3        = P0^3;
sbit  P0_4        = P0^4;
sbit  P0_5        = P0^5;
sbit  P0_6        = P0^6;
sbit  P0_7        = P0^7;

sbit  P1_0        = P1^0;
sbit  P1_1        = P1^1;
sbit  P1_2        = P1^2;
sbit  P1_3        = P1^3;
sbit  P1_4        = P1^4;
sbit  P1_5        = P1^5;
sbit  P1_6        = P1^6;
sbit  P1_7        = P1^7;

sbit  P3_0        = P3^0;
sbit  P3_1        = P3^1;
sbit  P3_2        = P3^2;
sbit  P3_3        = P3^3;
sbit  P3_4        = P3^4;
sbit  P3_5        = P3^5;
sbit  P3_6        = P3^6;  
sbit  P3_7        = P3^7;

sbit  P2_0        = P2^0;
sbit  P2_1        = P2^1;
sbit  P2_2        = P2^2;
sbit  P2_3        = P2^3;
sbit  P2_4        = P2^4;
sbit  P2_5        = P2^5;
sbit  P2_6        = P2^6;
sbit  P2_7        = P2^7;


sbit  EA          = IEN0^7;
sbit  ET2         = IEN0^5;
sbit  ES          = IEN0^4;
sbit  ET1         = IEN0^3;
sbit  EX1         = IEN0^2;
sbit  ET0         = IEN0^1;
sbit  EX0         = IEN0^0;

sbit  IELVI       = IEN1^4;
sbit  IEIIC       = IEN1^5;
sbit  EXEN2       = IEN1^7;


sbit  LVIIF       = IRCON^4;
sbit  IICIF       = IRCON^5;
sbit  TF2         = IRCON^6;
sbit  EXF2        = IRCON^7;

sbit  SM0         = S0CON^7;
sbit  SM1         = S0CON^6;
sbit  SM2         = S0CON^5;
sbit  REN         = S0CON^4;
sbit  TB8         = S0CON^3;
sbit  RB8         = S0CON^2;
sbit  TI0         = S0CON^1;
sbit  RI0         = S0CON^0;

/*  TCON  */
sbit  TF1         = TCON^7;
sbit  TR1         = TCON^6;
sbit  TF0         = TCON^5;
sbit  TR0         = TCON^4;
sbit  IE1         = TCON^3;
sbit  IT1         = TCON^2;
sbit  IE0         = TCON^1;
sbit  IT0         = TCON^0;
//-------------------------------------
sbit  MPIF        = IICS^6;
sbit  LAIF        = IICS^5;
sbit  RXIF        = IICS^4;
sbit  TXIF        = IICS^3;
sbit  RXAK        = IICS^2;
sbit  TXAK        = IICS^1;
sbit  RW          = IICS^0;
//-------------------------------------


#endif
