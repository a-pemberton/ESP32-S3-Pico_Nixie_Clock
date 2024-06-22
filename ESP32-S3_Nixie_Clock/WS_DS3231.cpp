//---------------------------------------------------------------------------------------------
//
// Module:              Waveshare Nixie Clock RTC module source file
// Filename:            WS_DS3231.cpp
// Version:             1.0
// Date:                09/SEP/2023
// Author:              Waveshare modified by A.Pemberton
// Function:            DS3231 RTC file
// Change History:      None
//
//---------------------------------------------------------------------------------------------


#include "ESP32_Nixie.h"

//---------------------------------------------------------------------------------
// Module global declarations
//---------------------------------------------------------------------------------

DS3231 RTC; // Declare the RTC hardware Class

time_t epochTime;  // Globally declared 

bool century = false;
bool h12Flag;
bool pmFlag;
//uint8_t alarmDay, alarmHour, alarmMinute, alarmSecond, alarmBits;
//bool alarmDy, alarmH12Flag, alarmPmFlag;

extern bool clock_Update_Flag;

extern struct tm timeinfo;

const char *day_of_week[] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
const char *month_of_year[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

//---------------------------------------------------------------------------------
// Function prototypes
//---------------------------------------------------------------------------------

bool RTC_DS3231_Init(void);
bool RTC_DS3231_Set_Time(void);

#ifdef DEBUG_RTC
void alarm_Debug_Status(void);
#endif

//void DS3231_Set_Time(datetime_t time);
//void DS3231_Set_Date(datetime_t time);
//void DS3231_Set_All(datetime_t time);

//void DS3231_Read_now(datetime_t *time);

//void DS3231_Enable_Alarm(void);
//void DS3231_Disable_Alarm(void);
//void DS3231_Set_Alarm(datetime_t time);
//void DS3231_Read_Alarm(datetime_t *time);

//bool DS3231_Get_Alarm_Flag(void);
//void DS3231_Clear_Alarm_Flag(void);


void showTimeFormated(time_t);
void debug_Print_Date_Time(void);

extern void on_Board_LED_colour(uint32_t, uint8_t);
extern void off_Board_LED(void);

//---------------------------------------------------------------------------------
// DS3231 Alarm Interrupt Service Routine - Activates NTP and RTC update functions
//---------------------------------------------------------------------------------
void isr_TickTock() {
// Interrupt sets clock update flag to the loop function (at 1 second to midnight)
  clock_Update_Flag = true;

  return;
}

//---------------------------------------------------------------------------------
// Convert normal decimal numbers to binary coded decimal
//---------------------------------------------------------------------------------
static uint8_t decToBcd(int val)
{
    return (uint8_t)((val / 10 * 16) + (val % 10));
}
//---------------------------------------------------------------------------------
// Convert binary coded decimal to normal decimal numbers
//---------------------------------------------------------------------------------
static int bcdToDec(uint8_t val)
{
    return (int)((val / 16 * 10) + (val % 16));
}

//---------------------------------------------------------------------------------
// function:	Initialise ESP32-S2 i2c port
//            Sets up I2C port for 'Nixie' clock RTC and BME chips
//---------------------------------------------------------------------------------
bool RTC_DS3231_Init(void)
{
#ifdef DEBUG_RTC
  Serial.println("Entered RTC_DS3231_Init");
  Serial.print("Start RTC_ESP on ");
  Serial.print(ARDUINO_BOARD);
  Serial.println(" Now Initialise Hardware");
#endif
// attach clock interrupt
  pinMode(DS_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(DEV_INT_PIN), isr_TickTock, FALLING);

// i2c addressing is handled by <wire.h>
// Check the 32KHz TCXO is running and turn it on if not - disable external 32KXz output
	if (!RTC.oscillatorCheck()) {
    RTC.enableOscillator(true, true, 3);
#ifdef DEBUG_RTC
    Serial.println("Oscillator is Off - start it!");
#endif
  }

	if (!RTC.oscillatorCheck()) {
    RTC.setSecond(1); // clear Oscillator Stp Flag
#ifdef DEBUG_RTC
    Serial.println("Oscillator is Still Off");
#endif
  }

	if (!RTC.oscillatorCheck()) {
#ifdef DEBUG_RTC
    Serial.println("DS3231 is Not Working");
#endif
    return true;
  }

	RTC.enable32kHz(false);

  RTC.turnOffAlarm(primary_Alarm);  // Turn off alarms to prevent spurious interrupts
  RTC.turnOffAlarm(secondary_Alarm);
// clear Alarm flags
  RTC.checkIfAlarm(primary_Alarm);
  RTC.checkIfAlarm(secondary_Alarm);

#ifdef DEBUG_RTC
  alarm_Debug_Status();
#endif

//  epochTime = 0;  // 0 is Unix start time which was 01/01/1970 at 00:00:00 Hrs
  RTC.setEpoch(epochTime,false);

// set to 24h
  RTC.setClockMode(false);

  if (update_Local_Time())
    return true;

  RTC_DS3231_Set_Time();

#ifdef DEBUG_RTC
  Serial.printf("Started RTC epochTime = %d or 0x16%x, seventyYears = %d or 0x%16x\n",epochTime,epochTime,seventyYears,seventyYears);
#endif


// Format of RTS Alarm 1 is:- RTC.setA1Time(, alarmHour, alarmMinute, alarmSecond,alarmBits, alarmDayIsDay, alarmH12, alarmPM);
// Set alarm 1 to fire at one-second to midnight with the settings as below
//  alarmDay = 0; - all days
//  alarmHour = 0;
//  alarmMinute = 0;
//  alarmSecond = 0;
//  alarmBits = 0b00001000; // Alarm 23:59:59
//  alarmDayIsDay = false;
//  alarmH12 = false;
//  alarmPM = false;    

  RTC.setA1Time(0, 0, 0, 0, 0b00001100, false, false, false);
// enable Alarm 1 interrupts
  RTC.turnOnAlarm(primary_Alarm);
// clear Alarm 1 flag
  if(RTC.checkAlarmEnabled(primary_Alarm)) {
#ifdef DEBUG_RTC
    Serial.println("primary_Alarm Enabled");
#endif
  }
// When using interrupt with only one of the DS3231 alarms, as in this code,
// it may be advisable to prevent the other alarm entirely so it will not covertly block the outgoing interrupt signal.

// Prevent Alarm 2 altogether by assigning an impossible alarm minute value (255 or 0xff) that cannot match the clock minutes
// and an alarmBits value (0b01100000) to activate "when minutes match". i.e., never!
    
// Upload the parameters to prevent Alarm 2 entirely
  RTC.setA2Time(0, 0, 0xff, 0b01100000, false, false, false);
// disable Alarm 2 interrupt
  RTC.turnOffAlarm(secondary_Alarm);
// clear Alarm 2 flag
  RTC.checkIfAlarm(secondary_Alarm,true);

#ifdef DEBUG_RTC
  alarm_Debug_Status();
#endif

  return false;

}

bool RTC_DS3231_Set_Time(void)
{
#ifdef DEBUG_RTC
  Serial.println("Entered RTC_DS3231_Set_Time");
#endif

  update_Local_Time();

#ifdef DEBUG_RTC
  Serial.print("struct tm &timeinfo is now: ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
  Serial.printf("epochTime now is %d\n",epochTime);
#endif

  if (timeinfo.tm_isdst == 1)
    epochTime += 3600;  // Quick fix for summertime
  RTC.setEpoch(epochTime);

/*
		RTC.setSecond = (decToBcd(timeinfo.tm_sec));
			// In addition to setting the seconds, this clears the
			// "Oscillator Stop Flag".
		RTC.setMinute(decToBcd(timeinfo.tm_min));
			// Sets the minute
		RTC.setHour(decToBcd(timeinfo.tm_hour));
			// Sets the hour
		RTC.setDoW(decToBcd(timeinfo.tm_wday + 1));
			// Sets the Day of the Week (1-7);
		RTC.setDate(decToBcd(timeinfo.tm_mday));
			// Sets the Date of the Month
		RTC.setMonth(decToBcd(timeinfo.tm_mon + 1));
			// Sets the Month of the year
		RTC.setYear(decToBcd(timeinfo.tm_year - 100));
			// Last two digits of the year


int16_t year();
int8_t month();
int8_t day();
int8_t weekDay();
int8_t hours();
int8_t minutes();
int8_t seconds();

  tm.tm_year = yr - 1900;   // Set date
  tm.tm_mon = month-1;
  tm.tm_mday = mday;
  tm.tm_hour = hr;      // Set time
  tm.tm_min = minute;
  tm.tm_sec = sec;
  tm.tm_isdst = isDst;  // 1 or 0

tm_sec	int	seconds after the minute	0-61*
tm_min	int	minutes after the hour	0-59
tm_hour	int	hours since midnight	0-23
tm_mday	int	day of the month	1-31
tm_mon	int	months since January	0-11
tm_year	int	years since 1900	
tm_wday	int	days since Sunday	0-6
tm_yday	int	days since January 1	0-365
tm_isdst	int	Daylight Saving Time flag	


  timeinfo.tm_year  = ntp.year();   // Set date
  timeinfo.tm_mon   = ntp.month();
  timeinfo.tm_mday  = ntp.day();
  timeinfo.tm_hour  = ntp.hours();      // Set time
  timeinfo.tm_min   = ntp.minutes();
  timeinfo.tm_sec   = ntp.seconds();
  timeinfo.tm_wday  = ntp.weekDay();  // 1 to 7
  timeinfo.tm_isdst = (int)ntp.isDST();  // 1 or 0

  time_t t = mktime(&timeinfo);
*/  
#ifdef DEBUG_RTC
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
  showTimeFormated(epochTime);
#endif

  return false;
}

uint64_t RTC_DS3231_Read_Time(void) {
    return ((uint64_t)epochTime);
}

#ifdef DEBUG_RTC
void alarm_Debug_Status(void)
{
  Serial.print("primary_Alarm is ");
  Serial.println((RTC.checkAlarmEnabled(1) ? "Enabled" : "Disabled"));
  Serial.print("secondary_Alarm is ");
  Serial.println((RTC.checkAlarmEnabled(2) ? "Enabled" : "Disabled"));
}
#endif



void showTimeFormated(time_t t) {
  char buffer[50];
  struct tm *ptm;
  ptm = gmtime (&t);
  const char * timeformat {"%a %F %X - weekday %w; CW %W"};
  strftime(buffer, sizeof(buffer), timeformat, ptm);
#ifdef DEBUG_RTC
  Serial.print(buffer);
  Serial.println();
#endif
}

void debug_Print_Date_Time(void)
{
#ifdef DEBUG_RTC
	Serial.print(RTC.getDoW(), DEC);
	Serial.print(" ");

  switch (RTC.getDoW(), DEC)
  {
    case 1:
      Serial.print("SUN");
      break;
    case 2:
      Serial.print("MON");
      break;
    case 3:
      Serial.print("TUE");
      break;
    case 4:
      Serial.print("WED");
      break;
    case 5:
      Serial.print("THU");
      break;
    case 6:
      Serial.print("FRI");
      break;
    case 7:
      Serial.print("SAT");
      break;
  }

  Serial.print(" ");
  Serial.print(RTC.getDate(), DEC);
  Serial.print("-");
  Serial.print(RTC.getMonth(century), DEC);
  Serial.print("-");
  Serial.print(RTC.getYear(), DEC);

  Serial.print(" ");

  Serial.print(RTC.getHour(h12Flag, pmFlag), DEC);
  Serial.print(":");
  Serial.print(RTC.getMinute(), DEC);
  Serial.print(":");
  Serial.print(RTC.getSecond(), DEC);
  if (h12Flag)
  {
    if (pmFlag)
    {
		  Serial.print(" PM ");
		} else {
			Serial.print(" AM ");
		}
	} else {
		Serial.print(" 24h ");
	}
 
  Serial.println();
#endif
}


