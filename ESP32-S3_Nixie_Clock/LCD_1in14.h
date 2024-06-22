/*****************************************************************************
* | File        :   LCD_1IN14.h
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
# OUT OF OR IN CONNECTION WITH THE SOFTWARLCD_1IN14E OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#ifndef __LCD_1in14_H__
#define __LCD_1in14_H__

#define LCD_1IN14_HEIGHT 240
#define LCD_1IN14_WIDTH 135
#define Image_Size (LCD_1IN14.WIDTH * LCD_1IN14.HEIGHT) // In this case, 16 bit pixel = 32400 or 64800 octets

#define HORIZONTAL 0
#define VERTICAL   1

#define LCD_1IN14_SetBacklight(Value) ; 

#define SetAlarmTime_Test 0)
#define SetTime 1
#define Normal_runmod 2

// Values to set LCD DC Pin - more descriptive than original
#define commandMode 0
#define dataMode 1

typedef struct{
    uint16_t WIDTH;
    uint16_t HEIGHT;
    uint8_t SCAN_DIR;
    uint8_t LCD_NUM;
} LCD_1IN14_ATTRIBUTES;

//#endif

//#define SPI_HAS_TRANSACTION // already defined in SPI.h

#define ST7789_240x240_XSTART_R0 0
#define ST7789_240x240_YSTART_R0 80
#define ST7789_240x240_XSTART_R1 80
#define ST7789_240x240_YSTART_R1 0
#define ST7789_240x240_XSTART_R2 0
#define ST7789_240x240_YSTART_R2 0
#define ST7789_240x240_XSTART_R3 0
#define ST7789_240x240_YSTART_R3 0

#define ST7789_135x240_XSTART_R0 53
#define ST7789_135x240_YSTART_R0 40
#define ST7789_135x240_XSTART_R1 40
#define ST7789_135x240_YSTART_R1 52
#define ST7789_135x240_XSTART_R2 52
#define ST7789_135x240_YSTART_R2 40
#define ST7789_135x240_XSTART_R3 40
#define ST7789_135x240_YSTART_R3 53

#define ST_CMD_DELAY      0x80    // special signifier for command lists

// ST7789 Command definitions from Sitronix ST7789VW Datasheet
#define ST7789_NOP        0x00  // Do nothing - padding
#define ST7789_SWRESET    0x01  // SWRESET (01h): Software Reset
#define ST7789_RDDID      0x04  // RDDID (04h): Read Display ID
#define ST7789_RDDST      0x09  // RDDST (09h): Read Display Status
#define ST7789_RDDPM      0x0A  // RDDPM (0Ah): Read Display Power Mode
#define ST7789_RDDMADCTL  0x0B  // RDDMADCTL (0Bh): Read Display MADCTL
#define ST7789_RDDCOLMOD  0x0C  // RDDCOLMOD (0Ch): Read Display Pixel Format
#define ST7789_RDDIM      0x0D  // RDDIM (0Dh): Read Display Image Mode
#define ST7789_RDDSM      0x0E  // RDDSM (0Eh): Read Display Signal Mode
#define ST7789_RDDSDR     0x0F  // RDDSDR (0Fh): Read Display Self-Diagnostic Result

#define ST7789_SLPIN      0x10  // SLPIN (10h): Sleep in 
#define ST7789_SLPOUT     0x11  // SLPOUT (11h): Sleep Out
#define ST7789_PTLON      0x12  // PTLON (12h): Partial Display Mode On
#define ST7789_NORON      0x13  // NORON (13h): Normal Display Mode On

#define ST7789_INVOFF     0x20  // INVOFF (20h): Display Inversion Off
#define ST7789_INVON      0x21  // INVON (21h): Display Inversion On
#define ST7789_GAMSET     0x26  // GAMSET (26h): Gamma Set
#define ST7789_DISPOFF    0x28  // DISPOFF (28h): Display Off
#define ST7789_DISPON     0x29  // DISPON (29h): Display On
#define ST7789_CASET      0x2A  // CASET (2Ah): Column Address Set
#define ST7789_RASET      0x2B  // RASET (2Bh): Row Address Set
#define ST7789_RAMWR      0x2C  // RAMWR (2Ch): Memory Write
#define ST7789_RAMRD      0x2E  // RAMRD (2Eh): Memory Read

#define ST7789_PTLAR      0x30  // PTLAR (30h): Partial Area
#define ST7789_VSCRDEF    0x33  // VSCRDEF (33h): Vertical Scrolling Definition
#define ST7789_TEOFF      0x34  // TEOFF (34h): Tearing Effect Line OFF
#define ST7789_TEON       0x35  // TEON (35h): Tearing Effect Line On
#define ST7789_MADCTL     0x36  // MADCTL (36h): Memory Data Access Control
#define ST7789_VSCSAD     0x37  // VSCSAD (37h): Vertical Scroll Start Address of RAM
#define ST7789_IDMOFF     0x38  // IDMOFF (38h): Idle Mode Off
#define ST7789_IDMON      0x39  // IDMON (39h): Idle mode on
#define ST7789_COLMOD     0x3A  // COLMOD (3Ah): Interface Pixel Format
#define ST7789_WRMEMC     0x3C  // WRMEMC (3Ch): Write Memory Continue
#define ST7789_RDMEMC     0x3E  // RDMEMC (3Eh): Read Memory Continue

#define ST7789_STE        0x44  // STE (44h): Set Tear Scanline
#define ST7789_GSCAN      0x45  // GSCAN (45h): Get Scanline

#define ST7789_WRDISBV    0x51  // WRDISBV (51h): Write Display Brightness
#define ST7789_RDDISBV    0x52  // RDDISBV (52h): Read Display Brightness Value
#define ST7789_WRCTRLD    0x53  // WRCTRLD (53h): Write CTRL Display
#define ST7789_RDCTRLD    0x54  // RDCTRLD (54h): Read CTRL Value Display
#define ST7789_WRCACE     0x55  // WRCACE (55h): Write Content Adaptive Brightness Control and Color Enhancement
#define ST7789_RDCABC     0x56  // RDCABC (56h): Read Content Adaptive Brightness Control
#define ST7789_WRCABCMB   0x5E  // WRCABCMB (5Eh): Write CABC Minimum Brightness
#define ST7789_RDCABCMB   0x5F  // RDCABCMB (5Fh): Read CABC Minimum Brightness

#define ST7789_RDABCSDR   0x68  // RDABCSDR (68h): Read Automatic Brightness Control Self-Diagnostic Result

#define ST7789_RDID1      0xDA  // RDID1 (DAh): Read ID1
#define ST7789_RDID2      0xDB  // RDID2 (DBh): Read ID2
#define ST7789_RDID3      0xDC  // RDID3 (DCh): Read ID3
#define ST7789_RDID4      0xDD  // 

#define ST7789_MADCTL_MY  0x80
#define ST7789_MADCTL_MX  0x40
#define ST7789_MADCTL_MV  0x20
#define ST7789_MADCTL_ML  0x10
#define ST7789_MADCTL_RGB 0x00

#define ST7789_RAMCTRL    0xB0  // RAMCTRL (B0h): RAM Control
#define ST7789_RGBCTRL    0xB1  // RGBCTRL (B1h): RGB Interface Control
#define ST7789_PORCTRL    0xB2  // PORCTRL (0xB2) Porch Setting
#define ST7789_FRCTRL1    0xB3  // FRCTRL1 (B3h): Frame Rate Control 1 (In partial mode/ idle colors)
#define ST7789_PARCTRL    0xB5  // PARCTRL (B5h): Partial Control
#define ST7789_GCTRL      0xB7  // GCTRL (B7h): Gate Control
#define ST7789_GTADJ      0xB8  // GTADJ (B8h): Gate On Timing Adjustment
#define ST7789_DGMEN      0xBA  // DGMEN (BAh): Digital Gamma Enable
#define ST7789_VCOMS      0xBB  // VCOMS (BBh): VCOM Setting
#define ST7789_POWSAVE    0xBC  // POWSAVE(BCh): Power Saving Mode
#define ST7789_DLPOFFSAVE 0xBD  // DLPOFFSAVE (BDh): Display off power save

#define ST7789_LCMCTRL    0xC0  // LCMCTRL (C0h): LCM Control
#define ST7789_IDSET      0xC1  // IDSET (C1h): ID Code Setting
#define ST7789_VDVVRHEN   0xC2  // VDVVRHEN (C2h): VDV and VRH Command Enable
#define ST7789_VRHS       0xC3  // VRHS (C3h): VRH Set
#define ST7789_VDVS       0xC4  // VDVS (C4h): VDV Set
#define ST7789_VCMOFSET   0xC5  // VCMOFSET (C5h): VCOM Offset Set
#define ST7789_FRCTRL2    0xC6  // FRCTRL2 (C6h): Frame Rate Control in Normal Mode
#define ST7789_CABCCTRL   0xC7  // CABCCTRL (C7h): CABC Control
#define ST7789_REGSEL1    0xC8  // REGSEL1 (C8h): Register Value Selection 1
#define ST7789_REGSEL2    0xCA  // REGSEL2 (CAh): Register Value Selection 2
#define ST7789_PWMFRSEL   0xCC  // PWMFRSEL (CCh): PWM Frequency Selection

#define ST7789_PWCTRL1    0xD0  // PWCTRL1 (D0h): Power Control 1
#define ST7789_VAPVANEN   0xD2  // VAPVANEN (D2h): Enable VAP/VAN signal output
#define ST7789_CMD2EN     0xDF  // CMD2EN (DFh): Command 2 Enable

#define ST7789_PVGAMCTRL  0xE0  // PVGAMCTRL (E0h): Positive Voltage Gamma Control
#define ST7789_NVGAMCTRL  0xE1  // NVGAMCTRL (E1h): Negative Voltage Gamma Control
#define ST7789_DGMLUTR    0xE2  // DGMLUTR (E2h): Digital Gamma Look-up Table for Red
#define ST7789_DGMLUTB    0xE3  // DGMLUTB (E3h): Digital Gamma Look-up Table for Blue
#define ST7789_GATECTRL   0xE4  // GATECTRL (E4h): Gate Control
#define ST7789_SPI2EN     0xE7  // SPI2EN (E7h): SPI2 Enable
#define ST7789_PWCTRL2    0xE8  // PWCTRL2 (E8h): Power Control 2
#define ST7789_EQCTRL     0xE9  // EQCTRL (E9h): Equalize time control
#define ST7789_PROMCTRL   0xEC  // PROMCTRL (ECh): Program Mode Control

#define ST7789_PROMEN     0xFA  // PROMEN (FAh): Program Mode Enable
#define ST7789_NVMSET     0xFC  // NVMSET (FCh): NVM Setting
#define ST7789_PROMACT    0xFE  // PROMACT (FEh): Program action


// Colour definitions                     Red Green Blur
#define ST7789_BLACK       0x0000      //   0,   0,   0   0000  0000  0000  0000
#define ST7789_NAVY        0x000F      //   0,   0, 128   0000  0000  0000  1111
#define ST7789_DARKGREEN   0x03E0      //   0, 128,   0   0000  0011  1110  0000
#define ST7789_DARKCYAN    0x03EF      //   0, 128, 128   0000  0011  1110  1111
#define ST7789_MAROON      0x7800      // 128,   0,   0   0111  1000  0000  0000
#define ST7789_PURPLE      0x780F      // 128,   0, 128   0111  1000  0000  1111
#define ST7789_OLIVE       0x7BE0      // 128, 128,   0   0111  1011  1110  0000
#define ST7789_LIGHTGREY   0xC618      // 192, 192, 192   1100  0110  0001  1000
#define ST7789_DARKGREY    0x7BEF      // 128, 128, 128   0111  1011  1110  1111
#define ST7789_BLUE        0x001F      //   0,   0, 255   0000  0000  0001  1111
#define ST7789_GREEN       0x07E0      //   0, 255,   0   0000  0111  1110  0000
#define ST7789_CYAN        0x07FF      //   0, 255, 255   0000  0111  1111  1111
#define ST7789_RED         0xF800      // 255,   0,   0   1111  1000  0000  0000
#define ST7789_MAGENTA     0xF81F      // 255,   0, 255   1111  1000  0001  1111
#define ST7789_YELLOW      0xFFE0      // 255, 255,   0   1111  1111  1110  0000
#define ST7789_WHITE       0xFFFF      // 255, 255, 255   1111  1111  1111  1111
#define ST7789_ORANGE      0xFD20      // 255, 165,   0   1111  1101  0010  0000
#define ST7789_GREENYELLOW 0xAFE5      // 173, 255,  47   1010  1111  1110  0101
#define ST7789_PINK        0xF81F      //                 1111  1000  0001  1111 

#define ST7789_BROWN       0XBC40
#define ST7789_BRRED       0XFC07
#define ST7789_GRAY        0X8430

#endif
