/**
 ******************************************************************************
 * @file    sha1_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   SHA1 Test Demo  based on MiCO !
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
 *  Functional Description of sha1_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_sha[] through SHA1 algorithm and compute each
 *  hash value with 160 bits.
 *  Compare each hash value with predefined correct hash value - test_sha[].output.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "SHA1 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "SHA1 Test Failed! The Wrong Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_sha[] to validate SHA1 algorithm function.
 *
 *******************************************************************************
 **/

#include "mico.h" 

#define sha1_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  sha1_test(void);


int application_start(void)
{
    int ret = 0;
 
    sha1_test_log( "SHA1 Test Start\r\n" );
    
    if ( (ret = sha1_test()) != 0) 
        sha1_test_log("SHA1 Test Failed!  The Wrong Number is %d ",ret);
    else
        sha1_test_log("SHA1 Test Passed!");
    
    return 0;
}



/************************** Defination of sha1_test() *******************************/
int sha1_test(void)
{
    uint8_t hash[SHA1HashSize];
    testVector a, b, c, d;
    testVector test_sha[4];
    int times = sizeof(test_sha) / sizeof(struct testVector), i,j;
    USHAContext usercontext;

    /* Defination of input string to be used SHA1 Enryption */
    a.input  = "abc";
    a.output = "\xA9\x99\x3E\x36\x47\x06\x81\x6A\xBA\x3E\x25\x71\x78\x50\xC2"
               "\x6C\x9C\xD0\xD8\x9D";
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA1HashSize;

    b.input  = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    b.output = "\x84\x98\x3E\x44\x1C\x3B\xD2\x6E\xBA\xAE\x4A\xA1\xF9\x51\x29"
               "\xE5\xE5\x46\x70\xF1";
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA1HashSize;

    c.input  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaa";
    c.output = "\x00\x98\xBA\x82\x4B\x5C\x16\x42\x7B\xD7\xA1\x12\x2A\x5A\x44"
               "\x2A\x25\xEC\x64\x4D";
    c.inLen  = strlen((char *)c.input);
    c.outLen = SHA1HashSize; 

    d.input  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaaaaaa";
    d.output = "\xAD\x5B\x3F\xDB\xCB\x52\x67\x78\xC2\x83\x9D\x2F\x15\x1E\xA7"
               "\x53\x99\x5E\x26\xA0";
    
    d.inLen  = strlen((char *)d.input);
    d.outLen = SHA1HashSize;

    test_sha[0] = a;
    test_sha[1] = b;
    test_sha[2] = c;
    test_sha[3] = d;
    
    for (i = 0; i < times; ++i) {
      USHAReset(&usercontext,SHA1);
      USHAInput(&usercontext,test_sha[i].input,test_sha[i].inLen);
      USHAResult(&usercontext,hash);
      
      for (j = 0; j < SHA1HashSize; j++)
      { 
        printf("-x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      if (memcmp(hash, test_sha[i].output, SHA1HashSize) != 0)
        return  i+1;
    }
    return 0;
}

