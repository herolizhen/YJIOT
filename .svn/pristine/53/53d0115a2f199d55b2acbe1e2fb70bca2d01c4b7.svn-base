/**
 ******************************************************************************
 * @file    micokit_ext_demo.c
 * @author  William Xu
 * @version V1.0.0
 * @date    21-Oct-2016
 * @brief   Sensor test for MiCOKit EXT sensor board
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
#include "MiCOKit_EXT.h"

#define app_log(format, ...)  custom_log("MiCOKit_STmems", format, ##__VA_ARGS__)

void micokit_ext_key1_clicked_callback(void)
{
  dc_motor_set(0);
}

void micokit_ext_key2_clicked_callback(void)
{
  dc_motor_set(1);
}


int application_start( void )
{
  OSStatus err = kNoErr;
  int16_t apds9930_Prox, apds9930_Lux;
  int32_t temperature = 24;
  uint32_t humidity = 50;
  int rgb_led_hue = 0;
  uint16_t light_adc;
  char oled_string[32];
  button_init_t init;
  mico_system_status_wlan_t* wlan_status;
  
  /* Start MiCO system functions according to mico_config.h*/
  err = mico_system_init( mico_system_context_init( 0 ) );
  require_noerr_string( err, exit, "ERROR: Unable to Init MiCO core" );
  
  micokit_ext_init();
  
  mico_system_get_status_wlan( &wlan_status );
  OLED_Clear();
  OLED_ShowString( 0, OLED_DISPLAY_ROW_1, (char *)wlan_status->mac );
  
  /* Initialise MiCOKit buttons */
  init.gpio = Arduino_D4;
  init.pressed_func = micokit_ext_key1_clicked_callback;
  init.long_pressed_func = NULL;
  init.long_pressed_timeout = 3000;
  button_init( IOBUTTON_USER_1, init );

  init.gpio = Arduino_D5;
  init.pressed_func = micokit_ext_key2_clicked_callback;
  button_init( IOBUTTON_USER_2, init );

  while(1)
  {
    hsb2rgb_led_open(rgb_led_hue, 100, 5);
    rgb_led_hue = (rgb_led_hue + 60)%360;

    app_log("//////////////////////////");
    err = apds9930_data_readout((uint16_t *)&apds9930_Prox, (uint16_t *)&apds9930_Lux);
    require_noerr_string( err, reload, "ERROR: Can't Read Data" );
    sprintf( oled_string, "%3.1fmm  %dlux    ", (float)(10239-apds9930_Prox)/100, apds9930_Lux );
    OLED_ShowString( 0, OLED_DISPLAY_ROW_2, (char *)oled_string );
    app_log( "APDS9930  Prox: %.1fmm  Lux: %d", (float)(10239-apds9930_Prox)/100, apds9930_Lux );

    err = temp_hum_sensor_read(&temperature,  &humidity);
    require_noerr_string( err, reload, "ERROR: Can't Read temperature" );
    sprintf( oled_string, "%.1fC %.1f%%", (double)temperature, (double)humidity);
    OLED_ShowString( 1, OLED_DISPLAY_ROW_3, (char *)oled_string );
    app_log("Temp:%.1fC Humi%.1f%%",(double)temperature, (double)humidity);

    light_sensor_read(&light_adc);
    sprintf( oled_string, "InfoRed: %d", light_adc );
    OLED_ShowString( 1, OLED_DISPLAY_ROW_4, (char *)oled_string );
    app_log("Light ADC: %d",light_adc);

  reload:

    mico_rtos_delay_milliseconds(1000);
  }
  
exit:
  mico_rtos_delete_thread( NULL );
  return err; 
}

