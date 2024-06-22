/*****************************************************************************
* | File      	:	Debug.h
* | Function    :	debug with Serial.println
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :   
*   1.USE_DEBUG -> DEBUG, If you need to see the debug information, 
*    clear the execution: make DEBUG=-DDEBUG
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

******************************************************************************/
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

//extern USBCDC USBSerial;

void last_reset_reason(void);

//#if DEBUG
//  #define DEBUGGER      // Delete or comment out for production server
// Module specific DEBUG definitons Comment definitions as required
//  #define DEBUG_PSRAM
//  #define DEBUG_LCD
//  #define DEBUG_GUI
//  #define DEBUG_DEV
//  #define DEBUG_RTC
//  #define DEBUG_WiFi
//  #define DEBUG_NTP
//  #define DEBUG_TIMER
//#endif

#if DEBUG
	#define Debug(__info,...) "Debug: " __info,##__VA_ARGS__)
#else
	#define Debug(__info,...)  
#endif

/*
*  Print last reset reason of ESP32
*  =================================
*
*  Use either of the methods print_reset_reason
*  or verbose_print_reset_reason to display the
*  cause for the last reset of this device.
*
*  Public Domain License.
*
*  Author:
*  Evandro Luis Copercini - 2017
*/

//#ifdef ESP_IDF_VERSION_MAJOR // IDF 4+
//#if CONFIG_IDF_TARGET_ESP32 // ESP32/PICO-D4
//#include "esp32/rom/rtc.h"
//#elif CONFIG_IDF_TARGET_ESP32S2
#include "esp32s2/rom/rtc.h"
//#elif CONFIG_IDF_TARGET_ESP32C3
//#include "esp32c3/rom/rtc.h"
//#else 
//#error Target CONFIG_IDF_TARGET is not supported
//#endif
//#else // ESP32 Before IDF 4.0
//#include "rom/rtc.h"
//#endif
/*
#define uS_TO_S_FACTOR 1000000  // Conversion factor for micro seconds to seconds

void print_reset_reason(RESET_REASON reason)
{
  switch (reason)
  {
    case 1 :  Serial.println ("POWERON_RESET");break;          //<1,  Vbat power on reset
    case 3 :  Serial.println ("SW_RESET");break;               //<3,  Software reset digital core
    case 4 :  Serial.println ("OWDT_RESET");break;             //<4,  Legacy watch dog reset digital core
    case 5 :  Serial.println ("DEEPSLEEP_RESET");break;        //<5,  Deep Sleep reset digital core
    case 6 :  Serial.println ("SDIO_RESET");break;             //<6,  Reset by SLC module, reset digital core
    case 7 :  Serial.println ("TG0WDT_SYS_RESET");break;       //<7,  Timer Group0 Watch dog reset digital core
    case 8 :  Serial.println ("TG1WDT_SYS_RESET");break;       //<8,  Timer Group1 Watch dog reset digital core
    case 9 :  Serial.println ("RTCWDT_SYS_RESET");break;       //<9,  RTC Watch dog Reset digital core
    case 10 : Serial.println ("INTRUSION_RESET");break;       //<10, Instrusion tested to reset CPU
    case 11 : Serial.println ("TGWDT_CPU_RESET");break;       //<11, Time Group reset CPU
    case 12 : Serial.println ("SW_CPU_RESET");break;          //<12, Software reset CPU
    case 13 : Serial.println ("RTCWDT_CPU_RESET");break;      //<13, RTC Watch dog Reset CPU
    case 14 : Serial.println ("EXT_CPU_RESET");break;         //<14, for APP CPU, reseted by PRO CPU
    case 15 : Serial.println ("RTCWDT_BROWN_OUT_RESET");break;//<15, Reset when the vdd voltage is not stable
    case 16 : Serial.println ("RTCWDT_RTC_RESET");break;      //<16, RTC Watch dog reset digital core and rtc module
    default : Serial.println ("NO_MEAN");
  }
}

void verbose_print_reset_reason(RESET_REASON reason)
{
  switch ( reason)
  {
    case 1  : Serial.println ("Vbat power on reset");break;
    case 3  : Serial.println ("Software reset digital core");break;
    case 4  : Serial.println ("Legacy watch dog reset digital core");break;
    case 5  : Serial.println ("Deep Sleep reset digital core");break;
    case 6  : Serial.println ("Reset by SLC module, reset digital core");break;
    case 7  : Serial.println ("Timer Group0 Watch dog reset digital core");break;
    case 8  : Serial.println ("Timer Group1 Watch dog reset digital core");break;
    case 9  : Serial.println ("RTC Watch dog Reset digital core");break;
    case 10 : Serial.println ("Instrusion tested to reset CPU");break;
    case 11 : Serial.println ("Time Group reset CPU");break;
    case 12 : Serial.println ("Software reset CPU");break;
    case 13 : Serial.println ("RTC Watch dog Reset CPU");break;
    case 14 : Serial.println ("for APP CPU, reseted by PRO CPU");break;
    case 15 : Serial.println ("Reset when the vdd voltage is not stable");break;
    case 16 : Serial.println ("RTC Watch dog reset digital core and rtc module");break;
    default : Serial.println ("NO_MEAN");
  }
}

void last_reset_reason(void)
{

  Serial.println("CPU0 reset reason:");
  print_reset_reason(rtc_get_reset_reason(0));
  verbose_print_reset_reason(rtc_get_reset_reason(0));

//  Serial.println("CPU1 reset reason:");
//  print_reset_reason(rtc_get_reset_reason(1));
//  verbose_print_reset_reason(rtc_get_reset_reason(1));

  // Set ESP32 to go to deep sleep to see a variation
  // in the reset reason. Device will sleep for 5 seconds.
//  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
//  Serial.println("Going to sleep");
//  esp_deep_sleep(5 * uS_TO_S_FACTOR);
}
*/

/*
  Example Serial Log:
  ====================

rst:0x10 (RTCWDT_RTC_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0x00
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0008,len:8
load:0x3fff0010,len:160
load:0x40078000,len:10632
load:0x40080000,len:252
entry 0x40080034
CPU0 reset reason:
RTCWDT_RTC_RESET
RTC Watch dog reset digital core and rtc module
CPU1 reset reason:
EXT_CPU_RESET
for APP CPU, reseted by PRO CPU
Going to sleep
ets Jun  8 2016 00:22:57

rst:0x5 (DEEPSLEEP_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0x00
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0008,len:8
load:0x3fff0010,len:160
load:0x40078000,len:10632
load:0x40080000,len:252
entry 0x40080034
CPU0 reset reason:
DEEPSLEEP_RESET
Deep Sleep reset digital core
CPU1 reset reason:
EXT_CPU_RESET
for APP CPU, reseted by PRO CPU
Going to sleep
ets Jun  8 2016 00:22:57

rst:0x5 (DEEPSLEEP_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0x00
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0008,len:8
load:0x3fff0010,len:160
load:0x40078000,len:10632
load:0x40080000,len:252
entry 0x40080034
CPU0 reset reason:
DEEPSLEEP_RESET
Deep Sleep reset digital core
CPU1 reset reason:
EXT_CPU_RESET
for APP CPU, reseted by PRO CPU
Going to sleep

*/
#endif

