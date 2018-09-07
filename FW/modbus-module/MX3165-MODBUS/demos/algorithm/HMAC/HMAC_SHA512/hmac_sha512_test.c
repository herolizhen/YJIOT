/**
 ******************************************************************************
 * @file    hmac_sha512_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   HMAC_SHA512 Test Demo  based on MiCO !
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
 *  Functional Description of hmac_sha512_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_hmac[] through HMAC_SHA512 algorithm and compute
 *  each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "HMAC SHA512 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "HMAC SHA512 Test Failed! The Wrong Number
 *   is 1"

 *  Note:
 *  Users can verify the string value of test_hmac[] to validate HMAC SHA56
 *  algorithm function.
 ********************************************************************************
 **/


#include "mico.h" 

#define hmac_sha512_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)
#define USE_32BIT_ONLY

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  hmac_sha512_test(void);


int application_start(void)
{
    int ret = 0;
    
    hmac_sha512_test_log( "HMAC SHA512 Test Start \r\n" );
    
    if ( (ret = hmac_sha512_test()) != 0)        
        hmac_sha512_test_log("HMAC SHA512 Test Failed!  The Wrong Number is %d",ret);
    
    else
        hmac_sha512_test_log("HMAC SHA512 Test Passed!");
    
    return 0;

}


/*************    Defination  of  hmac_sha512_test() *****************************/

int hmac_sha512_test(void)
{
    uint8_t hash[SHA512HashSize];
    HMACContext context;

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

    a.input  = "Hi There";
    a.output = "\x87\xaa\x7c\xde\xa5\xef\x61\x9d\x4f\xf0\xb4\x24\x1a\x1d\x6c"
               "\xb0\x23\x79\xf4\xe2\xce\x4e\xc2\x78\x7a\xd0\xb3\x05\x45\xe1"
               "\x7c\xde\xda\xa8\x33\xb7\xd6\xb8\xa7\x02\x03\x8b\x27\x4e\xae"
               "\xa3\xf4\xe4\xbe\x9d\x91\x4e\xeb\x61\xf1\x70\x2e\x69\x6c\x20"
               "\x3a\x12\x68\x54";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA512HashSize;

    b.input  = "what do ya want for nothing?";
    b.output = "\x16\x4b\x7a\x7b\xfc\xf8\x19\xe2\xe3\x95\xfb\xe7\x3b\x56\xe0"
               "\xa3\x87\xbd\x64\x22\x2e\x83\x1f\xd6\x10\x27\x0c\xd7\xea\x25"
               "\x05\x54\x97\x58\xbf\x75\xc0\x5a\x99\x4a\x6d\x03\x4f\x65\xf8"
               "\xf0\xe6\xfd\xca\xea\xb1\xa3\x4d\x4a\x6b\x4b\x63\x6e\x07\x0a"
               "\x38\xbc\xe7\x37";
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA512HashSize;

    c.input  = "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD\xDD"
               "\xDD\xDD\xDD\xDD\xDD\xDD";
    c.output = "\xfa\x73\xb0\x08\x9d\x56\xa2\x84\xef\xb0\xf0\x75\x6c\x89\x0b"
               "\xe9\xb1\xb5\xdb\xdd\x8e\xe8\x1a\x36\x55\xf8\x3e\x33\xb2\x27"
               "\x9d\x39\xbf\x3e\x84\x82\x79\xa7\x22\xc8\x06\xb4\x85\xa4\x7e"
               "\x67\xc8\x07\xb9\x46\xa3\x37\xbe\xe8\x94\x26\x74\x27\x88\x59"
               "\xe1\x32\x92\xfb";
    c.inLen  = strlen((char *)c.input);
    c.outLen = SHA512HashSize;

    test_hmac[0] = a;
    test_hmac[1] = b;
    test_hmac[2] = c;
    
    for (i = 0; i < times; ++i) {
      
      hmacReset(&context, SHA512, keys[i], strlen((char *)keys[i]));
      hmacInput(&context, test_hmac[i].input, test_hmac[i].inLen);
      hmacResult(&context, hash);
      
      for (int j = 0; j < SHA512HashSize; j++)
      { 
        printf("-0x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      
      if (memcmp(hash, test_hmac[i].output, SHA512HashSize) != 0)
        return i+1; 
    }
    return 0;
}
