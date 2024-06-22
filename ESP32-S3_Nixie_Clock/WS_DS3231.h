//---------------------------------------------------------------------------------------------
//
// Module:              Waveshare Nixie Clock RTC module header file
// Filename:            WS_DS3231.h
// Version:             1.0
// Date:                09/SEP/2023
// Author:              Arduino library example modified by A.Pemberton
// Function:            DS3231 RTC header file
//                      Uses DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.
//
//                      Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
//                      Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic and Licensed under MIT license
//                      
// Change History:      None
//
//---------------------------------------------------------------------------------------------


#ifndef _WS_DS3231_H_
#define _WS_DS3231_H_

// i2c slave address of the DS3231 chip
#define DS3231_I2C_ADDR             0x68

#define DS3231_YEAR_OFFSET          2000

// Unix time starts on Jan 1 1970. In seconds, that's 2208988800 ticks from 1/1/1900
#define seventyYears 2208988800UL

//#define SECONDS_FROM_1970_TO_2000   946684800UL

// timekeeping registers
#define DS3231_TIME_CAL_ADDR        (0x00)
#define DS3231_ALARM1_ADDR          (0x07)
#define DS3231_ALARM2_ADDR          (0x0B)
#define DS3231_CONTROL_ADDR         (0x0E)
#define DS3231_STATUS_ADDR          (0x0F)
#define DS3231_AGING_OFFSET_ADDR    (0x10)
#define DS3231_TEMPERATURE_ADDR     (0x11)

// control register bits
#define DS3231_CONTROL_A1IE         (0x01)	/* Alarm 2 Interrupt Enable */
#define DS3231_CONTROL_A2IE         (0x02)	/* Alarm 2 Interrupt Enable */
#define DS3231_CONTROL_INTCN        (0x04)	/* Interrupt Control */
#define DS3231_CONTROL_RS1	        (0x08)	/* square-wave rate select 2 */
#define DS3231_CONTROL_RS2    	    (0x10)	/* square-wave rate select 2 */
#define DS3231_CONTROL_CONV    	    (0x20)	/* Convert Temperature */
#define DS3231_CONTROL_BBSQW        (0x40)	/* Battery-Backed Square-Wave Enable */
#define DS3231_CONTROL_EOSC	        (0x80)	/* not Enable Oscillator, 0 equal on */

// status register bits
#define DS3231_STATUS_A1F           (0x01)		/* Alarm 1 Flag */
#define DS3231_STATUS_A2F           (0x02)		/* Alarm 2 Flag */
#define DS3231_STATUS_BUSY          (0x04)		/* device is busy executing TCXO */
#define DS3231_STATUS_EN32KHZ       (0x08)		/* Enable 32KHz Output  */
#define DS3231_STATUS_OSF           (0x80)		/* Oscillator Stop Flag */

#define primary_Alarm               1
#define secondary_Alarm             2


#endif
