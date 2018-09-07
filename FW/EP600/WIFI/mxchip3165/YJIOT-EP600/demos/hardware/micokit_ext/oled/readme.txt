/**
  @page " micokit_ext "  demo
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 MXCHIP MiCO SDK*******************
  * @file    micokit_ext/readme.txt 
  * @author  MDWG (MiCO Documentation Working Group)
  * @version v2.4.x
  * @date    11-April-2016
  * @brief   Description of the  "micokit_ext"  demo.
  ******************************************************************************


  @par Demo Description 
  This demo includes 9 parts:
    - ext_ambient_light_sensor: how to read data from ambient light sensor, APDS9930,  through I2C in MiCO
    - ext_dc_motor.c:  how to control motror ON or OFF status through GPIO pin in MiCO 
    - ext_environmental_sensor.c: how to read data from environmental sensor, BME280, through I2C in MiCO
    - ext_infrared_reflective.c:  how to read data from infrared reflective through ADC in MiCO
    - ext_light_sensor.c: how to read datat from light sensor through ADC in MiCO
    - ext_motion_sensor.c: how to read datat from motion sensor through I2C in MiCO    
    - ext_oled.c: how to write data to OLED through SPI  in MiCO
    - ext_rgb_led.c: how to control RGB LED(P9813) ON/OFF status and parameters such as color, brightness, saturation through I2C in MiCO
    - ext_temp_hum_sensor.c: how to read data from temp and hum sensor(DHT11) through GPIO pin in MiCO



@par Directory contents 
    - Demos/micokit_ext/ext_abient_light_sensor.c           Abient light sensor demo (APDS9930)
    - Demos/micokit_ext/ext_dc_motor.c                      DC motor control demo
    - Demos/micokit_ext/ext_environmental_sensor.c          Temperature and humidity sensor demo (BME280)
    - Demos/micokit_ext/ext_infrared_reflective.c           Infrared_reflective sensor demo
    - Demos/micokit_ext/ext_light_sensor.c                  Light sensor demo
    - Demos/micokit_ext/ext_motion_sensor.c                 motion sensor demo
    - Demos/micokit_ext/ext_oled.c                          Simple display on MiCOKit demo
    - Demos/micokit_ext/ext_rgb_led.c                       MiCOKit RGB Led demo
    - Demos/micokit_ext/ext_temp_hum_sensor.c               Temperature and humidity sensor demo (DHT11)
    - Demos/micokit_ext/mico_config.h                       MiCO function header file for all .c files in micokit_ext.



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

