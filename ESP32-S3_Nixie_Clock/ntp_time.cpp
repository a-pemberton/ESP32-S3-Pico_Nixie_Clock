//---------------------------------------------------------------------------------------------
//
// Module:              ntp and time Functions
// Filename:            ntp_time.cpp
// Version:             1.0
// Date:                16/APR/2024
// Author:              A.Pemberton
// Function:            Arduino style ntp to time functions for ESP32-S2
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


#include "ESP32_Nixie.h"

//---------------------------------------------------------------------------------
// Module prototypes
//---------------------------------------------------------------------------------
bool ntp_Init(String);

void setTime(void);
void setTimezone(String);
//bool initTime(String);
bool update_Local_Time(void);

#ifdef DEBUG_NTP
void printLocalTime(void);
#endif

//---------------------------------------------------------------------------------
// Class declarations
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
// Module Global 'variable' declarations
//---------------------------------------------------------------------------------

//char timeServer[] = NTPpoolName_1;  // NTP server name

//uint8_t ntp_Packet_Buffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// NTP.ORG have doubled the epoch_t value to 64 bits to overcome the 2036 rollover issue
// Unix time starts on Jan 1 1970. In seconds, that's 2208988800 ticks

struct tm timeinfo;
extern const char *day_of_week[];
extern const char *month_of_year[];

//const char *initial_TimeZone[] = timezone_Test_Data;
//char current_TimeZone[30];

//---------------------------------------------------------------------------------
// Module Functions
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------
/*
bool ntp_Init(void)
{
#ifdef DEBUG_NTP
  Serial.println("Entered NTP Setup");
#endif
  ntp.ruleDST("BST", Last, Sun, Mar, 2, 120); // last sunday in march 2:00, timetone +120min (+1 GMT + 1h summertime offset)
  ntp.ruleSTD("GMT", Last, Sun, Oct, 3, 60); // last sunday in october 3:00, timezone +60min (+1 GMT)
  // ntp.isDST(false);
  // ntp.timeZone(1);
  // ntp.offset(0, 0, 0, 0);
  ntp.begin();

  String current_TimeZone = timezone_Test_Data;

  if (!initTime(current_TimeZone))
  {
#ifdef DEBUG_NTP
    Serial.println("initTime failed");
#endif
    return true;  // initTime() has failed
  }
#ifdef DEBUG_NTP
  printLocalTime();
#endif

  return false; // ntp setup has succeeded

}
*/
// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  return now;
}

void setTimezone(String timezone)
{
#ifdef DEBUG_NTP
  Serial.printf("Setting Timezone to %s\n",timezone.c_str());
#endif
  setenv("TZ",timezone.c_str(),1);  //  Now adjust the TZ.  Clock settings are adjusted to show the new local time
  tzset();
}

//---------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------
bool ntp_Init(String timezone)
{
#ifdef DEBUG_NTP
  Serial.println("Setting up NTP time");
#endif
  // Init and get the time
  configTime(0, 3600, NTPpoolName_1, NTPpoolName_2, NTPpoolName_3); // Up to three predefined NTP servers from "ntp_time.hpp"

  if(!getLocalTime(&timeinfo)){
#ifdef DEBUG_NTP
    Serial.println("Failed to obtain time");
#endif
    return(true); // Setup_fail = true
  }
// Adjust the current timezone to current location - Test timezone only at present Europe/London
  setTimezone(timezone);

  const char *tz = timezone.c_str();

  configTzTime(tz, NTPpoolName_3, NTPpoolName_2, NTPpoolName_1);
//configTzTime("GMT0BST,M3.5.0/1,M10.5.0", "pool.ntp.org");
//configTime(0, 0, NTPpoolName_3, NTPpoolName_2, NTPpoolName_1);    // First connect to a NTP server, with 0 TZ offset
  if (!getLocalTime(&timeinfo))
  {
#ifdef DEBUG_NTP
    Serial.println("  Failed to obtain time");
#endif
    return true;
  }
  time(&epochTime);
  
//  epochTime = getTime();
#ifdef DEBUG_NTP
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);
#endif

#ifdef DEBUG_NTP
  Serial.print("Got the time from NTP ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
#endif

  return false;
}

//---------------------------------------------------------------------------------
bool update_Local_Time(void)
{
#ifdef DEBUG_NTP
  Serial.println("Updating time");
#endif

  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time 1");
    return true;
  }
  time(&epochTime);
//  epochTime = getTime();

#ifdef DEBUG_NTP
  Serial.print("Got the time from NTP ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
#endif
  return false;
}

//---------------------------------------------------------------------------------
#ifdef DEBUG_NTP
void printLocalTime(void)
{

  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time 1");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
}
#endif


