/**
 ******************************************************************************
 * @file    sha256_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   SHA256 Test Demo  based on MiCO !
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
 *  Functional Description of sha256_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_sha[] through SHA256 algorithm and compute each
 *  hash value with 256 bits.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "SHA256 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "SHA256 Test Failed! The Wrong Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_sha[] to validate SHA256 algorithm function.
 *
 ******************************************************************************/

#include "mico.h" 

#define sha256_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  sha256_test(void);


int application_start(void)
{
    int ret = 0;
 
    sha256_test_log( "SHA256 Test Start\r\n" );

    if ( (ret = sha256_test()) != 0) 
        sha256_test_log("SHA256 Test Failed! The Wrong Number is  %d",ret);
    else
        sha256_test_log("SHA256 Test Passed!");
    
    return 0;
}



/************************** Defination of sha256_test() *******************************/

int sha256_test(void)
{
    uint8_t   hash[SHA256HashSize];
    testVector a, b;
    testVector test_sha[2];
    int times = sizeof(test_sha) / sizeof(struct testVector), i,j;  
    USHAContext usercontext;

    /* Defination of input string to be used SHA256 Enryption */
    a.input  = "abc";
    a.output = "\xBA\x78\x16\xBF\x8F\x01\xCF\xEA\x41\x41\x40\xDE\x5D\xAE\x22"
               "\x23\xB0\x03\x61\xA3\x96\x17\x7A\x9C\xB4\x10\xFF\x61\xF2\x00"
               "\x15\xAD";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA256HashSize;

    b.input  = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    b.output = "\x24\x8D\x6A\x61\xD2\x06\x38\xB8\xE5\xC0\x26\x93\x0C\x3E\x60"
               "\x39\xA3\x3C\xE4\x59\x64\xFF\x21\x67\xF6\xEC\xED\xD4\x19\xDB"
               "\x06\xC1";

    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA256HashSize;

    test_sha[0] = a;
    test_sha[1] = b;
    
    for (i = 0; i < times; ++i) {
      
      USHAReset(&usercontext,SHA256);
      USHAInput(&usercontext,test_sha[i].input,test_sha[i].inLen);
      USHAResult(&usercontext,hash);
      
      for (j = 0; j < SHA256HashSize; j++)
      { 
        printf("-x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      if (memcmp(hash, test_sha[i].output, SHA256HashSize) != 0)
        return  i+1;
    }

    return 0;
}
