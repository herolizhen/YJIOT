/**
 ******************************************************************************
 * @file    des_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   DES Test Demo  based on MiCO !
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2016 MXCHIP Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 *
 *  Functional Description of des_test.c
 *
 *  Demo Function:
 *  To encrypt and decrypt for string for vector[] through DES algorithm.
 *
 *  Compare cipher text with verify[], which is predefined cipher text,after
 *  encryption.
 *  Compare plain text with vector[] after decryption.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "DES Test passed!".
 *  If the result is not correct,stop the process and display the error message
 *  such as "DES Test Failed! The Error Code is 1!"
 *
 *  Note:
 *  Users can change the string value of vector[] to validate DES algorithm
 *  function.
 *  But the length of vector[] must be the multiple of 8 bytes.
 *
 *******************************************************************************
 **/

#include "mico.h" 

#define des_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  des_test(void);


int application_start(void)
{
    int ret = 0;
 
    des_test_log( "DES Test Start\r\n" );
    
    if ( (ret = des_test()) != 0)        
        des_test_log("DES Test Failed!  The Error Code is %d",ret);
    
    else
        des_test_log("DES Test Passed!");
    
    return 0;

}


/*********************  Defination of des_test() ***************************/

int des_test(void)
{
  
  /* Defination of input string to be used DES Enryption */
    const byte vector[] = { /* length must be a multiple of 8 bytes */
        0x6e,0x6f,0x77,0x20,0x69,0x73,0x20,0x74,
        0x68,0x65,0x20,0x74,0x69,0x6d,0x65,0x20,
        0x66,0x6f,0x72,0x20,0x61,0x6c,0x6c,0x20,
        
    };

    byte plain[24];
    byte cipher[24];

    Des enc;
    Des dec;

    const byte key[] = 
    {
        0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
    };

    const byte iv[] = 
    {
        0x12,0x34,0x56,0x78,0x90,0xab,0xcd,0xef
    };

    const byte verify[] = 
    {
        0x8b,0x7c,0x52,0xb0,0x01,0x2b,0x6c,0xb8,
        0x4f,0x0f,0xeb,0xf3,0xfb,0x5f,0x86,0x73,
        0x15,0x85,0xb3,0x22,0x4b,0x86,0x2b,0x4b
    };

    
    
    Des_SetKey(&enc, key, iv, DES_ENCRYPTION);
    Des_SetKey(&dec, key, iv, DES_DECRYPTION);
    
    
    /* Encryption Process */  
    Des_CbcEncrypt(&enc, cipher, vector, sizeof(vector));

    /* Print the cipher text */
    printf("The Cipher Text is:");
    for(int i=0;i<sizeof(vector);i++)
        {
           printf("-%x",cipher[i]); /* Print Cipher Text after encryption */
        }
        printf("\r\n");
        printf("\r\n");

        
    /* Decryption Process */    
    Des_CbcDecrypt(&dec, plain, cipher, sizeof(cipher));
    
    /* Print the plain text */
    printf("The Plain Text is:");
    for(int i=0;i<sizeof(vector);i++)
        {
           printf("-%x",plain[i]); /* Print Plain Text after decryption */
        }
        printf("\r\n");
        printf("\r\n");
 
        
     /* Compare cipher text, generated from encryption, with verify[] predefined */           
    if (memcmp(cipher, verify, sizeof(cipher)))
        return -1;
    
    
    /* Compare plain text��generated from decryption, with vector defined */           
    if (memcmp(plain, vector, sizeof(plain)))
        return 1;


    return 0;
}
