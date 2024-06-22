/*****************************************************************************
* | File      	:   ESP32-Pico_Nixie_Clock.c
* | Function    :   Waveshare 'Nixie' Clock
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2021-03-16
* | Info        :   Original Waveshare files adapted for Arduino
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
******************************************************************************/


#include "ESP32_Nixie.h"

#ifdef DEBUGGER
void printMem(void);

void printMem(void)
{
//  Serial.printf("ESP.getFreeHeap()                                     : %i\n",ESP.getFreeHeap());
//  Serial.printf("ESP.getMinFreeHeap()                                  : %i\n",ESP.getMinFreeHeap());
//  Serial.printf("ESP.getHeapSize()                                     : %i\n",ESP.getHeapSize());
//  Serial.printf("ESP.getMaxAllocHeap()                                 : %i\n",ESP.getMaxAllocHeap());
//  Serial.printf("esp_get_free_heap_size()                              : %i\n",esp_get_free_heap_size());
  Serial.printf("heap_caps_get_free_size(MALLOC_CAP_SPIRAM)            : %7d\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM) );
  Serial.printf("heap_caps_get_free_size(MALLOC_CAP_INTERNAL)          : %7d\n", heap_caps_get_free_size(MALLOC_CAP_INTERNAL) );
  Serial.printf("heap_caps_get_free_size(MALLOC_CAP_DEFAULT)           : %7d\n", heap_caps_get_free_size(MALLOC_CAP_DEFAULT) );
  Serial.printf("heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM)   : %7d\n", heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM) );
  Serial.printf("heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL) : %7d\n", heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL) );
  Serial.printf("heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT)  : %7d\n", heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT) );
  Serial.printf("Used PSRAM                                            : %7d\n\n", ESP.getPsramSize() - ESP.getFreePsram());

  Serial.flush();

}
#endif
//---------------------------------------------------------------------------------
// Global Variables
//---------------------------------------------------------------------------------
static uint16_t *dispImageNum_0; // Permanent PSRAM Image memory pointers
static uint16_t *dispImageNum_1;
static uint16_t *dispImageNum_2;
static uint16_t *dispImageNum_3;
static uint16_t *dispImageNum_4;
static uint16_t *dispImageNum_5;
static uint16_t *dispImageNum_6;
static uint16_t *dispImageNum_7;
static uint16_t *dispImageNum_8;
static uint16_t *dispImageNum_9;

uint16_t **digit_MemoryImages[] = {&dispImageNum_0,&dispImageNum_1,&dispImageNum_2,&dispImageNum_3,&dispImageNum_4,&dispImageNum_5,&dispImageNum_6,&dispImageNum_7,&dispImageNum_8,&dispImageNum_9};
const uint16_t *Image_Names[] = {Num0_New,Num1_New,Num2_New,Num3_New,Num4_New,Num5_New,Num6_New,Num7_New,Num8_New,Num9_New};

bool clock_Update_Flag;
#ifdef DEBUGGER
static bool state = true;
#endif

extern const char* const w_Day[];
extern const char* const Day[];
extern const char* const m_Month[];
extern const char* const year;

extern void on_Board_LED_colour(uint32_t, uint8_t);
extern void off_Board_LED(void);

//---------------------------------------------------------------------------------
// 'main()' and 'init()' modules aka loop() and setup() repectively
//---------------------------------------------------------------------------------

void setup(void)
{

  bool setup_fail = false;

  //HWSerial.begin(115200, SERIAL_8N1, 3,2);
  //HWSerial.setDebugOutput(true);
  
  Serial.begin(115200);
  USB.begin();

  delay(5000);

  //Serial.println("This is Serial.println");
  //HWSerial.println("This is HWSerial.println");
  delay(1000);

#ifdef DEBUGGER
  Serial.println("---------------------------------------------------------------------------------");
  Serial.println("Initialisation Sequence started");
  Serial.println("---------------------------------------------------------------------------------");
#endif

#ifdef DEBUGGER
//    Serial.println("Configuring WatchDogTimeout WDT...");
#endif
//  esp_task_wdt_deinit();    
//  watchDog_Start(watchDogTimeout);

// Allocate and initialise PSRAM display memory with Flash Number Images
  if (!setup_fail)
  {
    setup_fail = setup_PSRAM_Init();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("setup_PSRAM_Images Done");
    else
      Serial.println("setup_PSRAM_Images Failed");
#endif
  }

// Initialise  Hardware
  if (!setup_fail)
  {
    setup_fail = DEV_GPIO_Init();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("DEV_GPIO_Init() Done");
    else
      Serial.println("DEV_GPIO_Init() Failed");
#endif
  }

// Configure Interrupt Timer
  if (!setup_fail)
  {
    setup_fail = Timer_ISR_Init();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("Timer_ISR_Init() Done");
    else
      Serial.println("Timer_ISR_Init() Failed");
#endif
  }

// Set up the SPI interface for the LCD driver
  if (!setup_fail)
  {
    setup_fail = DEV_SPI_Init(); 
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("DEV_SPI_Init() Done");
    else
      Serial.println("DEV_SPI_Init() Failed");
#endif
  }

// Start i2c interface
  if (!setup_fail)
  {
    setup_fail = DEV_i2c_Init();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("DEV_i2c_Init() Done");
    else
      Serial.println("DEV_i2c_Init() Failed");
#endif
  }

// Initialise the PWM channels for LCD backlight and buzzer pitch
  if (!setup_fail)
  {
    setup_fail = DEV_Init_PWM();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("DEV_Init_PWM() Done");
    else
      Serial.println("DEV_Init_PWM() Failed");
#endif
  }

// Set up initial PWM ports and values for LCD backlight and Buzzer loudness respctively
  if (!setup_fail)
  {
    setup_fail = DEV_SET_PWM(backlight_ptr, 200);
    setup_fail = DEV_SET_PWM(buzzer_ptr, 0);
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("DEV_Init_PWM backlight and buzzer Done");
    else
      Serial.println("DEV_SET_PWM backlight brightness or buzzer volume settings Failed");
#endif
  }

// Start up the WiFi module in module WiFi_procs.c
  if (!setup_fail)
  {
    setup_fail = WiFi_Setup();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("WiFi_Setup() Done");
    else
      Serial.println("WiFi_Setup() Failed");
#endif
  }

// Start up the NTP module in module ntp_timr.cpp
  if (!setup_fail)
  {
    setup_fail = ntp_Init(timezone_Test_Data);
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("ntp_Init() Done");
    else
      Serial.println("ntp_Init() Failed");
#endif
  }

// Start RTC module - do not set to current time yet
  if (!setup_fail)
  {
    clock_Update_Flag = false;
    setup_fail = RTC_DS3231_Init();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("RTC_DS3231_Init() Done");
    else
      Serial.println("RTC_DS3231_Init() Failed");
#endif
  }

// Initialise and clear the LCD's. Will scan thourgh all images and numbers
  if (!setup_fail)
  {
    setup_fail = LCD_1IN14_Init(VERTICAL);
#ifdef DEBUGGER
    if (!setup_fail) {
      Serial.println("LCD Init Done");
      printMem();
    }
    else
      Serial.println("LCD Init Failed");
#endif
  }

// Clear and fill LCD's with described colour
  if (!setup_fail)
  {
    setup_fail = LCD_1IN14_Clear(ST7789_PINK);
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("LCD_1IN14_Clear Done");
    else
      Serial.println("LCD_1IN14_Clear Failed");
#endif
  }
// Test images to LCD's - long process!
  if (!setup_fail)
  {
    setup_fail = LCD_1in14_test();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("LCD_1in14_test Done");
    else
      Serial.println("LCD_1in14_test Failed");
#endif
  }

// Allocate PSRAM memory for 'nixie' images and transposing octets for correct transmission to LCD's
  if (!setup_fail)
  {
    setup_fail = setup_PSRAM_Images();
#ifdef DEBUGGER
    if (!setup_fail)
      Serial.println("setup_PSRAM_Images Done");
    else
      Serial.println("setup_PSRAM_Images Failed");
#endif
  }

  if (setup_fail) {
#ifdef DEBUGGER
    Serial.println("Initialisation sequence failed! - STOP");
#endif
    while(1);
  }

  rgb_setup();
  rgb_action(100, 0, 210, NUM_NIXIE_TUBE_LED_BRIGHTNESS);

#ifdef DEBUGGER
  on_Board_LED_colour(0x0000ff, 200);

  Serial.println("End of setup()");
#endif
}

//---------------------------------------------------------------------------------


void loop(void)
{
  Display_time_hms(BlackImage);
//  infoTicker.tick();
  watchDogRefresh();

  if (clock_Update_Flag) // It's Midnight - uupdate the clock!
  {
    update_Local_Time();
    RTC_DS3231_Set_Time();
    clock_Update_Flag = false;
    RTC.checkIfAlarm(primary_Alarm);
#ifdef DEBUGGER
//  colorWipe(builtin_led.Color(rgb_red, rgb_green, rgb_blue)); // Violet
  if (state)
  {
    on_Board_LED_colour(0xff0000, 20);
    state = false;
  }
  else
  {
    on_Board_LED_colour(0x00ff00, 20);
    state = true;
  }
#endif
  }
}
