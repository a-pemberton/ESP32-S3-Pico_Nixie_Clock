//---------------------------------------------------------------------------------------------
//
// Module:              WiFi Functions
// Filename:            WiFi_procs.c
// Version:             1.0
// Date:                08/JUN/2023
// Author:              A.Pemberton
// Function:            Arduino style WiFi functions for RP2040W with CYW43439 WiFi
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
bool WiFi_Setup(void);

//---------------------------------------------------------------------------------
// Class declarations
//---------------------------------------------------------------------------------
// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

//---------------------------------------------------------------------------------
// Module Global 'variable' declarations
//---------------------------------------------------------------------------------

char ssid[] = STASSID;        // your network SSID (name)
char pass[] = STAPSK;         // your network password (use for WPA, or use as key for WEP), length must be 8+

bool WiFi_Setup(void)
{
#ifdef DEBUG_WiFi
  Serial.print(F("Entered WiFi Setup - Connecting to "));
  Serial.println(ssid);
#endif

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
  int count = 0;
#ifdef DEBUG_WiFi
    Serial.print(".");
#endif
   delay(250);
   count++;
   if (count > (30*4)) return true; // WiFi has failed to connect so return error
  }
  // you're connected now, so print out the data
#ifdef DEBUG_WiFi
  Serial.print("\nYou're connected to the network, IP = ");
  Serial.println(WiFi.localIP());
#endif

  return false;

}
/*

wifi_country_t myCountryCode = {
    .cc = "UK",
    .schan = 1,
    .nchan = 13,
    .policy = WIFI_COUNTRY_POLICY_AUTO,
};


// =======================================================================================================
// Send HTML root page
// =======================================================================================================
void handleRoot(AsyncWebServerRequest *request)
{
//	digitalWrite(LED_BUILTIN, LED_ON);

//  struct tm timeinfo;
  if(!getLocalTime(&timeinfo,5000)){
#ifdef DEBUG_WiFi
    Serial.println("Failed to obtain time 1");
#endif
    return;
  }
  String message = " Internet time is:- ";
  message += (((timeinfo.tm_wday - 1) < 6) && ((timeinfo.tm_wday - 1) >= 0)) ? day_of_week[(timeinfo.tm_wday - 1)] : "";
  message += ", ";
  message += timeinfo.tm_mday;
  message += ", ";
  message += month_of_year[timeinfo.tm_mon];
  message += ", ";
  message += (timeinfo.tm_year) + 1900;
  message += ", ";
  message += timeinfo.tm_hour;
  message += ":";
  message += timeinfo.tm_min;
  message += ":";
  message += timeinfo.tm_sec;

	snprintf(temp, BUFFER_SIZE - 1, "Hello from Async_HelloServer on ESP32-S2_Pico at ");
//  build_home_page();

	request->send(200, "text/plain", temp + message);

}


// =======================================================================================================
// Send HTML 404 page not found message if the client requested an invalid page
// =======================================================================================================
void handleNotFound(AsyncWebServerRequest *request)
{
  digitalWrite(LED_BUILTIN, LED_ON);
  String message = "File Not Found\n\n";
  message += "URL: ";
  message += request->url();
  message += "\nMethod: ";
  message += (request->method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += request->args();
  message += "\n";
  for (uint8_t i = 0; i < request->args(); i++) {
    message += " " + request->argName(i) + ": " + request->arg(i) + "\n";
  }
  request->send(404, "text/plain", message);
//  digitalWrite(led, 0);
}

void printWifiStatus(void)
{
#ifdef DEBUG_WiFi
	// print the SSID of the network you're attached to:
	printf("SSID: %s\n",&ssid);
#endif

// print your board's IP address:
	IPAddress ip = WiFi.localIP();
#ifdef DEBUG_WiFi
	printf("Local IP Address: %s\n",ip);
#endif

#ifdef DEBUG_WiFi
	printf("Country code: %s\n", &countryCode);
#endif
}

// =======================================================================================================
// Initial WiFi setup as called from setup in .ino main program
// =======================================================================================================

void WiFi_Setup(void)
{
/*
// check for the WiFi module:
	if (WiFi.status() == WL_NO_MODULE)
	{
		printf("Communication with WiFi module failed!\n");

// don't continue
		while (true) {
    	digitalWrite(LED_BUILTIN, LED_OFF);
      delay(200);
      digitalWrite(LED_BUILTIN, LED_ON);
      delay(200);
    }
	}
//
#ifdef DEBUG_WiFi
  printf("Connecting to '%s' with '%s'\n", ssid, pass);
#endif
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
#ifdef DEBUG_WiFi
    printf(".");
#endif
    delay(250);
  }
#ifdef DEBUG_WiFi
  printf("\n");
#endif

#ifdef DEBUG_WiFi
  printf("Wifi RSSI=%i\n",WiFi.RSSI());
  printf("Connected to %s\nIP address: %s\n",ssid,(WiFi.localIP().toString().c_str()));
#endif
    
  delay(250);
		// Connect to WPA/WPA2 network
	WiFi_Status = WiFi.status();

#ifdef DEBUG_WiFi
  printf("\nConnected to WiFi\n\nConnect to server at %s:%i\n", WiFi.localIP().toString().c_str(), server_Port_HTML);
#endif

	server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
	{
		handleRoot(request);
	});

	server.on("/inline", [](AsyncWebServerRequest *request)
	{
		request->send(200, "text/plain", "This works as well");
	});

	server.onNotFound(handleNotFound);

	server.begin();

#ifdef DEBUG_WiFi
	printf("HTTP EthernetWebServer is @ IP : %s\n", WiFi.localIP());
#endif

// Now start NTP Server
  NTP_setup();

}

void heartBeatPrint(void)
{
	static int num = 1;
#ifdef DEBUG_WiFi
	printf(".");
#endif

	if (num == 80)
	{
#ifdef DEBUG_WiFi
		printf("\n");
#endif
		num = 1;
	}
	else if (num++ % 10 == 0)
	{
#ifdef DEBUG_WiFi
		printf(" ");
#endif
	}
}

void check_status(void)
{
	static unsigned long checkstatus_timeout = 0;

	// Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
	if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
	{
		heartBeatPrint();
		checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
	}
}



*/