/*
# This file is in the public domain, so clarified as of
# 2009-05-17 by Arthur David Olson.
#
# TZ zone descriptions
#
# From Paul Eggert (1996-08-05):
#
# This file contains a table with the following columns:
# 1.  ISO 3166 2-character country code.  See the file `iso3166.tab'.
# 2.  Latitude and longitude of the zone's principal location
#     in ISO 6709 sign-degrees-minutes-seconds format,
#     either +-DDMM+-DDDMM or +-DDMMSS+-DDDMMSS,
#     first latitude (+ is north), then longitude (+ is east).
# 3.  Zone name used in value of TZ environment variable.
# 4.  Comments; present if and only if the country has multiple rows.
#
# Columns are separated by a single tab.
# The table is sorted first by country, then an order within the country that
# (1) makes some geographical sense, and
# (2) puts the most populous zones first, where that does not contradict (1).
#
*/
/*
#ifndef __iso8601_H__
#define __iso8601_H__

#include "iso3166.h"

#if defined(__AVR__)
    #include <avr/pgmspace.h>
#elif defined(__PIC32MX__)
    #define PROGMEM
#elif defined(__arm__)
    #define PROGMEM
#endif


char countryCode[3] = { 0, 0, 0 };

wifi_country_t myCountryCode = {
    .cc = "UK",
    .schan = 1,
    .nchan = 13,
    .policy = WIFI_COUNTRY_POLICY_AUTO,
};

// Structure describing WiFi country-based regional restrictions
typedef struct {
    char                  cc[3];   // country code string
    uint8_t               schan;   // start channel
    uint8_t               nchan;   // total channel number
    int8_t                max_tx_power;   // This field is used for getting WiFi maximum transmitting power, call esp_wifi_set_max_tx_power to set the maximum transmitting power
    wifi_country_policy_t policy;  // country policy
} wifi_country_t;



const char *tzContinent[] PROGMEM=
  { "Africa","America","Antarctica","Arctic","Asia","Atlantic","Australia","Brazil","CET","CST6CDT","Canada","Chile","Cuba","EET","EST","EST5EDT","Egypt","Eire","Europe","Factory","GB","GB-Eire","GMT","GMT+0","GMT-0","GMT0","Greenwich","HST","Hongkong","Iceland","Indian","Iran","Israel","Jamaica","Japan",\
    "Kwajalein","Libya","MET","MST","MST7MDT","Mexico","NZ","NZ-CHAT","Navajo","PRC","PST8PDT","Pacific","Poland","Portugal","ROC","ROK","Singapore","Turkey","UCT","US","UTC","Universal","W-SU","WET","Zulu"
  };

const char *tzAfrica[] PROGMEM=
  { "Abidjan", "Accra", "Addis_Ababa", "Algiers", "Asmara", "Asmera", "Bamako", "Bangui", "Banjul", "Bssiau", \
    "Blantyre", "Brazzaville", "Bujumbura", "Cairo", "Casablanca", "Ceuta", "Conakry", "Dakar", "Dar_es_Salaam", "Djibouti", \
    "Douala", "El_Aaiun", "Freetown", "Gaborone", "Harare", "Johannesburg", "Juba", "Kampala", "Khartoum", "Kigali", \
    "Kinshasa", "Lagos", "Libreville", "Lome", "Luanda", "Lubumbashi", "Lusaka", "Malabo", "Maputo", "Maseru", \
    "Mbabane", "Mogadishu", "Monrovia", "Nairobi", "Ndjamena", "Niamey", "Nouakchott", "Ouagadougou", "Porto-Novo", "Sao_Tome", \
    "Timbuktu", "Tripoli", "Tunis", "Windhoek"
  };


const char *tzAfmerica[] PROGMEM=
  { "Adak", "Anchorage", "Anguilla", "Antigua", "Araguaina", "Argentina", "Aruba","Asuncion", "Atikokan", "Atka", \
    "Bahia", "Bahia_Banderas", "Barbados", "Belem", "Belize", "Blanc-Sablon", "Boa_Vista", "Bogota", "Boise", "Buenos_Aires", \
    "Cambridge_Bay", "Campo_Grande", "Cancun", "Caracas", "Catamarca", "Cayenne", "Cayman", "Chicago", "Chihuahua", "Ciudad_Juarez", \
    "Coral_Harbour", "Cordoba", "Costa_Rica", "Creston", "Cuiaba", "Curacao", "Danmarkshavn", "Dawson", "Dawson_Creek", "Denver", \
    "Detroit", "Dominica", "Edmonton", "Eirunepe", "El_Salvador", "Ensenada", "Fortaleza", "Fort_Nelson", "Fort_Wayne", "Glace_Bay", \
    "Godthab", "Goose_Bay", "Grand_Turk", "Grenada", "Guadeloupe", "Guatemala", "Guayaquil", "Guyana", "Halifax", "Havana", "Hermosillo", \
    "Indiana", "Indianapolis", "Inuvik", "Iqaluit", "Jamaica", "Jujuy", "Juneau", "Kentucky", "Knox_IN", "Kralendijk", \
    "La_Paz", "Lima", "Los_Angeles", "Louisville", "Lower_Princes", "Maceio", "Managua", "Manaus", "Marigot", "Martinique", "Matamoros", \
    "Mazatlan", "Mendoza", "Menominee", "Merida", "Metlakatla", "Mexico_City", "Miquelon", "Moncton", "Monterrey", "Montevideo", \
    "Montreal", "Montserrat", "Nassau", "New_York", "Nipigon", "Nome", "Noronha", "North_Dakota", "Nuuk", "Ojinaga", "Panama", \
    "Pangnirtung", "Paramaribo", "Phoenix", "Port-au-Prince", "Porto_Acre", "Port_of_Spain", "Porto_Velho", "Puerto_Rico", "Punta_Arenas", "Rainy_River", "Rankin_Inlet", \
    "Recife", "Regina", "Resolute", "Rio_Branco", "Rosario", "Santa_Isabel", "Santarem", "Santiago", "Santo_Domingo", "Sao_Paulo", \
    "Scoresbysund", "Shiprock", "Sitka", "St_Barthelemy", "St_Johns", "St_Kitts", "St_Lucia", "St_Thomas", "St_Vincent", "Swift_Current", "Tegucigalpa", \
    "Thule", "Thunder_Bay", "Tijuana", "Toronto", "Tortola", "Vancouver", "Virgin", "Whitehorse", "Winnipeg", "Yakutat", "Yellowknife"
  };

const char *tzArgentina[] PROGMEM=
  { "Buenos_Aires", "Catamarca", "ComodRivadavia", "Cordoba", "Jujuy", "La_Rioja", "Mendoza", "Rio_Gallegos", "Salta", "San_Juan", "San_Luis", "Tucuman", "Ushuaia" };
                    
const char *tzIndiana[] PROGMEM=
  { "Indianapolis", "Knox", "Marengo", "Petersburg", "Tell_City", "Vevay", "Vincennes", "Winamac" };

const char *tzKentucky[] PROGMEM=
  { "Louisville", "Monticello" };

const char *tzNorth_Dakota[] PROGMEM=
  { "Beulah", "Center", "New_Salem" };

const char *tzAntarctica[] PROGMEM=
  { "Casey","Davis","DumontDUrville","Macquarie","Mawson","McMurdo","Palmer","Rothera","South_Pole","Syowa","Troll","Vostok" };

const char *tzArctic[] PROGMEM=
  { "Longyearbyen" };

const char *tzAsia[] PROGMEM=
  { "Aden", "Almaty", "Amman", "Anadyr", "Aqtau", "Aqtobe", "Ashgabat", "Ashkhabad", "Atyrau", "Baghdad", \
    "Bahrain", "Baku", "Bangkok", "Barnaul", "Beirut", "Bishkek", "Brunei", "Calcutta", "Chita", "Choibalsan", \
    "Chongqing", "Chungking", "Colombo", "Dacca", "Damascus", "Dhaka", "Dili", "Dubai", "Dushanbe", "Famagusta", \
    "Gaza", "Harbin", "Hebron", "Ho_Chi_Minh", "Hong_Kong", "Hovd", "Irkutsk", "Istanbul", "Jakarta", "Jayapura", \
    "Jerusalem", "Kabul", "Kamchatka", "Karachi", "Kashgar", "Kathmandu", "Katmandu", "Khandyga", "Kolkata", "Krasnoyarsk", \
    "Kuala_Lumpur", "Kuching", "Kuwait", "Macao", "Macau", "Magadan", "Makassar", "Manila", "Muscat", "Nicosia", \
    "Novokuznetsk", "Novosibirsk", "Omsk", "Oral", "Phnom_Penh", "Pontianak", "Pyongyang", "Qatar", "Qostanay", "Qyzylorda", \
    "Rangoon", "Riyadh", "Saigon", "Sakhalin", "Samarkand", "Seoul", "Shanghai", "Singapore", "Srednekolymsk", "Taipei", \
    "Tashkent", "Tbilisi", "Tehran", "Tel_Aviv", "Thimbu", "Thimphu", "Tokyo", "Tomsk", "Ujung_Pandang", "Ulaanbaatar", \
    "Ulan_Bator","Urumqi","Ust-Nera","Vientiane","Vladivostok","Yakutsk","Yangon","Yekaterinburg","Yerevan"
  };

const char *tzAtlantic[] PROGMEM=
  { "Azores", "Bermuda", "Canary", "Cape_Verde", "Faeroe", "Faroe", "Jan_Mayen", "Madeira", "Reykjavik", "South_Georgia", "Stanley", "St_Helena" };

const char *tzAustralia[] PROGMEM=
  { "ACT", "Adelaide", "Brisbane", "Broken_Hill", "Canberra", "Currie", "Darwin", "Eucla", "Hobart", "LHI", \
    "Lindeman", "Lord_Howe", "Melbourne", "North", "NSW", "Perth", "Queensland", "South", "Sydney", "Tasmania", \
    "Victoria","West","Yancowinna"
  };

const char *tzBrazil[] PROGMEM=
  { "Acre", "DeNoronha", "East", "West" };

const char *tzCanada[] PROGMEM=
  { "Atlantic", "Central", "Eastern", "Mountain", "Newfoundland", "Pacific", "Saskatchewan", "Yukon" };

const char *tzChile[] PROGMEM=
  { "Continental", "EasterIsland" };

const char *tzEtc[] PROGMEM=
  { "GMT-12","GMT-11","GMT-10","GMT-9","GMT-8","GMT-7","GMT-6","GMT-5","GMT-4","GMT-3","GMT-2","GMT-1","GMT-0",\
    "GMT+0","GMT+1","GMT+2","GMT+3","GMT+4","GMT+5","GMT+6","GMT+7","GMT+8","GMT+9","GMT+10","GMT+11","GMT+12", \
    "Greenwich", "UCT", "Universal", "UTC", "Zulu" 
  };

const char *tzEurope[] PROGMEM=
  { "Amsterdam", "Andorra", "Astrakhan", "Athens", "Belfast", "Belgrade", "Berlin", "Bratislava", "Brussels", "Bucharest", \
  "Budapest", "Busingen", "Chisinau", "Copenhagen", "Dublin", "Gibraltar", "Guernsey", "Helsinki", "Isle_of_Man", "Istanbul", \
  "Jersey", "Kaliningrad", "Kiev", "Kirov", "Kyiv", "Lisbon", "Ljubljana", "London", "Luxembourg", "Madrid", \
  "Malta", "Mariehamn", "Minsk", "Monaco", "Moscow", "Nicosia", "Oslo", "Paris", "Podgorica", "Prague", \
  "Riga", "Rome", "Samara", "San_Marino", "Sarajevo", "Saratov", "Simferopol", "Skopje", "Sofia", "Stockholm", \
  "Tallinn", "Tirane", "Tiraspol", "Ulyanovsk", "Uzhgorod", "Vaduz", "Vatican", "Vienna", "Vilnius", "Volgograd", \
  "Warsaw", "Zagreb", "Zaporozhye", "Zurich"
  };

const char *tzIndian[] PROGMEM=
  { "Antananarivo", "Chagos", "Christmas", "Cocos", "Comoro", "Kerguelen", "Mahe", "Maldives", "Mauritius", "Mayotte", "Reunion" };

const char *tzMexico[] PROGMEM=
  { "BajaNorte", "BajaSur", "General" };

const char *tzPacific[] PROGMEM=
  { "Apia", "Auckland", "Bougainville", "Chatham", "Chuuk", "Easter", "Efate", "Enderbury", "Fakaofo", "Fiji", \
  "Funafuti", "Galapagos", "Gambier", "Guadalcanal", "Guam", "Honolulu", "Johnston", "Kanton", "Kiritimati", "Kosrae", \
  "Kwajalein", "Majuro", "Marquesas", "Midway", "Nauru", "Niue", "Norfolk", "Noumea", "Pago_Pago", "Palau", \
  "Pitcairn", "Pohnpei", "Ponape", "Port_Moresby", "Rarotonga", "Saipan", "Samoa", "Tahiti", "Tarawa", "Tongatapu", \
  "Truk", "Wake", "Wallis", "Yap"
  };

const char *tzUS[] PROGMEM=
  { "Alaska", "Aleutian", "Arizona", "Central", "Eastern", "East-Indiana", "Hawaii", "Indiana-Starke", "Michigan", "Mountain", \
  "Pacific", "Samoa" 
  };

const char *tzposix[] PROGMEM=
  { "Africa", "America", "Antarctica", "Arctic", "Asia", "Atlantic", "Australia", "Brazil", "Canada", "CET" \
  "Chile", "CST6CDT", "Cuba", "EET", "Egypt", "Eire", "EST", "EST5EDT", "Etc", "Europe", \
  "Factory", "GB", "GB-Eire", "GMT", "GMT+0", "GMT-0", "GMT0", "Greenwich", "Hongkong", "HST", \
  "Iceland", "Indian", "Iran", "Israel", "Jamaica", "Japan", "Kwajalein", "Libya", "MET", "Mexico", \
  "MST", "MST7MDT", "Navajo", "NZ", "NZ-CHAT", "Pacific", "Poland", "Portugal", "PRC", "PST8PDT", \
  "ROC", "ROK", "Singapore", "Turkey", "UCT", "Universal", "US", "UTC", "WET", "W-SU", "Zulu" 
  };




//"Africa/Abidjan","GMT0"
//"Africa/Accra","GMT0"
//"Africa/Addis_Ababa","EAT-3"
//"Africa/Algiers","CET-1"
//"Africa/Asmara","EAT-3"
//"Africa/Bamako","GMT0"
//"Africa/Bangui","WAT-1"
//"Africa/Banjul","GMT0"
//"Africa/Bissau","GMT0"
//"Africa/Blantyre","CAT-2"
//"Africa/Brazzaville","WAT-1"
//"Africa/Bujumbura","CAT-2"
//"Africa/Cairo","EET-2EEST,M4.5.5/0,M10.5.4/24"
//"Africa/Casablanca","<+01>-1"
//"Africa/Ceuta","CET-1CEST,M3.5.0,M10.5.0/3"
//"Africa/Conakry","GMT0"
//"Africa/Dakar","GMT0"
//"Africa/Dar_es_Salaam","EAT-3"
//"Africa/Djibouti","EAT-3"
//"Africa/Douala","WAT-1"
//"Africa/El_Aaiun","<+01>-1"
//"Africa/Freetown","GMT0"
//"Africa/Gaborone","CAT-2"
//"Africa/Harare","CAT-2"
//"Africa/Johannesburg","SAST-2"
//"Africa/Juba","CAT-2"
//"Africa/Kampala","EAT-3"
//"Africa/Khartoum","CAT-2"
//"Africa/Kigali","CAT-2"
//"Africa/Kinshasa","WAT-1"
//"Africa/Lagos","WAT-1"
//"Africa/Libreville","WAT-1"
//"Africa/Lome","GMT0"
//"Africa/Luanda","WAT-1"
//"Africa/Lubumbashi","CAT-2"
//"Africa/Lusaka","CAT-2"
//"Africa/Malabo","WAT-1"
//"Africa/Maputo","CAT-2"
//"Africa/Maseru","SAST-2"
//"Africa/Mbabane","SAST-2"
//"Africa/Mogadishu","EAT-3"
//"Africa/Monrovia","GMT0"
//"Africa/Nairobi","EAT-3"
//"Africa/Ndjamena","WAT-1"
//"Africa/Niamey","WAT-1"
//"Africa/Nouakchott","GMT0"
//"Africa/Ouagadougou","GMT0"
//"Africa/Porto-Novo","WAT-1"
//"Africa/Sao_Tome","GMT0"
//"Africa/Tripoli","EET-2"
//"Africa/Tunis","CET-1"
//"Africa/Windhoek","CAT-2"
//"America/Adak","HST10HDT,M3.2.0,M11.1.0"
//"America/Anchorage","AKST9AKDT,M3.2.0,M11.1.0"
//"America/Anguilla","AST4"
//"America/Antigua","AST4"
//"America/Araguaina","<-03>3"
//"America/Argentina/Buenos_Aires","<-03>3"
//"America/Argentina/Catamarca","<-03>3"
//"America/Argentina/Cordoba","<-03>3"
//"America/Argentina/Jujuy","<-03>3"
//"America/Argentina/La_Rioja","<-03>3"
//"America/Argentina/Mendoza","<-03>3"
//"America/Argentina/Rio_Gallegos","<-03>3"
//"America/Argentina/Salta","<-03>3"
//"America/Argentina/San_Juan","<-03>3"
//"America/Argentina/San_Luis","<-03>3"
//"America/Argentina/Tucuman","<-03>3"
//"America/Argentina/Ushuaia","<-03>3"
//"America/Aruba","AST4"
//"America/Asuncion","<-04>4<-03>,M10.1.0/0,M3.4.0/0"
//"America/Atikokan","EST5"
//"America/Bahia","<-03>3"
//"America/Bahia_Banderas","CST6"
//"America/Barbados","AST4"
//"America/Belem","<-03>3"
//"America/Belize","CST6"
//"America/Blanc-Sablon","AST4"
//"America/Boa_Vista","<-04>4"
//"America/Bogota","<-05>5"
//"America/Boise","MST7MDT,M3.2.0,M11.1.0"
//"America/Cambridge_Bay","MST7MDT,M3.2.0,M11.1.0"
//"America/Campo_Grande","<-04>4"
//"America/Cancun","EST5"
//"America/Caracas","<-04>4"
//"America/Cayenne","<-03>3"
//"America/Cayman","EST5"
//"America/Chicago","CST6CDT,M3.2.0,M11.1.0"
//"America/Chihuahua","CST6"
//"America/Costa_Rica","CST6"
//"America/Creston","MST7"
//"America/Cuiaba","<-04>4"
//"America/Curacao","AST4"
//"America/Danmarkshavn","GMT0"
//"America/Dawson","MST7"
//"America/Dawson_Creek","MST7"
//"America/Denver","MST7MDT,M3.2.0,M11.1.0"
//"America/Detroit","EST5EDT,M3.2.0,M11.1.0"
//"America/Dominica","AST4"
//"America/Edmonton","MST7MDT,M3.2.0,M11.1.0"
//"America/Eirunepe","<-05>5"
//"America/El_Salvador","CST6"
//"America/Fortaleza","<-03>3"
//"America/Fort_Nelson","MST7"
//"America/Glace_Bay","AST4ADT,M3.2.0,M11.1.0"
//"America/Godthab","<-02>2<-01>,M3.5.0/-1,M10.5.0/0"
//"America/Goose_Bay","AST4ADT,M3.2.0,M11.1.0"
//"America/Grand_Turk","EST5EDT,M3.2.0,M11.1.0"
//"America/Grenada","AST4"
//"America/Guadeloupe","AST4"
//"America/Guatemala","CST6"
//"America/Guayaquil","<-05>5"
//"America/Guyana","<-04>4"
//"America/Halifax","AST4ADT,M3.2.0,M11.1.0"
//"America/Havana","CST5CDT,M3.2.0/0,M11.1.0/1"
//"America/Hermosillo","MST7"
//"America/Indiana/Indianapolis","EST5EDT,M3.2.0,M11.1.0"
//"America/Indiana/Knox","CST6CDT,M3.2.0,M11.1.0"
//"America/Indiana/Marengo","EST5EDT,M3.2.0,M11.1.0"
//"America/Indiana/Petersburg","EST5EDT,M3.2.0,M11.1.0"
//"America/Indiana/Tell_City","CST6CDT,M3.2.0,M11.1.0"
//"America/Indiana/Vevay","EST5EDT,M3.2.0,M11.1.0"
//"America/Indiana/Vincennes","EST5EDT,M3.2.0,M11.1.0"
//"America/Indiana/Winamac","EST5EDT,M3.2.0,M11.1.0"
//"America/Inuvik","MST7MDT,M3.2.0,M11.1.0"
//"America/Iqaluit","EST5EDT,M3.2.0,M11.1.0"
//"America/Jamaica","EST5"
//"America/Juneau","AKST9AKDT,M3.2.0,M11.1.0"
//"America/Kentucky/Louisville","EST5EDT,M3.2.0,M11.1.0"
//"America/Kentucky/Monticello","EST5EDT,M3.2.0,M11.1.0"
//"America/Kralendijk","AST4"
//"America/La_Paz","<-04>4"
//"America/Lima","<-05>5"
//"America/Los_Angeles","PST8PDT,M3.2.0,M11.1.0"
//"America/Lower_Princes","AST4"
//"America/Maceio","<-03>3"
//"America/Managua","CST6"
//"America/Manaus","<-04>4"
//"America/Marigot","AST4"
//"America/Martinique","AST4"
//"America/Matamoros","CST6CDT,M3.2.0,M11.1.0"
//"America/Mazatlan","MST7"
//"America/Menominee","CST6CDT,M3.2.0,M11.1.0"
//"America/Merida","CST6"
//"America/Metlakatla","AKST9AKDT,M3.2.0,M11.1.0"
//"America/Mexico_City","CST6"
//"America/Miquelon","<-03>3<-02>,M3.2.0,M11.1.0"
//"America/Moncton","AST4ADT,M3.2.0,M11.1.0"
//"America/Monterrey","CST6"
//"America/Montevideo","<-03>3"
//"America/Montreal","EST5EDT,M3.2.0,M11.1.0"
//"America/Montserrat","AST4"
//"America/Nassau","EST5EDT,M3.2.0,M11.1.0"
//"America/New_York","EST5EDT,M3.2.0,M11.1.0"
//"America/Nipigon","EST5EDT,M3.2.0,M11.1.0"
//"America/Nome","AKST9AKDT,M3.2.0,M11.1.0"
//"America/Noronha","<-02>2"
//"America/North_Dakota/Beulah","CST6CDT,M3.2.0,M11.1.0"
//"America/North_Dakota/Center","CST6CDT,M3.2.0,M11.1.0"
//"America/North_Dakota/New_Salem","CST6CDT,M3.2.0,M11.1.0"
//"America/Nuuk","<-02>2<-01>,M3.5.0/-1,M10.5.0/0"
//"America/Ojinaga","CST6CDT,M3.2.0,M11.1.0"
//"America/Panama","EST5"
//"America/Pangnirtung","EST5EDT,M3.2.0,M11.1.0"
//"America/Paramaribo","<-03>3"
//"America/Phoenix","MST7"
//"America/Port-au-Prince","EST5EDT,M3.2.0,M11.1.0"
//"America/Port_of_Spain","AST4"
//"America/Porto_Velho","<-04>4"
//"America/Puerto_Rico","AST4"
//"America/Punta_Arenas","<-03>3"
//"America/Rainy_River","CST6CDT,M3.2.0,M11.1.0"
//"America/Rankin_Inlet","CST6CDT,M3.2.0,M11.1.0"
//"America/Recife","<-03>3"
//"America/Regina","CST6"
//"America/Resolute","CST6CDT,M3.2.0,M11.1.0"
//"America/Rio_Branco","<-05>5"
//"America/Santarem","<-03>3"
//"America/Santiago","<-04>4<-03>,M9.1.6/24,M4.1.6/24"
//"America/Santo_Domingo","AST4"
//"America/Sao_Paulo","<-03>3"
//"America/Scoresbysund","<-01>1<+00>,M3.5.0/0,M10.5.0/1"
//"America/Sitka","AKST9AKDT,M3.2.0,M11.1.0"
//"America/St_Barthelemy","AST4"
//"America/St_Johns","NST3:30NDT,M3.2.0,M11.1.0"
//"America/St_Kitts","AST4"
//"America/St_Lucia","AST4"
//"America/St_Thomas","AST4"
//"America/St_Vincent","AST4"
//"America/Swift_Current","CST6"
//"America/Tegucigalpa","CST6"
//"America/Thule","AST4ADT,M3.2.0,M11.1.0"
//"America/Thunder_Bay","EST5EDT,M3.2.0,M11.1.0"
//"America/Tijuana","PST8PDT,M3.2.0,M11.1.0"
//"America/Toronto","EST5EDT,M3.2.0,M11.1.0"
//"America/Tortola","AST4"
//"America/Vancouver","PST8PDT,M3.2.0,M11.1.0"
//"America/Whitehorse","MST7"
//"America/Winnipeg","CST6CDT,M3.2.0,M11.1.0"
//"America/Yakutat","AKST9AKDT,M3.2.0,M11.1.0"
//"America/Yellowknife","MST7MDT,M3.2.0,M11.1.0"
//"Antarctica/Casey","<+11>-11"
//"Antarctica/Davis","<+07>-7"
//"Antarctica/DumontDUrville","<+10>-10"
//"Antarctica/Macquarie","AEST-10AEDT,M10.1.0,M4.1.0/3"
//"Antarctica/Mawson","<+05>-5"
//"Antarctica/McMurdo","NZST-12NZDT,M9.5.0,M4.1.0/3"
//"Antarctica/Palmer","<-03>3"
//"Antarctica/Rothera","<-03>3"
//"Antarctica/Syowa","<+03>-3"
//"Antarctica/Troll","<+00>0<+02>-2,M3.5.0/1,M10.5.0/3"
//"Antarctica/Vostok","<+06>-6"
//"Arctic/Longyearbyen","CET-1CEST,M3.5.0,M10.5.0/3"
//"Asia/Aden","<+03>-3"
//"Asia/Almaty","<+06>-6"
//"Asia/Amman","<+03>-3"
//"Asia/Anadyr","<+12>-12"
//"Asia/Aqtau","<+05>-5"
//"Asia/Aqtobe","<+05>-5"
//"Asia/Ashgabat","<+05>-5"
//"Asia/Atyrau","<+05>-5"
//"Asia/Baghdad","<+03>-3"
//"Asia/Bahrain","<+03>-3"
//"Asia/Baku","<+04>-4"
//"Asia/Bangkok","<+07>-7"
//"Asia/Barnaul","<+07>-7"
//"Asia/Beirut","EET-2EEST,M3.5.0/0,M10.5.0/0"
//"Asia/Bishkek","<+06>-6"
//"Asia/Brunei","<+08>-8"
//"Asia/Chita","<+09>-9"
//"Asia/Choibalsan","<+08>-8"
//"Asia/Colombo","<+0530>-5:30"
//"Asia/Damascus","<+03>-3"
//"Asia/Dhaka","<+06>-6"
//"Asia/Dili","<+09>-9"
//"Asia/Dubai","<+04>-4"
//"Asia/Dushanbe","<+05>-5"
//"Asia/Famagusta","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Asia/Gaza","EET-2EEST,M3.4.4/50,M10.4.4/50"
//"Asia/Hebron","EET-2EEST,M3.4.4/50,M10.4.4/50"
//"Asia/Ho_Chi_Minh","<+07>-7"
//"Asia/Hong_Kong","HKT-8"
//"Asia/Hovd","<+07>-7"
//"Asia/Irkutsk","<+08>-8"
//"Asia/Jakarta","WIB-7"
//"Asia/Jayapura","WIT-9"
//"Asia/Jerusalem","IST-2IDT,M3.4.4/26,M10.5.0"
//"Asia/Kabul","<+0430>-4:30"
//"Asia/Kamchatka","<+12>-12"
//"Asia/Karachi","PKT-5"
//"Asia/Kathmandu","<+0545>-5:45"
//"Asia/Khandyga","<+09>-9"
//"Asia/Kolkata","IST-5:30"
//"Asia/Krasnoyarsk","<+07>-7"
//"Asia/Kuala_Lumpur","<+08>-8"
//"Asia/Kuching","<+08>-8"
//"Asia/Kuwait","<+03>-3"
//"Asia/Macau","CST-8"
//"Asia/Magadan","<+11>-11"
//"Asia/Makassar","WITA-8"
//"Asia/Manila","PST-8"
//"Asia/Muscat","<+04>-4"
//"Asia/Nicosia","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Asia/Novokuznetsk","<+07>-7"
//"Asia/Novosibirsk","<+07>-7"
//"Asia/Omsk","<+06>-6"
//"Asia/Oral","<+05>-5"
//"Asia/Phnom_Penh","<+07>-7"
//"Asia/Pontianak","WIB-7"
//"Asia/Pyongyang","KST-9"
//"Asia/Qatar","<+03>-3"
//"Asia/Qyzylorda","<+05>-5"
//"Asia/Riyadh","<+03>-3"
//"Asia/Sakhalin","<+11>-11"
//"Asia/Samarkand","<+05>-5"
//"Asia/Seoul","KST-9"
//"Asia/Shanghai","CST-8"
//"Asia/Singapore","<+08>-8"
//"Asia/Srednekolymsk","<+11>-11"
//"Asia/Taipei","CST-8"
//"Asia/Tashkent","<+05>-5"
//"Asia/Tbilisi","<+04>-4"
//"Asia/Tehran","<+0330>-3:30"
//"Asia/Thimphu","<+06>-6"
//"Asia/Tokyo","JST-9"
//"Asia/Tomsk","<+07>-7"
//"Asia/Ulaanbaatar","<+08>-8"
//"Asia/Urumqi","<+06>-6"
//"Asia/Ust-Nera","<+10>-10"
//"Asia/Vientiane","<+07>-7"
//"Asia/Vladivostok","<+10>-10"
//"Asia/Yakutsk","<+09>-9"
//"Asia/Yangon","<+0630>-6:30"
//"Asia/Yekaterinburg","<+05>-5"
//"Asia/Yerevan","<+04>-4"
//"Atlantic/Azores","<-01>1<+00>,M3.5.0/0,M10.5.0/1"
//"Atlantic/Bermuda","AST4ADT,M3.2.0,M11.1.0"
//"Atlantic/Canary","WET0WEST,M3.5.0/1,M10.5.0"
//"Atlantic/Cape_Verde","<-01>1"
//"Atlantic/Faroe","WET0WEST,M3.5.0/1,M10.5.0"
//"Atlantic/Madeira","WET0WEST,M3.5.0/1,M10.5.0"
//"Atlantic/Reykjavik","GMT0"
//"Atlantic/South_Georgia","<-02>2"
//"Atlantic/Stanley","<-03>3"
//"Atlantic/St_Helena","GMT0"
//"Australia/Adelaide","ACST-9:30ACDT,M10.1.0,M4.1.0/3"
//"Australia/Brisbane","AEST-10"
//"Australia/Broken_Hill","ACST-9:30ACDT,M10.1.0,M4.1.0/3"
//"Australia/Currie","AEST-10AEDT,M10.1.0,M4.1.0/3"
//"Australia/Darwin","ACST-9:30"
//"Australia/Eucla","<+0845>-8:45"
//"Australia/Hobart","AEST-10AEDT,M10.1.0,M4.1.0/3"
//"Australia/Lindeman","AEST-10"
//"Australia/Lord_Howe","<+1030>-10:30<+11>-11,M10.1.0,M4.1.0"
//"Australia/Melbourne","AEST-10AEDT,M10.1.0,M4.1.0/3"
//"Australia/Perth","AWST-8"
//"Australia/Sydney","AEST-10AEDT,M10.1.0,M4.1.0/3"
//"Europe/Amsterdam","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Andorra","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Astrakhan","<+04>-4"
//"Europe/Athens","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Belgrade","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Berlin","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Bratislava","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Brussels","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Bucharest","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Budapest","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Busingen","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Chisinau","EET-2EEST,M3.5.0,M10.5.0/3"
//"Europe/Copenhagen","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Dublin","IST-1GMT0,M10.5.0,M3.5.0/1"
//"Europe/Gibraltar","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Guernsey","GMT0BST,M3.5.0/1,M10.5.0"
//"Europe/Helsinki","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Isle_of_Man","GMT0BST,M3.5.0/1,M10.5.0"
//"Europe/Istanbul","<+03>-3"
//"Europe/Jersey","GMT0BST,M3.5.0/1,M10.5.0"
//"Europe/Kaliningrad","EET-2"
//"Europe/Kiev","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Kirov","MSK-3"
//"Europe/Lisbon","WET0WEST,M3.5.0/1,M10.5.0"
//"Europe/Ljubljana","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/London","GMT0BST,M3.5.0/1,M10.5.0"
//"Europe/Luxembourg","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Madrid","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Malta","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Mariehamn","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Minsk","<+03>-3"
//"Europe/Monaco","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Moscow","MSK-3"
//"Europe/Oslo","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Paris","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Podgorica","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Prague","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Riga","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Rome","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Samara","<+04>-4"
//"Europe/San_Marino","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Sarajevo","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Saratov","<+04>-4"
//"Europe/Simferopol","MSK-3"
//"Europe/Skopje","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Sofia","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Stockholm","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Tallinn","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Tirane","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Ulyanovsk","<+04>-4"
//"Europe/Uzhgorod","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Vaduz","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Vatican","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Vienna","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Vilnius","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Volgograd","MSK-3"
//"Europe/Warsaw","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Zagreb","CET-1CEST,M3.5.0,M10.5.0/3"
//"Europe/Zaporozhye","EET-2EEST,M3.5.0/3,M10.5.0/4"
//"Europe/Zurich","CET-1CEST,M3.5.0,M10.5.0/3"
//"Indian/Antananarivo","EAT-3"
//"Indian/Chagos","<+06>-6"
//"Indian/Christmas","<+07>-7"
//"Indian/Cocos","<+0630>-6:30"
//"Indian/Comoro","EAT-3"
//"Indian/Kerguelen","<+05>-5"
//"Indian/Mahe","<+04>-4"
//"Indian/Maldives","<+05>-5"
//"Indian/Mauritius","<+04>-4"
//"Indian/Mayotte","EAT-3"
//"Indian/Reunion","<+04>-4"
//"Pacific/Apia","<+13>-13"
//"Pacific/Auckland","NZST-12NZDT,M9.5.0,M4.1.0/3"
//"Pacific/Bougainville","<+11>-11"
//"Pacific/Chatham","<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45"
//"Pacific/Chuuk","<+10>-10"
//"Pacific/Easter","<-06>6<-05>,M9.1.6/22,M4.1.6/22"
//"Pacific/Efate","<+11>-11"
//"Pacific/Enderbury","<+13>-13"
//"Pacific/Fakaofo","<+13>-13"
//"Pacific/Fiji","<+12>-12"
//"Pacific/Funafuti","<+12>-12"
//"Pacific/Galapagos","<-06>6"
//"Pacific/Gambier","<-09>9"
//"Pacific/Guadalcanal","<+11>-11"
//"Pacific/Guam","ChST-10"
//"Pacific/Honolulu","HST10"
//"Pacific/Kiritimati","<+14>-14"
//"Pacific/Kosrae","<+11>-11"
//"Pacific/Kwajalein","<+12>-12"
//"Pacific/Majuro","<+12>-12"
//"Pacific/Marquesas","<-0930>9:30"
//"Pacific/Midway","SST11"
//"Pacific/Nauru","<+12>-12"
//"Pacific/Niue","<-11>11"
//"Pacific/Norfolk","<+11>-11<+12>,M10.1.0,M4.1.0/3"
//"Pacific/Noumea","<+11>-11"
//"Pacific/Pago_Pago","SST11"
//"Pacific/Palau","<+09>-9"
//"Pacific/Pitcairn","<-08>8"
//"Pacific/Pohnpei","<+11>-11"
//"Pacific/Port_Moresby","<+10>-10"
//"Pacific/Rarotonga","<-10>10"
//"Pacific/Saipan","ChST-10"
//"Pacific/Tahiti","<-10>10"
//"Pacific/Tarawa","<+12>-12"
//"Pacific/Tongatapu","<+13>-13"
//"Pacific/Wake","<+12>-12"
//"Pacific/Wallis","<+12>-12"
"Etc/GMT","GMT0"
"Etc/GMT-0","GMT0"
"Etc/GMT-1","<+01>-1"
"Etc/GMT-2","<+02>-2"
"Etc/GMT-3","<+03>-3"
"Etc/GMT-4","<+04>-4"
"Etc/GMT-5","<+05>-5"
"Etc/GMT-6","<+06>-6"
"Etc/GMT-7","<+07>-7"
"Etc/GMT-8","<+08>-8"
"Etc/GMT-9","<+09>-9"
"Etc/GMT-10","<+10>-10"
"Etc/GMT-11","<+11>-11"
"Etc/GMT-12","<+12>-12"
"Etc/GMT-13","<+13>-13"
"Etc/GMT-14","<+14>-14"
"Etc/GMT0","GMT0"
"Etc/GMT+0","GMT0"
"Etc/GMT+1","<-01>1"
"Etc/GMT+2","<-02>2"
"Etc/GMT+3","<-03>3"
"Etc/GMT+4","<-04>4"
"Etc/GMT+5","<-05>5"
"Etc/GMT+6","<-06>6"
"Etc/GMT+7","<-07>7"
"Etc/GMT+8","<-08>8"
"Etc/GMT+9","<-09>9"
"Etc/GMT+10","<-10>10"
"Etc/GMT+11","<-11>11"
"Etc/GMT+12","<-12>12"
"Etc/UCT","UTC0"
"Etc/UTC","UTC0"
"Etc/Greenwich","GMT0"
"Etc/Universal","UTC0"
"Etc/Zulu","UTC0"
/*
# <pre>
# @(#)zone.tab	8.28
# Lines beginning with `#' are comments.
#
#country-
#code	coordinates	TZ			comments
AD	+4230+00131	Europe/Andorra
AE	+2518+05518	Asia/Dubai
AF	+3431+06912	Asia/Kabul
AG	+1703-06148	America/Antigua
AI	+1812-06304	America/Anguilla
AL	+4120+01950	Europe/Tirane
AM	+4011+04430	Asia/Yerevan
AN	+1211-06900	America/Curacao
AO	-0848+01314	Africa/Luanda
AQ	-7750+16636	Antarctica/McMurdo	McMurdo Station, Ross Island
AQ	-9000+00000	Antarctica/South_Pole	Amundsen-Scott Station, South Pole
AQ	-6734-06808	Antarctica/Rothera	Rothera Station, Adelaide Island
AQ	-6448-06406	Antarctica/Palmer	Palmer Station, Anvers Island
AQ	-6736+06253	Antarctica/Mawson	Mawson Station, Holme Bay
AQ	-6835+07758	Antarctica/Davis	Davis Station, Vestfold Hills
AQ	-6617+11031	Antarctica/Casey	Casey Station, Bailey Peninsula
AQ	-7824+10654	Antarctica/Vostok	Vostok Station, S Magnetic Pole
AQ	-6640+14001	Antarctica/DumontDUrville	Dumont-d'Urville Station, Terre Adelie
AQ	-690022+0393524	Antarctica/Syowa	Syowa Station, E Ongul I
AR	-3436-05827	America/Argentina/Buenos_Aires	Buenos Aires (BA, CF)
AR	-3124-06411	America/Argentina/Cordoba	most locations (CB, CC, CN, ER, FM, MN, SE, SF)
AR	-2447-06525	America/Argentina/Salta	(SA, LP, NQ, RN)
AR	-2411-06518	America/Argentina/Jujuy	Jujuy (JY)
AR	-2649-06513	America/Argentina/Tucuman	Tucuman (TM)
AR	-2828-06547	America/Argentina/Catamarca	Catamarca (CT), Chubut (CH)
AR	-2926-06651	America/Argentina/La_Rioja	La Rioja (LR)
AR	-3132-06831	America/Argentina/San_Juan	San Juan (SJ)
AR	-3253-06849	America/Argentina/Mendoza	Mendoza (MZ)
AR	-3319-06621	America/Argentina/San_Luis	San Luis (SL)
AR	-5138-06913	America/Argentina/Rio_Gallegos	Santa Cruz (SC)
AR	-5448-06818	America/Argentina/Ushuaia	Tierra del Fuego (TF)
AS	-1416-17042	Pacific/Pago_Pago
AT	+4813+01620	Europe/Vienna
AU	-3133+15905	Australia/Lord_Howe	Lord Howe Island
AU	-4253+14719	Australia/Hobart	Tasmania - most locations
AU	-3956+14352	Australia/Currie	Tasmania - King Island
AU	-3749+14458	Australia/Melbourne	Victoria
AU	-3352+15113	Australia/Sydney	New South Wales - most locations
AU	-3157+14127	Australia/Broken_Hill	New South Wales - Yancowinna
AU	-2728+15302	Australia/Brisbane	Queensland - most locations
AU	-2016+14900	Australia/Lindeman	Queensland - Holiday Islands
AU	-3455+13835	Australia/Adelaide	South Australia
AU	-1228+13050	Australia/Darwin	Northern Territory
AU	-3157+11551	Australia/Perth	Western Australia - most locations
AU	-3143+12852	Australia/Eucla	Western Australia - Eucla area
AW	+1230-06958	America/Aruba
AX	+6006+01957	Europe/Mariehamn
AZ	+4023+04951	Asia/Baku
BA	+4352+01825	Europe/Sarajevo
BB	+1306-05937	America/Barbados
BD	+2343+09025	Asia/Dhaka
BE	+5050+00420	Europe/Brussels
BF	+1222-00131	Africa/Ouagadougou
BG	+4241+02319	Europe/Sofia
BH	+2623+05035	Asia/Bahrain
BI	-0323+02922	Africa/Bujumbura
BJ	+0629+00237	Africa/Porto-Novo
BL	+1753-06251	America/St_Barthelemy
BM	+3217-06446	Atlantic/Bermuda
BN	+0456+11455	Asia/Brunei
BO	-1630-06809	America/La_Paz
BR	-0351-03225	America/Noronha	Atlantic islands
BR	-0127-04829	America/Belem	Amapa, E Para
BR	-0343-03830	America/Fortaleza	NE Brazil (MA, PI, CE, RN, PB)
BR	-0803-03454	America/Recife	Pernambuco
BR	-0712-04812	America/Araguaina	Tocantins
BR	-0940-03543	America/Maceio	Alagoas, Sergipe
BR	-1259-03831	America/Bahia	Bahia
BR	-2332-04637	America/Sao_Paulo	S & SE Brazil (GO, DF, MG, ES, RJ, SP, PR, SC, RS)
BR	-2027-05437	America/Campo_Grande	Mato Grosso do Sul
BR	-1535-05605	America/Cuiaba	Mato Grosso
BR	-0226-05452	America/Santarem	W Para
BR	-0846-06354	America/Porto_Velho	Rondonia
BR	+0249-06040	America/Boa_Vista	Roraima
BR	-0308-06001	America/Manaus	E Amazonas
BR	-0640-06952	America/Eirunepe	W Amazonas
BR	-0958-06748	America/Rio_Branco	Acre
BS	+2505-07721	America/Nassau
BT	+2728+08939	Asia/Thimphu
BW	-2439+02555	Africa/Gaborone
BY	+5354+02734	Europe/Minsk
BZ	+1730-08812	America/Belize
CA	+4734-05243	America/St_Johns	Newfoundland Time, including SE Labrador
CA	+4439-06336	America/Halifax	Atlantic Time - Nova Scotia (most places), PEI
CA	+4612-05957	America/Glace_Bay	Atlantic Time - Nova Scotia - places that did not observe DST 1966-1971
CA	+4606-06447	America/Moncton	Atlantic Time - New Brunswick
CA	+5320-06025	America/Goose_Bay	Atlantic Time - Labrador - most locations
CA	+5125-05707	America/Blanc-Sablon	Atlantic Standard Time - Quebec - Lower North Shore
CA	+4531-07334	America/Montreal	Eastern Time - Quebec - most locations
CA	+4339-07923	America/Toronto	Eastern Time - Ontario - most locations
CA	+4901-08816	America/Nipigon	Eastern Time - Ontario & Quebec - places that did not observe DST 1967-1973
CA	+4823-08915	America/Thunder_Bay	Eastern Time - Thunder Bay, Ontario
CA	+6344-06828	America/Iqaluit	Eastern Time - east Nunavut - most locations
CA	+6608-06544	America/Pangnirtung	Eastern Time - Pangnirtung, Nunavut
CA	+744144-0944945	America/Resolute	Eastern Standard Time - Resolute, Nunavut
CA	+484531-0913718	America/Atikokan	Eastern Standard Time - Atikokan, Ontario and Southampton I, Nunavut
CA	+624900-0920459	America/Rankin_Inlet	Central Time - central Nunavut
CA	+4953-09709	America/Winnipeg	Central Time - Manitoba & west Ontario
CA	+4843-09434	America/Rainy_River	Central Time - Rainy River & Fort Frances, Ontario
CA	+5024-10439	America/Regina	Central Standard Time - Saskatchewan - most locations
CA	+5017-10750	America/Swift_Current	Central Standard Time - Saskatchewan - midwest
CA	+5333-11328	America/Edmonton	Mountain Time - Alberta, east British Columbia & west Saskatchewan
CA	+690650-1050310	America/Cambridge_Bay	Mountain Time - west Nunavut
CA	+6227-11421	America/Yellowknife	Mountain Time - central Northwest Territories
CA	+682059-1334300	America/Inuvik	Mountain Time - west Northwest Territories
CA	+5946-12014	America/Dawson_Creek	Mountain Standard Time - Dawson Creek & Fort Saint John, British Columbia
CA	+4916-12307	America/Vancouver	Pacific Time - west British Columbia
CA	+6043-13503	America/Whitehorse	Pacific Time - south Yukon
CA	+6404-13925	America/Dawson	Pacific Time - north Yukon
CC	-1210+09655	Indian/Cocos
CD	-0418+01518	Africa/Kinshasa	west Dem. Rep. of Congo
CD	-1140+02728	Africa/Lubumbashi	east Dem. Rep. of Congo
CF	+0422+01835	Africa/Bangui
CG	-0416+01517	Africa/Brazzaville
CH	+4723+00832	Europe/Zurich
CI	+0519-00402	Africa/Abidjan
CK	-2114-15946	Pacific/Rarotonga
CL	-3327-07040	America/Santiago	most locations
CL	-2709-10926	Pacific/Easter	Easter Island & Sala y Gomez
CM	+0403+00942	Africa/Douala
CN	+3114+12128	Asia/Shanghai	east China - Beijing, Guangdong, Shanghai, etc.
CN	+4545+12641	Asia/Harbin	Heilongjiang (except Mohe), Jilin
CN	+2934+10635	Asia/Chongqing	central China - Sichuan, Yunnan, Guangxi, Shaanxi, Guizhou, etc.
CN	+4348+08735	Asia/Urumqi	most of Tibet & Xinjiang
CN	+3929+07559	Asia/Kashgar	west Tibet & Xinjiang
CO	+0436-07405	America/Bogota
CR	+0956-08405	America/Costa_Rica
CU	+2308-08222	America/Havana
CV	+1455-02331	Atlantic/Cape_Verde
CX	-1025+10543	Indian/Christmas
CY	+3510+03322	Asia/Nicosia
CZ	+5005+01426	Europe/Prague
DE	+5230+01322	Europe/Berlin
DJ	+1136+04309	Africa/Djibouti
DK	+5540+01235	Europe/Copenhagen
DM	+1518-06124	America/Dominica
DO	+1828-06954	America/Santo_Domingo
DZ	+3647+00303	Africa/Algiers
EC	-0210-07950	America/Guayaquil	mainland
EC	-0054-08936	Pacific/Galapagos	Galapagos Islands
EE	+5925+02445	Europe/Tallinn
EG	+3003+03115	Africa/Cairo
EH	+2709-01312	Africa/El_Aaiun
ER	+1520+03853	Africa/Asmara
ES	+4024-00341	Europe/Madrid	mainland
ES	+3553-00519	Africa/Ceuta	Ceuta & Melilla
ES	+2806-01524	Atlantic/Canary	Canary Islands
ET	+0902+03842	Africa/Addis_Ababa
FI	+6010+02458	Europe/Helsinki
FJ	-1808+17825	Pacific/Fiji
FK	-5142-05751	Atlantic/Stanley
FM	+0725+15147	Pacific/Truk	Truk (Chuuk) and Yap
FM	+0658+15813	Pacific/Ponape	Ponape (Pohnpei)
FM	+0519+16259	Pacific/Kosrae	Kosrae
FO	+6201-00646	Atlantic/Faroe
FR	+4852+00220	Europe/Paris
GA	+0023+00927	Africa/Libreville
GB	+513030-0000731	Europe/London
GD	+1203-06145	America/Grenada
GE	+4143+04449	Asia/Tbilisi
GF	+0456-05220	America/Cayenne
GG	+4927-00232	Europe/Guernsey
GH	+0533-00013	Africa/Accra
GI	+3608-00521	Europe/Gibraltar
GL	+6411-05144	America/Godthab	most locations
GL	+7646-01840	America/Danmarkshavn	east coast, north of Scoresbysund
GL	+7029-02158	America/Scoresbysund	Scoresbysund / Ittoqqortoormiit
GL	+7634-06847	America/Thule	Thule / Pituffik
GM	+1328-01639	Africa/Banjul
GN	+0931-01343	Africa/Conakry
GP	+1614-06132	America/Guadeloupe
GQ	+0345+00847	Africa/Malabo
GR	+3758+02343	Europe/Athens
GS	-5416-03632	Atlantic/South_Georgia
GT	+1438-09031	America/Guatemala
GU	+1328+14445	Pacific/Guam
GW	+1151-01535	Africa/Bissau
GY	+0648-05810	America/Guyana
HK	+2217+11409	Asia/Hong_Kong
HN	+1406-08713	America/Tegucigalpa
HR	+4548+01558	Europe/Zagreb
HT	+1832-07220	America/Port-au-Prince
HU	+4730+01905	Europe/Budapest
ID	-0610+10648	Asia/Jakarta	Java & Sumatra
ID	-0002+10920	Asia/Pontianak	west & central Borneo
ID	-0507+11924	Asia/Makassar	east & south Borneo, Celebes, Bali, Nusa Tengarra, west Timor
ID	-0232+14042	Asia/Jayapura	Irian Jaya & the Moluccas
IE	+5320-00615	Europe/Dublin
IL	+3146+03514	Asia/Jerusalem
IM	+5409-00428	Europe/Isle_of_Man
IN	+2232+08822	Asia/Kolkata
IO	-0720+07225	Indian/Chagos
IQ	+3321+04425	Asia/Baghdad
IR	+3540+05126	Asia/Tehran
IS	+6409-02151	Atlantic/Reykjavik
IT	+4154+01229	Europe/Rome
JE	+4912-00207	Europe/Jersey
JM	+1800-07648	America/Jamaica
JO	+3157+03556	Asia/Amman
JP	+353916+1394441	Asia/Tokyo
KE	-0117+03649	Africa/Nairobi
KG	+4254+07436	Asia/Bishkek
KH	+1133+10455	Asia/Phnom_Penh
KI	+0125+17300	Pacific/Tarawa	Gilbert Islands
KI	-0308-17105	Pacific/Enderbury	Phoenix Islands
KI	+0152-15720	Pacific/Kiritimati	Line Islands
KM	-1141+04316	Indian/Comoro
KN	+1718-06243	America/St_Kitts
KP	+3901+12545	Asia/Pyongyang
KR	+3733+12658	Asia/Seoul
KW	+2920+04759	Asia/Kuwait
KY	+1918-08123	America/Cayman
KZ	+4315+07657	Asia/Almaty	most locations
KZ	+4448+06528	Asia/Qyzylorda	Qyzylorda (Kyzylorda, Kzyl-Orda)
KZ	+5017+05710	Asia/Aqtobe	Aqtobe (Aktobe)
KZ	+4431+05016	Asia/Aqtau	Atyrau (Atirau, Gur'yev), Mangghystau (Mankistau)
KZ	+5113+05121	Asia/Oral	West Kazakhstan
LA	+1758+10236	Asia/Vientiane
LB	+3353+03530	Asia/Beirut
LC	+1401-06100	America/St_Lucia
LI	+4709+00931	Europe/Vaduz
LK	+0656+07951	Asia/Colombo
LR	+0618-01047	Africa/Monrovia
LS	-2928+02730	Africa/Maseru
LT	+5441+02519	Europe/Vilnius
LU	+4936+00609	Europe/Luxembourg
LV	+5657+02406	Europe/Riga
LY	+3254+01311	Africa/Tripoli
MA	+3339-00735	Africa/Casablanca
MC	+4342+00723	Europe/Monaco
MD	+4700+02850	Europe/Chisinau
ME	+4226+01916	Europe/Podgorica
MF	+1804-06305	America/Marigot
MG	-1855+04731	Indian/Antananarivo
MH	+0709+17112	Pacific/Majuro	most locations
MH	+0905+16720	Pacific/Kwajalein	Kwajalein
MK	+4159+02126	Europe/Skopje
ML	+1239-00800	Africa/Bamako
MM	+1647+09610	Asia/Rangoon
MN	+4755+10653	Asia/Ulaanbaatar	most locations
MN	+4801+09139	Asia/Hovd	Bayan-Olgiy, Govi-Altai, Hovd, Uvs, Zavkhan
MN	+4804+11430	Asia/Choibalsan	Dornod, Sukhbaatar
MO	+2214+11335	Asia/Macau
MP	+1512+14545	Pacific/Saipan
MQ	+1436-06105	America/Martinique
MR	+1806-01557	Africa/Nouakchott
MS	+1643-06213	America/Montserrat
MT	+3554+01431	Europe/Malta
MU	-2010+05730	Indian/Mauritius
MV	+0410+07330	Indian/Maldives
MW	-1547+03500	Africa/Blantyre
MX	+1924-09909	America/Mexico_City	Central Time - most locations
MX	+2105-08646	America/Cancun	Central Time - Quintana Roo
MX	+2058-08937	America/Merida	Central Time - Campeche, Yucatan
MX	+2540-10019	America/Monterrey	Central Time - Coahuila, Durango, Nuevo Leon, Tamaulipas
MX	+2313-10625	America/Mazatlan	Mountain Time - S Baja, Nayarit, Sinaloa
MX	+2838-10605	America/Chihuahua	Mountain Time - Chihuahua
MX	+2904-11058	America/Hermosillo	Mountain Standard Time - Sonora
MX	+3232-11701	America/Tijuana	Pacific Time
MY	+0310+10142	Asia/Kuala_Lumpur	peninsular Malaysia
MY	+0133+11020	Asia/Kuching	Sabah & Sarawak
MZ	-2558+03235	Africa/Maputo
NA	-2234+01706	Africa/Windhoek
NC	-2216+16627	Pacific/Noumea
NE	+1331+00207	Africa/Niamey
NF	-2903+16758	Pacific/Norfolk
NG	+0627+00324	Africa/Lagos
NI	+1209-08617	America/Managua
NL	+5222+00454	Europe/Amsterdam
NO	+5955+01045	Europe/Oslo
NP	+2743+08519	Asia/Kathmandu
NR	-0031+16655	Pacific/Nauru
NU	-1901-16955	Pacific/Niue
NZ	-3652+17446	Pacific/Auckland	most locations
NZ	-4357-17633	Pacific/Chatham	Chatham Islands
OM	+2336+05835	Asia/Muscat
PA	+0858-07932	America/Panama
PE	-1203-07703	America/Lima
PF	-1732-14934	Pacific/Tahiti	Society Islands
PF	-0900-13930	Pacific/Marquesas	Marquesas Islands
PF	-2308-13457	Pacific/Gambier	Gambier Islands
PG	-0930+14710	Pacific/Port_Moresby
PH	+1435+12100	Asia/Manila
PK	+2452+06703	Asia/Karachi
PL	+5215+02100	Europe/Warsaw
PM	+4703-05620	America/Miquelon
PN	-2504-13005	Pacific/Pitcairn
PR	+182806-0660622	America/Puerto_Rico
PS	+3130+03428	Asia/Gaza
PT	+3843-00908	Europe/Lisbon	mainland
PT	+3238-01654	Atlantic/Madeira	Madeira Islands
PT	+3744-02540	Atlantic/Azores	Azores
PW	+0720+13429	Pacific/Palau
PY	-2516-05740	America/Asuncion
QA	+2517+05132	Asia/Qatar
RE	-2052+05528	Indian/Reunion
RO	+4426+02606	Europe/Bucharest
RS	+4450+02030	Europe/Belgrade
RU	+5443+02030	Europe/Kaliningrad	Moscow-01 - Kaliningrad
RU	+5545+03735	Europe/Moscow	Moscow+00 - west Russia
RU	+4844+04425	Europe/Volgograd	Moscow+00 - Caspian Sea
RU	+5312+05009	Europe/Samara	Moscow+01 - Samara, Udmurtia
RU	+5651+06036	Asia/Yekaterinburg	Moscow+02 - Urals
RU	+5500+07324	Asia/Omsk	Moscow+03 - west Siberia
RU	+5502+08255	Asia/Novosibirsk	Moscow+03 - Novosibirsk
RU	+5601+09250	Asia/Krasnoyarsk	Moscow+04 - Yenisei River
RU	+5216+10420	Asia/Irkutsk	Moscow+05 - Lake Baikal
RU	+6200+12940	Asia/Yakutsk	Moscow+06 - Lena River
RU	+4310+13156	Asia/Vladivostok	Moscow+07 - Amur River
RU	+4658+14242	Asia/Sakhalin	Moscow+07 - Sakhalin Island
RU	+5934+15048	Asia/Magadan	Moscow+08 - Magadan
RU	+5301+15839	Asia/Kamchatka	Moscow+09 - Kamchatka
RU	+6445+17729	Asia/Anadyr	Moscow+10 - Bering Sea
RW	-0157+03004	Africa/Kigali
SA	+2438+04643	Asia/Riyadh
SB	-0932+16012	Pacific/Guadalcanal
SC	-0440+05528	Indian/Mahe
SD	+1536+03232	Africa/Khartoum
SE	+5920+01803	Europe/Stockholm
SG	+0117+10351	Asia/Singapore
SH	-1555-00542	Atlantic/St_Helena
SI	+4603+01431	Europe/Ljubljana
SJ	+7800+01600	Arctic/Longyearbyen
SK	+4809+01707	Europe/Bratislava
SL	+0830-01315	Africa/Freetown
SM	+4355+01228	Europe/San_Marino
SN	+1440-01726	Africa/Dakar
SO	+0204+04522	Africa/Mogadishu
SR	+0550-05510	America/Paramaribo
ST	+0020+00644	Africa/Sao_Tome
SV	+1342-08912	America/El_Salvador
SY	+3330+03618	Asia/Damascus
SZ	-2618+03106	Africa/Mbabane
TC	+2128-07108	America/Grand_Turk
TD	+1207+01503	Africa/Ndjamena
TF	-492110+0701303	Indian/Kerguelen
TG	+0608+00113	Africa/Lome
TH	+1345+10031	Asia/Bangkok
TJ	+3835+06848	Asia/Dushanbe
TK	-0922-17114	Pacific/Fakaofo
TL	-0833+12535	Asia/Dili
TM	+3757+05823	Asia/Ashgabat
TN	+3648+01011	Africa/Tunis
TO	-2110-17510	Pacific/Tongatapu
TR	+4101+02858	Europe/Istanbul
TT	+1039-06131	America/Port_of_Spain
TV	-0831+17913	Pacific/Funafuti
TW	+2503+12130	Asia/Taipei
TZ	-0648+03917	Africa/Dar_es_Salaam
UA	+5026+03031	Europe/Kiev	most locations
UA	+4837+02218	Europe/Uzhgorod	Ruthenia
UA	+4750+03510	Europe/Zaporozhye	Zaporozh'ye, E Lugansk / Zaporizhia, E Luhansk
UA	+4457+03406	Europe/Simferopol	central Crimea
UG	+0019+03225	Africa/Kampala
UM	+1645-16931	Pacific/Johnston	Johnston Atoll
UM	+2813-17722	Pacific/Midway	Midway Islands
UM	+1917+16637	Pacific/Wake	Wake Island
US	+404251-0740023	America/New_York	Eastern Time
US	+421953-0830245	America/Detroit	Eastern Time - Michigan - most locations
US	+381515-0854534	America/Kentucky/Louisville	Eastern Time - Kentucky - Louisville area
US	+364947-0845057	America/Kentucky/Monticello	Eastern Time - Kentucky - Wayne County
US	+394606-0860929	America/Indiana/Indianapolis	Eastern Time - Indiana - most locations
US	+384038-0873143	America/Indiana/Vincennes	Eastern Time - Indiana - Daviess, Dubois, Knox & Martin Counties
US	+410305-0863611	America/Indiana/Winamac	Eastern Time - Indiana - Pulaski County
US	+382232-0862041	America/Indiana/Marengo	Eastern Time - Indiana - Crawford County
US	+382931-0871643	America/Indiana/Petersburg	Eastern Time - Indiana - Pike County
US	+384452-0850402	America/Indiana/Vevay	Eastern Time - Indiana - Switzerland County
US	+415100-0873900	America/Chicago	Central Time
US	+375711-0864541	America/Indiana/Tell_City	Central Time - Indiana - Perry County
US	+411745-0863730	America/Indiana/Knox	Central Time - Indiana - Starke County
US	+450628-0873651	America/Menominee	Central Time - Michigan - Dickinson, Gogebic, Iron & Menominee Counties
US	+470659-1011757	America/North_Dakota/Center	Central Time - North Dakota - Oliver County
US	+465042-1012439	America/North_Dakota/New_Salem	Central Time - North Dakota - Morton County (except Mandan area)
US	+394421-1045903	America/Denver	Mountain Time
US	+433649-1161209	America/Boise	Mountain Time - south Idaho & east Oregon
US	+364708-1084111	America/Shiprock	Mountain Time - Navajo
US	+332654-1120424	America/Phoenix	Mountain Standard Time - Arizona
US	+340308-1181434	America/Los_Angeles	Pacific Time
US	+611305-1495401	America/Anchorage	Alaska Time
US	+581807-1342511	America/Juneau	Alaska Time - Alaska panhandle
US	+593249-1394338	America/Yakutat	Alaska Time - Alaska panhandle neck
US	+643004-1652423	America/Nome	Alaska Time - west Alaska
US	+515248-1763929	America/Adak	Aleutian Islands
US	+211825-1575130	Pacific/Honolulu	Hawaii
UY	-3453-05611	America/Montevideo
UZ	+3940+06648	Asia/Samarkand	west Uzbekistan
UZ	+4120+06918	Asia/Tashkent	east Uzbekistan
VA	+415408+0122711	Europe/Vatican
VC	+1309-06114	America/St_Vincent
VE	+1030-06656	America/Caracas
VG	+1827-06437	America/Tortola
VI	+1821-06456	America/St_Thomas
VN	+1045+10640	Asia/Ho_Chi_Minh
VU	-1740+16825	Pacific/Efate
WF	-1318-17610	Pacific/Wallis
WS	-1350-17144	Pacific/Apia
YE	+1245+04512	Asia/Aden
YT	-1247+04514	Indian/Mayotte
ZA	-2615+02800	Africa/Johannesburg
ZM	-1525+02817	Africa/Lusaka
ZW	-1750+03103	Africa/Harare



#endif
*/