/**
******************************************************************************
* @file    aes_ecb_test.c 
* @author  Jenny Liu
* @version V1.0.0
* @date    4-January-2016
* @brief   AES in ECB mode Test Demo  based on MiCO !
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
*  Functional Description of aes_test.c
*  
*  Demo Function:
*  To encrypt and decrypt for string for niPlain[] through AES algorithm in ECB mode.
*   
*  Compare cipher text with niCipher[], which is predefined cipher text,after encryption.
*  Compare plain text with niPlain[] after decryption.
*  Print the comparison results through serial port log.
*
*  If the result is correct, display message such as "AES in ECB mode Test passed!".
*  If the result is not correct,stop the process and display the error message 
*  such as "AES Test Failed! The Error Code is 1!" 
*
*  Note:
*  Users can change the string value of niPlain[] to validate AES algorithm function.
*  But the length of niPlain[] must be a multiple of 16 bytes.
*********************************************************************************************/

#include "mico.h" 

#define aes_ecb_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  aes_ecb_test(void);


int application_start(void)
{
    int ret = 0;
 
    aes_ecb_test_log( "AES Test Start\r\n" );
    
    if ( (ret = aes_ecb_test()) != 0)        
        aes_ecb_test_log("AES in ECB mode Test Failed!  The Error Code is %d",ret);
    
    else
        aes_ecb_test_log("AES in ECB mode Test Passed!");
    
    return 0;

}
            
            
            
/*********************  Definition of aes_test() ***************************/
int aes_ecb_test(void)
{
  
    Aes enc;
    Aes dec;
    
    const byte niPlain[] =
        {   /* Must be 128 bits */
            0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
            0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
        };

        const byte niCipher[] =
        {
            0xf3,0xee,0xd1,0xbd,0xb5,0xd2,0xa0,0x3c,
            0x06,0x4b,0x5a,0x7e,0x3d,0xb1,0x81,0xf8,
        };

        const byte niKey[] =
        {   /* Must be 256 bits */
            0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
            0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
            0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
            0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4,
        };
        
        byte cipher[AES_BLOCK_SIZE * 8];
        byte plain [AES_BLOCK_SIZE * 8];

        memset(cipher, 0, AES_BLOCK_SIZE);
        AesSetKey(&enc, niKey, sizeof(niKey), cipher, AES_ENCRYPTION);
        AesEncryptDirect(&enc, cipher, niPlain);
        
        /* Printf cipher text */
        printf("The Cipher Text is: "); 
        for(int i=0;i<sizeof(niCipher);i++)
                             
        {
            printf("-%x",cipher[i]);    /* Print Cipher Text after encryption */
        }
        printf("\r\n");
        printf("\r\n");  
        
        if (memcmp(cipher, niCipher, AES_BLOCK_SIZE) != 0)
            return -1;

        memset(plain, 0, AES_BLOCK_SIZE);
        AesSetKey(&dec, niKey, sizeof(niKey), plain, AES_DECRYPTION);
        AesDecryptDirect(&dec, plain, niCipher);
        
        /* Print plain text */
        printf("The Plain Text is: "); 
        for(int i=0;i<sizeof(niPlain);i++)
        {
            printf("-%x",plain[i]);    /* Print Plain Text after decryption */
        }
        printf("\r\n");
        printf("\r\n");
    
        if (memcmp(plain, niPlain, AES_BLOCK_SIZE) != 0)
            return 1;
 
    return 0;
}


