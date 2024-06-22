/*****************************************************************************
* | File      	:   DEV_Config.c
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

#include "ESP32_Nixie.h"

//SPIClass fspi = SPIClass(FSPI);
//SPIClass hspi = SPIClass(HSPI);
SPIClass vspi = SPIClass(VSPI);

//ESP32PsramLock psramLock;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(NUM_NIXIE_TUBE_LEDS, DEV_RGB_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel builtin_led(1, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

//---------------------------------------------------------------------------------
// Global variables
//---------------------------------------------------------------------------------

static pwm_params backlight; // Set up a fixed structure for baclklight PWM 
static pwm_params buzzer; // Set up a fixed structure for Audio buzzer PWM 
pwm_params *backlight_ptr;
pwm_params *buzzer_ptr;

extern volatile bool Timer0_Interrupt_Latch;
extern volatile bool Timer1_Interrupt_Latch;

//---------------------------------------------------------------------------------
// Function prototypes
//---------------------------------------------------------------------------------
void DEV_Digital_Write(uint16_t, uint8_t);
uint8_t DEV_Digital_Read(uint16_t);

void DEV_SPI_WriteByte(uint8_t);
void DEV_SPI_Write_nByte(uint8_t *, uint32_t);
void DEV_SPI_Write_pattern(uint8_t *, uint8_t, uint32_t);

void DEV_KEY_Config(uint16_t);

void Non_Blocking_Delay_Sec(int);
void Non_Blocking_Delay_mSec(uint32_t);
void Non_Blocking_Delay_uSec(uint32_t);

bool DEV_Init_PWM(pwm_params *);
bool DEV_SET_PWM(pwm_params *, int);

bool gpio_Clear(void);
bool DEV_GPIO_Init(void);
bool DEV_i2c_Init(void);
bool DEV_SPI_Init(void);

bool DEV_Module_Init(void);
void DEV_Module_Exit(void);

void rgb_setup(void);
void rgb_action(uint8_t, uint8_t, uint8_t, uint8_t);
void colorWipe(uint32_t);
void on_Board_LED_colour(uint32_t, uint8_t);
void off_Board_LED(void);

/******************************************************************************
function:	GPIO read and write
parameter:
		Pin		： GPIO 
		Value	： 0 level  or  1 level 
******************************************************************************/
void DEV_Digital_Write(uint16_t Pin, uint8_t Value)
{
    digitalWrite(Pin, Value);
}

uint8_t DEV_Digital_Read(uint16_t Pin)
{
    return digitalRead(Pin);
}

//---------------------------------------------------------------------------------
// function:	void DEV_SPI_WriteByte(uint8_t Value) - Single byte to 'Nixie' Tube(s)
// parameter: 
//		Value	： 8 bits of data
//    SPIClass *vspi - Global 

//    void write(uint8_t data);
//    void write16(uint16_t data);
//    void write32(uint32_t data);
//    void writeBytes(const uint8_t * data, uint32_t size);
//    void writePixels(const void * data, uint32_t size);//ili9341 compatible
//    void writePattern(const uint8_t * data, uint8_t size, uint32_t repeat);

//---------------------------------------------------------------------------------
void DEV_SPI_WriteByte(uint8_t Value)
{
//  SPIClass fspi
//use it as you would the regular arduino SPI API
//  fspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  fspi.transfer(Value);
//  fspi.endTransaction();

//  SPIClass hspi
//use it as you would the regular arduino SPI API
//  hspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  hspi.transfer(Value);
//  hspi.endTransaction();

//  SPIClass vspi
//use it as you would the regular arduino SPI API
//  vspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  vspi.write(Value);
//  vspi.endTransaction();

}

//---------------------------------------------------------------------------------
// function:	void DEV_SPI_WritenByte(uint8_t Value) - writes image to 'Nixie' Tube(s)
// parameter: 
//		pData	： data array
//		Len		： The length of the array
//    SPIClass *vspi - Global        
//---------------------------------------------------------------------------------
void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
#ifdef DEBUG_DEV
//  Serial.printf("Entered DEV_SPI_Write_nByte: pData = 0x%x, *pData = 0x%x%x, len = %i\n",pData, *pData, *(pData +1), Len);
#endif

//use it as you would the regular arduino SPI API
//  fspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  fspi.transfer(pData,Len);
//  fspi.endTransaction();

//use it as you would the regular arduino SPI API
//  hspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
//  hspi.transfer(pData,Len);
//  hspi.endTransaction();

//use it as you would the regular arduino SPI API
//  vspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));

//  vspi.transferBytes(pData, NULL, Len);

  vspi.writeBytes(pData, Len);
//  vspi.endTransaction();
#ifdef DEBUG_DEV
//  Serial.printf("Do we get here?\n");
#endif
}

//---------------------------------------------------------------------------------
// function:	void DEV_SPI_Write_pattern (uint8_t Value) - writes (clears)) to 'Nixie' Tube(s)
// parameter: 
//		pData	： data pointer
//		pattern_Size : The length of the pattern in octets
//    repeat : The number of times the pattern is repeated
//    SPIClass *vspi - Global        
//---------------------------------------------------------------------------------
void DEV_SPI_Write_pattern(uint8_t *pData, uint8_t pattern_Size, uint32_t repeat)
{

//use it as you would the regular arduino SPI API
//  fspi.writePattern(pData, pattern_Size, repeat);

//use it as you would the regular arduino SPI API
//  hspi.writePattern(pData, pattern_Size, repeat);

//use it as you would the regular arduino SPI API
//  vspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  vspi.writePattern(pData, pattern_Size, repeat);
//  vspi.endTransaction();

}

//---------------------------------------------------------------------------------
// Non-Blocking Delay functions - See Timer_ISR module for details
// Uses Pico Timer Interrupts to allow WiFi, HTTP or NTP updates 
// parameter:
//  xs    Delay Seconds. Passes Seconds * 1000 into
//	xms		Delay millisecond * xms
//	xus		Delay microseconds * xus
//---------------------------------------------------------------------------------
void Non_Blocking_Delay_Sec(int xs)
{
// Convert seconds to microseconds and call the microsecond timer function
  uint32_t time_uSec = (uint32_t)(xs * 1000000);
  Non_Blocking_Delay_uSec(time_uSec);
  return;
}

void Non_Blocking_Delay_mSec(uint32_t xms)
{
// Convert milliseconds to microseconds and call the microsecond timer function
  uint32_t time_uSec = (uint32_t)(xms * 1000);
  Non_Blocking_Delay_uSec(time_uSec);
  return;
}

void Non_Blocking_Delay_uSec(uint32_t xus)
{
// Function Initialises and starts interrupt timer.  
  Timer2_Start(xus, one_shot); // GP Timer - parameters are void uint32_t duration and bool repeat or one-shot

  while (!Timer2_End()) {
    yield();
  };             // Wait for Timer Timeout - does not affect Interrupts nor callbacks
}

//---------------------------------------------------------------------------------
//  function:	PWM initialization
//  parameter:
//  Info:returns false by default
//---------------------------------------------------------------------------------

bool DEV_Init_PWM(void) {
// Function uses the ESP32-S2 Analog Write (<pwmWrite.h>) library
#ifdef DEBUG_DEV
  Serial.println("Entered DEV_Init_PWM");
#endif

  bool fail = false;
  pinMode(LCD_BL_PIN, OUTPUT);  // Configure LCD Backlight Pins (6)
  pinMode(DEV_KBZR_PIN, OUTPUT);// Configure Buzzer/Alarm Pin


// Initialise pointers to backlight and buzzer structures
  backlight_ptr = &backlight;
  buzzer_ptr = &buzzer;

  backlight.pin = LCD_BL_PIN;
  buzzer.pin = DEV_KBZR_PIN;

  backlight.dutyCycle = ((BACKLIGHT_Resolution_Factor^2) / PWM_Max_Duty_Cycle) * min(PWM_Min_Duty_Cycle, PWM_Max_Duty_Cycle);
  buzzer.dutyCycle = ((BUZZER_Resolution_Factor^2) / PWM_Max_Duty_Cycle) * min(PWM_Min_Duty_Cycle, PWM_Max_Duty_Cycle);

  backlight.PWMFreq = 5000;
  buzzer.PWMFreq = 500;

  backlight.PWMChannel = BACKLIGHT_PWM_CHAN;
  buzzer.PWMChannel = BUZZER_PWM_CHAN;

  backlight.PWMResolution = BACKLIGHT_Resolution_Factor;
  buzzer.PWMResolution = BUZZER_Resolution_Factor;

  backlight.MAX_DUTY_CYCLE = (int)(pow(2, backlight.PWMResolution) - 1);
  buzzer.MAX_DUTY_CYCLE = (int)(pow(2, buzzer.PWMResolution) - 1);

// Can we set up the PWM channels?
  fail = !(ledcAttach(backlight.pin, backlight.PWMFreq, backlight.PWMResolution));
  if (!fail)
    fail = !(ledcAttach(buzzer.pin, buzzer.PWMFreq, buzzer.PWMResolution));
  if (fail)
    return true;

// Now set the duty cycle for backlight and buzzer
  ledcWrite(backlight.pin, backlight.dutyCycle);
  ledcWrite(buzzer.pin, buzzer.dutyCycle);

#ifdef DEBUG_DEV
  Serial.printf("DEV_Init_PWM Initial backlight Values are:- backlight.pin = %i, backlight.dutyCycle = %i\n",backlight.pin, backlight.dutyCycle);
  Serial.printf("DEV_Init_PWM Initial buzzer Values are:- buzzer.pin = %i, buzzer.dutyCycle = %i\n",buzzer.pin, buzzer.dutyCycle);
#endif

  return false; // default
}

//---------------------------------------------------------------------------------
//  function:	Set PWM duty cycle as requested for LCD backlight or PWM buzzer parameters
//  parameter:
//  Info:
//---------------------------------------------------------------------------------

bool DEV_SET_PWM(pwm_params *pwm, int Value)
{
#ifdef DEBUG_DEV
  Serial.println("Entered DEV_SET_PWM");
  Serial.printf("DEV_SET_PWM: Pin is %i, Value is %i\n",pwm->pin , Value);
#endif

  if ((Value < 0) || (Value > 255))
  {
#ifdef DEBUG_DEV
    Serial.printf("DEV_SET_PWM Value out of range\n");
#endif
    return true; // fail
  }
  
  pwm->dutyCycle = (4095 / PWM_Max_Duty_Cycle) * min(Value, PWM_Max_Duty_Cycle);

  ledcWrite(pwm->pin, pwm->dutyCycle);

  return false; // Should never reach here!
}

//---------------------------------------------------------------------------------
// Sets up WS2812 backlight LEDs in the 'Nixie' tubes
//---------------------------------------------------------------------------------
void rgb_setup(void)
{
#ifdef DEBUGGER
    Serial.println("Sets up WS2812 backlight LEDs");
#endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  builtin_led.begin();           // INITIALIZE NeoPixel builtin_led object (REQUIRED)
  builtin_led.show();            // Turn OFF all pixels ASAP
  builtin_led.setBrightness(200); // Set BRIGHTNESS to about 1/5 (max = 255)

}

//---------------------------------------------------------------------------------
// Sets up WS2812 backlight LEDs in the 'Nixie' tubes
//---------------------------------------------------------------------------------

void rgb_action(uint8_t rgb_red, uint8_t rgb_green, uint8_t rgb_blue, uint8_t brightness)
{
#ifdef DEBUGGER
  Serial.printf("Sets up WS2812 backlight colours Red = %i, Green = %i, Blue = %i, Brightness = %i\n", rgb_red, rgb_green, rgb_blue, brightness);
#endif

  strip.setBrightness(brightness); // Set BRIGHTNESS to about 1/5 (max = 255)

  colorWipe(strip.Color(rgb_red, rgb_green, rgb_blue)); // Violet
}

// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t colour)
{
  uint8_t pixelCurrent;                // Pattern Current Pixel Number

  for (pixelCurrent = 0; pixelCurrent < NUM_NIXIE_TUBE_LEDS; pixelCurrent++)
  {
    strip.setPixelColor(pixelCurrent, colour); //  Set pixel's color (in RAM)
    strip.show();                             //  Update strip to match

    Non_Blocking_Delay_mSec(50);              // Wait 50msecs between NUM_NIXIE_TUBE_LEDS
  }
}

// Set the single WS2812 on board WS2812 to 'colour' - value 
void on_Board_LED_colour(uint32_t colour, uint8_t brightness)
{
  builtin_led.setBrightness(brightness);
  builtin_led.fill(colour);
  builtin_led.show();            // Turn OFF all pixels ASAP
}

void off_Board_LED(void)
{
  builtin_led.fill(0x000000);
  builtin_led.show();            // Turn OFF all pixels ASAP
}


//---------------------------------------------------------------------------------
//  function:	GPIO Clear - just clears GPIO's but does NOT set them up
//---------------------------------------------------------------------------------
bool gpio_Clear(void)
{
  pinMode(UART0TX,      OUTPUT);            // UART1 TXD - only used for debugging in this app
  pinMode(UART0RX,      INPUT);             // UART1 RXD - pulled down if not connected - only used for debugging
  pinMode(LCD_GSA1,     OUTPUT);            // LCD_GSA1 - LSB of pins controlling LCD selection via a 74HC138
  pinMode(LCD_GSA2,     OUTPUT);            // LCD_GSA2 - middle pin controlling LCD selection via a 74HC138
  pinMode(LCD_GSA3,     OUTPUT);            // LCD_GSA3 - MSB of pins controlling LCD selection via a 74HC138
  pinMode(DEV_RGB_PIN,  INPUT_PULLDOWN);    // ADC0 - Pulled down as not used inthis implementation
  pinMode(LED_PIN,      OUTPUT);            // This is the onboard LED. It is not brought out to the I/O Pins
  pinMode(LCD_CLK_PIN,  OUTPUT);            // FSPI_SCLK - LCD_CLK_PIN Clocks LCD's at 5MHz per bit
  pinMode(LCD_MOSI_PIN, OUTPUT);            // VSPI_MOSI - LCD_MOSI_PIN Sends bit image data to LCD
  pinMode(LCD_RST_PIN,  OUTPUT);            // VSPI_MISO - LCD_RST_PIN - NOT used for MISO input
  pinMode(LCD_BL_PIN,   OUTPUT);            // VSPI_SS - LCD_BL_PIN Used to turn LCD Backlight On or OFF. 
  pinMode(DEV_SDA_PIN,  OPEN_DRAIN);        // Primary I2C Data Pin - DEV_SDA_PIN - Pulled up externally
  pinMode(DEV_SCL_PIN,  OUTPUT_OPEN_DRAIN); // RTC Xtal pin reassigned as output for Primary I2C Clock Pin - DEV_SCL_PIN - Pulled up externally
  pinMode(LCD_DC_PIN,   OUTPUT);            // RTC Xtal pin reassigned as output for LCD Data/Command line
  pinMode(GPIO34,       OUTPUT);            // DAC-1 but set to Output and Not Used
  pinMode(DEV_KBZR_PIN, OUTPUT);            // DEV_KBZR_PIN - Audio buzzer (Alarm clock?)
  pinMode(DEV_KR_PIN,   INPUT);             // DEV_KR_PIN - Right push button - externally pulled down
  pinMode(DEV_KL_PIN,   INPUT);             // DEV_KL_PIN - Left push button - externally pulled down
  pinMode(DEV_KM_PIN,   INPUT);             // DEV_KM_PIN - Mode push button - externally pulled down
  pinMode(DEV_INT_PIN,  INPUT);             // DEV_INT_PIN - Real Time Clock Interrupt pin
  pinMode(GPIO0,        INPUT_PULLUP);      // Pressing to 'BOOT' button drags pin to ground
  pinMode(GPIO1,        INPUT);             // Pin senses a high voltage approx 3V when the USB plug is inserted No pullup
  pinMode(GPIO2,        OUTPUT);            // Not Used externally
  pinMode(GPIO4,        PULLUP);            // Secondary I2C Data pin - Not Used
  pinMode(GPIO5,        OUTPUT_OPEN_DRAIN); // Secondary I2C Clock pin - Not Used
  pinMode(GPIO6,        OUTPUT);            // DEV_RGB_PIN (WS2812B) Daisy chained through LCD's
  pinMode(GPIO7,        OUTPUT);            // Not Used externally
  pinMode(GPIO8,        INPUT_PULLDOWN);    // ADC1 - Pulled down as not used inthis implementation
  pinMode(GPIO9,        INPUT_PULLDOWN);    // ADC2 - Pulled down as not used inthis implementation

  return false;
}

//---------------------------------------------------------------------------------
//  function:	GPIO initialization
//  parameter:
//  Info:
//---------------------------------------------------------------------------------
bool DEV_GPIO_Init(void)
{
#ifdef DEBUG_DEV
  Serial.printf("Entered DEV_GPIO_Init\n");
#endif
  pinMode(LCD_RST_PIN, OUTPUT); // Configure LCD Reset Pins (6)
  pinMode(LCD_DC_PIN, OUTPUT);  // Configure LCD Data/Command Pins (6) - High for Data, Loe for Commands
  pinMode(LCD_BL_PIN, OUTPUT);
    
  pinMode(LCD_GSA1, OUTPUT);    // Configure LCD tube selection, Outputs Y0,Y1 = Hours
  pinMode(LCD_GSA2, OUTPUT);    // Configure LCD tube selection, Outputs Y2,Y3 = Mins
  pinMode(LCD_GSA3, OUTPUT);    // Configure LCD tube selection, Outputs Y4,Y5 = Secs, Outputs Y6,Y7 Not Used
    
  pinMode(DEV_INT_PIN,INPUT);   // Real Time Clock Interrupt pin
  pinMode(DEV_KL_PIN,INPUT);    // Configure 'Left' button pin for Input
  pinMode(DEV_KR_PIN,INPUT);    // Configure 'Right' button pin for Input
  pinMode(DEV_KM_PIN,INPUT);    // Configure 'Mode' button pin for Input

// Set Pins initial state
  digitalWrite(LCD_GSA1, HIGH);
  digitalWrite(LCD_DC_PIN, LOW);
  digitalWrite(LCD_BL_PIN, HIGH);
  digitalWrite(DEV_KBZR_PIN, HIGH);
    
  digitalWrite(LED_PIN, HIGH); // Power on WS2812 on board LED indicator

#ifdef DEBUG_DEV
  Serial.printf("GPIO Set Up Done\n");
#endif
  return false; // Default for now
}    

//---------------------------------------------------------------------------------
// function:	Initialise ESP32-S3 SPI interface using SPIO2 (FSPI) for LCD
//  See note below - For the Waveshare clock we use FSPI mapped to VSPI only
//---------------------------------------------------------------------------------

/* The ESP32 has four SPi buses, however as of right now only two of
 * them are available to use, HSPI and VSPI. Simply using the SPI API 
 * as illustrated in Arduino examples will use VSPI, leaving HSPI unused.
 * 
 */

bool DEV_SPI_Init(void)
{
#ifdef DEBUG_DEV
  Serial.printf("Entered DEV_SPI_Init\n");
#endif

#ifdef DEBUG_DEV

#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
    Serial.printf("#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3 is true so #define VSPI FSPI\n");
  #ifdef ALTERNATE_PINS
    Serial.printf("#define VSPI_MISO   is %i\n",LCD_RST_PIN);
    Serial.printf("#define VSPI_MOSI   is %i\n",LCD_MOSI_PIN);
    Serial.printf("#define VSPI_SCLK   is %i\n",LCD_CLK_PIN);
    Serial.printf("#define VSPI_SS     is %i\n",LCD_BL_PIN);

    Serial.printf("#define HSPI_MISO   is %i\n",26);
    Serial.printf("#define HSPI_MOSI   is %i\n",27);
    Serial.printf("#define HSPI_SCLK   is %i\n",25);
    Serial.printf("#define HSPI_SS     is %i\n",32);
  #else
    Serial.printf("#define VSPI_MISO   is %i\n",MISO);
    Serial.printf("#define VSPI_MOSI   is %i\n",MOSI);
    Serial.printf("#define VSPI_SCLK   is %i\n",SCLK);
    Serial.printf("#define VSPI_SS     is %i\n",SS);

    Serial.printf("#define HSPI_MISO   is %i\n",12);
    Serial.printf("#define HSPI_MOSI   is %i\n",13);
    Serial.printf("#define HSPI_SCLK   is %i\n",14);
    Serial.printf("#define HSPI_SS     is %i\n",15);
  #endif
#endif
#endif

#ifdef DEBUG_DEV
  Serial.println("SPI Starting SPI -vspi");
#endif

// Use alternative route through GPIO pins of your choice
//  fspi.begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI);
//  hspi.begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI);
  vspi.begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI);


//DO NOT set up slave select pins as outputs as the Arduino API
//doesn't handle automatically pulling SS low
// The Waveshare 'Nixie' Clock selects each 'tube' through a 1 of 6 multiplexor
// and uses the fspi.pinSS as a PWN pulsed backlight and is driven separately by a PWM channel
//  pinMode(fspi.pinSS(), OUTPUT); //FSPI SS which is LCD_BL_PIN

  return false; // Default for now
}

//---------------------------------------------------------------------------------
// function:	Initialise ESP32-S2 i2c1 interface for DS3231 RTC and BME280 environment
//  sensor later perhaps display
//---------------------------------------------------------------------------------

bool DEV_i2c_Init(void)
{
#ifdef DEBUG_DEV
  Serial.println("Entered DEV_i2c_Init");
  Serial.printf("#define DEV_SDA_PIN is %i\n",DEV_SDA_PIN);
  Serial.printf("#define DEV_SCL_PIN is %i\n",DEV_SCL_PIN);
#endif
  return(!(Wire.begin(DEV_SDA_PIN, DEV_SCL_PIN, i2c_frequency)));
//  return(!(Wire.begin(14.15,i2c_frequency)));
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
******************************************************************************/
void DEV_Module_Exit(void)
{
#ifdef DEBUG_DEV
  printf("void DEV_Module_Exit(void)\n");
#endif
}
