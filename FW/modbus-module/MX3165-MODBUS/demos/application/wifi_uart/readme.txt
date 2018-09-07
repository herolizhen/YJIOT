/**
  @page " wifi_uart "  demo
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 MXCHIP MiCO SDK*******************
  * @file    wifi_uart/readme.txt 
  * @author  MDWG (MiCO Documentation Working Group)
  * @version v2.4.0
  * @date    11-April-2016
  * @brief   Description of the "wifi_uart" demo.
  ******************************************************************************


@par Demo Description 
This demo shows:  how to realize data transmission between UART and WiFi RF in Wi-Fi Module .


@par Directory contents 
    - Demos/applicaiton/wifi_uart/MICOAppEntrance.c     Applicaiton Entrance
    - Demos/applicaiton/wifi_uart/MICOConfigDelegate.c  EasyLink configuration delegate functions
    - Demos/applicaiton/wifi_uart/MICOBonjour.c         Zero-configuration protocol compatiable with Bonjour from Apple
    - Demos/applicaiton/wifi_uart/LocalTcpServer.c      Create a TCP listener thread, accept every TCP client connection and create thread for them.
    - Demos/applicaiton/wifi_uart/RemoteTcpClient.c     Create a TCP client thread, and connect to a remote server.
    - Demos/applicaiton/wifi_uart/UartRecv.c            Create a UART recv thread.
    - Demos/applicaiton/wifi_uart/SppProtocol.c         SPP protocol deliver any data received from UART to wlan and deliver wlan data to UART.
    - Demos/applicaiton/wifi_uart/mico_config.h         Provide constant definition and type declaration for MICO system running.



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
 - View operating results and system serial log (Serial port: Baud rate: 115200, data bits: 8bit, parity: No, stop bits: 1).   Please referring to http://mico.io/wiki/doku.php?id=com.mxchip.basic

**/

