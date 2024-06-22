/*****************************************************************************
* | File        :   ESP32_Nixie.h
* | Function    :   Waveshare 'Nixie' Clock main header file
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2021-03-16
* | Info        :   
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
#ifndef _ESP32_Nixie_H_
#define _ESP32_Nixie_H_

//---------------------------------------------------------------------------------
// file #includes
//---------------------------------------------------------------------------------
#define _TIMERINTERRUPT_LOGLEVEL_     4

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <Arduino.h>
#include <SPI.h>
//#include <SPIFFS.h>
#include <DS3231.h>
#include <Wire.h>
#include <USB.h>
#include <ESP32PsramLock.h>
//#include <pwmWrite.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTP.h>
#include <Adafruit_NeoPixel.h>

#include "fonts.h"
#include "a1_image.h"
#include "pic1_image.h"
#include "pic2_image.h"
#include "ImageData.h"
#include "Num0_image.h"
#include "Num1_image.h"
#include "Num2_image.h"
#include "Num3_image.h"
#include "Num4_image.h"
#include "Num5_image.h"
#include "Num6_image.h"
#include "Num7_image.h"
#include "Num8_image.h"
#include "Num9_image.h"
#include "LCD_1in14.h"
#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "WiFi_Procs.hpp"
#include "Timer_ISR.h"
#include "WS_DS3231.h"
#include "WS_BME280.h"
#include "ntp_time.hpp"
#include "Debug.h"

//#include "iso3166.h"    // For ISO 2 letter country codes
//#include "iso8601.h"    // For ISO defined Time Zones and Daylight Saving offsets - requires iso3166.h
//#include "IANAports.h"  // A list of Internet assigned service ports as specified by IANA

//---------------------------------------------------------------------------------
// Definitions
//---------------------------------------------------------------------------------
#define true 1
#define false 0

#define LED_OFF             HIGH
#define LED_ON              LOW

//#define WDT_TIMEOUT   3                                           // define a 3 seconds WDT (Watch Dog Timer)

//---------------------------------------------------------------------------------
// Type definitions
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
// Class definitions for all modules
//---------------------------------------------------------------------------------

//extern SPIClass fspi;
//extern SPIClass hspi;
extern SPIClass vspi;

//extern ESP32PsramLock psramLock;

//extern Pwm backlight_pwm;
//extern Pwm buzzer_pwm;

extern DS3231 RTC; // Declare the RTC hardware Class
extern WiFiUDP udp;
extern NTP ntp;

// Nixie Tube WS2812 Glow class
//extern CRGB leds[NUM_LEDS];

// Declare our NeoPixel strip object:
//extern Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
extern Adafruit_NeoPixel builtin_led;
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

//---------------------------------------------------------------------------------
// extern variable declarations for all modules
//---------------------------------------------------------------------------------

extern uint16_t *BlackImage;
extern const uint16_t *nixie_names[];
extern uint16_t **digit_MemoryImages[];

extern pwm_params *backlight_ptr;
extern pwm_params *buzzer_ptr;
extern time_t epochTime;
extern bool century, h12Flag, pmFlag;
extern uint8_t alarmDay, alarmHour, alarmMinute, alarmSecond, alarmBits;
extern bool alarmDy, alarmH12Flag, alarmPmFlag;
extern struct tm timeinfo;

//---------------------------------------------------------------------------------
// Debug Function prototypes
//---------------------------------------------------------------------------------

#ifdef DEBUGGER
extern void printMem(void);
extern void last_reset_reason(void);
#endif

//---------------------------------------------------------------------------------
// Hardware Device Function prototypes
//---------------------------------------------------------------------------------

extern void DEV_Digital_Write(uint16_t, uint8_t);
extern uint8_t DEV_Digital_Read(uint16_t);

extern void DEV_SPI_WriteByte(uint8_t);
extern void DEV_SPI_Write_nByte(uint8_t *, uint32_t);
extern void DEV_SPI_Write_pattern(uint8_t *, uint8_t, uint32_t);

extern void DEV_KEY_Config(uint16_t);

extern void Non_Blocking_Delay_Sec(int);
extern void Non_Blocking_Delay_mSec(uint32_t);
extern void Non_Blocking_Delay_uSec(uint32_t);

extern bool DEV_Init_PWM(void);
extern bool DEV_SET_PWM(pwm_params *, int);

extern bool gpio_Clear(void);
extern bool DEV_GPIO_Init(void);
extern bool DEV_i2c_Init(void);
extern bool DEV_SPI_Init(void);

extern bool DEV_Module_Init(void);
extern void DEV_Module_Exit(void);

extern void rgb_setup(void);
extern void rgb_action(uint8_t, uint8_t, uint8_t, uint8_t);

//---------------------------------------------------------------------------------
// LCD Handler Function Prototypes
//---------------------------------------------------------------------------------

extern LCD_1IN14_ATTRIBUTES LCD_1IN14;

//bool reserved_addr(uint8_t);

//void Handler_1IN14_LCD(int signo);

extern void LCD_1IN14_Reset(void);
extern void LCD_1IN14_SendCommand(uint8_t);
extern void LCD_1IN14_SendData_8Bit(uint8_t);
extern void LCD_1IN14_SendData_16Bit(uint16_t);
extern void LCD_1IN14_InitReg(void);
extern void LCD_1IN14_SetAttributes(uint8_t);
extern bool LCD_1IN14_Init(uint8_t);
extern void LCD_1IN14_SetWindows(uint16_t, uint16_t, uint16_t, uint16_t);
extern bool LCD_1IN14_Clear(uint16_t);
extern void LCD_1IN14_Display(uint16_t *);
extern void LCD_1IN14_DisplayWindows(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t *);
extern void LCD_1IN14_DisplayPoint(uint16_t, uint16_t, uint16_t);
extern bool LCD_1in14_test(void);
extern void Display_time_hms(uint16_t *);

//---------------------------------------------------------------------------------
// 'Infrared' Prototypes - in reality joystick device handler
//---------------------------------------------------------------------------------
extern void SET_Infrared_PIN(uint8_t);
extern int Read_Infrared_Value(void);

//---------------------------------------------------------------------------------
// PSRAM Function
//---------------------------------------------------------------------------------
// PSRAM and Image setup
extern bool setup_PSRAM_Init(void);
extern bool setup_PSRAM_Images(void);


//---------------------------------------------------------------------------------
// LCD Paint Prototypes
//---------------------------------------------------------------------------------
extern void Paint_NewImage(uint8_t *, uint16_t, uint16_t, uint16_t, uint16_t);
extern void Paint_SelectImage(uint8_t *);
extern void Paint_SetRotate(uint16_t);
extern void Paint_SetMirroring(uint8_t);
extern void Paint_SetPixel(uint16_t, uint16_t, uint16_t);
extern bool Paint_SetScale(uint8_t);

extern bool Paint_Clear(uint16_t);
extern void Paint_ClearWindows(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);

//Drawing
extern void Paint_DrawPoint(uint16_t, uint16_t, uint16_t, DOT_PIXEL, DOT_STYLE);
extern void Paint_DrawLine(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, LINE_STYLE);
extern void Paint_DrawRectangle(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, DRAW_FILL);
extern void Paint_DrawCircle(uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, DRAW_FILL);

//Display string
extern void Paint_DrawChar(uint16_t, uint16_t, const char, sFONT*, uint16_t, uint16_t);
extern void Paint_DrawString_EN(uint16_t, uint16_t, const char *, sFONT*, uint16_t, uint16_t);
extern void Paint_DrawString_CN(uint16_t, uint16_t, const char *, cFONT*, uint16_t, uint16_t);
extern void Paint_DrawNum(uint16_t, uint16_t, double, sFONT*, uint16_t,uint16_t, uint16_t);
extern void Paint_DrawTime(uint16_t, uint16_t, PAINT_TIME *, sFONT*, uint16_t, uint16_t);

//pic
extern void Paint_DrawBitMap(const unsigned char*);
extern void Paint_DrawBitMap_Block(const unsigned char*, uint8_t);

extern void Paint_DrawImage(const unsigned char *, uint16_t, uint16_t, uint16_t, uint16_t) ;
extern void Paint_DrawImage_16bit(const uint16_t *, uint16_t, uint16_t, uint16_t, uint16_t); 
extern void Paint_DrawImage1(const unsigned char *, uint16_t, uint16_t, uint16_t, uint16_t);

extern void Paint_BmpWindows(unsigned char,unsigned char,const unsigned char *,	unsigned char,unsigned char);

//---------------------------------------------------------------------------------
// WiFi and NTP Function prototypes
//---------------------------------------------------------------------------------

//extern void check_NTP_status(void);
//extern void handleRoot(AsyncWebServerRequest *);
//extern void handleNotFound(AsyncWebServerRequest *);
//extern void printWifiStatus(void);
extern bool WiFi_Setup(void);
//extern void WebServer_Setup(void);
//extern void heartBeatPrint(void);
//extern void check_status(void);
//extern void WiFi_Loop(void);

extern bool ntp_Init(String);
extern time_t NTP_Set_Time(void);

//---------------------------------------------------------------------------------
// Interrupt Driven Timer Function prototypes
//---------------------------------------------------------------------------------

extern bool Timer_ISR_Init(void);

//extern void Timer1_Start(uint32_t, bool); // GP Timer for future use - parameters are void uint32_t duration and bool repeat or one-shot
//extern bool Timer1_End(bool);             // Flags Timer Timeout

extern void Timer2_Start(uint32_t, bool);  // One-Shot non-blocking timer start function
extern bool Timer2_End(void);              // Flags Timer Timeout

extern void watchDog_Start(uint32_t);
extern void watchDogRefresh(void);   // Stop the watchdog timing out

extern void showTimeFormated(time_t);
extern void debug_Print_Date_Time(void);


//---------------------------------------------------------------------------------
// Real Time Clock (DS3231) Function prototypes
//---------------------------------------------------------------------------------
extern bool RTC_DS3231_Init(void);
extern bool RTC_DS3231_Set_Time(void);
extern bool update_Local_Time(void);

//---------------------------------------------------------------------------------
// OLED Display Function Prototypes
//---------------------------------------------------------------------------------
extern void setup_Date(void);
extern void OLED_Init(void);


// =======================================================================================================
// WiFi Module Prototypes
// =======================================================================================================
//extern void handleRoot(AsyncWebServerRequest *);
//extern void handleNotFound(AsyncWebServerRequest *);
extern void printWifiStatus(void);
extern void heartBeatPrint(void);
extern void check_status(void);
extern void WiFi_Loop(void);
extern void NTP_setup(void);
extern void initCountry(void);
//extern void initTime(String);
extern bool getLocalTime(struct tm *, uint32_t);
//extern void setTimezone(String);
extern void printLocalTime(void);
extern uint32_t read_NTP_Time(void);


#endif
