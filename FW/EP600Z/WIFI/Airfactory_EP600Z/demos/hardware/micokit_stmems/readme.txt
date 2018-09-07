/**
  @page " micokit_stmems "  demo
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 MXCHIP MiCO SDK*******************
  * @file    micokit_stmems/readme.txt 
  * @author  MDWG (MiCO Documentation Working Group)
  * @version v2.4.x
  * @date    11-April-2016
  * @brief   Description of the  "micokit_stmems"  demo.
  ******************************************************************************


  @par Demo Description 
  This demo demonstrate STmems board functions: EMW1062 wlan controller, key button,
  RGB led, HTS221 Tem/Hump sensor, LPS25HB atmosphere pressure, UVIS25 ultraviolet rays
  sensor, LSM9DS1 9D accelerometer( G-sensor ) and an ADC light sensor.



@par Directory contents 
    - Demos/micokit_stmems/micokit_STmems_demo.c         STmems board demo
    - Demos/micokit_ext/mico_config.h                    MiCO function header file for all .c files in micokit_ext.



@par Hardware and Software environment      
    - This demo has been tested on MiCOKit-3165 board.
    - This demo can be easily tailored to any other supported device and development board.



@par How to use it ? 
In order to make the program work, you must do the following :
 - Open your preferred toolchain, 
    - IDE:  IAR 7.30.4 or Keil MDK 5.13.       
    - Debugging Tools: JLINK or STLINK
 - Modify header file path of  "mico_config.h".   Please referring to "http://mico.io/wiki/doku.php?id=confighchange"
 - Rebuild all files and load your image into target memory.   Please referring to "http://mico.io/wiki/doku.php?id=debug"
 - Run the demo.
 - View operating results and system serial log (Serial port: Baud rate: 115200, data bits: 8bit, parity: No, stop bits: 1).   Please referring to http://mico.io/wiki/doku.php?id=Demos

**/

