/**
 ******************************************************************************
 * @file    crc16_mico_check_test.c
 * @author  Jenny Liu
 * @version V1.0.0
 * @date    4-January-2016
 * @brief   CRC16 mico Check Test Demo  based on MiCO !
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
 *  Functional Description of crc16_mico_check_test.c
 *
 *  Demo Function:
 *  To encrypt and decrypt for string for msg[] through CRC16 mico check algorithm.
 *
 *  Compare result text with test_crc16[].output, which is predefined.
 *  Print the comparison results through serial port log.
 *
 *  If the result is correct, display message such as
 *  "CRC16 mico check Test finished! The 16-bit result is 12456".
 *  If the result is not correct,stop the process and display the error message
 *  such as "CRC16 mico check Test failed!"
 *
 *  Note:
 *  Users can change the string value of msg[] to validate CRC16 mico check
 *  algorithm function.
 *
 *******************************************************************************
 **/

#include "mico.h" 

#define crc16_mico_check_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)


typedef struct testVector {
    const char*  input;
    const char*  output; 
    size_t inLen;
    size_t outLen;
} testVector;

int  crc16_mico_check_test(void);


int application_start(void)
{
    int ret = 0;
 
    crc16_mico_check_test_log( "CRC16 mico Check Test Start !\r\n" );
          
    ret = crc16_mico_check_test();
    crc16_mico_check_test_log("CRC16 mico Check Test Finished!  The CRC16 result is %d",ret);
   
    printf("\r\n");
    return 0;

}
/*********************  Defination of crc16_mico_check_test() ****************/
int crc16_mico_check_test(void)
{
     CRC16_Context crc;
     uint16_t Result;

    
    /* Defination of input string to be used crc16 check */
    
    uint8_t msg[] = {0x01,0x02,0x03,0x04,0x05,0x06}; /*length is arbitrary */
    
    
    CRC16_Init( &crc );

    CRC16_Update( &crc, msg, sizeof(msg) );

    CRC16_Final( &crc, &Result );
  
    return Result;
    

}


