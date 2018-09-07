/**
 ******************************************************************************
 * @file    MICOBonjour.c
 * @author  William Xu
 * @version V1.0.0
 * @date    05-May-2014
 * @brief   Zero-configuration protocol compatiable with Bonjour from Apple
 ******************************************************************************
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
 ******************************************************************************
 */

#include "mico.h"

#include "platform_config.h"
#include "StringUtils.h"
#include "MICOAppDefine.h"

OSStatus MICOStartBonjourService( WiFi_Interface interface, app_context_t * const inContext )
{
  char *temp_txt= NULL;
  char *temp_txt2;
  OSStatus err = kNoErr;
  net_para_st para;
  mdns_init_t init;
  mico_system_status_wlan_t *wlan_status;
  mico_Context_t *mico_config = mico_system_context_get();
  mico_system_wlan_get_status( &wlan_status );

  temp_txt = malloc(500);
  require_action(temp_txt, exit, err = kNoMemoryErr);

  memset(&init, 0x0, sizeof(mdns_init_t));

  micoWlanGetIPStatus(&para, Station);

  init.service_name = BONJOUR_SERVICE;

  /*   name#xxxxxx.local.  */
  snprintf( temp_txt, 100, "%s#%c%c%c%c%c%c.local.", mico_config->micoSystemConfig.name,
            wlan_status->mac[9],  wlan_status->mac[10], wlan_status->mac[12], wlan_status->mac[13], \
            wlan_status->mac[15], wlan_status->mac[16] );

  init.host_name = (char*)__strdup(temp_txt);

  /*   name#xxxxxx.   */
  snprintf( temp_txt, 100, "%s#%c%c%c%c%c%c", mico_config->micoSystemConfig.name,
            wlan_status->mac[9],  wlan_status->mac[10], wlan_status->mac[12], wlan_status->mac[13], \
            wlan_status->mac[15], wlan_status->mac[16] );

  init.instance_name = (char*)__strdup(temp_txt);

  init.service_port = inContext->appConfig->localServerPort;

  temp_txt2 = __strdup_trans_dot(wlan_status->mac);
  sprintf(temp_txt, "MAC=%s.", temp_txt2);
  free(temp_txt2);

  temp_txt2 = __strdup_trans_dot(FIRMWARE_REVISION);
  sprintf(temp_txt, "%sFirmware Rev=%s.", temp_txt, temp_txt2);
  free(temp_txt2);
  
  temp_txt2 = __strdup_trans_dot(HARDWARE_REVISION);
  sprintf(temp_txt, "%sHardware Rev=%s.", temp_txt, temp_txt2);
  free(temp_txt2);

  temp_txt2 = __strdup_trans_dot(MicoGetVer());
  sprintf(temp_txt, "%sMICO OS Rev=%s.", temp_txt, temp_txt2);
  free(temp_txt2);

  temp_txt2 = __strdup_trans_dot(MODEL);
  sprintf(temp_txt, "%sModel=%s.", temp_txt, temp_txt2);
  free(temp_txt2);

  temp_txt2 = __strdup_trans_dot(PROTOCOL);
  sprintf(temp_txt, "%sProtocol=%s.", temp_txt, temp_txt2);
  free(temp_txt2);

  temp_txt2 = __strdup_trans_dot(MANUFACTURER);
  sprintf(temp_txt, "%sManufacturer=%s.", temp_txt, temp_txt2);
  free(temp_txt2);
  
  sprintf(temp_txt, "%sSeed=%lu.", temp_txt, mico_config->micoSystemConfig.seed);
  init.txt_record = (char*)__strdup(temp_txt);

  mdns_add_record( init, interface, 1500);

  free(init.host_name);
  free(init.instance_name);
  free(init.txt_record);
  
exit:
  if(temp_txt) free(temp_txt);
  return err;
}
