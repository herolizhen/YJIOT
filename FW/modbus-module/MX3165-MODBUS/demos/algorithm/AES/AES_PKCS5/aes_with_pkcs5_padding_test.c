/**
******************************************************************************
* @file    aes_with_pkcs5_padding_test.c 
* @author  swyang
* @version V1.0.0
* @date    4-January-2016
* @brief   AES in CBC mode with PKCS5 padding Test Demo  based on MiCO !
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
******************************************************************************/

#include "mico.h"

#define aes_test_log(format, ...)  custom_log("Security", format, ##__VA_ARGS__)



int application_start(void){
  aes_test_log("AES PKCS#5 Padding Demo.");
  
  byte msg[] = "012345678";
  
  byte cipher[AES_BLOCK_SIZE * 8] = "";
  byte plain [AES_BLOCK_SIZE * 8] = "";
  byte key[] = "0123456789abcdef";  /* align  Must be 128 bits */
  byte iv[]  = "1234567890123456";  /* align  Must be 128 bits */
  Aes enc;
  Aes dec;
  AesSetKey(&enc, key, AES_BLOCK_SIZE, iv, AES_ENCRYPTION);
  AesSetKey(&dec, key, AES_BLOCK_SIZE, iv, AES_DECRYPTION);
  
  /* Encryption process */
  word32 ciphe_sz = AesCbcEncryptPkcs5Padding(&enc, cipher, msg, strlen((char *)msg));
  
  if(ciphe_sz == 0){
    aes_test_log("Encrypt failed!\r\n");
    return 0;
  }
  
  aes_test_log("The Cipher Text is: ");
  for(byte i = 0; i < ciphe_sz; i++)
    printf("%02x ", cipher[i]);    /* Print Cipher Text after decryption */
  printf("\r\n");
  
  /* Decryption process */
  word32 plain_sz = AesCbcDecryptPkcs5Padding(&dec, plain, cipher, ciphe_sz);
  
  if(plain_sz == 0){
    aes_test_log("Decrypt failed!\r\n");
    return 0;
  }
  
  aes_test_log("The Plain Text is: ");
  for(byte i = 0; i < plain_sz; i++)
    printf("%02x ", plain[i]);    /* Print Plain Text after decryption */
  printf("\r\n");
  
  return 0;
}


word32 AesCbcEncryptPkcs5Padding(Aes* aes, byte* output, const byte* input, word32 sz){
  if(aes == NULL || output == NULL || input == NULL || sz == 0)
    return 0;
  
  word32 div = sz / 16;
  word32 sz_align = (div + 1) * 16;
  byte pad_byte = sz_align - sz;
  
  byte* input_align = malloc(sz_align);
  if(input_align == NULL) return 0;
  
  memcpy(input_align, input, sz);
  memset(input_align + sz, pad_byte, sz_align - sz);
  
  AesCbcEncrypt(aes, output, input_align, sz_align);
  
  free(input_align);
  return sz_align;
}


word32 AesCbcDecryptPkcs5Padding(Aes* aes, byte* output, const byte* input, word32 sz){
  if(aes == NULL || output == NULL || input == NULL || sz < 16 || sz % 16 > 0)
    return 0;
  
  byte* output_align = malloc(sz);
  if(output_align == NULL) return 0;
  
  AesCbcDecrypt(aes, output_align, input, sz);
  
  byte pad_byte = output_align[sz - 1];
  if(pad_byte >= sz) return 0;
  
  word32 act_size = sz - pad_byte;
  
  byte pad_cmp[16];
  memset(pad_cmp, pad_byte, 16);
  if(memcmp(output_align + act_size, pad_cmp, pad_byte))
    return 0;
  
  memcpy(output, output_align, act_size);
  
  free(output_align);
  
  return act_size;
}
