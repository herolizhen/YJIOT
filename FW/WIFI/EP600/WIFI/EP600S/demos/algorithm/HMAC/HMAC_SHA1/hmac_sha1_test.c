/**
 ******************************************************************************
 * @file    hmac_sha1_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   HMAC_SHA1 Test Demo  based on MiCO !
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
 *  Functional Description of hmac_sha1_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_hmac[] through HMAC_SHA1 algorithm and compute
 *  each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "HMAC SHA1 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "HMAC SHA1 Test Failed! The Wrong Number
 *  is 1"

 *  Note:
 *  Users can verify the string valude of test_hmac[] to validate HMAC SHA1
 *  algorithm function.
 *******************************************************************************
 **/


#include "mico.h" 

#define hmac_sha1_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  hmac_sha1_test(void);


int application_start(void)
{
    int ret = 0;
    
    hmac_sha1_test_log( "HMAC SHA1 Test Start \r\n" );
    
    if ( (ret = hmac_sha1_test()) != 0)        
        hmac_sha1_test_log("HMAC SHA1 Test Failed!  The Wrong Number is %d",ret);
    
    else
        hmac_sha1_test_log("HMAC SHA1 Test Passed!");
    
    return 0;

}


/*************    Defination  of  hmac_sha1_test() *****************************/
int hmac_sha1_test(void)
{
    uint8_t hash[SHA1HashSize];
    HMACContext context;

    
    /* Defination of key */
    const unsigned char* keys[]=
    {
        "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b"
                                                                "\x0b\x0b\x0b",
        "Jefe",
        "\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA"
                                                                "\xAA\xAA\xAA"
    };

    testVector a, b, c;
    testVector test_hmac[3];

    int times = sizeof(test_hmac) / sizeof(testVector), i;

    
    /* Defination of input string to be used HMAC SHA1 Enryption */
    a.input  = "Hi There";
    a.output = "\xb6\x17\x31\x86\x55\x05\x72\x64\xe2\x8b\xc0\xb6\xfb\x37\x8c"
               "\x8e\xf1\x46\xbe\x00";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA1HashSize;

    b.input  = "what do ya want for nothing?";
    b.output = "\xef\xfc\xdf\x6a\xe5\xeb\x2f\xa2\xd2\x74\x16\xd5\xf1\x84\xdf"
               "\x9c\x25\x9a\x7c\x79";
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA1HashSize;

    c.input  = "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD";
    c.output = "\x12\x5d\x73\x42\xb9\xac\x11\xcd\x91\xa3\x9a\xf4\x8a\xa1\x7b"
               "\x4f\x63\xf1\x75\xd3";
    c.inLen  = strlen((char *)c.input);
    c.outLen = SHA1HashSize;

    test_hmac[0] = a;
    test_hmac[1] = b;
    test_hmac[2] = c;
    
    for (i = 0; i < times; ++i) {
      
      hmacReset(&context, SHA1, keys[i], strlen((char *)keys[i]));
      hmacInput(&context, test_hmac[i].input, test_hmac[i].inLen);
      hmacResult(&context, hash);
      
      for (int j = 0; j < SHA1HashSize; j++)
      { 
        printf("-0x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      
      if (memcmp(hash, test_hmac[i].output, SHA1HashSize) != 0)
        return i+1; 
    }

    return 0;
}
