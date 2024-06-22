/*****************************************************************************
* | File        :   LCD_1in14.C
* | Function    :   test Demo
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

#include "ESP32_Nixie.h"

LCD_1IN14_ATTRIBUTES LCD_1IN14;

extern pwm_params *backlight_ptr;
extern pwm_params *buzzer_ptr;

// Allocate global pointers to PSRAM display memory
uint16_t *BlackImage;

extern uint16_t *dispImageNum_0;
extern uint16_t *dispImageNum_1;
extern uint16_t *dispImageNum_2;
extern uint16_t *dispImageNum_3;
extern uint16_t *dispImageNum_4;
extern uint16_t *dispImageNum_5;
extern uint16_t *dispImageNum_6;
extern uint16_t *dispImageNum_7;
extern uint16_t *dispImageNum_8;
extern uint16_t *dispImageNum_9;

extern uint16_t **digit_MemoryImages[];
extern const uint16_t *Image_Names[];

//---------------------------------------------------------------------------------
// Module Prototypes
//---------------------------------------------------------------------------------

void LCD_1IN14_SendCommand(uint8_t);
void LCD_1IN14_SendData_8Bit(uint8_t);
void LCD_1IN14_SendData_16Bit(uint16_t);
void LCD_1IN14_Reset(void);
static void LCD_1IN14_Num(uint8_t, uint8_t);
bool LCD_1IN14_Init(uint8_t);
bool LCD_1IN14_Clear(uint16_t);
void LCD_1IN14_InitReg(void);
void LCD_1IN14_SetAttributes(uint8_t);
void LCD_1IN14_SetWindows(uint16_t, uint16_t, uint16_t, uint16_t);
void LCD_1IN14_Display(uint16_t *);
void LCD_1IN14_DisplayWindows(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t *);
void LCD_1IN14_DisplayPoint(uint16_t, uint16_t, uint16_t);
void LCD_1IN14_Display_Image(const uint16_t *, uint16_t *, uint8_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t); 
bool LCD_1in14_test(void);
void Display_time_hms(uint16_t *);

//---------------------------------------------------------------------------------
// function :	send command
// parameter:
//   Reg : Command register
//#define commandMode LOW
//#define dataMode HIGH
//---------------------------------------------------------------------------------
void LCD_1IN14_SendCommand(uint8_t Reg)
{
  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);

  DEV_Digital_Write(LCD_DC_PIN, commandMode);
  DEV_SPI_WriteByte(Reg);

  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1);
}

/******************************************************************************
function :	send data
parameter:
    Data : Write data
******************************************************************************/
void LCD_1IN14_SendData_8Bit(uint8_t Data)
{
  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);

  DEV_Digital_Write(LCD_DC_PIN, dataMode);
  DEV_SPI_WriteByte(Data);

  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1);
}

/******************************************************************************
function :	send data
parameter:
    Data : Write data
******************************************************************************/
void LCD_1IN14_SendData_16Bit(uint16_t Data)
{
  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);

  DEV_Digital_Write(LCD_DC_PIN, dataMode);
  DEV_SPI_WriteByte((Data >> 8) & 0xFF);
  DEV_SPI_WriteByte(Data & 0xFF);

  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1);
}

/******************************************************************************
function :	Hardware reset
parameter:
******************************************************************************/
void LCD_1IN14_Reset(void)
{
  DEV_Digital_Write(LCD_RST_PIN, true);
//  delay(100);
  Non_Blocking_Delay_mSec(5);
#ifdef DEBUG_LCD
  Serial.println("Set LCD_RST_PIN, true");
#endif
  DEV_Digital_Write(LCD_RST_PIN, false);
//  delay(100);
  Non_Blocking_Delay_mSec(5);
#ifdef DEBUG_LCD
  Serial.println("Set LCD_RST_PIN, false");
#endif
  DEV_Digital_Write(LCD_RST_PIN, true);
//  delay(100);
  Non_Blocking_Delay_mSec(5);
#ifdef DEBUG_LCD
  Serial.println("Set LCD_RST_PIN, true");
#endif
}

//---------------------------------------------------------------------------------
// function : Select individual LCD - 1 0f 8 multiplexor using 6 'tubes'
// parameter:
//   Data : Write data
//---------------------------------------------------------------------------------

static void LCD_1IN14_Num(uint8_t lcd_num, uint8_t Value)
{
// Chip Select (one of six) is active low. 74HC138 has 8 outputs, only /Y0 to /Y5 sre connected
  if(Value == 1)
  {
    lcd_num = lcd_num + 1;
  }
    
#ifdef DEBUG_LCD
//  Serial.printf("GSA1 is 0x%x, ",(lcd_num & 0x01));
#endif
  DEV_Digital_Write(LCD_GSA1, (lcd_num & 0x01));

  lcd_num = lcd_num >> 1;
#ifdef DEBUG_LCD
//  Serial.printf("GSA2 is 0x%x, ",(lcd_num & 0x01));
#endif
  DEV_Digital_Write(LCD_GSA2, (lcd_num & 0x01));

  lcd_num = lcd_num >> 1;
#ifdef DEBUG_LCD
//  Serial.printf("GSA3 is 0x%x\n",(lcd_num & 0x01));
#endif
  DEV_Digital_Write(LCD_GSA3, (lcd_num & 0x01));

}    

//---------------------------------------------------------------------------------
// function :	Initialize the lcd
// parameter:  uint8_t Scan_Direction (HORIZONTAL or VERTICAL)
//---------------------------------------------------------------------------------
bool LCD_1IN14_Init(uint8_t Scan_Direction)
{
#ifdef DEBUG_LCD
  Serial.printf("Entered LCD_1IN14_Init(%s);\n", Scan_Direction ? "VERTICAL" : "HORIZONTAL");
#endif

// Hardware reset
  LCD_1IN14_Reset();

  for (int i = 0; i < NUM_LCDS; i++)
  {
    LCD_1IN14.LCD_NUM = i;

// Set LCD Multiplexor (74HC138) Outputs 1 of 6 for each 'nixie' tube in turn
    LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);

// Set the resolution and scanning method of the screen
    LCD_1IN14_SetAttributes(Scan_Direction);

// Set the initialization register for each LCD
    LCD_1IN14_InitReg();
  }

  LCD_1IN14.LCD_NUM = 0;

  DEV_Digital_Write(LCD_BL_PIN, 0); 
  DEV_SET_PWM(backlight_ptr,100);

  return false;

}

//---------------------------------------------------------------------------------
// function :	Clear screen with a fixed colour - we need to allocate 64800 octets
//            which needs to use PSRAM on the Waveshare ESP32-S2_Pico board. To
//            avoid memory allocation problems PSRAM must be enabled in Arduino IDE
//            tools menu and PSRAM must be locked initially, unlocked here, calloc'ed
//            here, used, free'd and finally locked again.
//
//  parameter: A fixed Colour as per include file
//
//---------------------------------------------------------------------------------

bool LCD_1IN14_Clear(uint16_t Colour)
{
#ifdef DEBUG_LCD
    Serial.printf("\nEntered LCD_1IN14_Clear\n");
#endif

// Swap Colour octets because ST7789 SPI is little endian
  Colour = ((Colour << 8) & 0xff00) | (Colour >> 8);
// Now select each LCD in turn - six
  for ( int i = 0; i < NUM_LCDS; i++)
  {

    LCD_1IN14.LCD_NUM = i;
    LCD_1IN14_SetWindows(0, 0, LCD_1IN14.WIDTH, LCD_1IN14.HEIGHT); // Sets the start display pixel position for each LCD
    DEV_Digital_Write(LCD_DC_PIN, dataMode); // sets LCD into data mode
    LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0); // actually select LCD (1 of 8 decoder)

// The ESP SPI Library has a nice pattern write function which avoids memory allocation!
    DEV_SPI_Write_pattern((uint8_t *)&Colour, sizeof(uint16_t), Image_Size);

    watchDogRefresh();

    Non_Blocking_Delay_uSec(20);  // Allow for SPI clock speed
//    LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1); // ? Essential fiddling with the 1 of 8 decoder but what does it do?

  }

  DEV_Digital_Write(LCD_DC_PIN, commandMode); // sets LCD into command mode
  LCD_1IN14_SendCommand(ST7789_DISPON);    // DISPON (0x29): Display On
  DEV_Digital_Write(LCD_DC_PIN, dataMode); // sets LCD into data mode

  return false;

}

/******************************************************************************
function :	Initialize the lcd register
parameter:
******************************************************************************/
void LCD_1IN14_InitReg(void)
{

  LCD_1IN14_SendCommand(ST7789_COLMOD);   // COLMOD (0x3A) Set Interface pixel format
  LCD_1IN14_SendData_8Bit(0x05);          // 9.8.17 Write Data for 16-bit/Pixel (RGB 5-6-5-bit Input), 65K-Colors, 3AH=“05h”


  LCD_1IN14_SendCommand(ST7789_PORCTRL);  // 0xB2 Porch Setting Datasheet Section 9.2.3
  LCD_1IN14_SendData_8Bit(0x0C);          // BPA0 BPA[6:0]: Back porch setting in normal mode. The minimum setting is 0x01
  LCD_1IN14_SendData_8Bit(0x0C);          // FPA0 FPA[6:0]: Front porch setting in normal mode. The minimum setting is 0x01.
  LCD_1IN14_SendData_8Bit(0x00);          // PSEN PSEN: Disable separate porch control.
  LCD_1IN14_SendData_8Bit(0x33);          // FPB0 BPB[3:0]: Back porch setting in idle mode. The minimum setting is 0x01.
  LCD_1IN14_SendData_8Bit(0x33);          // FPC0 FPB[3:0]: Front porch setting in idle mode. The minimum setting is 0x01
// Not Used BPC[3:0]: Back porch setting in partial mode. The minimum setting is 0x01.
// Not Used FPC[3:0]: Front porch setting in partial mode. The minimum setting is 0x01.

  LCD_1IN14_SendCommand(ST7789_GCTRL);    // GCTRL (B7h): Gate Control Datasheet Section 9.2.6
  LCD_1IN14_SendData_8Bit(0x35);          // Set to Default Value

  LCD_1IN14_SendCommand(ST7789_VCOMS);    // VCOMS (BBh): VCOM Setting Datasheet Section 9.2.9 
  LCD_1IN14_SendData_8Bit(0x19);          // VCOMS[5:0] = 0x19 VCOM (V) = 0.725

  LCD_1IN14_SendCommand(ST7789_LCMCTRL);  // LCMCTRL (C0h): LCM Control Datasheet Section 9.2.12
  LCD_1IN14_SendData_8Bit(0x2C);          // Set to Default Value

  LCD_1IN14_SendCommand(ST7789_VDVVRHEN); // VDVVRHEN (C2h): VDV and VRH Command Enable Datasheet Section 9.2.14
  LCD_1IN14_SendData_8Bit(0x01);          // CMDEN=”1”, VDV and VRH register value comes from command write.

  LCD_1IN14_SendCommand(ST7789_VRHS);     // VRHS (C3h): VRH Set Datasheet Section 9.2.15
  LCD_1IN14_SendData_8Bit(0x12);          // 12h = 4.45+ ( vcom+vcom offset+vdv)

  LCD_1IN14_SendCommand(ST7789_VDVS);     // VDVS (C4h): VDV Set Datasheet Section 9.2.16 
  LCD_1IN14_SendData_8Bit(0x20);          // VDVS[5:0] = 0x20 VDV (V) = 0

  LCD_1IN14_SendCommand(ST7789_FRCTRL2);  // FRCTRL2 (C6h): Frame Rate Control in Normal Mode Datasheet Section 9.2.18 
  LCD_1IN14_SendData_8Bit(0x0F);          // RTNA[4:0] = 0x0F FR in normal mode (Hz) = 60

  LCD_1IN14_SendCommand(ST7789_PWCTRL1);  // PWCTRL1 (D0h): Power Control 1 Datasheet Section 9.2.23
  LCD_1IN14_SendData_8Bit(0xA4);          // Set to Default Value
  LCD_1IN14_SendData_8Bit(0xA1);          // Set to Default Value

  LCD_1IN14_SendCommand(ST7789_PVGAMCTRL);// PVGAMCTRL (E0h): Positive Voltage Gamma Control Datasheet Section 9.2.26
  LCD_1IN14_SendData_8Bit(0xD0);          // These 14 parameters are NOT default values
  LCD_1IN14_SendData_8Bit(0x04);
  LCD_1IN14_SendData_8Bit(0x0D);
  LCD_1IN14_SendData_8Bit(0x11);
  LCD_1IN14_SendData_8Bit(0x13);
  LCD_1IN14_SendData_8Bit(0x2B);
  LCD_1IN14_SendData_8Bit(0x3F);
  LCD_1IN14_SendData_8Bit(0x54);
  LCD_1IN14_SendData_8Bit(0x4C);
  LCD_1IN14_SendData_8Bit(0x18);
  LCD_1IN14_SendData_8Bit(0x0D);
  LCD_1IN14_SendData_8Bit(0x0B);
  LCD_1IN14_SendData_8Bit(0x1F);
  LCD_1IN14_SendData_8Bit(0x23);

  LCD_1IN14_SendCommand(ST7789_NVGAMCTRL);// NVGAMCTRL (E1h): Negative Voltage Gamma Control Datasheet Section 9.2.27
  LCD_1IN14_SendData_8Bit(0xD0);          // These 14 parameters are NOT default values
  LCD_1IN14_SendData_8Bit(0x04);
  LCD_1IN14_SendData_8Bit(0x0C);
  LCD_1IN14_SendData_8Bit(0x11);
  LCD_1IN14_SendData_8Bit(0x13);
  LCD_1IN14_SendData_8Bit(0x2C);
  LCD_1IN14_SendData_8Bit(0x3F);
  LCD_1IN14_SendData_8Bit(0x44);
  LCD_1IN14_SendData_8Bit(0x51);
  LCD_1IN14_SendData_8Bit(0x2F);
  LCD_1IN14_SendData_8Bit(0x1F);
  LCD_1IN14_SendData_8Bit(0x1F);
  LCD_1IN14_SendData_8Bit(0x20);
  LCD_1IN14_SendData_8Bit(0x23);

  LCD_1IN14_SendCommand(ST7789_INVON);    // INVON (21h): Display Inversion On Datasheet Section 9.1.16

  LCD_1IN14_SendCommand(ST7789_SLPOUT);   // SLPOUT (11h): Sleep Out Datasheet Section 9.1.12

  LCD_1IN14_SendCommand(ST7789_DISPON);   // DISPON (29h): Display On Datasheet Section 9.1.19

}

//---------------------------------------------------------------------------------
// function:	Set the resolution and scanning method of the screen
// parameter: Scan_dir:   Scan direction
//---------------------------------------------------------------------------------
void LCD_1IN14_SetAttributes(uint8_t Scan_direction)
{
//Get the screen scan direction
  LCD_1IN14.SCAN_DIR = Scan_direction;
  uint8_t MemoryAccessReg = 0x00;

//Get GRAM and LCD width and height
  if(Scan_direction == HORIZONTAL) {
    LCD_1IN14.HEIGHT	= LCD_1IN14_WIDTH;
    LCD_1IN14.WIDTH   = LCD_1IN14_HEIGHT;
    MemoryAccessReg = 0X70;
  } else {
    LCD_1IN14.HEIGHT	= LCD_1IN14_HEIGHT;       
    LCD_1IN14.WIDTH   = LCD_1IN14_WIDTH;
    MemoryAccessReg = 0X00;
  }

// Set the read / write scan direction of the frame memory
  LCD_1IN14_SendCommand(ST7789_MADCTL);     // MADCTL (36h): Memory Data Access Control - MX, MY, RGB mode
  LCD_1IN14_SendData_8Bit(MemoryAccessReg);	//0x08 set RGB
#ifdef DEBUG_LCD
  Serial.printf("Done LCD_1IN14_SetAttributes(uint8_t Scan_direction = %d) with LCD_1IN14_SendCommand(ST7789_MADCTL); followed by LCD_1IN14_SendData_8Bit(MemoryAccessReg = 0x%X); LCD_1IN14.HEIGHT = %i, LCD_1IN14.WIDTH = %i\n",Scan_direction,MemoryAccessReg, LCD_1IN14.HEIGHT, LCD_1IN14.WIDTH);
#endif
}

/********************************************************************************
function:	Sets the start position and size of the display area
parameter:
        Xstart 	:   X direction Start coordinates
        Ystart  :   Y direction Start coordinates
        Xend    :   X direction end coordinates
        Yend    :   Y direction end coordinates
********************************************************************************/
void LCD_1IN14_SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
  uint8_t x, y;
  if (LCD_1IN14.SCAN_DIR == HORIZONTAL)
  {
    x = 40;
    y = 53;
  }
  else
  {
    x = 52;
    y = 40;
  }

// set the X coordinates
  LCD_1IN14_SendCommand(ST7789_CASET);    // CASET (0x2A): Column Address Set
  LCD_1IN14_SendData_16Bit(Xstart + x);
  LCD_1IN14_SendData_16Bit(Xend - 1 + x);

// set the Y coordinates
  LCD_1IN14_SendCommand(ST7789_RASET);    // RASET (0x2B): Row Address Set
  LCD_1IN14_SendData_16Bit(Ystart + y);
  LCD_1IN14_SendData_16Bit(Yend - 1 + y);

  LCD_1IN14_SendCommand(ST7789_RAMWR);    // RAMWR (0x2C): Memory Write
// printf("%d %d\r\n",x,y);
}

/******************************************************************************
function :	Sends the image buffer in RAM to displays
parameter:
******************************************************************************/
void LCD_1IN14_Display(uint16_t *Image)
{
#ifdef DEBUG_LCD
    Serial.printf("\nEntered LCD_1IN14_Display\n");
#endif

  LCD_1IN14_SetWindows(0, 0, LCD_1IN14.WIDTH, LCD_1IN14.HEIGHT);
  DEV_Digital_Write(LCD_DC_PIN, dataMode);

  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);

#ifdef DEBUG_LCD
    Serial.printf("LCD_1IN14_Display Image at 0x%X and number of octets to be sent is %d\n",Image,((LCD_1IN14.WIDTH * LCD_1IN14.HEIGHT) * 2));
#endif

  DEV_SPI_Write_nByte((uint8_t *)Image, ((LCD_1IN14.WIDTH * LCD_1IN14.HEIGHT) * 2));
#ifdef DEBUG_LCD
  Serial.printf("LCD_1IN14_Display - is data written?\n");
#endif


  Non_Blocking_Delay_mSec(5);  // Allow for SPI clock speed   

  LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1);
  DEV_Digital_Write(LCD_DC_PIN, commandMode); // sets LCD into command mode
  LCD_1IN14_SendCommand(ST7789_DISPON);    // DISPON (0x29): Display On
  DEV_Digital_Write(LCD_DC_PIN, dataMode); // sets LCD into data mode
}

/******************************************************************************
function :	Sends the image buffer in RAM to displays
parameter:
        Xstart 	:   X direction Start coordinates
        Ystart  :   Y direction Start coordinates
        Xend    :   X direction end coordinates
        Yend    :   Y direction end coordinates
        Image	:	Written content
******************************************************************************/
void LCD_1IN14_DisplayWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image)
{
// display
  uint32_t Addr = 0;

  uint16_t j;
    LCD_1IN14_SetWindows(Xstart, Ystart, Xend, Yend);
    DEV_Digital_Write(LCD_DC_PIN, dataMode);
    LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 0);
    for (j = Ystart; j < Yend - 1; j++)
    {
        Addr = Xstart + j * LCD_1IN14.WIDTH;
        DEV_SPI_Write_nByte((uint8_t *)&Image[Addr], (Xend - Xstart) * 2);
    }
    LCD_1IN14_Num(LCD_1IN14.LCD_NUM, 1);
}

/******************************************************************************
function :	Change the color of a point
parameter:
        X 		:   X coordinates
        Y  		:   Y coordinates
        Color	:	Color
******************************************************************************/
void LCD_1IN14_DisplayPoint(uint16_t X, uint16_t Y, uint16_t Color)
{
    LCD_1IN14_SetWindows(X, Y, X, Y);
    LCD_1IN14_SendData_16Bit(Color);
}


//---------------------------------------------------------------------------------
// Routine to display ('nixie') image on LCD's
//---------------------------------------------------------------------------------
void LCD_1IN14_Display_Image(const uint16_t *imageName, uint16_t *outImage, uint8_t LCD_Num, uint16_t Rotate, uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd) 
{
#ifdef DEBUG_LCD
  Serial.printf("\nEntered LCD_1IN14_Display_Image, *imageName = 0x%x, *outImage = 0x%x, LCD_Num = %d, Rotate = %d, xStart = %i, yStart = %i, xEnd = %i, yEnd = %i\n",imageName, outImage, LCD_Num, Rotate, xStart, yStart, xEnd, yEnd);
#endif
// Select LCD to display  
  LCD_1IN14.LCD_NUM = LCD_Num;
// Set Image Angle (Rotation shall be 0,90,180,270 only)
  Paint_SetRotate(Rotate);
// Create desired image in memory - viz BlackImage)  
  Paint_DrawImage_16bit(imageName, xStart, yStart, xEnd, yEnd);
// Actually do the display
  LCD_1IN14_Display(outImage);
// Allow a bit of time for image to complete
  Non_Blocking_Delay_mSec(20);
// Refresh the watchdog after memory operations
  watchDogRefresh();

}

//---------------------------------------------------------------------------------
// Routine to test LCD's at startup
//---------------------------------------------------------------------------------

bool LCD_1in14_test(void)
{

//  static uint16_t *BlackImage;

#ifdef DEBUG_LCD
  Serial.println("\nEntered LCD_1in14_test");
#endif

  Non_Blocking_Delay_mSec(100);
  LCD_1IN14_SetBacklight(10);

// For Waveshare "NIXIE" Clock Display
  LCD_1IN14_Init(HORIZONTAL);
  LCD_1IN14_Clear(ST7789_GREEN);

// Allocate display memory for 1 image

	BlackImage = (uint16_t *)malloc(Image_Size * sizeof(uint16_t));

  if (BlackImage == NULL) {
#ifdef DEBUG_LCD
    Serial.printf("Failed to apply for black memory...\n");
#endif
    return true;
  }

  watchDogRefresh();
  
#ifdef DEBUG_LCD
 	Serial.printf("BlackImage is now pointing to: 0x%X\n", BlackImage);
	Serial.printf("BlackImage's number of octets: %d\n", Image_Size * sizeof(uint16_t));
  printMem();
//	HWSerial.printf("Printed Memory\n");
#endif

//.Set BlackImage GUI parameters, set scaling and fill memory with a colour - do not display this image
  Paint_NewImage((uint8_t *)BlackImage,LCD_1IN14.WIDTH,LCD_1IN14.HEIGHT, ROTATE_0, ST7789_BLUE); // Set basic GUI parameters
  if (Paint_SetScale(65)) // Modify them for our display later - order of functions is important
    return true; // If a value other than 2,4,16 or 65 (depending on LCD) is specified then fail
  Paint_SetRotate(ROTATE_0);
  if (Paint_Clear(ST7789_WHITE))    // Set the image memory to value WHITE - this will be our background colour
    return true; // If Paint_Clear fails, return to setup() module with a funtion fail value

#ifdef DEBUG_LCD
  Serial.println("Paint_SetScale and Paint_Clear succeeded");
#endif
  for (uint8_t x = 0; x < NUM_LCDS; x++) // now display the background colour on each LCD
  {
    LCD_1IN14.LCD_NUM = x;
    LCD_1IN14_Display(BlackImage);
    watchDogRefresh();
  }

// GUI Test Routine
#ifdef DEBUG_LCD
  Serial.printf("2.Create the test image using GUI_Paint library\n");
#endif
// 2.Drawing on the image
    Paint_DrawPoint(2,1, ST7789_BLACK, DOT_PIXEL_1X1,  DOT_FILL_RIGHTUP);//240 240
    Paint_DrawPoint(2,6, ST7789_BLACK, DOT_PIXEL_2X2,  DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,11, ST7789_BLACK, DOT_PIXEL_3X3, DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,16, ST7789_BLACK, DOT_PIXEL_4X4, DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,21, ST7789_BLACK, DOT_PIXEL_5X5, DOT_FILL_RIGHTUP);
    Paint_DrawLine( 10,  5, 40, 35, ST7789_MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    Paint_DrawLine( 10, 35, 40,  5, ST7789_MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    Paint_DrawLine( 80,  20, 110, 20, ST7789_CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawLine( 95,   5,  95, 35, ST7789_CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawRectangle(10, 5, 40, 35, ST7789_RED, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    Paint_DrawRectangle(45, 5, 75, 35, ST7789_BLUE, DOT_PIXEL_2X2,DRAW_FILL_FULL);
    Paint_DrawCircle(95, 20, 15, ST7789_GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawCircle(130, 20, 15, ST7789_GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawNum (50, 40 ,9.87654321, &Font20,3,  ST7789_WHITE,  ST7789_BLACK);
    Paint_DrawString_EN(1, 40, "ABC", &Font20, 0x000f, 0xfff0);
//  Paint_DrawString_CN(1,60, "��ӭʹ��",  &Font24CN, ST7789_WHITE, ST7789_BLUE);
    Paint_DrawString_EN(1, 100, "Pico-LCD-1.14", &Font16, ST7789_RED, ST7789_WHITE); 

#ifdef DEBUG_LCD
    Serial.printf("3.Send the created image in in RAM to all LCD's\n");
#endif

  for (uint8_t x = 0; x < NUM_LCDS; x++)
  {
// 3.Refresh the picture in RAM to LCD
    LCD_1IN14.LCD_NUM = x;

    LCD_1IN14_Display(BlackImage);

    watchDogRefresh();
  }

  Non_Blocking_Delay_mSec(20);
  DEV_SET_PWM(backlight_ptr,90);

#ifdef DEBUG_LCD
  Serial.printf("4. Paint contents of imageData.c as test\n");
#endif

  for (uint8_t x = 0; x < NUM_LCDS; x++)
  {

    LCD_1IN14.LCD_NUM = x;
    Paint_SetRotate(ROTATE_0);
  
    Paint_DrawImage(gImage_1inch14_1,0,0,LCD_1IN14_HEIGHT,LCD_1IN14_WIDTH);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);

    watchDogRefresh();

  }

#ifdef DEBUG_LCD
  Serial.printf("5. Copy contents of Numx_New.h files to malloc()-ed memory\n");
#endif

// For 16 bit image files such as the 'nixie' images only
  for (uint8_t x = 0; x < NUM_LCDS; x++)
  {
    LCD_1IN14_Display_Image(Num0_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num1_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num2_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num3_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num4_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num5_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num6_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num7_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num8_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num9_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
    LCD_1IN14_Display_Image(Num0_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);

  }

#ifdef DEBUG_LCD
  Serial.println("Exit from button/joystick test...");
#endif

  return false;

}


//---------------------------------------------------------------------------------
// Time Display Routine
//---------------------------------------------------------------------------------

void Display_time_hms(uint16_t *BlackImage)
{
  static uint8_t display_num[6];

  display_num[0] = RTC.getSecond() % 10;
  display_num[1] = RTC.getSecond() / 10;
  display_num[2] = RTC.getMinute() % 10;
  display_num[3] = RTC.getMinute() / 10;
  display_num[4] = RTC.getHour(h12Flag, pmFlag) % 10;
  display_num[5] = RTC.getHour(h12Flag, pmFlag) / 10;

//  Serial.printf("display_num[0] = %i display_num[1] = %i display_num[2] = %i display_num[3] = %i display_num[4] = %i display_num[5] = %i\n", display_num[0], display_num[1], display_num[2], display_num[3], display_num[4], display_num[5]);


  for (uint8_t x = 0; x < NUM_LCDS; x++)
  {

// Select LCD to display  
    switch (display_num[x])
    {
      case 0:
        LCD_1IN14_Display_Image(Num0_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 1:
        LCD_1IN14_Display_Image(Num1_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 2:
        LCD_1IN14_Display_Image(Num2_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 3:
        LCD_1IN14_Display_Image(Num3_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 4:
        LCD_1IN14_Display_Image(Num4_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 5:
        LCD_1IN14_Display_Image(Num5_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 6:
        LCD_1IN14_Display_Image(Num6_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 7:
        LCD_1IN14_Display_Image(Num7_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 8:
        LCD_1IN14_Display_Image(Num8_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;

      case 9:
        LCD_1IN14_Display_Image(Num9_New, BlackImage, x, ROTATE_180, 0, 0, LCD_1IN14_HEIGHT, LCD_1IN14_WIDTH);
      break;
    }
    
    watchDogRefresh();
  }

}

/*
void Display_time_ymd(uint16_t *BlackImage)
{
    const char *until_str[] = {"��", "��", "��"};
    uint8_t num_str[2];
    time_t Now_time;
    uint8_t display_num[6];
    DS3231_Read_now(&Now_time);
    display_num[0] = Now_time.day % 10;
    display_num[1] = Now_time.day / 10;
    display_num[2] = Now_time.month % 10;
    display_num[3] = Now_time.month / 10;
    display_num[4] = Now_time.year % 10;
    display_num[5] = Now_time.year / 10 % 10;

    for (uint8_t x = 0; x < 6; x++)
    {
        LCD_1IN14.LCD_NUM = x;
        sprintf(num_str, "%d", display_num[x]);
        Paint_Clear(WHITE);
        Paint_DrawString_EN(25, 50, num_str, &Font96CN, 0x0518, WHITE);
        if ((x % 2) == 0)
        {
            Paint_DrawString_EN(85, 170, until_str[x / 2], &Font32CN, 0x0518, WHITE);
        }
        LCD_1IN14_Display(BlackImage);
    }
}

*/
/*
  for (uint8_t x = 0; x < 6; x++)
  {
    LCD_1IN14.LCD_NUM = x;
    Paint_SetRotate(ROTATE_180);
  
    Paint_DrawImage(gImage_1inch14_1,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
    
    Paint_DrawImage_16bit(Num0_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num1_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num2_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num3_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num4_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num5_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num6_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num7_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num8_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
     
    Paint_DrawImage_16bit(Num9_New,0,0,240,135);
    LCD_1IN14_Display(BlackImage);
    Non_Blocking_Delay_mSec(20);
  }
*/     

