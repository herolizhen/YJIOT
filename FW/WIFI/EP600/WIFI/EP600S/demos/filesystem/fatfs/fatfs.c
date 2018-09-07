/**
 ******************************************************************************
 * @file    fatfs.c
 * @author  Ding QQ
 * @version V1.0.0
 * @date    21-May-2015
 * @brief   MiCO RTOS Fatfs file system demo.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 MXCHIP Inc.
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
 **/

#include "mico.h"
#include "ff_gen_drv.h"
#include "sflash_diskio.h"

#define os_fatfs_log(M, ...) custom_log("FATFS", M, ##__VA_ARGS__)

FATFS SFLASHFatFs;      /* File system object for flash disk logical drive */
FIL SFLASHFile;         /* File object */
char SFLASHPath[4];     /* SFLASH logical drive path */

void test_fatfs( )
{
    FRESULT err;
    filesystem_info fatfs_info;
    uint32_t byteswritten, bytesread;
    char filename[] = "MiCO.txt";
    uint8_t wtext[] = "hello MiCO!";
    uint8_t rtext[100];
    FATFS_LinkDriver( &SFLASHDISK_Driver, SFLASHPath );

    err = f_mount( &SFLASHFatFs, (TCHAR const*) SFLASHPath, 0 );
    require_noerr( err, exit );

    do
    {
        fatfs_info = fatfs_get_info( (uint8_t*) SFLASHPath );
        if ( fatfs_info.total_space == 0 )
        {
            os_fatfs_log("filesystem free space is %d, need format", fatfs_info.total_space);
            os_fatfs_log("start format filesystem");
            err = f_mkfs( (TCHAR const*) SFLASHPath, 0, _MAX_SS );
        }
    } while ( fatfs_info.total_space == 0 );

    os_fatfs_log("filesystem total space is %dKB, free space is %dKB", fatfs_info.total_space, fatfs_info.free_space);

    err = f_open( &SFLASHFile, filename, FA_CREATE_ALWAYS | FA_WRITE );
    require_noerr( err, exit );

    err = f_write( &SFLASHFile, wtext, sizeof(wtext), (void *) &byteswritten );
    if ( (byteswritten == 0) || (err != FR_OK) )
    {
        os_fatfs_log("fatfs write error %d", err);
        goto exit;
    }

    os_fatfs_log("fatfs write file, name:%s, data:%s", filename, wtext);

    err = f_close( &SFLASHFile );
    require_noerr( err, exit );

    err = f_open( &SFLASHFile, filename, FA_READ );
    require_noerr( err, exit );

    err = f_read( &SFLASHFile, rtext, sizeof(rtext), (void *) &bytesread );
    if ( (bytesread == 0) || (err != FR_OK) )
    {
        os_fatfs_log("fatfs read error %d", err);
        goto exit;
    }

    os_fatfs_log("fatfs read file, name:%s, data:%s", filename, rtext);

    err = f_close( &SFLASHFile );
    require_noerr( err, exit );
    
exit:
    FATFS_UnLinkDriver( SFLASHPath );
}  


int application_start( void )
{
    test_fatfs( );
    return 0;
}  
