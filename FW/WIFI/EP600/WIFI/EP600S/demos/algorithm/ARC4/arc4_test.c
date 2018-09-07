/**
******************************************************************************
* @file    arc4_test.c 
* @author  Jenny Liu
* @version V1.0.0
* @date    4-January-2016
* @brief   ARC4 Test Demo  based on MiCO !
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
*  Functional Description of arc4_test.c
*  
*  Demo Function:
*  To encrypt and decrypt for string for test_arc4[].input through ARC4 algorithm.
*   
*  Compare cipher text with test_arc4[].output,which is predefined cipher text after encryption..
*  Compare plain text with test_arc4[].input after decryption.
*  Print the comparison results through serial port log.
*
*  If the result is correct, display message such as "ARC4 Test passed!".
*  If the result is not correct,stop the process and display the error message 
*  such as "ARC4 Test Failed! Decryption is wrong!" 
*
*  Note:
*  Users can change the string value of text_arc4[].input to validate ARC4 algorithm function.
*  But the length of vector[] must be within 1 -20 bytes.
*********************************************************************************************/

#include "mico.h" 

#define arc4_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  arc4_test(void);


int application_start(void)
{
    int ret = 0;
 
    arc4_test_log( "ARC4 Test Start!\r\n" );
    
    if ( (ret = arc4_test()) != 0)        
        arc4_test_log("ARC4 Test Failed!  The Error Code is %d",ret);
    
    else
        arc4_test_log("ARC4 Test Passed!");
    
    return 0;
}


/*********************  Defination of arc4_test() ***************************/
int arc4_test(void)
{
    byte cipher[16];
    byte plain[16];

    /* Defination of input string to be used ARC4 Enryption */
    const char* keys[] = 
    {           
        "\x01\x23\x45\x67\x89\xab\xcd\xef",
        "\x01\x23\x45\x67\x89\xab\xcd\xef",
        "\x00\x00\x00\x00\x00\x00\x00\x00",
        "\xef\x01\x23\x45",
    };

    testVector a, b, c, d;
    testVector test_arc4[4];

    int times = sizeof(test_arc4) / sizeof(testVector);

    a.input  = "\x01\x23\x45\x67\x89\xab\xcd\xef";
    a.output = "\x75\xb7\x87\x80\x99\xe0\xc5\x96";
    a.inLen  = 8;/* must be the right number of bytes of input*/
    a.outLen = 8;/* must be the right number of bytes of input*/
    

    b.input  = "\x00\x00\x00\x00\x00\x00\x00\x00";
    b.output = "\x74\x94\xc2\xe7\x10\x4b\x08\x79";
    b.inLen  = 8;
    b.outLen = 8;

    c.input  = "\x00\x00\x00\x00\x00\x00\x00\x00";
    c.output = "\xde\x18\x89\x41\xa3\x37\x5d\x3a";
    c.inLen  = 8;
    c.outLen = 8;

    d.input  = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
    d.output = "\xd6\xa1\x41\xa7\xec\x3c\x38\xdf\xbd\x61";
    d.inLen  = 10;
    d.outLen = 10;

    test_arc4[0] = a;
    test_arc4[1] = b;
    test_arc4[2] = c;
    test_arc4[3] = d;

    for (int i = 0; i < times; i++) 
    {
        Arc4 enc;
        Arc4 dec;
        
        int  keylen = 8;  /* strlen with key 0x00 not good */
        if (i == 3)
            keylen = 4;

        
        Arc4SetKey(&enc, (byte*)keys[i], keylen);
        Arc4SetKey(&dec, (byte*)keys[i], keylen); 
        
        /* Encryption  Process */

        Arc4Process(&enc, cipher, (byte*)test_arc4[i].input,
                    (word32)test_arc4[i].outLen);
        
       /* Print Cipher Text after encryption */       
        printf("The %d's Cipher Text is: ",i);

       for(int j=0;j < test_arc4[i].inLen;j++) 
       {
           printf("-%x",cipher[j]); /* Print Cipher Text after encryption */
       }

        printf("\r\n");
        printf("\r\n");

        
        /* Decryption  Process */       
        Arc4Process(&dec, plain,  cipher, (word32)test_arc4[i].outLen);
        
        /* Print Plain Text after decryption */
        printf("The %d's Plain Text is: ",i);
          
        for(int j=0;j < test_arc4[i].inLen;j++) 
        {
            printf("-%x",plain[j]);  
        }
        
        printf("\r\n");
        printf("\r\n");


        /* Compare cipher text, generated from encryption, with test_arc4[i].output predefined */          
        if (memcmp(cipher, test_arc4[i].output, test_arc4[i].outLen))
           return i+1;
        
        
        /* Compare plain text��generated from decryption, with test_arc4[i].input defined */           
        if (memcmp(plain, test_arc4[i].input, test_arc4[i].outLen))
           return -(i+1);
    }
    return 0;
}



