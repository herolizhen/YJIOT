/********************************************************************************
 * @file    md5_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   MD5 Test Demo  based on MiCO !
 *********************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2016 MXCHIP Inc.
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
 **********************************************************************************
 *
 *  Functional Description of md5_test.c
 *
 *  Demo Function:
 *  To encrypt for string in test_md5[] through MD5 algorithm and compute each hash value.
 *  Compare each hash value with predefined correct hash value.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as "MD5 Test passed!".
 *  If the result is not correct, stop the check process,
 *  and display the error message such as "MD5  Test Failed! The Wrong Number is 1"
 *
 *  Note:
 *  Users can verify the string value of test_md5[] to validate MD5 algorithm function.
 *  You can log in the site  http://www.atool.org/hash.php  to verify the reliability
 *  of the algorithm
 *
 *******************************************************************************************
 **/

#include "mico.h" 

#define md5_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  md5_test(void);


int application_start(void)
{
    int ret = 0;
 
    md5_test_log( "MD5 Test Start !\r\n" );

    if ( (ret = md5_test()) != 0) 
        md5_test_log("MD5  Test Failed! The Wrong Number is  %d",ret);
    else
        md5_test_log("MD5  Test Passed!");

    return 0;
    
}

/*************    Defination  of  md5_test() ***********************************/
int md5_test(void)
{
    md5_context  md5;
    uint8_t hash[MD5_DIGEST_SIZE];

    testVector a, b, c, d, e;
    testVector test_md5[5];
    int times = sizeof(test_md5) / sizeof(testVector), i,j;

    /* Defination of input string to be used MD5 Enryption */
    a.input  = "abc";
    a.output = "\x90\x01\x50\x98\x3c\xd2\x4f\xb0\xd6\x96\x3f\x7d\x28\xe1\x7f"
               "\x72";    
    
    a.inLen  = strlen(a.input);
    a.outLen = MD5_DIGEST_SIZE;

    
    b.input  = "message digest";
    b.output = "\xf9\x6b\x69\x7d\x7c\xb7\x93\x8d\x52\x5a\x2f\x31\xaa\xf1\x61"
               "\xd0";
  
    b.inLen  = strlen(b.input);
    b.outLen = MD5_DIGEST_SIZE;

    
    c.input  = "abcdefghijklmnopqrstuvwxyz";
    c.output = "\xc3\xfc\xd3\xd7\x61\x92\xe4\x00\x7d\xfb\x49\x6c\xca\x67\xe1"
               "\x3b";
    c.inLen  = strlen(c.input);         
    c.outLen = MD5_DIGEST_SIZE; 

    
    d.input  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    d.output = "\xd1\x74\xab\x98\xd2\x77\xd9\xf5\xa5\x61\x1c\x2c\x9f\x41\x9d\x9f";

    d.inLen  = strlen(d.input);
    d.outLen = MD5_DIGEST_SIZE; 

    
    e.input  = "1234567890123456789012345678901234567890123456789012345678"
               "9012345678901234567890";
    e.output = "\x57\xed\xf4\xa2\x2b\xe3\xc9\x55\xac\x49\xda\x2e\x21\x07\xb6"
               "\x7a";
    e.inLen  = strlen(e.input);
    e.outLen = MD5_DIGEST_SIZE; 

    
    test_md5[0] = a;
    test_md5[1] = b;
    test_md5[2] = c;
    test_md5[3] = d;
    test_md5[4] = e;

    InitMd5(&md5);

    for (i = 0; i < times; ++i) 
    {
        
        Md5Update(&md5, (uint8_t*)test_md5[i].input, (uint32_t)test_md5[i].inLen);
        Md5Final(&md5, hash);
       
        /* Print each hash value of test_md5[i].input */
        printf( "The %d's MD5 Hash Value is: ",i+1);       
        for (j = 0; j < MD5_DIGEST_SIZE; ++j)
        { 
            printf("-0x%x",hash[j]);   
        }
        printf("\r\n");
        printf("\r\n");
        
       /* Compare each hash with predefined hash value - test_md5[i].output */
        if (memcmp(hash, test_md5[i].output, MD5_DIGEST_SIZE) != 0) 
            return i+1;             
    }

    return 0;
}

