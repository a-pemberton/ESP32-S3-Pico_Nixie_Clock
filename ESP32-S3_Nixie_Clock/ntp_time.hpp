//---------------------------------------------------------------------------------------------
//
// Module:              ntp and time header file
// Filename:            ntp_time.h
// Version:             1.0
// Date:                16/APR/2024
// Author:              A.Pemberton
// Function:            Arduino style ntp to time function definitions
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

#ifndef __ntp_time_H__
#define __ntp_time_H__

//---------------------------------------------------------------------------------
// Module Definitions - NTP
//---------------------------------------------------------------------------------

#define NTPpoolName_1 "time.nist.gov"   // Default NTP time server - others are available!
#define NTPpoolName_2 "0.pool.ntp.org" 
#define NTPpoolName_3 "1.pool.ntp.org"

#define local_NTP_Port 2390
#define NTP_port 123
// Debug Level from 0 to 4
#define _NTP_LOGLEVEL_ 0
#define SHOW_TIME_PERIOD 5000
#define NTP_TIMEOUT       1500
#define NTP_PACKET_SIZE   48       // NTP timestamp is in the first 48 octets of the message

#define NTP_Update_Interval (60*60*1000)  // Update NTP interval once per hour in mSecs

#define STATUS_CHECK_INTERVAL 10000L

// ToDo: Make timezone configurable
#define timezone_Test_Data "GMT0BST,M3.5.0/1,M10.5.0" // Set for Europe/London

#endif
