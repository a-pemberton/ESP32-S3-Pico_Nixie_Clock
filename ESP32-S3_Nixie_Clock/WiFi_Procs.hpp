//---------------------------------------------------------------------------------------------
//
// Module:              Include file for SSID and PASSWORD
// Filename:            WiFi_Procs.h
// Version:             1.0
// Date:                07/JUN/2023
// Author:              A.Pemberton
// Function:            Supply parameters for WLAN connection and For RP2040W with CYW43439 WiFi
// Libraries included:  AsyncWebServer_RP2040W is a library for the RP2040W with CYW43439 WiFi
//                      Based on and modified from ESPAsyncWebServer (https://github.com/me-no-dev/ESPAsyncWebServer)
//                      Built by Khoi Hoang https://github.com/khoih-prog/AsyncWebServer_RP2040W
//                      Licensed under GPLv3 license
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

#ifndef __WiFi_Procs_H__
#define __WiFi_Procs_H__

//---------------------------------------------------------------------------------
// Module Definitions - basic WiFi
//---------------------------------------------------------------------------------

#ifndef STASSID
#define STASSID "COWROAST20"
#define STAPSK "Albatross#9"
#endif

#define My_Hostname "Nixie_Clock"

#define UDP_TIMEOUT 2000     // timeout in miliseconds to wait for an UDP packet to arrive

//---------------------------------------------------------------------------------
// Module Definitions - Webserver
//---------------------------------------------------------------------------------

#define server_Port_HTML 80
//WebServer    server(server_Port_HTML);

#endif  // #ifndef __WiFi_params_H__
