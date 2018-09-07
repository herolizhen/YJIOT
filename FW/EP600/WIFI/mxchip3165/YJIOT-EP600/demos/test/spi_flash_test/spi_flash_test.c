/**
 ******************************************************************************
 * @file    hello_world.c
 * @author  William Xu
 * @version V1.0.0
 * @date    21-May-2015
 * @brief   First MiCO application to say hello world!
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
 */

#include "mico.h"
#include "spi_flash.h"

#define log(format, ...)  custom_log("SPI FLASH TEST", format, ##__VA_ARGS__)

static sflash_handle_t sflash_handle = {0x0, 0x0, SFLASH_WRITE_NOT_ALLOWED};

const mico_spi_device_t mico_spi_flash =
{
  .port        = MICO_SPI_1,
  .chip_select = MICO_GPIO_8,
  .speed       = 30000000,
  .mode        = (SPI_CLOCK_RISING_EDGE | SPI_CLOCK_IDLE_HIGH | SPI_USE_DMA | SPI_MSB_FIRST ),
  .bits        = 8
};

static uint8_t w_buf[1024*4];
static uint8_t r_buf[1024*4];

int application_start( void )
{
  OSStatus err = kNoErr;
  memset(w_buf, 'A', sizeof(w_buf));
  log("Init flash...");
  err = init_sflash( &sflash_handle, 0, SFLASH_WRITE_ALLOWED );
  require_noerr_action( err, exit, log("ERROR: init_sflash err = %d.", err) );
  log("Device ID = %08x", sflash_handle.device_id);
  for(uint16_t i=0; i<2000; i++){
    log("[%d]================================================", i);
    log("Erasing sector 0...");
    err = sflash_sector_erase(&sflash_handle, 0);
    require_noerr_action( err, exit, log("ERROR: sflash_sector_erase err = %d.", err) );
    log("Writting 4KBytes...");
    err = sflash_write(&sflash_handle, 0, w_buf, sizeof(w_buf));
    require_noerr_action( err, exit, log("ERROR: sflash_write err = %d.", err) );
    memset(r_buf, 0, sizeof(r_buf));
    log("Reading 4KBytes...");
    err = sflash_read(&sflash_handle, 0, r_buf, sizeof(r_buf));
    require_noerr_action( err, exit, log("ERROR: sflash_read err = %d.", err) );
    log("Comparing result...");
    int ret = memcmp(w_buf, r_buf, sizeof(w_buf));
    if(ret == 0)
    {
    	log("SPI test success");
    }
    else
    {
    	log("SPI test failed");
    	log("w_buf: %02x %02x %02x %02x", w_buf[0], w_buf[1], w_buf[2], w_buf[3]);
    	log("r_buf: %02x %02x %02x %02x", r_buf[0], r_buf[1], r_buf[2], r_buf[3]);
    }
  }

exit:
  return 0;
}


