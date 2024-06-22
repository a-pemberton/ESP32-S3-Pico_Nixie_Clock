//---------------------------------------------------------------------------------------------
//
// Module:              GUI Image Paint header file
// Filename:            GUI_Paiont.h
// Version:             1.0
// Date:                ????
// Author:              Waveshare modified by A.Pemberton
// Function:            Arduino style header file for ESP32-S2
// Libraries included:  
//
// Change History:      None
//
//---------------------------------------------------------------------------------------------
/*
    Copyright (C) Waveshare / A.Pemberton 2023

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GUI_PAINT_H_
#define _GUI_PAINT_H_

// Custom structure of a time attribute
typedef struct {
  uint16_t	Year;  //0000
  uint8_t Month; //1 - 12
  uint8_t Day;   //1 - 30
  uint8_t Hour;  //0 - 23
  uint8_t Min;   //0 - 59
  uint8_t Sec;   //0 - 59
} PAINT_TIME;
extern PAINT_TIME sPaint_time;


// Display Flip
typedef enum {
  MIRROR_NONE  = 0x00,
  MIRROR_HORIZONTAL = 0x01,
  MIRROR_VERTICAL = 0x02,
  MIRROR_ORIGIN = 0x03,
} MIRROR_IMAGE;

// The size of the point
typedef enum {
  DOT_PIXEL_1X1  = 1,	// 1 x 1
  DOT_PIXEL_2X2  , 		// 2 X 2
  DOT_PIXEL_3X3  ,		// 3 X 3
  DOT_PIXEL_4X4  ,		// 4 X 4
  DOT_PIXEL_5X5  , 		// 5 X 5
  DOT_PIXEL_6X6  , 		// 6 X 6
  DOT_PIXEL_7X7  , 		// 7 X 7
  DOT_PIXEL_8X8  , 		// 8 X 8
} DOT_PIXEL;

// Point size fill style
typedef enum {
  DOT_FILL_AROUND  = 1,		// dot pixel 1 x 1
  DOT_FILL_RIGHTUP  , 		// dot pixel 2 X 2
} DOT_STYLE;

// Line style, solid or dashed
typedef enum {
  LINE_STYLE_SOLID = 0,
  LINE_STYLE_DOTTED,
} LINE_STYLE;

// Whether the graphic is filled
typedef enum {
  DRAW_FILL_EMPTY = 0,
  DRAW_FILL_FULL,
} DRAW_FILL;


/**
 * Display rotate
**/
#define ROTATE_0            0
#define ROTATE_90           90
#define ROTATE_180          180
#define ROTATE_270          270

#define IMAGE_BACKGROUND    ST7789_WHITE
#define FONT_FOREGROUND     ST7789_BLACK
#define FONT_BACKGROUND     ST7789_WHITE

#define DOT_STYLE_DFT  DOT_FILL_AROUND  //Default dot pilex
#define MIRROR_IMAGE_DFT MIRROR_NONE
#define DOT_PIXEL_DFT  DOT_PIXEL_1X1  //Default dot pilex
#define DOT_STYLE_DFT  DOT_FILL_AROUND  //Default dot pilex


#endif
