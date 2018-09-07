/**
 ******************************************************************************
 * @file    aes_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   AES in CBC mode Test Demo  based on MiCO !
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
 *
 ******************************************************************************
 *
 *  Functional Description of aes_test.c
 *
 *  Demo Function:
 *  To encrypt and decrypt for string for msg[] through AES algorithm in Cbc mode.
 *
 *  Compare cipher text with verify[], which is predefined cipher text,after encryption.
 *  Compare plain text with msg[] after decryption.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "AES in CBC mode Test passed!".
 *  If the result is not correct,stop the process and display the error message
 *  such as "AES in CBC mode Test Failed! The Error Code is 1!"
 *
 *  Note:
 *  Users can change the string value of msg[] to validate AES algorithm function.
 *  But the length of msg[] must be a multiple of 16 bytes.
 *******************************************************************************************
 **/

#include "mico.h" 

#define aes_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  aes_test(void);


int application_start(void)
{
    int ret = 0;
 
    aes_test_log( "AES in CBC mode Test Start\r\n" );
    
    if ( (ret = aes_test()) != 0)        
        aes_test_log("AES in CBC mode Test Failed!  The Error Code is %d",ret);
    
    else
        aes_test_log("AES in CBC mode Test Passed!");
    
    return 0;

}
/*********************  Defination of aes_test() ***************************/
int aes_test(void)
{
    Aes enc;
    Aes dec;

    
    /* Defination of input string to be used AES Enryption */
    
    const byte msg[] = { /*length must be a multiple of 128 bits ��16 bytes��*/
        0x6e,0x6f,0x77,0x20,0x69,0x73,0x20,0x74,
        0x68,0x65,0x20,0x74,0x69,0x6d,0x65,0x20,
   };

    const byte verify[] = 
    {
        0x95,0x94,0x92,0x57,0x5f,0x42,0x81,0x53,
        0x2c,0xcc,0x9d,0x46,0x77,0xa2,0x33,0xcb,
    };
 
    byte key[] = "0123456789abcdef";  /* align  Must be 128 bits */
    byte iv[]  = "1234567890abcdef";  /* align  Must be 128 bits */
    
    byte cipher[AES_BLOCK_SIZE * 8];
    byte plain [AES_BLOCK_SIZE * 8];
    
   
    AesSetKey(&enc, key, AES_BLOCK_SIZE, iv, AES_ENCRYPTION);
    AesSetKey(&dec, key, AES_BLOCK_SIZE, iv, AES_DECRYPTION);
    
    /* Encryption process */
    AesCbcEncrypt(&enc, cipher, msg, sizeof(msg));
    
    /* Printf cipher text */
    printf("The Cipher Text is: "); 
    for(int i=0;i<sizeof(msg);i++)
    {
        printf("-%x",cipher[i]);    /* Print Cipher Text after encryption */
    }
    printf("\r\n");
    printf("\r\n");

    /* Decryption process */
    AesCbcDecrypt(&dec, plain, cipher, sizeof(cipher));
    
    /* Print plain text */
    printf("The Plain Text is: "); 
    for(int i=0;i<sizeof(msg);i++)
    {
        printf("-%x",plain[i]);    /* Print Plain Text after decryption */
    }
    printf("\r\n");
    printf("\r\n");
    
    /* Compare cipher text, generated from encryption, with verify[] predefined */    
    if (memcmp(cipher, verify, sizeof(msg)))
        return -1;
    
    
    /* Compare plain text generated from decryption, with msg[] defined */
    if (memcmp(plain, msg, sizeof(msg)))
        return 1;
 
    return 0;
}


