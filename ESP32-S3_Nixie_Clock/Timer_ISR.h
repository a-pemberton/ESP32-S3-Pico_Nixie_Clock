//---------------------------------------------------------------------------------------------
//
// Module:              Timer Interrupt Service Routine header file
// Filename:            Timer_ISR.h
// Version:             1.0
// Date:                25/NOV/2023
// Author:              A.Pemberton
// Function:            Arduino style Timer functions for ESP32-S2
// Libraries included:  
//
// Change History:      None
//
//---------------------------------------------------------------------------------------------
/*
    Copyright (C) 2023 A.Pemberton

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

#ifndef __Timer_ISR_H__
#define __Timer_ISR_H__

// These define's must be placed at the beginning before #include "TimerInterrupt_Generic.h"
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.

#define timer1frequency           1000000
#define timer2frequency           1000000
#define watchDogfrequency         1000000

#define prescaler                 80
#define countUp                   true
#define countDown                 false

#define auto_reload               true
#define one_shot                  false

// Predefined times in microseconds
#define One_Sec                   1000000UL
#define Two_Sec                   2000000UL
#define Five_Sec                  5000000UL
#define Ten_Sec                   10000000UL

#define One_Hundred_mSec          100000UL
#define Two_Hundred_mSec          200000UL
#define Five_Hundred_mSec         500000UL

#define Ten_mSec                  10000UL
#define Twenty_mSec               20000UL
#define Fifty_mSec                50000UL

#define One__mSec                 1000UL
#define Two__mSec                 2000UL
#define Five__mSec                5000UL

#define One_Hundred_uSec          100UL
#define Two_Hundred_uSec          200UL
#define Five_Hundred_uSec         500UL

#define one_shot_compensation     14  // A fiddle factor to correct for time taken by code execution. Adjust to get accurate one shot time.

#define WATCHDOG_TIMEOUT_S        3  // Number of seconds until the watchdog times out and the system has a forced restart
#define watchDogTimeout (WATCHDOG_TIMEOUT_S *1000000)  // Above converted to microseconds

#define blink_frequency One_Sec
#define blink_duty_cycle blink_frequency/10  // 100ms on 900mS off or 10%
#define blink_on_time blink_duty_cycle
#define blink_off_time blink_frequency - blink_duty_cycle

#endif
