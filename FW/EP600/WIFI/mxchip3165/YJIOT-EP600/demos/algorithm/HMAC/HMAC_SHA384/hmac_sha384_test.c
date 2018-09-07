/**
 ******************************************************************************
 * @file    hmac_sha384_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   HMAC_SHA384 Test Demo  based on MiCO !
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
 *  Functional Description of hmac_sha384_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_hmac[] through HMAC_SHA384 algorithm and compute
 *  each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "HMAC SHA384 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "HMAC SHA384 Test Failed! The Wrong
 *  Number is 1"

 *  Note:
 *  Users can verify the string value of test_hmac[] to validate HMAC SHA56
 *  algorithm function.
 ******************************************************************************
 **/

#include "mico.h" 

#define hmac_sha384_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)
#define USE_32BIT_ONLY

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  hmac_sha384_test(void);


int application_start(void)
{
    int ret = 0;
    
    hmac_sha384_test_log( "HMAC SHA384 Test Start \r\n" );
    
    if ( (ret = hmac_sha384_test()) != 0)        
        hmac_sha384_test_log("HMAC SHA384 Test Failed!  The Wrong Number is %d",ret);
    
    else
        hmac_sha384_test_log("HMAC SHA384 Test Passed!");
    
    return 0;

}


/*************    Defination  of  hmac_sha384_test() *****************************/

int hmac_sha384_test(void)
{
    uint8_t hash[SHA384HashSize];
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

    
    /* Defination of input string to be used HMAC SHA384 Enryption */
    a.input  = "Hi There";
    a.output = "\xaf\xd0\x39\x44\xd8\x48\x95\x62\x6b\x08\x25\xf4\xab\x46\x90"
               "\x7f\x15\xf9\xda\xdb\xe4\x10\x1e\xc6\x82\xaa\x03\x4c\x7c\xeb"
               "\xc5\x9c\xfa\xea\x9e\xa9\x07\x6e\xde\x7f\x4a\xf1\x52\xe8\xb2"
               "\xfa\x9c\xb6";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA384HashSize;

    b.input  = "what do ya want for nothing?";
    b.output = "\xaf\x45\xd2\xe3\x76\x48\x40\x31\x61\x7f\x78\xd2\xb5\x8a\x6b"
               "\x1b\x9c\x7e\xf4\x64\xf5\xa0\x1b\x47\xe4\x2e\xc3\x73\x63\x22"
               "\x44\x5e\x8e\x22\x40\xca\x5e\x69\xe2\xc7\x8b\x32\x39\xec\xfa"
               "\xb2\x16\x49";
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA384HashSize;

    c.input  = "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD";
    c.output = "\x88\x06\x26\x08\xd3\xe6\xad\x8a\x0a\xa2\xac\xe0\x14\xc8\xa8"
               "\x6f\x0a\xa6\x35\xd9\x47\xac\x9f\xeb\xe8\x3e\xf4\xe5\x59\x66"
               "\x14\x4b\x2a\x5a\xb3\x9d\xc1\x38\x14\xb9\x4e\x3a\xb6\xe1\x01"
               "\xa3\x4f\x27";
    c.inLen  = strlen((char *)c.input);
    c.outLen = SHA384HashSize;

    test_hmac[0] = a;
    test_hmac[1] = b;
    test_hmac[2] = c;
    
    for (i = 0; i < times; ++i) {
      
      hmacReset(&context, SHA384, keys[i], strlen((char *)keys[i]));
      hmacInput(&context, test_hmac[i].input, test_hmac[i].inLen);
      hmacResult(&context, hash);
      
      for (int j = 0; j < SHA384HashSize; j++)
      { 
        printf("-0x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      
      if (memcmp(hash, test_hmac[i].output, SHA384HashSize) != 0)
        return i+1; 
    }

    return 0;
    
}
