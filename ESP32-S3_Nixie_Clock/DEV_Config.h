/*****************************************************************************
* | File      	:   DEV_Config.h
* | Author      :   
* | Function    :   Hardware underlying interface
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
# copies of theex Software, and to permit persons to  whom the Software is
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
#ifndef _DEV_Config_H_
#define _DEV_Config_H_

//---------------------------------------------------------------------------------
//  function:	GPIO initialization
//  parameter:
//  Info:
//---------------------------------------------------------------------------------
    

/*
Pico      Waveshare     RPi Pico/PicoW        ESP32-S2_Pico         ESP32-S3_Pico
Pin       Nixie Clock             Default               Default               Default
Number    Function      GPIO      Function    GPIO      Function    GPIO      Function    Pin Sense     Nixie Clock Function
--------  -----------   --------------------  --------------------  --------------------  -----------   -----------------         ---------         --------------------
Pin 1         N/C       GP0       UART0TX     GP2       U1TXD       GPIO11                OUTPUT          N/C
Pin 2         N/C       GP1       UART0RX     GP3       U1RXD       GPIO12                INPUT           N/C
Pin 3         GND       GND                   GND                   GND
Pin 4         CSA1      GP2                   GP4       GPIO4       GPIO13                OUTPUT          GSA1
Pin 5         GPA2      GP3                   GP5       GPIO5       GPIO14                OUTPUT          GSA2
Pin 6         GPA3      GP4                   GP43      U0TXD       GPIO15                OUTPUT          GSA3
Pin 7         N/C       GP5                   GP44      U0RXD       GPIO16                INPUT           N/C
Pin 8         GND       GND                   GND                   GND
Pin 9         GP6       GP6                   GP14      I2C1 SDA    GPIO17                BiDi            I2C1-SDA Default
Pin 10        GP7       GP7                   GP15      I2C1 SCL    GPIO18                OUTPUT          I2C1-SCLK Default
Pin 11        DC        GP8                   GP16      GPIO16      GPIO33                OUTPUT          LCD Data(HIGH)/Command(LOW)
Pin 12        N/C       GP9                   GP17      GPIO17      GPIO34                                Not Used
Pin 13        GND       GND                   GND                   GND
Pin 14        CLK       GP10                  GP10      SPI1 SCK    GPIO35                OUTPUT          SPI Clock to LCD's
Pin 15        DIN       GP11                  GP11      SPI1 MOSI   GPIO36                OUTPUT          SPI Data Out to LCD's
Pin 16        RST       GP12                  GP12      SPI1 MISO   GPIO37                OUTPUT          LCD Reset pin - NOT MISO!
Pin 17        BL        GP13                  GP13      SPI1 CS     GPIO38                OUTPUT          LCD Backlight - a PWM overide
Pin 18        GND       GND                   GND                   GND
Pin 19        Pbzr      GP14                  GP34      GPIO34      GPIO39                OUTPUT          Buzzer/alarm - a PWM channel
Pin 20        K R       GP15                  GP35      GPIO35      GPIO40                INPUT           Right button control
Pin 21        K L       GP16                  GP36      GPIO36      GPIO42                INPUT           Left button control
Pin 22        K MODE    GP17                  GP37      GPIO37      GPIO41                INPUT           Mode button control
Pin 23        GND       GND                   GND                   GND
Pin 24        DS INT    GP18                  GP38      GPIO38      GPIO1                 INPUT           RTC Interrupt
Pin 25        N/C       GP19                  GP39      GPIO39      GPIO2                 OUTPUT          Buzzer/alarm - Alternative
Pin 26        GP20      GP20                  GP40      I2C0 SDA    GPIO4                 BiDi            I2C1-SDA Alternative
Pin 27        GP21      GP21                  GP41      I2C0 SCL    GPIO5                 OUTPUT          I2C1-SCLK Alternative
Pin 28        GND       GND                   GND                   GND
Pin 29        RGB       GP22                  GP42      GPIO42      GPIO6                 OUTPUT          WS2812B Nixie tube string
Pin 30        RUN       RUN                   RUN       RESET       CHIP PU               Float N/C
Pin 31        N/C       GP26      ADC0        GP6       ADC0        GPIO7
Pin 32        N/C       GP27      ADC1        GP7       ADC1        GPIO8
Pin 33        GND       GND       ADC GND     GND       AGND        GND
Pin 34        N/C       GP28      ADC2        GP8       ADC2        GPIO9
Pin 35        N/C       ADC VREF  ADC VREF    N/C                   GPIO10
Pin 36        3V3(OUT)  3V3(OUT)              3V3(OUT)  3V3(OUT)    3V3(OUT)  3V3(OUT)
Pin 37        3V3_EN    3V3_EN                3V3_EN    3V3_EN      3V3_EN    3V3_EN
Pin 38        GND       GND                   GND                   GND
Pin 39        VSYS      VSYS                  VSYS      VSYS        VSYS      VSYS
Pin 40        VBUS      VBUS                  VBUS      VBUS        VBUS      VBUS


*/

// Using ESP32-S3_Pico Pin References

#define GPIO0   0 // Boot pin linked to Boot switch - DO NOT USE
#define GPIO1   1 // USB Sensing - ladder network attached to give approx 3V if USB plugged in
#define GPIO2   2
#define GPIO3   3
#define GPIO4   4
#define GPIO5   5
#define GPIO6   6
#define GPIO7   7
#define GPIO8   8
#define GPIO9   9
#define GPIO10  10
#define GPIO11  11
#define GPIO12  12
#define GPIO13  13
#define GPIO14  14
#define GPIO15  15
#define GPIO16  16
#define GPIO17  17
#define GPIO18  18
#define GPIO19  19
#define GPIO20  20
#define GPIO21  21
#define GPIO22  22
#define GPIO23  23
#define GPIO24  24
#define GPIO25  25
#define GPIO26  26
#define GPIO27  27
#define GPIO28  28
#define GPIO29  29
#define GPIO30  30
#define GPIO31  31
#define GPIO32  32
#define GPIO33  33
#define GPIO34  34
#define GPIO35  35
#define GPIO36  36
#define GPIO37  37
#define GPIO38  38
#define GPIO39  39
#define GPIO40  40
#define GPIO41  41
#define GPIO42  42
#define GPIO43  43
#define GPIO44  44
#define GPIO45  45

#define ALTERNATE_PINS

#define LCD_DC_PIN      GPIO33  // Sets Data or Command mode to selected 'Nixie tube' LCD
#define LCD_CLK_PIN     GPIO35  // SPI Clock Pin for all 'nixie tubes'
#define LCD_MOSI_PIN    GPIO36  // SPI MOSI Sends data to selected 'Nixie tube'
#define LCD_RST_PIN     GPIO37  // SPI MISO
#define LCD_BL_PIN      GPIO38  // SPI CS Controls selected 'Nixie tube' LCD backlight


/* The ESP32 has four SPi buses, however as of right now only two of
 * them are available to use, HSPI and VSPI. Simply using the SPI API 
 * as illustrated in Arduino examples will use VSPI, leaving HSPI unused.
 * 
 * However if we simply intialise two instance of the SPI class for both
 * of these buses both can be used. However when just using these the Arduino
 * way only will actually be outputting at a time.
 * 
 * Logic analyser capture is in the same folder as this example as
 * "multiple_bus_output.png"
 * 
 * created 30/04/2018 by Alistair Symonds
 */

// Define ALTERNATE_PINS to use non-standard GPIO pins for SPI bus
#define ALTERNATE_PINS

#if CONFIG_IDF_TARGET_ESP32C3 || CONFIG_IDF_TARGET_ESP32S3
	#define FSPI  0
	#define HSPI  1
#else
	#define FSPI  1 //SPI bus attached to the flash (can use the same data lines but different SS)
	#define HSPI  2 //SPI bus normally mapped to pins 12 - 15, but can be matrixed to any pins
	#if CONFIG_IDF_TARGET_ESP32
		#define VSPI  3 //SPI bus normally attached to pins 5, 18, 19 and 23, but can be matrixed to any pins
	#endif
#endif

// Define ALTERNATE_PINS to use non-standard GPIO pins for SPI bus

#ifdef ALTERNATE_PINS
  #define VSPI_MISO   LCD_RST_PIN
  #define VSPI_MOSI   LCD_MOSI_PIN
  #define VSPI_SCLK   LCD_CLK_PIN
  #define VSPI_SS     LCD_BL_PIN

//  #define HSPI_MISO   26
//  #define HSPI_MOSI   27
//  #define HSPI_SCLK   25
//  #define HSPI_SS     32
#else
  #define VSPI_MISO   MISO
  #define VSPI_MOSI   MOSI
  #define VSPI_SCLK   SCK
  #define VSPI_SS     SS

//  #define HSPI_MISO   12
//  #define HSPI_MOSI   13
//  #define HSPI_SCLK   14
//  #define HSPI_SS     15
#endif

#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
#define VSPI FSPI
#endif

static const int spiClk = 40000000; // 10 MHz SPI clock rate

#define LCD_GSA1        GPIO13    // Select 'Nixie tube'
#define LCD_GSA2        GPIO14    // Ditto
#define LCD_GSA3        GPIO15    // Ditto

#define DEV_I2C_PORT    I2C_ONE
#define DEV_SDA_PIN     GPIO17
#define DEV_SCL_PIN     GPIO18
#define i2c_frequency   400*1000  // 400,000 KHz i2c clock frequency

#define DS_INT_PIN      GPIO1     // ESP32-S3_Pico GPIO pin assigned for DS3231 interrupt

#define DEV_KBZR_PIN    GPIO39    // Audio buzzer (Alarm clock?)

#define DEV_KR_PIN      GPIO40    // Right push button
#define DEV_KL_PIN      GPIO42    // Left push button
#define DEV_KM_PIN      GPIO41    // Mode push button
#define DEV_INT_PIN     DS_INT_PIN  // Real Time Clock Interrupt pin

#define DEV_RGB_PIN     GPIO6     // Source of WS2812 daisy chain through LCD displays

#define NUM_LCDS        6         // Number of Waveshare 'Nixie' tubes
#define NUM_NIXIE_TUBE_LEDS       NUM_LCDS  // WS2812 LEDs embedded within 'Nixie' tubes
#define NUM_NIXIE_TUBE_LED_BRIGHTNESS 10 // Value up to 255. Set low for general nixie tube backlighting

#define LED_PIN         GPIO21   // Onboard RGB LED (WS2812B) assignment
// the setup function runs once when you press reset or power the board
#ifdef RGB_BUILTIN
  #undef RGB_BUILTIN
#endif
#define RGB_BUILTIN     LED_PIN


#define UART0TX         GPIO11   // Changes UART 0 pins for UART 1 as used by default debugging
#define UART0RX         GPIO12

#define BACKLIGHT_PWM_CHAN 0 
#define BUZZER_PWM_CHAN 1
#define PWM_CHAN_B BACKLIGHT_PWM_CHAN
#define BACKLIGHT_Resolution_Factor 12 // 12 bit PWM resolution
#define BUZZER_Resolution_Factor 12 // 12 bit PWM resolution
#define PWM_Max_Duty_Cycle 255
#define PWM_Min_Duty_Cycle 0

// PWM Parameter typedef structure
typedef struct {
  uint8_t   pin;
  uint32_t  dutyCycle;
  uint32_t  PWMFreq;
  uint8_t   PWMChannel;
  uint8_t   PWMResolution;
  uint8_t   MAX_DUTY_CYCLE;
} pwm_params;

#endif
