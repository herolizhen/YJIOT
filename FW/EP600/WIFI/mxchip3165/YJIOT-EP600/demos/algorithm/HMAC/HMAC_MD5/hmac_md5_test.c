/**
 ******************************************************************************
 * @file    hmac_md5_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   HMAC_MD5 Test Demo  based on MiCO !
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
 *  Functional Description of hmac_md5_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_hmac[] through HMAC_MD5 algorithm and compute
 *  each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "HMAC MD5 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "HMAC MD5  Test Failed! The Wrong
 *  Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_hmac[] to validate HMAC MD5
 *  algorithm function.
 *
 ********************************************************************************
 **/

#include "mico.h" 

#define hmac_md5_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)

typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  hmac_md5_test(void);


int application_start(void)
{
    int ret = 0;
    
    hmac_md5_test_log( "HMAC MD5 Test Start\r\n" );
    
    if ( (ret = hmac_md5_test()) != 0)        
        hmac_md5_test_log("HMAC MD5 Test Failed!  The Wrong Number is %d",ret);
    
    else
        hmac_md5_test_log("HMAC MD5 Test Passed!");
    
    return 0;

}


/*************    Defination  of  hmac_md5_test() *****************************/
int hmac_md5_test(void)
{
    Hmac hmac;
    byte hash[MD5_DIGEST_SIZE];

    /* Defination of key */
    const char* keys[]=
    {
        "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b",
        "Jefe",
        "\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA"
    };

    testVector a, b, c;
    testVector test_hmac[3];

    int times = sizeof(test_hmac) / sizeof(testVector), i;

    /* Defination of input string to be used HMAC MD5 Enryption */
    a.input  = "Hi There";
    a.output = "\x92\x94\x72\x7a\x36\x38\xbb\x1c\x13\xf4\x8e\xf8\x15\x8b\xfc"
               "\x9d";
    a.inLen  = strlen(a.input);
    a.outLen = MD5_DIGEST_SIZE;

    b.input  = "what do ya want for nothing?";
    b.output = "\x75\x0c\x78\x3e\x6a\xb0\xb5\x03\xea\xa8\x6e\x31\x0a\x5d\xb7"
               "\x38";
    b.inLen  = strlen(b.input);
    b.outLen = MD5_DIGEST_SIZE;

    c.input  = "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD";
    c.output = "\x56\xbe\x34\x52\x1d\x14\x4c\x88\xdb\xb8\xc7\x33\xf0\xe8\xb3"
               "\xf6";
    c.inLen  = strlen(c.input);
    c.outLen = MD5_DIGEST_SIZE;

    test_hmac[0] = a;
    test_hmac[1] = b;
    test_hmac[2] = c;

    for (i = 0; i < times; ++i) {
      
      wc_HmacSetKey(&hmac, MD5, (byte*)keys[i], (word32)strlen(keys[i]));
      wc_HmacUpdate(&hmac, (byte*)test_hmac[i].input,
                 (word32)test_hmac[i].inLen);
      wc_HmacFinal(&hmac, hash);
      
      /* Print each hash value of test_hmac[i].input */
      printf( "The %d's hmac_md5 Hash Value is: ",i+1);       
      for (int j = 0; j < MD5_DIGEST_SIZE; j++)
      { 
        printf("-0x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      /* Compare each hash with predefined hash value - test_hmac[i].output */
      if (memcmp(hash, test_hmac[i].output, MD5_DIGEST_SIZE) != 0)
        return i+1;
      
    }

    return 0;
}
