/**
 ******************************************************************************
 * @file    sha512_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    5-January-2016
 * @brief   SHA512 Test Demo  based on MiCO !
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
 *  Functional Description of sha512_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_sha[] through SHA512 algorithm and compute each
 *  hash value with 512 bits.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "SHA512Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "SHA512 Test Failed! The Wrong Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_sha[] to validate SHA512 algorithm
 *  function.
 *
 ********************************************************************************
 **/


#include "mico.h" 

#define sha512_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)
#define USE_32BIT_ONLY

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  sha512_test(void);


int application_start(void)
{
    int ret = 0;
 
    sha512_test_log( "SHA512 Test Start\r\n" );

    if ( (ret = sha512_test()) != 0) 
        sha512_test_log("SHA512 Test Failed! The Wrong Number is  %d",ret);
    else
        sha512_test_log("SHA512 Test Passed!");
    
    return 0;

}

/*********************  Defination of sha512_test() ***************************/

int sha512_test(void)
{
    uint8_t   hash[SHA512HashSize];
    testVector a, b;
    testVector test_sha[2];
    int times = sizeof(test_sha) / sizeof(struct testVector), i,j;
    
    USHAContext usercontext;

    
    /* Defination of input string to be used SHA512 Enryption */
    a.input  = "abc";
    
/*  The Correct hash value.  */
    a.output = "\xdd\xaf\x35\xa1\x93\x61\x7a\xba\xcc\x41\x73\x49\xae\x20\x41"
               "\x31\x12\xe6\xfa\x4e\x89\xa9\x7e\xa2\x0a\x9e\xee\xe6\x4b\x55"
               "\xd3\x9a\x21\x92\x99\x2a\x27\x4f\xc1\xa8\x36\xba\x3c\x23\xa3"
               "\xfe\xeb\xbd\x45\x4d\x44\x23\x64\x3c\xe8\x0e\x2a\x9a\xc9\x4f"
               "\xa5\x4c\xa4\x9f";

    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA512HashSize;

    b.input  = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhi"
               "jklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
    
 /*  The Correct hash value.  */
    b.output = "\x8e\x95\x9b\x75\xda\xe3\x13\xda\x8c\xf4\xf7\x28\x14\xfc\x14"
               "\x3f\x8f\x77\x79\xc6\xeb\x9f\x7f\xa1\x72\x99\xae\xad\xb6\x88"
               "\x90\x18\x50\x1d\x28\x9e\x49\x00\xf7\xe4\x33\x1b\x99\xde\xc4"
               "\xb5\x43\x3a\xc7\xd3\x29\xee\xb6\xdd\x26\x54\x5e\x96\xe5\x5b"
               "\x87\x4b\xe9\x09"; 
    
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA512HashSize;

    test_sha[0] = a;
    test_sha[1] = b;
    
    for (i = 0; i < times; ++i) {
      
      USHAReset(&usercontext,SHA512);
      USHAInput(&usercontext,test_sha[i].input,test_sha[i].inLen);
      USHAResult(&usercontext,hash);
      
      
      for (j = 0; j < SHA512HashSize; j++)
      { 
        printf("-x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      if (memcmp(hash, test_sha[i].output, SHA512HashSize) != 0)
        return  i+1;
    }

    return 0;
}
