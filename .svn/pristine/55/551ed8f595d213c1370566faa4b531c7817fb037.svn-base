/**
 ******************************************************************************
 * @file    rabbit_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   Rabbit Test Demo  based on MiCO !
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
 *  Functional Description of rabbit_test.c
 *
 *  Demo Function:
 *  To encrypt and decrypt for string of test_rabbit[].input through Rabbit algorithm.
 *
 *  Compare cipher text with test_rabbit[].output, which is predefined cipher text after encryption.
 *  Compare plain text with  test_rabbit[].input after decryption.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "Rabbit Test passed!".
 *  If the result is not correct,stop the process and display the error message
 *  such as "Rabbit Test Failed! The Wrong Number is 1!"
 *
 *  Note:
 *  Users can change the string valude of test_rabbit[].input to validate rabbit
 *  algorithm function. But the test_rabbit[].input must be within 1 to 16 bytes.
 *
 *******************************************************************************************
 **/

#include "mico.h" 

#define rabbit_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  rabbit_test(void);


int application_start(void)
{
    int ret = 0;
 
    rabbit_test_log( "Rabbit Test Start \r\n" );
    
    if ( (ret = rabbit_test()) != 0)        
        rabbit_test_log("Rabbit Test Failed!  The Wrong Number is %d",ret);
    
    else
        rabbit_test_log("Rabbit Test Passed!");
    
    return 0;

}


/*********************  Defination of rabbit_test() ***************************/
int rabbit_test(void)
{
    byte cipher[16];
    byte plain[16];

    const char* keys[] = 
    {    /* each keys[i] must be 128 bits��16 bytes��*/     
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
        "\xAC\xC3\x51\xDC\xF1\x62\xFC\x3B\xFE\x36\x3D\x2E\x29\x13\x28\x91",
    };

    const char* ivs[] =
    {   /* each iv[i] must be 64 bits��8 bytes��*/     
        "\x00\x00\x00\x00\x00\x00\x00\x00",
        "\x59\x7E\x26\xC1\x75\xF5\x73\xC3",       
    };

    testVector a, b, c;
    testVector test_rabbit[3];

    int times = sizeof(test_rabbit) / sizeof(testVector);

    a.input  = "\x00\x00\x00\x00\x00\x00\x00\x00";
    a.output = "\xED\xB7\x05\x67\x37\x5D\xCD\x7C";
    a.inLen  = 8;/* must be the right number of bytes of input*/
    a.outLen = 8;/* must be the right number of bytes of output*/

    b.input  = "\x00\x00\x00\x00\x00\x00\x00\x00\x00";
    b.output = "\x6D\x7D\x01\x22\x92\xCC\xDC\xE0\xE2";
    b.inLen  = 9;
    b.outLen = 9;

    c.input  = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
    c.output = "\x04\xCE\xCA\x7A\x1A\x86\x6E\x77\xFC\xCA";
    c.inLen  = 10;
    c.outLen = 10;

    test_rabbit[0] = a;
    test_rabbit[1] = b;
    test_rabbit[2] = c;

    for (int i = 0; i < times; ++i) 
    {
        Rabbit enc;
        Rabbit dec;
        byte*  iv;

        /* align keys/ivs in plain/cipher buffers */
        memcpy(plain,  keys[i],16);
        
        /* get 64 bits iv */
        if (ivs[i]) {
            memcpy(cipher, ivs[i],8);
            iv = cipher;
        } else
            iv = NULL;
        
        RabbitSetKey(&enc, plain, iv);
        RabbitSetKey(&dec, plain, iv);
        
        
        /* align input */
        memcpy(plain, test_rabbit[i].input, test_rabbit[i].outLen);
        
        /* Rabbit Encryption process */
        RabbitProcess(&enc, cipher, plain,  (word32)test_rabbit[i].outLen);
        
        /*Print the cipher text */
        printf("The %d's Cipher Text is: ",i+1);
        for(int j=0;j<test_rabbit[i].outLen;j++)
        {
            printf("-%x",cipher[j]);
         }
        printf("\r\n");
        printf("\r\n");
        
        /* Rabbit Decryption process */

        RabbitProcess(&dec, plain,  cipher, (word32)test_rabbit[i].outLen);
        
        /*Print the plain text */
        printf("The %d's Plain  Text is: ",i+1);
        for(int j=0;j<test_rabbit[i].outLen;j++)
        {
            printf("-%x",plain[j]);
         }
         printf("\r\n");    
         printf("\r\n");
 
         /* Compare plain text��generated from decryption, with test_rabbit[i].input defined */  
         if (memcmp(plain, test_rabbit[i].input, test_rabbit[i].outLen))
           return  i+1;

         /* Compare cipher text, generated from encryption, with vtest_rabbit[i].output predefined */           
         if (memcmp(cipher, test_rabbit[i].output, test_rabbit[i].outLen))
           return  -(i+1);
    }

    return 0;
}
