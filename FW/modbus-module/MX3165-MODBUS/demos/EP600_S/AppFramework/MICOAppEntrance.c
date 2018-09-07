#include "mico.h"
#include "fog_v2_include.h"
#include "MICOAppDefine.h"
#include "micokit_ext.h"
#include "user_main.h"
#include "user_uart.h"
#include "user_charge.h"

#define app_log(M, ...)             custom_log("APP", M, ##__VA_ARGS__)
#define app_log_trace()             custom_log_trace("APP")

static mico_semaphore_t wifi_sem;


USED void user_fog_v2_ota_notification(FOG2_OTA_EVENT_TYPE ota_event_type)
{
    switch(ota_event_type)
    {
        case FOG2_OTA_CHECK_FAILURE:
            app_log("OTA EVENT: FOG2_OTA_CHECK_FAILURE");
            break;

        case FOG2_OTA_NO_NEW_VERSION:
            app_log("OTA EVENT: FOG2_OTA_NO_NEW_VERSION");
            break;

        case FOG2_OTA_IN_UPDATE:
            app_log("OTA EVENT: FOG2_OTA_IN_UPDATE");
            break;

        case FOG2_OTA_UPDATE_SUCCESS:
            app_log("OTA EVENT: FOG2_OTA_UPDATE_SUCCESS");
            break;

        case FOG2_OTA_UPDATE_FAILURE:
            app_log("OTA EVENT: FOG2_OTA_UPDATE_FAILURE");
            break;
    }

    return;
}



void appNotify_WifiStatusHandler( WiFiEvent status, void* const inContext )
{
    switch ( status )
    {
        case NOTIFY_STATION_UP:
            app_log("Wi-Fi connected.");
            mico_rtos_set_semaphore( &wifi_sem );
            break;
        case NOTIFY_STATION_DOWN:
            app_log("Wi-Fi disconnected.");
            break;
        default:
            break;
    }
}



void user_main_thread(mico_thread_arg_t arg)
{
  OSStatus err = kUnknownErr;
  mico_Context_t* inContext = (mico_Context_t*)arg;
  
  // loop in user mian function && must not return
  err = user_main(inContext);
  
  // never get here only if user work error.
  app_log("ERROR: user_main thread exit err=%d, system will reboot...", err);
  
  err = mico_system_power_perform(inContext, eState_Software_Reset);
  UNUSED_PARAMETER(err);
  
  mico_rtos_delete_thread(NULL);   
}

OSStatus startUserMainThread(mico_Context_t *inContext)
{
  app_log_trace();
  OSStatus err = kNoErr;
  //require_action(app_context, exit, err = kParamErr);
  
  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "user_main", 
                                user_main_thread, STACK_SIZE_USER_MAIN_THREAD, 
                                (mico_thread_arg_t) inContext);
  require_noerr( err, exit );
exit:
  return err;
}



int application_start( void )
{
    app_log_trace();
    OSStatus err = kNoErr;
    mico_Context_t* mico_context;

    app_log("APP Version:%s%s", FOG_V2_REPORT_VER, FOG_V2_REPORT_VER_NUM);

	micokit_ext_init();

    err = mico_rtos_init_semaphore( &wifi_sem, 1 );
    require_noerr( err, exit );

    /* Register user function for MiCO notification: WiFi status changed */
    err = mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED, (void *) appNotify_WifiStatusHandler, NULL );
    require_noerr( err, exit );

    mico_context = mico_system_context_init( sizeof(FOG_DES_S) );

    /*init fog v2 service*/
    err = init_fog_v2_service( );
    require_noerr( err, exit );

    err = mico_system_init( mico_context );
    require_noerr( err, exit );
    
    //必须先开启计费和UART线程，否则MCU无法工作起来，加入更换网络则无法进入配网模式
        // Start the recv thread for user_uart to recv data from sensor 's  mcu
    
    err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "charge_thread", 
                                charge_thread, STACK_SIZE_CHARGE_THREAD, 
                                NULL );
    require_noerr_action( err, exit, app_log("ERROR: create charge_thread failed!") );
    
    err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "uart_recv_thread", 
                                uart_recv_thread, STACK_SIZE_UART_RECV_THREAD, 
                                NULL );
    require_noerr_action( err, exit, app_log("ERROR: create user_uptream thread failed!") );
    

    /* wait for wifi on */
    mico_rtos_get_semaphore( &wifi_sem, MICO_WAIT_FOREVER );

    /*start fog v2 service*/
    err = start_fog_v2_service( );
    require_noerr( err, exit );
    

      /* start user thread */
    err = startUserMainThread( mico_context );
    require_noerr_action( err, exit, app_log("ERROR: start user_main thread failed!") ); 
      
      
      
    exit:
    if(err != kNoErr)
    {
        MicoSystemReboot( );
    }
    //解绑超级用户
    //fog_v2_set_device_recovery_flag();
    
    mico_rtos_delete_thread( NULL );
    return err;
}
