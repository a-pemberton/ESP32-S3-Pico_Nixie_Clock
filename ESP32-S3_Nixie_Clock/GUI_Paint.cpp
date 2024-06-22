
/*****************************************************************************
* | File        :   GUI_Paint.C
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

//---------------------------------------------------------------------------------
// LCD Paint Prototypes
//---------------------------------------------------------------------------------

//init and Clear
void Paint_NewImage(uint8_t *, uint16_t, uint16_t, uint16_t, uint16_t);
void Paint_SelectImage(uint8_t *);
void Paint_SetRotate(uint16_t);
void Paint_SetMirroring(uint8_t);
void Paint_SetPixel(uint16_t, uint16_t, uint16_t);
bool Paint_SetScale(uint8_t);

bool Paint_Clear(uint16_t);
void Paint_ClearWindows(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);

//Drawing
void Paint_DrawPoint(uint16_t, uint16_t, uint16_t, DOT_PIXEL, DOT_STYLE);
void Paint_DrawLine(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, LINE_STYLE);
void Paint_DrawRectangle(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, DRAW_FILL);
void Paint_DrawCircle(uint16_t, uint16_t, uint16_t, uint16_t, DOT_PIXEL, DRAW_FILL);

//Display string
void Paint_DrawChar(uint16_t, uint16_t, const char, sFONT*, uint16_t, uint16_t);
void Paint_DrawString_EN(uint16_t, uint16_t, const char *, sFONT*, uint16_t, uint16_t);
void Paint_DrawString_CN(uint16_t, uint16_t, const char *, cFONT*, uint16_t, uint16_t);
void Paint_DrawNum(uint16_t, uint16_t, double, sFONT*, uint16_t,uint16_t, uint16_t);
void Paint_DrawTime(uint16_t, uint16_t, PAINT_TIME *, sFONT*, uint16_t, uint16_t);

//pic
void Paint_DrawBitMap(const unsigned char*);
void Paint_DrawBitMap_Block(const unsigned char*, uint8_t);

void Paint_DrawImage(const unsigned char *, uint16_t, uint16_t, uint16_t, uint16_t) ;
void Paint_DrawImage_16bit(const uint16_t *, uint16_t, uint16_t, uint16_t, uint16_t); 
void Paint_DrawImage1(const unsigned char *, uint16_t, uint16_t, uint16_t, uint16_t);

void Paint_BmpWindows(unsigned char,unsigned char,const unsigned char *,	unsigned char,unsigned char);

// Image attributes
typedef struct {
  uint8_t *Image;
  uint16_t Width;
  uint16_t Height;
  uint16_t WidthMemory;
  uint16_t HeightMemory;
  uint16_t Color;
  uint16_t Rotate;
  uint16_t Mirror;
  uint16_t WidthByte;
  uint16_t HeightByte;
  uint16_t Scale;
} PAINT;
PAINT Paint;


/******************************************************************************
function: Create Image
parameter:
    image   :   Pointer to the image cache
    width   :   The width of the picture
    Height  :   The height of the picture
    Color   :   Whether the picture is inverted
******************************************************************************/
void Paint_NewImage(uint8_t *image, uint16_t Width, uint16_t Height, uint16_t Rotate, uint16_t Color)
{
#ifdef DEBUG_GUI
    Serial.printf("Paint_NewImage(*image = 0x%X, Width = %i, Height = %i, Rotate = %i, Color = 0x%x)\n", image, Width, Height, Rotate, Color);
#endif

  Paint.Image = NULL;
  Paint.Image = image;  // Sets address of BlackImage

  Paint.WidthMemory = Width;
  Paint.HeightMemory = Height;
  Paint.Color = Color;    
	Paint.Scale = 2;
		
  Paint.WidthByte = (Width % 8 == 0) ? (Width / 8 ) : (Width / 8 + 1);
  Paint.HeightByte = Height;    
//    Serial.println("WidthByte = %d, HeightByte = %d\r\n", Paint.WidthByte, Paint.HeightByte);
//    Serial.println(" EPD_WIDTH / 8 = %d\r\n",  122 / 8);
   
  Paint.Rotate = Rotate;
  Paint.Mirror = MIRROR_NONE;
    
  if(Rotate == ROTATE_0 || Rotate == ROTATE_180) 
  {
    Paint.Width = Width;
    Paint.Height = Height;
  } else {
    Paint.Width = Height;
    Paint.Height = Width;
  }
#ifdef DEBUG_GUI
    Serial.printf("Paint.Image = 0x%X, Paint.WidthMemory = %i, Paint.HeightMemory = %i, Paint.Rotate = %i, Paint.Color = %i, Paint.WidthByte = %i, Paint.HeightByte = %i, Paint.Mirror = %i, Paint.Width = %i, Paint.Height = %i \n", Paint.Image, Paint.WidthMemory, Paint.HeightMemory, Paint.Rotate, Paint.Color, Paint.WidthByte, Paint.HeightByte, Paint.Mirror, Paint.Width, Paint.Height);
#endif
}

/******************************************************************************
function: Select Image
parameter:
    image : Pointer to the image cache
******************************************************************************/
void Paint_SelectImage(uint8_t *image)
{
  Paint.Image = image;
}

/******************************************************************************
function: Select Image Rotate
parameter:
    Rotate : 0,90,180,270
******************************************************************************/
void Paint_SetRotate(uint16_t Rotate)
{
  if(Rotate == ROTATE_0 || Rotate == ROTATE_90 || Rotate == ROTATE_180 || Rotate == ROTATE_270) {
#ifdef DEBUG_GUI
    Serial.printf("Set image Rotate %d\n", Rotate);
#endif
    Paint.Rotate = Rotate;
  } else {
#ifdef DEBUG_GUI
    Serial.printf("rotate = 0, 90, 180, 270 Only\n");
#endif
  }
}

//---------------------------------------------------------------------------------
// Routine to set LCD's scaling parameters at startup - Overrides default scale value 2
//---------------------------------------------------------------------------------

bool Paint_SetScale(uint8_t scale)
{

  Paint.Scale = scale;

  switch (Paint.Scale) {
    case 2: // for 8 pixels per 
      Paint.WidthByte = (Paint.WidthMemory % 8 == 0) ? (Paint.WidthMemory / 8) : (Paint.WidthMemory / 8 + 1);
      break;

    case 4:
      Paint.WidthByte = (Paint.WidthMemory % 4 == 0) ? (Paint.WidthMemory / 4) : (Paint.WidthMemory / 4 + 1);
      break;

    case 16:
      Paint.WidthByte = (Paint.WidthMemory % 2 == 0) ? (Paint.WidthMemory / 2) : (Paint.WidthMemory / 2 + 1);
      break;

    case 65: // 2 octets per pixel
      Paint.WidthByte = Paint.WidthMemory * 2;
      break;

    default:      
#ifdef DEBUG_GUI
      Serial.printf("Set Scale Input parameter error\n");
      Serial.printf("Scale Only support: 2 4 16 65\n");
#endif
      return true; // Flag failure
  }
#ifdef DEBUG_GUI
      Serial.printf("Paint.Scale is %i, Paint.WidthMemory is %i, Paint.WidthByte is %i\n",Paint.Scale, Paint.WidthMemory, Paint.WidthByte);
#endif

  return false;
}

/******************************************************************************
function:	Select Image mirror
parameter:
    mirror   :Not mirror,Horizontal mirror,Vertical mirror,Origin mirror
******************************************************************************/
void Paint_SetMirroring(uint8_t mirror)
{
  if (mirror == MIRROR_NONE || mirror == MIRROR_HORIZONTAL || mirror == MIRROR_VERTICAL || mirror == MIRROR_ORIGIN)
  {
#ifdef DEBUG_GUI
    Serial.printf("mirror image x:%s, y:%s\n",(mirror & 0x01)? "mirror":"none", ((mirror >> 1) & 0x01)? "mirror":"none");
#endif
    Paint.Mirror = mirror;
  } else {
#ifdef DEBUG_GUI
    Serial.printf("mirror should be MIRROR_NONE, MIRROR_HORIZONTAL, MIRROR_VERTICAL or MIRROR_ORIGIN\n");
#endif
  }    
}
    
/******************************************************************************
function: Draw Pixels
parameter:
    Xpoint : At point X
    Ypoint : At point Y
    Color  : Painted colors
******************************************************************************/
void Paint_SetPixel(uint16_t Xpoint, uint16_t Ypoint, uint16_t Color)
{
  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Exceeding display boundaries #1: Xpoint = %d, Paint.Width = %d, Ypoint = %d, Paint.Height = %d\n", Xpoint, Paint.Width, Ypoint, Paint.Height);
#endif
    return;
  }
  uint16_t X, Y = 0;
  uint32_t Addr = 0;
  uint8_t Rdata = 0;

  switch (Paint.Rotate) {
    case 0:
      X = Xpoint;
      Y = Ypoint;
      break;

    case 90:
      X = (Paint.WidthMemory - 1) - Ypoint;
      Y = Xpoint;
      break;

    case 180:
      X = (Paint.WidthMemory - 1) - Xpoint;
      Y = (Paint.HeightMemory - 1) - Ypoint;
      break;

    case 270:
      X = Ypoint;
      Y = (Paint.HeightMemory - 1) - Xpoint;
      break;

    default:
        return;
  }

#ifdef DEBUG_GUI
//  if (X > Paint.WidthMemory || Y > Paint.HeightMemory) {
//    Serial.printf("Exceeding display boundaries #2: Xpoint = %d, X = %d, Paint.WidthMemory = %d, Ypoint = %d, Y = %d, Paint.HeightMemory = %d\n", Xpoint, X, Paint.WidthMemory, Ypoint, Y, Paint.HeightMemory);
//  }
#endif
  switch (Paint.Mirror) {
    case MIRROR_NONE:
      break;
  
    case MIRROR_HORIZONTAL:
      X = Paint.WidthMemory - X - 1;
        break;
    
    case MIRROR_VERTICAL:
      Y = Paint.HeightMemory - Y - 1;
      break;

    case MIRROR_ORIGIN:
        X = Paint.WidthMemory - X - 1;
        Y = Paint.HeightMemory - Y - 1;
        break;

    default:
        return;
  }

  if (X > Paint.WidthMemory || Y > Paint.HeightMemory) {
#ifdef DEBUG_GUI
//    Serial.printf("Exceeding display boundaries #3: X = %d, Paint.WidthMemory = %d, Y = %d, Paint.HeightMemory = %d\n", X, Paint.WidthMemory, Y, Paint.HeightMemory);
#endif
    return;
  }
#ifdef DEBUG_GUI
//    Serial.printf("Doing the transfer of ROM image to PSRAM Image: \n");
#endif

  switch (Paint.Scale)
  {
    case 2:
      Addr = X / 8 + Y * Paint.WidthByte;
      Rdata = *(Paint.Image+Addr);
      if (Color & 0xff == ST7789_BLACK)
        *(Paint.Image+Addr) = Rdata & ~(0x80 >> (X % 8));
      else
        *(Paint.Image+Addr) = Rdata | (0x80 >> (X % 8));
    break;

    case 4:
      Addr = X / 4 + Y * Paint.WidthByte;
      Color = Color % 4; // Guaranteed color scale is 4  --- 0~3
      Rdata = *(Paint.Image+Addr);

      Rdata = Rdata & (~(0xC0 >> ((X % 4) * 2)));
      *(Paint.Image+Addr) = Rdata | ((Color << 6) >> ((X % 4) * 2));
    break;

    case 16:
      Addr = X / 2 + Y * Paint.WidthByte;
      Rdata = *(Paint.Image+Addr);
      Color = Color % 16;
      Rdata = Rdata & (~(0xf0 >> ((X % 2) * 4)));
      *(Paint.Image+Addr) = Rdata | ((Color << 4) >> ((X % 2) * 4));
    break;

    case 65:
      Addr = X * 2 + Y * Paint.WidthByte;
      *(Paint.Image+Addr) = 0xff & (Color>>8);
      *(Paint.Image+(++Addr)) = 0xff & Color;
    break;

    default:
#ifdef DEBUG_GUI
      Serial.println("Paint.Scale value is not 2,4,16 or 65 - Fail!");
#endif
    break;
  }
}

/******************************************************************************
function: Clear the color of the picture
parameter:
    Color : Painted colors
******************************************************************************/
bool Paint_Clear(uint16_t Color)
{
  uint32_t X = 0;

#ifdef DEBUG_GUI
  Serial.println("Entered Paint_Clear - ");
  Serial.printf("Paint.Image at      - 0x%x\n",Paint.Image);
  Serial.printf("Paint.Scale         - %i\n",Paint.Scale);
  Serial.printf("Paint.HeightByte    - %i\n",Paint.HeightByte);
  Serial.printf("Paint.WidthByte     - %i\n",Paint.WidthByte);
#endif

  switch (Paint.Scale)
    {
      case 2:
      case 4:
        for (X = 0; X < (Paint.HeightByte*Paint.WidthByte); X++ ) 
        {//8 pixel =  1 byte
          *(Paint.Image+X) = Color;
        }
      break;

      case 16:
        for (X = 0; X < (Paint.HeightByte*Paint.WidthByte); X++ ) 
        {//8 pixel =  1 byte
          Color = Color & 0x0f;
          *(Paint.Image+X) = (Color<<4) | Color;
        }
      break;

      case 65:
        for (X = 0; X < (Paint.HeightByte*Paint.WidthByte); X++ ) 
        {//8 pixel =  1 byte
          *(Paint.Image+X) = 0xff & (Color>>8);
          *(Paint.Image+(++X)) = 0xff & Color;
        }
      break;

      default:
#ifdef DEBUG_GUI
        Serial.println("Paint.Scale value is not 2,4,16 or 65 - Fail!");
#endif
        return true; // Scale value is not 2,4,16 or 65 - Fail!
      break;

    }
    watchDogRefresh();

#ifdef DEBUG_GUI
    Serial.printf("X is %i\n",X);
    Serial.printf("Paint.Image is 0x%x, Paint.Image + X is 0x%x, Difference is %d\n",Paint.Image,(Paint.Image+X),(Paint.Image+X) - Paint.Image);
#endif

  return false;
}

/******************************************************************************
function: Clear the color of a window
parameter:
    Xstart : x starting point
    Ystart : Y starting point
    Xend   : x end point
    Yend   : y end point
    Color  : Painted colors
******************************************************************************/
void Paint_ClearWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color)
{
  uint16_t X, Y;
  for (Y = Ystart; Y < Yend; Y++) {
    for (X = Xstart; X < Xend; X++) {//8 pixel =  1 byte
      Paint_SetPixel(X, Y, Color);
    }
  }
}

/******************************************************************************
function: Draw Point(Xpoint, Ypoint) Fill the color
parameter:
    Xpoint		: The Xpoint coordinate of the point
    Ypoint		: The Ypoint coordinate of the point
    Color		: Painted color
    Dot_Pixel	: point size
    Dot_Style	: point Style
******************************************************************************/
void Paint_DrawPoint(uint16_t Xpoint, uint16_t Ypoint, uint16_t Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_Style)
{
  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
#ifdef DEBUG_GUI
//    Serial.printf("Paint_DrawPoint Input exceeds the normal display range\n");
//    Serial.printf("Xpoint = %d , Paint.Width = %d  \n ",Xpoint,Paint.Width);
//    Serial.printf("Ypoint = %d , Paint.Height = %d \n ",Ypoint,Paint.Height);
#endif
    return;
  }

  int16_t XDir_Num , YDir_Num;
  if (Dot_Style == DOT_FILL_AROUND) {
    for (XDir_Num = 0; XDir_Num < 2 * Dot_Pixel - 1; XDir_Num++) {
      for (YDir_Num = 0; YDir_Num < 2 * Dot_Pixel - 1; YDir_Num++) {
        if(Xpoint + XDir_Num - Dot_Pixel < 0 || Ypoint + YDir_Num - Dot_Pixel < 0)
          break;
#ifdef DEBUG_GUI
//        Serial.printf("x = %d, y = %d\n", Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel);
#endif
        Paint_SetPixel(Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel, Color);
      }
    }
  } else {
    for (XDir_Num = 0; XDir_Num <  Dot_Pixel; XDir_Num++) {
      for (YDir_Num = 0; YDir_Num <  Dot_Pixel; YDir_Num++) {
        Paint_SetPixel(Xpoint + XDir_Num - 1, Ypoint + YDir_Num - 1, Color);
      }
    }
  }
}

/******************************************************************************
function: Draw a line of arbitrary slope
parameter:
    Xstart ：Starting Xpoint point coordinates
    Ystart ：Starting Xpoint point coordinates
    Xend   ：End point Xpoint coordinate
    Yend   ：End point Ypoint coordinate
    Color  ：The color of the line segment
    Line_width : Line width
    Line_Style: Solid and dotted lines
******************************************************************************/
void Paint_DrawLine(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style)
{
  if (Xstart > Paint.Width || Ystart > Paint.Height || Xend > Paint.Width || Yend > Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Paint_DrawLine Input exceeds the normal display range\n");
#endif
    return;
  }

  uint16_t Xpoint = Xstart;
  uint16_t Ypoint = Ystart;
  int dx = (int)Xend - (int)Xstart >= 0 ? Xend - Xstart : Xstart - Xend;
  int dy = (int)Yend - (int)Ystart <= 0 ? Yend - Ystart : Ystart - Yend;

// Increment direction, 1 is positive, -1 is counter;
  int XAddway = Xstart < Xend ? 1 : -1;
  int YAddway = Ystart < Yend ? 1 : -1;

//Cumulative error
  int Esp = dx + dy;
  char Dotted_Len = 0;

  for (;;) {
    Dotted_Len++;
//Painted dotted line, 2 point is really virtual
    if (Line_Style == LINE_STYLE_DOTTED && Dotted_Len % 3 == 0) {
#ifdef DEBUG_GUI
      Serial.printf("LINE_DOTTED\n");
#endif
			if(Color)
				Paint_DrawPoint(Xpoint, Ypoint, ST7789_BLACK, Line_width, DOT_STYLE_DFT);
      else
				Paint_DrawPoint(Xpoint, Ypoint, ST7789_WHITE, Line_width, DOT_STYLE_DFT);
        Dotted_Len = 0;
    } else {
        Paint_DrawPoint(Xpoint, Ypoint, Color, Line_width, DOT_STYLE_DFT);
    }
    if (2 * Esp >= dy) {
      if (Xpoint == Xend)
        break;
      Esp += dy;
      Xpoint += XAddway;
    }
    if (2 * Esp <= dx) {
      if (Ypoint == Yend)
        break;
      Esp += dx;
      Ypoint += YAddway;
    }
  }
}

/******************************************************************************
function: Draw a rectangle
parameter:
    Xstart ：Rectangular  Starting Xpoint point coordinates
    Ystart ：Rectangular  Starting Xpoint point coordinates
    Xend   ：Rectangular  End point Xpoint coordinate
    Yend   ：Rectangular  End point Ypoint coordinate
    Color  ：The color of the Rectangular segment
    Line_width: Line width
    Draw_Fill : Whether to fill the inside of the rectangle
******************************************************************************/
void Paint_DrawRectangle(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
{
  if (Xstart > Paint.Width || Ystart > Paint.Height || Xend > Paint.Width || Yend > Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Input exceeds the normal display range\n");
#endif
    return;
  }

  if (Draw_Fill) {
    uint16_t Ypoint;
    for(Ypoint = Ystart; Ypoint < Yend; Ypoint++) {
      Paint_DrawLine(Xstart, Ypoint, Xend, Ypoint, Color , Line_width, LINE_STYLE_SOLID);
    }
  } else {
    Paint_DrawLine(Xstart, Ystart, Xend, Ystart, Color, Line_width, LINE_STYLE_SOLID);
    Paint_DrawLine(Xstart, Ystart, Xstart, Yend, Color, Line_width, LINE_STYLE_SOLID);
    Paint_DrawLine(Xend, Yend, Xend, Ystart, Color, Line_width, LINE_STYLE_SOLID);
    Paint_DrawLine(Xend, Yend, Xstart, Yend, Color, Line_width, LINE_STYLE_SOLID);
  }
}

/******************************************************************************
function: Use the 8-point method to draw a circle of the
            specified size at the specified position->
parameter:
    X_Center  ：Center X coordinate
    Y_Center  ：Center Y coordinate
    Radius    ：circle Radius
    Color     ：The color of the ：circle segment
    Line_width: Line width
    Draw_Fill : Whether to fill the inside of the Circle
******************************************************************************/
void Paint_DrawCircle(uint16_t X_Center, uint16_t Y_Center, uint16_t Radius, uint16_t Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
{
  if (X_Center > Paint.Width || Y_Center >= Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Paint_DrawCircle Input exceeds the normal display range\n");
#endif
    return;
  }

//Draw a circle from(0, R) as a starting point
  int16_t XCurrent, YCurrent;
  XCurrent = 0;
  YCurrent = Radius;

//Cumulative error,judge the next point of the logo
  int16_t Esp = 3 - (Radius << 1 );

  int16_t sCountY;
  if (Draw_Fill == DRAW_FILL_FULL) {
    while (XCurrent <= YCurrent ) { //Realistic circles
      for (sCountY = XCurrent; sCountY <= YCurrent; sCountY ++ ) {
        Paint_DrawPoint(X_Center + XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//1
        Paint_DrawPoint(X_Center - XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//2
        Paint_DrawPoint(X_Center - sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//3
        Paint_DrawPoint(X_Center - sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//4
        Paint_DrawPoint(X_Center - XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//5
        Paint_DrawPoint(X_Center + XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//6
        Paint_DrawPoint(X_Center + sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//7
        Paint_DrawPoint(X_Center + sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);
      }
      if (Esp < 0 )
        Esp += 4 * XCurrent + 6;
      else {
        Esp += 10 + 4 * (XCurrent - YCurrent );
        YCurrent --;
      }
      XCurrent ++;
    }
  } else { //Draw a hollow circle
    while (XCurrent <= YCurrent ) {
      Paint_DrawPoint(X_Center + XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//1
      Paint_DrawPoint(X_Center - XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//2
      Paint_DrawPoint(X_Center - YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//3
      Paint_DrawPoint(X_Center - YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//4
      Paint_DrawPoint(X_Center - XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//5
      Paint_DrawPoint(X_Center + XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//6
      Paint_DrawPoint(X_Center + YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//7
      Paint_DrawPoint(X_Center + YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//0

      if (Esp < 0 )
        Esp += 4 * XCurrent + 6;
      else {
        Esp += 10 + 4 * (XCurrent - YCurrent );
        YCurrent --;
      }
      XCurrent ++;
    }
  }
}

/******************************************************************************
function: Show English characters
parameter:
    Xpoint           ：X coordinate
    Ypoint           ：Y coordinate
    Acsii_Char       ：To display the English characters
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void Paint_DrawChar(uint16_t Xpoint, uint16_t Ypoint, const char Acsii_Char, sFONT* Font, uint16_t Color_Foreground, uint16_t Color_Background)
{
  uint16_t Page, Column;

  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Paint_DrawChar Input exceeds the normal display range\n");
#endif
    return;
  }

  uint32_t Char_Offset = (Acsii_Char - ' ') * Font->Height * (Font->Width / 8 + (Font->Width % 8 ? 1 : 0));
  const unsigned char *ptr = &Font->table[Char_Offset];

  for (Page = 0; Page < Font->Height; Page ++ ) {
    for (Column = 0; Column < Font->Width; Column ++ ) {

//To determine whether the font background color and screen background color is consistent
      if (FONT_BACKGROUND == Color_Background) { //this process is to speed up the scan
        if (*ptr & (0x80 >> (Column % 8)))
          Paint_SetPixel(Xpoint + Column, Ypoint + Page, Color_Foreground);
          // Paint_DrawPoint(Xpoint + Column, Ypoint + Page, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
      } else {
        if (*ptr & (0x80 >> (Column % 8))) {
          Paint_SetPixel(Xpoint + Column, Ypoint + Page, Color_Foreground);
          // Paint_DrawPoint(Xpoint + Column, Ypoint + Page, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
        } else {
          Paint_SetPixel(Xpoint + Column, Ypoint + Page, Color_Background);
          // Paint_DrawPoint(Xpoint + Column, Ypoint + Page, Color_Background, DOT_PIXEL_DFT, DOT_STYLE_DFT);
        }
      }
//One pixel is 8 bits
      if (Column % 8 == 7)
        ptr++;
    }// Write a line
    if (Font->Width % 8 != 0)
      ptr++;
  }// Write all
}

/******************************************************************************
function:	Display the Latin Character string
parameter:
    Xstart           ：X coordinate
    Ystart           ：Y coordinate
    pString          ：The first address of the English string to be displayed
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void Paint_DrawString_EN(uint16_t Xstart, uint16_t Ystart, const char * pString, sFONT* Font, uint16_t Color_Foreground, uint16_t Color_Background)
{
  uint16_t Xpoint = Xstart;
  uint16_t Ypoint = Ystart;

  if (Xstart > Paint.Width || Ystart > Paint.Height) {
#ifdef DEBUG_GUI
    Serial.printf("Paint_DrawString_EN Input exceeds the normal display range\n");
#endif
    return;
  }

  while (* pString != '\0') {
//if X direction filled , reposition to(Xstart,Ypoint),Ypoint is Y direction plus the Height of the character
    if ((Xpoint + Font->Width ) > Paint.Width ) {
      Xpoint = Xstart;
      Ypoint += Font->Height;
    }

// If the Y direction is full, reposition to(Xstart, Ystart)
    if ((Ypoint  + Font->Height ) > Paint.Height ) {
      Xpoint = Xstart;
      Ypoint = Ystart;
    }
    Paint_DrawChar(Xpoint, Ypoint, * pString, Font, Color_Background, Color_Foreground);

//The next character of the address
    pString ++;

//The next word of the abscissa increases the font of the broadband
    Xpoint += Font->Width;
  }
}

/******************************************************************************
function: Display the Ideogram (Chinese) string
parameter:
    Xstart  ：X coordinate
    Ystart  ：Y coordinate
    pString ：The first address of the Chinese string and English
              string to be displayed
    Font    ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void Paint_DrawString_CN(uint16_t Xstart, uint16_t Ystart, const char * pString, cFONT* font, uint16_t Color_Foreground, uint16_t Color_Background)
{
  const char* p_text = pString;
  int x = Xstart, y = Ystart;
  int i, j,Num;

// Send the string character by character on LCD
  while (*p_text != 0) {
    if(*p_text <= 0x7F) {  //ASCII < 126
      for(Num = 0; Num < font->size; Num++) {
        if(*p_text== font->table[Num].index[0]) {
          const char* ptr = &font->table[Num].matrix[0];

        for (j = 0; j < font->Height; j++) {
          for (i = 0; i < font->Width; i++) {
            if (FONT_BACKGROUND == Color_Background) { //this process is to speed up the scan
              if (*ptr & (0x80 >> (i % 8))) {
                Paint_SetPixel(x + i, y + j, Color_Foreground);
                // Paint_DrawPoint(x + i, y + j, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
              }
            } else {
              if (*ptr & (0x80 >> (i % 8))) {
                Paint_SetPixel(x + i, y + j, Color_Foreground);
                // Paint_DrawPoint(x + i, y + j, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
              } else {
                Paint_SetPixel(x + i, y + j, Color_Background);
                // Paint_DrawPoint(x + i, y + j, Color_Background, DOT_PIXEL_DFT, DOT_STYLE_DFT);
              }
            }
            if (i % 8 == 7) ptr++;
          }
          if (font->Width % 8 != 0) ptr++;
        }
        break;
      }
    }
// Point on the next character
    p_text += 1;
// Decrement the column position by 16
    x += font->ASCII_Width;
    } else {        //Chinese
      for(Num = 0; Num < font->size; Num++) {
        if((*p_text== font->table[Num].index[0]) && (*(p_text+1) == font->table[Num].index[1])) {
          const char* ptr = &font->table[Num].matrix[0];

          for (j = 0; j < font->Height; j++) {
            for (i = 0; i < font->Width; i++) {
              if (FONT_BACKGROUND == Color_Background) { //this process is to speed up the scan
                if (*ptr & (0x80 >> (i % 8))) {
                  Paint_SetPixel(x + i, y + j, Color_Foreground);
                  // Paint_DrawPoint(x + i, y + j, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
                }
              } else {
                if (*ptr & (0x80 >> (i % 8))) {
                  Paint_SetPixel(x + i, y + j, Color_Foreground);
                  // Paint_DrawPoint(x + i, y + j, Color_Foreground, DOT_PIXEL_DFT, DOT_STYLE_DFT);
                } else {
                  Paint_SetPixel(x + i, y + j, Color_Background);
                  // Paint_DrawPoint(x + i, y + j, Color_Background, DOT_PIXEL_DFT, DOT_STYLE_DFT);
                }
              }
              if (i % 8 == 7) ptr++;
            }
            if (font->Width % 8 != 0) ptr++;
          }
          break;
        }
      }
// Point on the next character
      p_text += 2;
// Decrement the column position by 16
      x += font->Width;
    }
  }
}

/******************************************************************************
function:	Display nummber
parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    Nummber          : The number displayed
    Font             ：A structure pointer that displays a character size
    Digit						 : Fractional width
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
#define ARRAY_LEN 32
void Paint_DrawNum(uint16_t Xpoint, uint16_t Ypoint, double Nummber, sFONT *Font, uint16_t Digit, uint16_t Color_Foreground, uint16_t Color_Background)
{
  char Str[ARRAY_LEN];
  sprintf(Str, "%.*lf", Digit + 1, Nummber);
  *(Str + strlen(Str) - 1) = '\0';
  if (Digit == 0)
    *(Str + strlen(Str) - 1) = '\0';
// show
  Paint_DrawString_EN(Xpoint, Ypoint, (const char *)Str, Font, Color_Foreground, Color_Background);

}

/******************************************************************************
function:	Display time
parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    pTime            : Time-related structures
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void Paint_DrawTime(uint16_t Xstart, uint16_t Ystart, PAINT_TIME *pTime, sFONT* Font, uint16_t Color_Foreground, uint16_t Color_Background)
{
  uint8_t value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  uint16_t Dx = Font->Width;

//Write data into the cache
  Paint_DrawChar(Xstart                           , Ystart, value[pTime->Hour / 10], Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx                      , Ystart, value[pTime->Hour % 10], Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx  + Dx / 4 + Dx / 2   , Ystart, ':'                    , Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 2 + Dx / 2         , Ystart, value[pTime->Min / 10] , Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 3 + Dx / 2         , Ystart, value[pTime->Min % 10] , Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 4 + Dx / 2 - Dx / 4, Ystart, ':'                    , Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 5                  , Ystart, value[pTime->Sec / 10] , Font, Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 6                  , Ystart, value[pTime->Sec % 10] , Font, Color_Background, Color_Foreground);
    
}

//******************************************************************************
// function: Paint_DrawImage
//    parameter:
//    Xpoint : At point X
//    Ypoint : At point Y
//    Color  : Painted colors
//    *sourceImage  : Pointer to start of image to be drawn - contents are unsigned char vis 8 bit
//    xStart  : Value of start point of the X axis of display, usually 0
//    yStart  : Value of start point of the Y axis of display, usually 0
//    W_Image : Maximum number of Pixel Points on the Width of the display
//    H_Image : Maximum number of Pixel Points on the Height of the display
//*******************************************************************************

void Paint_DrawImage(const uint8_t *sourceImage, uint16_t xStart, uint16_t yStart, uint16_t W_Image, uint16_t H_Image) 
{
#ifdef DEBUG_GUI
    Serial.printf("Entered Paint_DrawImage\n");
#endif
  int i,j; 
	for(j = 0; j < H_Image; j++) {
		for(i = 0; i < W_Image; i++) {
			if(xStart+i < Paint.WidthMemory  &&  yStart+j < Paint.HeightMemory) //Exceeded part does not display
				Paint_SetPixel(xStart + i, yStart + j, (*(sourceImage + j*W_Image*2 + i*2+1))<<8 | (*(sourceImage + j*W_Image*2 + i*2)));
				//Using arrays is a property of sequential storage, accessing the original array by algorithm
				//j*W_Image*2 			   Y offset
				//i*2              	   X offset
		}
	} 
#ifdef DEBUG_GUI
    Serial.printf("Finished Paint_DrawImage\n");
#endif
}

//******************************************************************************
// function: Paint_DrawImage_16bit
//    parameter:
//    Xpoint : At point X
//    Ypoint : At point Y
//    Color  : Painted colors
//    *sourceImage  : Pointer to start of image to be drawn
//    xStart  : Value of start point of the X axis of display, usually 0
//    yStart  : Value of start point of the Y axis of display, usually 0
//    W_Image : Maximum number of Pixel Points on the Width of the display
//    H_Image : Maximum number of Pixel Points on the Height of the display
//*******************************************************************************

void Paint_DrawImage_16bit(const uint16_t *sourceImage, uint16_t xStart, uint16_t yStart, uint16_t W_Image, uint16_t H_Image) 
{
  int i,j; 
	for(j = 0; j < H_Image; j++){
		for(i = 0; i < W_Image; i++){
			if(((xStart+i) < Paint.WidthMemory)  &&  ((yStart+j) < Paint.HeightMemory))  //Exceeded part does not display
				Paint_SetPixel((xStart+W_Image) - i, yStart + j, (*(sourceImage + (i*H_Image) + j)));
		}
	} 
}

// Paints image turned if LCD is rotated 90 degrees (e.g.Landscape) 8 bit data only
void Paint_DrawImage1(const unsigned char *sourceImage, uint16_t xStart, uint16_t yStart, uint16_t W_Image, uint16_t H_Image)
{
  int i, j;
  for (j = 0; j < H_Image; j++) {
    for (i = 0; i < W_Image; i++) {
      if (xStart + i < Paint.HeightMemory && yStart + j < Paint.WidthMemory) // Exceeded part does not display
        Paint_SetPixel(xStart + i, yStart + j, (*(sourceImage + j * W_Image * 2 + i * 2 + 1)) << 8 | (*(sourceImage + j * W_Image * 2 + i * 2)));
        // Using arrays is a property of sequential storage, accessing the original array by algorithm
        // j*W_Image*2 			   Y offset
        // i*2              	   X offset
    }
  }
}

/******************************************************************************
function:	Display monochrome bitmap
parameter:
    image_buffer ：A picture data converted to a bitmap
info:
    Use a computer to convert the image into a corresponding array,
    and then embed the array directly into Imagedata.cpp as a .c file.
******************************************************************************/
void Paint_DrawBitMap(const unsigned char *image_buffer)
{
  uint16_t x, y;
  uint32_t Addr = 0;

  for (y = 0; y < Paint.HeightByte; y++) {
    for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
      Addr = x + y * Paint.WidthByte;
      Paint.Image[Addr] = (unsigned char)image_buffer[Addr];
    }
  }
}

void Paint_DrawBitMap_Block(const unsigned char* image_buffer, uint8_t Region)
{
  uint16_t x, y;
  uint32_t Addr = 0;
	for (y = 0; y < Paint.HeightByte; y++) {
		for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
			Addr = x + y * Paint.WidthByte ;
			Paint.Image[Addr] = \
			(unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte*(Region - 1)];
		}
	}
}

void Paint_BmpWindows(unsigned char x,unsigned char y,const unsigned char *pBmp, unsigned char chWidth,unsigned char chHeight)
{
	uint16_t i, j, byteWidth = (chWidth + 7)/8;
  for(j = 0; j < chHeight; j ++) {
    for(i = 0; i < chWidth; i ++ ) {
      if(*(pBmp + j * byteWidth + i / 8) & (128 >> (i & 7)))
        Paint_SetPixel(x+i, y+j, 0xffff);
    }
  }
}
         