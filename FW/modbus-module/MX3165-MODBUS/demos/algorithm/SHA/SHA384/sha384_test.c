/**
 ******************************************************************************
 * @file    sha384_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    5-January-2016
 * @brief   SHA384 Test Demo  based on MiCO !
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
 *  Functional Description of sha384_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_sha[] through SHA384 algorithm and compute each
 *  hash value with 384bits.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "SHA384Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "SHA384 Test Failed! The Wrong Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_sha[] to validate SHA384 algorithm
 *  function.
 *
 ********************************************************************************
 **/

#include "mico.h"
#include "sha.h"

#define sha384_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)
#define USE_32BIT_ONLY

typedef struct testVector {
    const uint8_t*  input;
    const uint8_t*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  sha384_test(void);


int application_start(void)
{
  int ret = 0;
  
  sha384_test_log( "SHA384 Test Start\r\n" );
  
  if ( (ret = sha384_test()) != 0) 
    sha384_test_log("SHA384 Test Failed! The Wrong Number is  %d",ret);
  else
    sha384_test_log("SHA384 Test Passed!");
  
  return 0;

}



/********************** Defination of sha384_test()*****************************/

int sha384_test(void)
{
    uint8_t   hash[SHA384HashSize];

    testVector a, b;
    testVector test_sha[2];
    int times = sizeof(test_sha) / sizeof(struct testVector), i,j;
    
    USHAContext usercontext;

    /* Defination of input string to be used SHA384 Enryption */
    a.input  = "abc";
    
    a.output = "\xcb\x00\x75\x3f\x45\xa3\x5e\x8b\xb5\xa0\x3d\x69\x9a\xc6\x50"
               "\x07\x27\x2c\x32\xab\x0e\xde\xd1\x63\x1a\x8b\x60\x5a\x43\xff"
               "\x5b\xed\x80\x86\x07\x2b\xa1\xe7\xcc\x23\x58\xba\xec\xa1\x34"
               "\xc8\x25\xa7"; 
    
    a.inLen  = strlen((char *)a.input);
    a.outLen = SHA384HashSize;

    b.input  = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhi"
               "jklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";


 /*  The correct hash value.  */  
    b.output = "\x09\x33\x0c\x33\xf7\x11\x47\xe8\x3d\x19\x2f\xc7\x82\xcd\x1b"
               "\x47\x53\x11\x1b\x17\x3b\x3b\x05\xd2\x2f\xa0\x80\x86\xe3\xb0"
               "\xf7\x12\xfc\xc7\xc7\x1a\x55\x7e\x2d\xb9\x66\xc3\xe9\xfa\x91"
               "\x74\x60\x39";
      
    b.inLen  = strlen((char *)b.input);
    b.outLen = SHA384HashSize; 

    test_sha[0] = a;
    test_sha[1] = b;
    
    for (i = 0; i < times; ++i) {
      
      USHAReset(&usercontext,SHA384);
      USHAInput(&usercontext,test_sha[i].input,test_sha[i].inLen);
      USHAResult(&usercontext,hash);
      
      
      for (j = 0; j < SHA384HashSize; j++)
      { 
        printf("-x%x",hash[j]);   
      }
      printf("\r\n");
      printf("\r\n");
      
      if (memcmp(hash, test_sha[i].output, SHA384HashSize) != 0)
        return  i+1;
    }

    return 0;
}
