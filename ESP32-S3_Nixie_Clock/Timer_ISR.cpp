//---------------------------------------------------------------------------------------------
//
// Module:              Timer Interrupt Service Routine functions
// Filename:            Timer_ISR.cpp
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

#include "ESP32_Nixie.h"

//---------------------------------------------------------------------------------
// Module global variables. Some declared volatile to preserve values across calls
//---------------------------------------------------------------------------------

// Create timer structures for ISR's herein

hw_timer_t *timer1 = NULL;
hw_timer_t *timer2 = NULL;
hw_timer_t *watchDogTimer= NULL;

volatile SemaphoreHandle_t timer1Semaphore;
volatile SemaphoreHandle_t timer2Semaphore;

portMUX_TYPE timerMux1 = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE timerMux2 = portMUX_INITIALIZER_UNLOCKED;

volatile uint32_t ISRCounter1 = 0;
volatile uint32_t ISRCounter2 = 0;

volatile uint32_t lastISRat1 = 0;
volatile uint32_t lastISRat2 = 0;

uint32_t interruptCounter1 = 0;
uint32_t interruptCounter2 = 0;

volatile int totalInterruptCounter1;
volatile int totalInterruptCounter2;


const int wdtTimeout = watchDogTimeout;  //time in ms to trigger the watchdog
//#ifdef DEBUG_TIMER
//uint32_t watchDog_Sampler;
//#endif

volatile bool led_state = false;
volatile uint32_t led_cycle_time = blink_on_time;

//---------------------------------------------------------------------------------
// Function prototypes
//---------------------------------------------------------------------------------

bool Timer_ISR_Init(void);    // Timer/Watchdog setup function

//void Timer1_Start(uint32_t, bool); // GP Timer - parameters are void uint32_t duration and bool auto_reload or one-shot
//bool Timer1_End(bool);             // Flags Timer Timeout

void Timer2_Start(uint32_t, bool);  // For future use
bool Timer2_End(void);              // Flags Timer Timeout

void watchdog_setup(void);
void watchDogRefresh(void);


//---------------------------------------------------------------------------------
// Timer Interrupt Service Routine - callback when Timer expires
//---------------------------------------------------------------------------------

void ARDUINO_ISR_ATTR onTime1()
{ 
// Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux1);
  interruptCounter1++;
  lastISRat1 = millis();
  portEXIT_CRITICAL_ISR(&timerMux1);
// Give a semaphore that we can check in the loop
  xSemaphoreGiveFromISR(timer1Semaphore, NULL);
}

void ARDUINO_ISR_ATTR onTime2()
{ 
  portENTER_CRITICAL_ISR(&timerMux2);
  interruptCounter2++;
  lastISRat2 = millis();
  portEXIT_CRITICAL_ISR(&timerMux2);  
  xSemaphoreGiveFromISR(timer2Semaphore, NULL);
}

void IRAM_ATTR watchDogInterrupt()
{
  ESP.restart();
}

//---------------------------------------------------------------------------------
// Initialise Timer1, Yimer2 and Watchdog Interrupt Service Routines
// Timer1 is set to just run with ticks - 1 second time interval passed to routine
// Unknown time or mode of operation here
//---------------------------------------------------------------------------------

bool Timer_ISR_Init(void)    // Timer/Watchdog setup function
{
#ifdef DEBUG_TIMER
  Serial.println("Entered Timer Setup function");
#endif

// Create semaphore to inform us when the timer has fired
  timer1Semaphore = xSemaphoreCreateBinary();
  timer2Semaphore = xSemaphoreCreateBinary();

  timer1 = timerBegin(timer1frequency); //1MHz, prescaler default 80, count up
  if (timer1 == NULL) // NULL is an error state
    return true;
  timerAttachInterrupt(timer1, &onTime1);
  // Set alarm to call onTimer function every second (value in microseconds).
  // Repeat the alarm (third parameter) with unlimited count = 0 (fourth parameter).
  timerAlarm(timer1, blink_off_time, one_shot, 0);
  timerWrite(timer1, 0);
  timerStart(timer1);

  timer2 = timerBegin(timer2frequency); //1MHz, prescaler default 80, count up
  if (timer2 == NULL) // NULL is an error state 
    return true;
  timerAttachInterrupt(timer2, &onTime2);
  timerStop(timer2);  // Don't run timer 2 yet!

  watchDogTimer = timerBegin(watchDogfrequency);                   //timer 1Mhz resolution
  timerAttachInterrupt(watchDogTimer, &watchDogInterrupt);           //attach callback
  timerAlarm(watchDogTimer, wdtTimeout, false, 0); //set time in us

  return false; // Timers Begun
}


void Timer2_Start(uint32_t duration, bool repeat)
{
#ifdef DEBUG_TIMER
//  Serial.println("Entered Timer2 Start function");
#endif
// Arm timer 2 with time duration and one-shot mode    
  timerWrite(timer2, 0);
  timerAlarm(timer2, duration, repeat, 0);
  timerStart(timer2);

}

bool Timer2_End(void)
{
  uint32_t ISRCount2 = 0, ISRTime2 = 0;

#ifdef DEBUG_TIMER
//  Serial.println("Entered Timer2 finish function");
#endif

// If Timer2 has fired
  if (xSemaphoreTake(timer2Semaphore, 0) == pdTRUE)
  {
// Read the interrupt count and time
    portENTER_CRITICAL(&timerMux2);
    ISRCount2 = interruptCounter2;
    ISRTime2 = lastISRat2;
    portEXIT_CRITICAL(&timerMux2);
    timerStop(timer2);
    return true;
  }
  return false;
}

void watchDogRefresh(void)
{
    timerWrite(watchDogTimer, 0);
}



