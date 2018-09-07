/**
  @page "iperf_test"  demo
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 MXCHIP MiCO SDK*******************
  * @file    iperf_test/readme.txt 
  * @author  MDWG (MiCO Documentation Working Group)
  * @version v3.2.0
  * @date    05-january-2017
  * @brief   Description of the "iperf_test"  demo.
  ******************************************************************************


 @par Demo Description 
    - This demo shows:  how to measure network bandwidth during the transmission process in network.


@par Directory contents 
    - Demos/iperf_test/iperf_cli.c            iperf connamd line interface to invoke iperf tasks
    - Demos/iperf_test/iperf_task.c           iperf tasks implement
    - Demos/iperf_test/iperf_main.c           iperf test application
    - Demos/iperf_test/iperf_debug.h          iperf debug macros
    - Demos/iperf_test/mico_config.h          MiCO function header file

@par Hardware and Software environment    
    - This demo has been tested on MiCOKit-3165 board,MiCOKit-3166 board,MiCOKit-3239 board
    - This demo can be easily tailored to any other supported device and development board.


@par How to use it ? 
In order to make the program work, you must do the following :
 =========== Run iperf on wifi module ==================
 - Build and download iperf application to wifi module by command: "make test.iperf@MK3165 download run"
 - Connect module's serial terminal to PC (Serial port: Baud rate: 115200, data bits: 8bit, parity: No, stop bits: 1).   Please referring to http://mico.io/wiki/doku.php?id=com.mxchip.basic
 - Run the demo.
 - Config wlan connection by EasyLink

 =========== Run iperf on PC ==================
 - Download and install iperf on PC. http://www.pc6.com/softview/SoftView_53879.html
 
 
 =========== TCP test case  ==================
 Condition：Taking MiCOKit board as iperf client, Using jperf-2.0.0 create a server on PC.
 -Steps:
        -Set up server on PC
          -1. Excute iperf command: "iperf -s"
        -Set up client on module
          -1. Excute iperf command: "iperf -c <host> -t 30 -i 1" on serial terminal, <host> is the IP address of PC. 
             
 =========== UDP test case  ==================
Condition：Taking MiCOKit board as iperf server, Using jperf-2.0.0 create a client on PC.
 -Steps:
         - Set up server on module
          -1. Excute iperf command: "iperf -s -u"
         -Set up client on PC
          -1. Excute iperf command: "iperf -c <host> -u -t 30 -i 1", <host> is the module's IP address.
            
Note:To get more information, please referring to "https://iperf.fr/"
**/

