/**
 ******************************************************************************
 * @file    hmac_sha256_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   HMAC SHA256 Test Demo  based on MiCO !
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
 *  Functional Description of hmac_sha256_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_hmac[] through HMAC_SHA256 algorithm and compute
 *  each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "HMAC SHA256 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "HMAC SHA256 Test Failed! The Wrong
 *  Number is 1"

 *  Note:
 *  Users can verify the string value of test_hmac[] to validate HMAC SHA56
 *  algorithm function.
 *******************************************************************************
 **/

#include "mico.h" 

#define hmac_sha256_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  hmac_sha256_test(void);


int application_start(void)
{
    int ret = 0;
    
    hmac_sha256_test_log( "HMAC SHA256 Test Start\r\n" );
    
    if ( (ret = hmac_sha256_test()) != 0)        
        hmac_sha256_test_log("HMAC SHA256 Test Failed!  The Wrong Number is %d",ret);
    
    else
        hmac_sha256_test_log("HMAC SHA256 Test Passed!");
    
    return 0;

}


/*************    Defination  of  hmac_sha256_test() *****************************/
int hmac_sha256_test(void)
{
    uint8_t hash[SHA256HashSize];
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

    
    /* Defination of input string to be used HMAC SHA256 Enryption */
    a.input  = "Hi There";
    a.output = "\xb0\x34\x4c\x61\xd8\xdb\x38\x53\x5c\xa8\xaf\xce\xaf\x0b\xf1"
               "\x2b\x88\x1d\xc2\x00\xc9\x83\x3d\xa7\x26\xe9\x37\x6c\x2e\x32"
               "\xcf\xf7";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA256HashSize;

    b.input  = "what do ya want for nothing?";
    b.output = "\x5b\xdc\xc1\x46\xbf\x60\x75\x4e\x6a\x04\x24\x26\x08\x95\x75"
               "\xc7\x5a\x00\x3f\x08\x9d\x27\x39\x83\x9d\xec\x58\xb9\x64\xec"
               "\x38\x43";
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA256HashSize;

    c.input  = "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD";
    c.output = "\x77\x3e\xa9\x1e\x36\x80\x0e\x46\x85\x4d\xb8\xeb\xd0\x91\x81"
               "\xa7\x29\x59\x09\x8b\x3e\xf8\xc1\x22\xd9\x63\x55\x14\xce\xd5"
               "\x65\xfe";
    c.inLen  = strlen((char *)c.input);
    c.outLen = SHA256HashSize;

    test_hmac[0] = a;
    test_hmac[1] = b;
    test_hmac[2] = c;
    
    for (i = 0; i < times; ++i) {
      
      hmacReset(&context, SHA256, keys[i], strlen((char *)keys[i]));
      hmacInput(&context, test_hmac[i].input, test_hmac[i].inLen);
      hmacResult(&context, hash);
      
      for (int j = 0; j < SHA256HashSize; j++)
      { 
        printf("-0x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      
      if (memcmp(hash, test_hmac[i].output, SHA256HashSize) != 0)
        return i+1; 
    }


    return 0;
}
