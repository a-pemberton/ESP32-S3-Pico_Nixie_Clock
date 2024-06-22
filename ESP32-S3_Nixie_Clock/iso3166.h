// A header file for country codes accodring to ISO 3166 and has been
// adapted from GNU glibc sources (iso3166.tab)
/*
# @(#)iso3166.tab	8.6
# This file is in the public domain, so clarified as of
# 2009-05-17 by Arthur David Olson.
# ISO 3166 alpha-2 country codes
#
# From Paul Eggert (2006-09-27):
#
# This file contains a table with the following columns:
# 1.  ISO 3166-1 alpha-2 country code, current as of
#     ISO 3166-1 Newsletter VI-1 (2007-09-21).  See:
#     <a href="http://www.iso.org/iso/en/prods-services/iso3166ma/index.html">
#     ISO 3166 Maintenance agency (ISO 3166/MA)
#     </a>.
# 2.  The usual English name for the country,
#     chosen so that alphabetic sorting of subsets produces helpful lists.
#     This is not the same as the English name in the ISO 3166 tables.
#
# Columns are separated by a single tab.
# The table is sorted by country code.
#
*/
/*
#ifndef __iso3166_H__
#define __iso3166_H__

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


typedef struct {
  const char* country_Name;
  const char* country_Continent;
  const char* country_TZ_Region;
  const char* country_NTP_value;
  int UN_Numeric_Code;
  wifi_country_t country_Code;
}	country_Database_t;

/*
Notes

The full names of countries and areas in ISO 3166 often but not always match these official state names.
The ISO 3166 country name Antarctica comprises the continent of Antarctica and all land and ice shelves south of the 60th parallel south.
The ISO 3166 country name Australia includes the Ashmore and Cartier Islands and the Coral Sea Islands.
Although the country code top-level domain .bq is reserved for the Caribbean Netherlands, these islands use the Netherlands country code top-level domain .nl instead.
The country code top-level domain .bv has not been implemented.
Both the International Organization for Standardization (ISO) and the United Nations (UN) use the country name Brunei Darussalam for Brunei.
Cabo Verde was previously known as Cape Verde.
The International Organization for Standardization (ISO) uses the United Nations (UN) country name The Congo for the Republic of the Congo.
Côte d'Ivoire was previously known as Ivory Coast.
Czechia was previously known by its state name Czech Republic.
Eswatini was previously known as Swaziland.
The International Organization for Standardization (ISO) uses the country name The Falkland Islands [Malvinas] for the Falkland Islands.
The ISO 3166 country name France includes Clipperton Island.
The ISO 3166 country name The French Southern Territories comprises all of the French Southern and Antarctic Lands except Adélie Land which is included in the ISO 3166 country name Antarctica.
The Holy See governs and represents the Vatican City State.
Both the International Organization for Standardization (ISO) and the United Nations (UN) use the full state name The Democratic People's Republic of Korea for North Korea.
Both the International Organization for Standardization (ISO) and the United Nations (UN) use the full state name The Republic of Korea for South Korea.
Both the International Organization for Standardization (ISO) and the United Nations (UN) use the full state name The Lao People's Democratic Republic for Laos.
Macao may be spelt either Macao or Macau.
The International Organization for Standardization (ISO) used The former Yugoslav Republic of Macedonia as the country name prior to February 2019 when the naming dispute with Greece was settled.
Myanmar was previously known as Burma.
The International Organization for Standardization (ISO) uses the United Nations (UN) country name Pitcairn for the Pitcairn, Henderson, Ducie and Oeno Islands.
Both the International Organization for Standardization (ISO) and the United Nations (UN) use the full state name The Russian Federation for Russia.
The country code top-level domain .sj has not been implemented.
The Syrian Arab Republic is also known by its common country name Syria.
The International Organization for Standardization (ISO) uses the country name Taiwan (Province of China) for Taiwan.
The Republic of China controls Taiwan. The People's Republic of China claims Taiwan as its Taiwan Province. In deference to the People's Republic of China, the United Nations refers to Taiwan as Taiwan, Province of China.
Timor-Leste was previously known as East Timor.
Türkiye was previously known as Turkey.
Although the country code top-level domain .gb is reserved for the United Kingdom, the country uses the .uk country code top-level domain instead.
The ISO 3166 country name The United States Minor Outlying Islands comprises Baker Island, Howland Island, Jarvis Island, Johnston Atoll, Kingman Reef, Midway Atoll, Navassa Island, Palmyra Atoll, and Wake Island.
The country code top-level domain .um has not been implemented.
The International Organization for Standardization (ISO) uses the United Nations (UN) country name Viet Nam for Vietnam.
The International Organization for Standardization (ISO) uses the country name Virgin Islands (British) for the Virgin Islands of the United Kingdom.
The International Organization for Standardization (ISO) uses the country name Virgin Islands (U.S.) for the Virgin Islands of the United States.
The International Organization for Standardization (ISO) has designated Western Sahara as the provisional country name for the region of the Maghreb claimed by both the Kingdom of Morocco and the Sahrawi Arab Democratic Republic.
Both the Kingdom of Morocco and the Sahrawi Arab Democratic Republic claim the region known as Western Sahara. Morocco currently (2018) controls most of the coastal region while the Sahrawis control the interior.
*/
country_Database_t select_Country = {
  .country_Name = "Afghanistan";
  .country_Continent = "Asia",
  .country_TZ_Region = "Kabul";
  .country_NTP_value = "<+0430>-4:30";
  .UN_Numeric_Code = 004;
  .country_Code.cc = "AF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Åland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Helsinki";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 248;
  .country_Code.cc = "AX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Albania";
  .country_Continent = "Europe";
  .country_TZ_Region = "Tirane";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 008;
  .country_Code.cc = "AL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Algeria";
  .country_Continent = "Africa";
  .country_TZ_Region = "Algiers";
  .country_NTP_value = "CET-1";
  .UN_Numeric_Code = 012;
  .country_Code.cc = "DZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "American Samoa";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Midway";
  .country_NTP_value = "SST11";
  .UN_Numeric_Code = 581;
  .country_Code.cc = "UM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "American Samoa";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Pago_Pago";
  .country_NTP_value = "SST11";
  .UN_Numeric_Code = 016;
  .country_Code.cc = "AS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Andorra";
  .country_Continent = "Europe";
  .country_TZ_Region = "Andorra";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 020;
  .country_Code.cc = "AD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Angola";
  .country_Continent = "Africa";
  .country_TZ_Region = "Luanda";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 024;
  .country_Code.cc = "AO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Anguilla";
  .country_Continent = "America";
  .country_TZ_Region = "Anguilla";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 660;
  .country_Code.cc = "AI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Casey";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Davis";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "DumontDUrville";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Macquarie";
  .country_NTP_value = "AEST-10AEDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Mawson";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "McMurdo";
  .country_NTP_value = "NZST-12NZDT,M9.5.0,M4.1.0/3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Palmer";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Rothera";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Syowa";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Troll";
  .country_NTP_value = "<+00>0<+02>-2,M3.5.0/1,M10.5.0/3";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antarctica";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "Vostok";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 010;
  .country_Code.cc = "AQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Arctic";
  .country_Continent = "Arctic";
  .country_TZ_Region = "Longyearbyen"; // Spitzbergen, Norway
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 578;
  .country_Code.cc = "NO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Antigua and Barbuda";
  .country_Continent = "America";
  .country_TZ_Region = "Antigua";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 028;
  .country_Code.cc = "AG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Buenos Aires";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Catamarca";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Cordoba";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Jujuy";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "La_Rioja";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Mendoza";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Rio Gallegos";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Salta";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "San Juan";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "San Luis";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Tucuman";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Argentina";
  .country_Continent = "America";
  .country_TZ_Region = "Ushuaia";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 032;
  .country_Code.cc = "AR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Armenia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Yerevan";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 051;
  .country_Code.cc = "AM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Aruba";
  .country_Continent = "America";
  .country_TZ_Region = "Aruba";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 533;
  .country_Code.cc = "AW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Adelaide";
  .country_NTP_value = "ACST-9:30ACDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Brisbane";
  .country_NTP_value = "AEST-10";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Broken Hill";
  .country_NTP_value = "ACST-9:30ACDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Currie";
  .country_NTP_value = "AEST-10AEDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Darwin";
  .country_NTP_value = "ACST-9:30";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Eucla";
  .country_NTP_value = "<+0845>-8:45";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Hobart";
  .country_NTP_value = "AEST-10AEDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Lindeman";
  .country_NTP_value = "AEST-10";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Lord Howe";
  .country_NTP_value = "<+1030>-10:30<+11>-11,M10.1.0,M4.1.0";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Melbourne";
  .country_NTP_value = "AEST-10AEDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Perth";
  .country_NTP_value = "AWST-8";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Australia";
  .country_Continent = "Australia";
  .country_TZ_Region = "Sydney";
  .country_NTP_value = "AEST-10AEDT,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 036;
  .country_Code.cc = "AU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Austria";
  .country_Continent = "Europe";
  .country_TZ_Region = "Vienna";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 040;
  .country_Code.cc = "AT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Azerbaijan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Baku";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 031;
  .country_Code.cc = "AZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "The Bahamas";
  .country_Continent = "America";
  .country_TZ_Region = "Nassau";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 044;
  .country_Code.cc = "BS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bahrain";
  .country_Continent = "Asia";
  .country_TZ_Region = "Bahrain";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 048;
  .country_Code.cc = "BH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bangladesh";
  .country_Continent = "Asia";
  .country_TZ_Region = "Dhaka";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 050;
  .country_Code.cc = "BD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Barbados";
  .country_Continent = "America";
  .country_TZ_Region = "Barbados";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 052;
  .country_Code.cc = "BB";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Belarus";
  .country_Continent = "Europe";
  .country_TZ_Region = "Minsk";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 112;
  .country_Code.cc = "BY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Belgium";
  .country_Continent = "Europe";
  .country_TZ_Region = "Brussels";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 056;
  .country_Code.cc = "BE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Belize";
  .country_Continent = "America";
  .country_TZ_Region = "Belize";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 084;
  .country_Code.cc = "BZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Benin";
  .country_Continent = "Africa";
  .country_TZ_Region = "Porto-Novo";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 204;
  .country_Code.cc = "BJ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bermuda";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Bermuda";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 060;
  .country_Code.cc = "BM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bhutan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Thimphu";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 064;
  .country_Code.cc = "BT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bolivia";
  .country_Continent = "America";
  .country_TZ_Region = "La Paz";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 068;
  .country_Code.cc = "BO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bonaire, Sint Eustatius and Saba";
  .country_Continent = "America";
  .country_TZ_Region = "Kralendijk";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 535;
  .country_Code.cc = "NL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bosnia and Herzegovina";
  .country_Continent = "Europe";
  .country_TZ_Region = "Sarajevo";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 070;
  .country_Code.cc = "BA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Botswana";
  .country_Continent = "Africa";
  .country_TZ_Region = "Gaborone";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 072;
  .country_Code.cc = "BW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Araguaina";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Bahia";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Belem";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Boa_Vista";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Campo_Grande";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Cuiaba";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Eirunepe";
  .country_NTP_value = "<-05>5";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Fortaleza";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Maceio";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Manaus";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Noronha";
  .country_NTP_value = "<-02>2";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Porto_Velho";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Recife";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Rio_Branco";
  .country_NTP_value = "<-05>5";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Santarem";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Brazil";
  .country_Continent = "America";
  .country_TZ_Region = "Sao Paulo";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 076;
  .country_Code.cc = "BR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "British Indian Ocean Territory";
  .country_Continent = "Indian";
  .country_TZ_Region = "Chagos";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 086;
  .country_Code.cc = "IO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}


country_Database_t select_Country = {
  .country_Name = "Brunei";
  .country_Continent = "Asia";
  .country_TZ_Region = "Brunei";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 096;
  .country_Code.cc = "BN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bulgaria";
  .country_Continent = "Europe";
  .country_TZ_Region = "Sofia";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 100;
  .country_Code.cc = "BG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Burkina Faso";
  .country_Continent = "Africa";
  .country_TZ_Region = "Ouagadougou";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 854;
  .country_Code.cc = "BF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Burundi";
  .country_Continent = "Africa";
  .country_TZ_Region = "Bujumbura";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 108;
  .country_Code.cc = "BI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cape Verde";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Cape Verde";
  .country_NTP_value = "<-01>1";
  .UN_Numeric_Code = 132;
  .country_Code.cc = "CV";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cambodia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Phnom Penh";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 116;
  .country_Code.cc = "KH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cameroon";
  .country_Continent = "Africa";
  .country_TZ_Region = "Douala";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 120;
  .country_Code.cc = "CM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Atikokan";
  .country_NTP_value = "EST5";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Blanc-Sablon";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Cambridge_Bay";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Creston";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Dawson";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Dawson Creek";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Edmonton";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Fort_Nelson";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Goose_Bay";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Glace_Bay";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Halifax";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Inuvik";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Iqaluit";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Moncton";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Montreal";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Nipigon";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Pangnirtung";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Rainy River";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Rankin Inlet";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Regina";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Resolute";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "St_Johns";
  .country_NTP_value = "NST3:30NDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Swift Current";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Thunder Bay";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Toronto";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Vancouver";
  .country_NTP_value = "PST8PDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Whitehorse";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Winnipeg";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Canada";
  .country_Continent = "America";
  .country_TZ_Region = "Yellowknife";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 124;
  .country_Code.cc = "CA";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cayman Islands";
  .country_Continent = "America";
  .country_TZ_Region = "Cayman";
  .country_NTP_value = "EST5";
  .UN_Numeric_Code = 136;
  .country_Code.cc = "KY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Chad";
  .country_Continent = "Africa";
  .country_TZ_Region = "Bangui";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 140;
  .country_Code.cc = "CF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Central African Republic";
  .country_Continent = "Africa";
  .country_TZ_Region = "Ndjamena";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 148;
  .country_Code.cc = "TD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Chile";
  .country_Continent = "America";
  .country_TZ_Region = "Punta_Arenas";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 152;
  .country_Code.cc = "CL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Chile";
  .country_Continent = "America";
  .country_TZ_Region = "Santiago";
  .country_NTP_value = "<-04>4<-03>,M9.1.6/24,M4.1.6/24";
  .UN_Numeric_Code = 152;
  .country_Code.cc = "CL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Chile";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Easter";
  .country_NTP_value = "<-06>6<-05>,M9.1.6/22,M4.1.6/22";
  .UN_Numeric_Code = 152;
  .country_Code.cc = "CL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "China";
  .country_Continent = "Asia";
  .country_TZ_Region = "Khandyga";
  .country_NTP_value = "<+09>-9";
  .UN_Numeric_Code = 156;
  .country_Code.cc = "CN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "China";
  .country_Continent = "Asia";
  .country_TZ_Region = "Shanghai";
  .country_NTP_value = "CST-8";
  .UN_Numeric_Code = 156;
  .country_Code.cc = "CN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "China";
  .country_Continent = "Asia";
  .country_TZ_Region = "Urumqi";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 156;
  .country_Code.cc = "CN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Christmas Island";
  .country_Continent = "Indian";
  .country_TZ_Region = "Christmas";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 162;
  .country_Code.cc = "CX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cocos (Keeling) Islands";
  .country_Continent = "Indian";
  .country_TZ_Region = "Cocos";
  .country_NTP_value = "<+0630>-6:30";
  .UN_Numeric_Code = 166;
  .country_Code.cc = "CC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Colombia";
  .country_Continent = "America";
  .country_TZ_Region = "Bogota";
  .country_NTP_value = "<-05>5";
  .UN_Numeric_Code = 170;
  .country_Code.cc = "CO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Comoros";
  .country_Continent = "Indian";
  .country_TZ_Region = "Comoro";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 174;
  .country_Code.cc = "KM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Democratic Republic of the Congo";
  .country_Continent = "Africa";
  .country_TZ_Region = "Kinshasa";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 180;
  .country_Code.cc = "CD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Democratic Republic of the Congo";
  .country_Continent = "Africa";
  .country_TZ_Region = "Lubumbashi";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 180;
  .country_Code.cc = "CD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Republic of the Congo";
  .country_Continent = "Africa";
  .country_TZ_Region = "Brazzaville";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 178;
  .country_Code.cc = "CG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cook Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Rarotonga";
  .country_NTP_value = "<-10>10";
  .UN_Numeric_Code = 184;
  .country_Code.cc = "CK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ivory Coast";
  .country_Continent = "Africa";
  .country_TZ_Region = "Abidjan";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 384;
  .country_Code.cc = "CI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Croatia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Zagreb";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 191;
  .country_Code.cc = "HR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cuba";
  .country_Continent = "America";
  .country_TZ_Region = "Havana";
  .country_NTP_value = "CST5CDT,M3.2.0/0,M11.1.0/1";
  .UN_Numeric_Code = 192;
  .country_Code.cc = "CU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Curaçao";
  .country_Continent = "America";
  .country_TZ_Region = "Curacao";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 531;
  .country_Code.cc = "CW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cyprus";
  .country_Continent = "Asia";
  .country_TZ_Region = "Nicosia";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 196;
  .country_Code.cc = "CY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Cyprus";
  .country_Continent = "Asia";
  .country_TZ_Region = "Famagusta";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 196;
  .country_Code.cc = "CY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Czech Republic";
  .country_Continent = "Europe";
  .country_TZ_Region = "Prague";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 203;
  .country_Code.cc = "CZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Denmark";
  .country_Continent = "Europe";
  .country_TZ_Region = "Copenhagen";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 208;
  .country_Code.cc = "DK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Djibouti";
  .country_Continent = "Africa";
  .country_TZ_Region = "Djibouti";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 262;
  .country_Code.cc = "DJ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Dominica";
  .country_Continent = "America";
  .country_TZ_Region = "Dominica";
  .country_NTP_value = AST4";
  .UN_Numeric_Code = 212;
  .country_Code.cc = "DM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Dominican Republic";
  .country_Continent = "America";
  .country_TZ_Region = "Santo_Domingo";
  .country_NTP_value = AST4";
  .UN_Numeric_Code = 214;
  .country_Code.cc = "DO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ecuador";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Galapagos";
  .country_NTP_value = "<-06>6";
  .UN_Numeric_Code = 218;
  .country_Code.cc = "EC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ecuador";
  .country_Continent = "America";
  .country_TZ_Region = "Guayaquil";
  .country_NTP_value = "<-05>5";
  .UN_Numeric_Code = 218;
  .country_Code.cc = "EC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Egypt";
  .country_Continent = "Africa";
  .country_TZ_Region = "Cairo";
  .country_NTP_value = "EET-2EEST,M4.5.5/0,M10.5.4/24";
  .UN_Numeric_Code = 818;
  .country_Code.cc = "EG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "El Salvador";
  .country_Continent = "America";
  .country_TZ_Region = "El_Salvador";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 222;
  .country_Code.cc = "SV";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Equatorial Guinea";
  .country_Continent = "Africa";
  .country_TZ_Region = "Malabo";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 226;
  .country_Code.cc = "GQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Eritrea";
  .country_Continent = "Africa";
  .country_TZ_Region = "Asmara";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 232;
  .country_Code.cc = "ER";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Estonia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Tallinn";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 233;
  .country_Code.cc = "EE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Eswatini";
  .country_Continent = "Africa";
  .country_TZ_Region = "Mbabane";
  .country_NTP_value = "SAST-2";
  .UN_Numeric_Code = 748;
  .country_Code.cc = "SZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ethiopia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Addis_Ababa";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 231;
  .country_Code.cc = "ET";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Falkland Islands";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Stanley";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 238;
  .country_Code.cc = "FK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Faroe Islands";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Faroe";
  .country_NTP_value = "WET0WEST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 234;
  .country_Code.cc = "FO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Fiji";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Fiji";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 242;
  .country_Code.cc = "FJ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Finland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Helsinki";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 246;
  .country_Code.cc = "FI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Finland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Mariehamn"; // Åland Islands
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 248;
  .country_Code.cc = "AX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "France";
  .country_Continent = "Europe";
  .country_TZ_Region = "Paris";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 250;
  .country_Code.cc = "FR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "French Guiana";
  .country_Continent = "America";
  .country_TZ_Region = "Cayenne";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 254;
  .country_Code.cc = "GF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "French Polynesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Gambier";
  .country_NTP_value = "<-09>9";
  .UN_Numeric_Code = 258;
  .country_Code.cc = "PF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "French Polynesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Marquesas";
  .country_NTP_value = "<-0930>9:30";
  .UN_Numeric_Code = 258;
  .country_Code.cc = "PF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "French Polynesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Tahiti";
  .country_NTP_value = "<-10>10";
  .UN_Numeric_Code = 258;
  .country_Code.cc = "PF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "French Southern and Antarctic Lands";
  .country_Continent = "Antarctica";
  .country_TZ_Region = "DumontDUrville";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 260;
  .country_Code.cc = "TF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}
"/",
country_Database_t select_Country = {
  .country_Name = "French Southern and Antarctic Lands";
  .country_Continent = "Indian";
  .country_TZ_Region = "Kerguelen";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 260;
  .country_Code.cc = "TF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Gabon";
  .country_Continent = "Africa";
  .country_TZ_Region = "Libreville";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 266;
  .country_Code.cc = "GA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "The Gambia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Banjul";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 270;
  .country_Code.cc = "GM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Georgia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Tbilisi";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 268;
  .country_Code.cc = "GE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Germany";
  .country_Continent = "Europe";
  .country_TZ_Region = "Berlin";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 276;
  .country_Code.cc = "DE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ghana";
  .country_Continent = "Africa";
  .country_TZ_Region = "Accra";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 288;
  .country_Code.cc = "GH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Gibraltar";
  .country_Continent = "Europe";
  .country_TZ_Region = "Gibraltar";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 292;
  .country_Code.cc = "GI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greece";
  .country_Continent = "Europe";
  .country_TZ_Region = "Athens";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 300;
  .country_Code.cc = "GR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greenland";
  .country_Continent = "America";
  .country_TZ_Region = "Danmarkshavn";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 304;
  .country_Code.cc = "GL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greenland";
  .country_Continent = "America";
  .country_TZ_Region = "Godthab";
  .country_NTP_value = "<-02>2<-01>,M3.5.0/-1,M10.5.0/0";
  .UN_Numeric_Code = 304;
  .country_Code.cc = "GL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greenland";
  .country_Continent = "America";
  .country_TZ_Region = "Nuuk";
  .country_NTP_value = "<-02>2<-01>,M3.5.0/-1,M10.5.0/0";
  .UN_Numeric_Code = 304;
  .country_Code.cc = "GL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greenland";
  .country_Continent = "America";
  .country_TZ_Region = "Scoresbysund";
  .country_NTP_value = "<-01>1<+00>,M3.5.0/0,M10.5.0/1";
  .UN_Numeric_Code = 304;
  .country_Code.cc = "GL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Greenland";
  .country_Continent = "America";
  .country_TZ_Region = "Thule";
  .country_NTP_value = "AST4ADT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 304;
  .country_Code.cc = "GL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Grenada";
  .country_Continent = "America";
  .country_TZ_Region = "Grenada";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 308;
  .country_Code.cc = "GD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guadeloupe";
  .country_Continent = "America";
  .country_TZ_Region = "Guadeloupe";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 312;
  .country_Code.cc = "GP";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guam";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Guam";
  .country_NTP_value = "ChST-10";
  .UN_Numeric_Code = 316;
  .country_Code.cc = "GU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guatemala";
  .country_Continent = "America";
  .country_TZ_Region = "Guatemala";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 320;
  .country_Code.cc = "GT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Bailiwick of Guernsey";
  .country_Continent = "Europe";
  .country_TZ_Region = "Guernsey";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 831;
  .country_Code.cc = "GG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guinea";
  .country_Continent = "Africa";
  .country_TZ_Region = "Conakry";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 324;
  .country_Code.cc = "GN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guinea-Bissau";
  .country_Continent = "Africa";
  .country_TZ_Region = "Bissau";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 624;
  .country_Code.cc = "GW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Guyana";
  .country_Continent = "America";
  .country_TZ_Region = "Guyana";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 328;
  .country_Code.cc = "GY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Haiti";
  .country_Continent = "America";
  .country_TZ_Region = "Port-au-Prince";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 332;
  .country_Code.cc = "HT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}
/*
country_Database_t select_Country = {
  .country_Name = "Heard Island and McDonald Islands";
  .country_Continent = "";
  .country_TZ_Region = "";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 334;
  .country_Code.cc = "HM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}
*/
country_Database_t select_Country = {
  .country_Name = "Holy See";
  .country_Continent = "Europe";
  .country_TZ_Region = "Vatican";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 336;
  .country_Code.cc = "VA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Honduras";
  .country_Continent = "America";
  .country_TZ_Region = "Tegucigalpa";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 340;
  .country_Code.cc = "HN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Hong Kong";
  .country_Continent = "Asia";
  .country_TZ_Region = "Hong_Kong";
  .country_NTP_value = "HKT-8";
  .UN_Numeric_Code = 344;
  .country_Code.cc = "HK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Hungary";
  .country_Continent = "Europe";
  .country_TZ_Region = "Budapest";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 348;
  .country_Code.cc = "HU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Iceland";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Reykjavik";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 352;
  .country_Code.cc = "IS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "India";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kolkata";
  .country_NTP_value = "IST-5:30";
  .UN_Numeric_Code = 356;
  .country_Code.cc = "IN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Indonesia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Jakarta";
  .country_NTP_value = "WIB-7";
  .UN_Numeric_Code = 356;
  .country_Code.cc = "ID";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Indonesia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Pontianak";
  .country_NTP_value = "WIB-7";
  .UN_Numeric_Code = 356;
  .country_Code.cc = "ID";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Indonesia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Jayapura";
  .country_NTP_value = "WIT-9";
  .UN_Numeric_Code = 356;
  .country_Code.cc = "ID";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Indonesia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Makassar";
  .country_NTP_value = "WITA-8";
  .UN_Numeric_Code = 356;
  .country_Code.cc = "ID";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Iran";
  .country_Continent = "Asia";
  .country_TZ_Region = "Tehran";
  .country_NTP_value = "<+0330>-3:30";
  .UN_Numeric_Code = 364;
  .country_Code.cc = "IR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Iraq";
  .country_Continent = "Asia";
  .country_TZ_Region = "Baghdad";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 368;
  .country_Code.cc = "IQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Republic of Ireland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Dublin";
  .country_NTP_value = "IST-1GMT0,M10.5.0,M3.5.0/1";
  .UN_Numeric_Code = 372;
  .country_Code.cc = "IE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Isle of Man";
  .country_Continent = "Europe";
  .country_TZ_Region = "Isle_of_Man";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 833;
  .country_Code.cc = "IM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Israel";
  .country_Continent = "Asia";
  .country_TZ_Region = "Jerusalem";
  .country_NTP_value = "IST-2IDT,M3.4.4/26,M10.5.0";
  .UN_Numeric_Code = 376;
  .country_Code.cc = "IL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Italy";
  .country_Continent = "Europe";
  .country_TZ_Region = "Rome";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 380;
  .country_Code.cc = "IT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Jamaica";
  .country_Continent = "America";
  .country_TZ_Region = "Jamaica";
  .country_NTP_value = "EST5";
  .UN_Numeric_Code = 388;
  .country_Code.cc = "JM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Japan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Tokyo";
  .country_NTP_value = "JST-9";
  .UN_Numeric_Code = 392;
  .country_Code.cc = "JP";
  .country_Code.schan = 1;
  .country_Code.nchan = 14;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Jersey";
  .country_Continent = "Europe";
  .country_TZ_Region = "Jersey";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 832;
  .country_Code.cc = "JE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Jordan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Amman";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 400;
  .country_Code.cc = "JO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Almaty";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Aqtau";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Aqtobe";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Atyrau";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Oral";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kazakhstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Qyzylorda";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 398;
  .country_Code.cc = "KZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kenya";
  .country_Continent = "Africa";
  .country_TZ_Region = "Nairobi";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 404;
  .country_Code.cc = "KE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kiribati";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Enderbury";
  .country_NTP_value = "<+13>-13";
  .UN_Numeric_Code = 296;
  .country_Code.cc = "KI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}
"Pacific/",
country_Database_t select_Country = {
  .country_Name = "Kiribati";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Kiritimati";
  .country_NTP_value = "<+14>-14";
  .UN_Numeric_Code = 296;
  .country_Code.cc = "KI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kiribati";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Tarawa";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 296;
  .country_Code.cc = "KI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "North Korea";
  .country_Continent = "Asia";
  .country_TZ_Region = "Pyongyang";
  .country_NTP_value = "KST-9";
  .UN_Numeric_Code = 408;
  .country_Code.cc = "KP";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "South Korea";
  .country_Continent = "Asia";
  .country_TZ_Region = "Seoul";
  .country_NTP_value = "KST-9";
  .UN_Numeric_Code = 410;
  .country_Code.cc = "KR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kuwait";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kuwait";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 414;
  .country_Code.cc = "KW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Kyrgyzstan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Bishkek";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 417;
  .country_Code.cc = "KG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Laos";
  .country_Continent = "Asia";
  .country_TZ_Region = "Vientiane";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 418;
  .country_Code.cc = "LA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Latvia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Riga";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 428;
  .country_Code.cc = "LV";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Lebanon";
  .country_Continent = "Asia";
  .country_TZ_Region = "Beirut";
  .country_NTP_value = "EET-2EEST,M3.5.0/0,M10.5.0/0";
  .UN_Numeric_Code = 422;
  .country_Code.cc = "LB";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Lesotho";
  .country_Continent = "Africa";
  .country_TZ_Region = "Maseru";
  .country_NTP_value = "SAST-2";
  .UN_Numeric_Code = 426;
  .country_Code.cc = "LS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Liberia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Monrovia";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 430;
  .country_Code.cc = "LR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Libya";
  .country_Continent = "Africa";
  .country_TZ_Region = "Tripoli";
  .country_NTP_value = "EET-2";
  .UN_Numeric_Code = 434;
  .country_Code.cc = "LY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Liechtenstein";
  .country_Continent = "Europe";
  .country_TZ_Region = "Vaduz";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 438;
  .country_Code.cc = "LI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Lithuania";
  .country_Continent = "Europe";
  .country_TZ_Region = "Vilnius";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 440;
  .country_Code.cc = "LT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Luxembourg";
  .country_Continent = "Europe";
  .country_TZ_Region = "Luxembourg";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 442;
  .country_Code.cc = "LU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Macau";
  .country_Continent = "Asia";
  .country_TZ_Region = "Macau";
  .country_NTP_value = "CST-8";
  .UN_Numeric_Code = 446;
  .country_Code.cc = "MO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "North Macedonia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Skopje";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 807;
  .country_Code.cc = "MK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Madagascar";
  .country_Continent = "Indian";
  .country_TZ_Region = "Antananarivo";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 450;
  .country_Code.cc = "MG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Malawi";
  .country_Continent = "Africa";
  .country_TZ_Region = "Blantyre";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 454;
  .country_Code.cc = "MW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Malaysia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kuala_Lumpur";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 458;
  .country_Code.cc = "MY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Malaysia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kuching";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 458;
  .country_Code.cc = "MY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Maldives";
  .country_Continent = "Indian";
  .country_TZ_Region = "Maldives";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 462;
  .country_Code.cc = "MV";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mali";
  .country_Continent = "Africa";
  .country_TZ_Region = "Bamako";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 466;
  .country_Code.cc = "ML";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Malta";
  .country_Continent = "Europe";
  .country_TZ_Region = "Malta";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 470;
  .country_Code.cc = "MT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Marshall Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Kwajalein";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 584;
  .country_Code.cc = "MH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Marshall Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Majuro";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 584;
  .country_Code.cc = "MH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Martinique";
  .country_Continent = "America";
  .country_TZ_Region = "Martinique";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 474;
  .country_Code.cc = "MQ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mauritania";
  .country_Continent = "Africa";
  .country_TZ_Region = "Nouakchott";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 478;
  .country_Code.cc = "MR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mauritius";
  .country_Continent = "Indian";
  .country_TZ_Region = "Mauritius";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 480;
  .country_Code.cc = "MU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mayotte";
  .country_Continent = "Indian";
  .country_TZ_Region = "Mayotte";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 175;
  .country_Code.cc = "YT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Bahia_Banderas";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Cancun";
  .country_NTP_value = "EST5";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Chihuahua";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Hermosillo";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Matamoros";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Mazatlan";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Merida";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Mexico_City";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Monterrey";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Ojinaga";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mexico";
  .country_Continent = "America";
  .country_TZ_Region = "Tijuana";
  .country_NTP_value = "PST8PDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 484;
  .country_Code.cc = "MX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Micronesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Chuuk";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 583;
  .country_Code.cc = "FM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Micronesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Kosrae";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 583;
  .country_Code.cc = "FM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Micronesia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Pohnpei";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 583;
  .country_Code.cc = "FM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Moldova";
  .country_Continent = "Europe";
  .country_TZ_Region = "Chisinau";
  .country_NTP_value = "EET-2EEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 498;
  .country_Code.cc = "MD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Monaco";
  .country_Continent = "Europe";
  .country_TZ_Region = "Monaco";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 492;
  .country_Code.cc = "MC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mongolia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Choibalsan";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 496;
  .country_Code.cc = "MN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mongolia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Hovd";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 496;
  .country_Code.cc = "MN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mongolia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Ulaanbaatar";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 496;
  .country_Code.cc = "MN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Montenegro";
  .country_Continent = "Europe";
  .country_TZ_Region = "Podgorica";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 499;
  .country_Code.cc = "ME";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Montserrat";
  .country_Continent = "America";
  .country_TZ_Region = "Montserrat";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 500;
  .country_Code.cc = "MS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Morocco";
  .country_Continent = "Africa";
  .country_TZ_Region = "Casablanca";
  .country_NTP_value = "<+01>-1";
  .UN_Numeric_Code = 504;
  .country_Code.cc = "MA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Mozambique";
  .country_Continent = "Africa";
  .country_TZ_Region = "Maputo";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 508;
  .country_Code.cc = "MZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Myanmar";
  .country_Continent = "Asia";
  .country_TZ_Region = "Yangon";
  .country_NTP_value = "<+0630>-6:30";
  .UN_Numeric_Code = 104;
  .country_Code.cc = "MM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Namibia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Windhoek";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 516;
  .country_Code.cc = "NA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Nauru";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Nauru";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 520;
  .country_Code.cc = "NR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Nepal";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kathmandu";
  .country_NTP_value = "<+0545>-5:45";
  .UN_Numeric_Code = 524;
  .country_Code.cc = "NP";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Netherlands";
  .country_Continent = "Europe";
  .country_TZ_Region = "Amsterdam";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 528;
  .country_Code.cc = "NL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "New Caledonia";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Noumea";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 540;
  .country_Code.cc = "NC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "New Zealand";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Auckland";
  .country_NTP_value = "NZST-12NZDT,M9.5.0,M4.1.0/3";
  .UN_Numeric_Code = 554;
  .country_Code.cc = "NZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}
"Pacific/",
country_Database_t select_Country = {
  .country_Name = "New Zealand";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Chatham";
  .country_NTP_value = "<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45";
  .UN_Numeric_Code = 554;
  .country_Code.cc = "NZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Nicaragua";
  .country_Continent = "America";
  .country_TZ_Region = "Managua";
  .country_NTP_value = "CST6";
  .UN_Numeric_Code = 558;
  .country_Code.cc = "NI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Niger";
  .country_Continent = "Africa";
  .country_TZ_Region = "Niamey";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 562;
  .country_Code.cc = "NE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Nigeria";
  .country_Continent = "Africa";
  .country_TZ_Region = "Lagos";
  .country_NTP_value = "WAT-1";
  .UN_Numeric_Code = 566;
  .country_Code.cc = "NG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Niue";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Niue";
  .country_NTP_value = "<-11>11";
  .UN_Numeric_Code = 570;
  .country_Code.cc = "NU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Norfolk Island";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Norfolk";
  .country_NTP_value = "<+11>-11<+12>,M10.1.0,M4.1.0/3";
  .UN_Numeric_Code = 574;
  .country_Code.cc = "NF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Northern Mariana Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Saipan";
  .country_NTP_value = "ChST-10";
  .UN_Numeric_Code = 580;
  .country_Code.cc = "MP";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Norway";
  .country_Continent = "Europe";
  .country_TZ_Region = "Oslo";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 578;
  .country_Code.cc = "NO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Oman";
  .country_Continent = "Asia";
  .country_TZ_Region = "Muscat";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 512;
  .country_Code.cc = "OM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Pakistan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Karachi";
  .country_NTP_value = "PKT-5";
  .UN_Numeric_Code = 586;
  .country_Code.cc = "PK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Palau";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Palau";
  .country_NTP_value = "<+09>-9";
  .UN_Numeric_Code = 585;
  .country_Code.cc = "PW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Palestine";
  .country_Continent = "Asia";
  .country_TZ_Region = "Gaza";
  .country_NTP_value = "EET-2EEST,M3.4.4/50,M10.4.4/50";
  .UN_Numeric_Code = 275;
  .country_Code.cc = "PS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Palestine";
  .country_Continent = "Asia";
  .country_TZ_Region = "Hebron";
  .country_NTP_value = "EET-2EEST,M3.4.4/50,M10.4.4/50";
  .UN_Numeric_Code = 275;
  .country_Code.cc = "PS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Panama";
  .country_Continent = "America";
  .country_TZ_Region = "Panama";
  .country_NTP_value = "EST5";
  .UN_Numeric_Code = 591;
  .country_Code.cc = "PA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Papua New Guinea";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Bougainville";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 598;
  .country_Code.cc = "PG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Papua New Guinea";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Port_Moresby";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 598;
  .country_Code.cc = "PG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Paraguay";
  .country_Continent = "America";
  .country_TZ_Region = "Asuncion";
  .country_NTP_value = "<-04>4<-03>,M10.1.0/0,M3.4.0/0";
  .UN_Numeric_Code = 600;
  .country_Code.cc = "PY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Peru";
  .country_Continent = "America";
  .country_TZ_Region = "Lima";
  .country_NTP_value = "<-05>5";
  .UN_Numeric_Code = 604;
  .country_Code.cc = "PE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Philippines";
  .country_Continent = "Asia";
  .country_TZ_Region = "Manila";
  .country_NTP_value = "PST-8";
  .UN_Numeric_Code = 608;
  .country_Code.cc = "PH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Pitcairn Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Pitcairn";
  .country_NTP_value = "<-08>8";
  .UN_Numeric_Code = 612;
  .country_Code.cc = "PN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Poland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Warsaw";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 616;
  .country_Code.cc = "PL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Portugal";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Azores";
  .country_NTP_value = "<-01>1<+00>,M3.5.0/0,M10.5.0/1";
  .UN_Numeric_Code = 620;
  .country_Code.cc = "PT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Portugal";
  .country_Continent = "Europe";
  .country_TZ_Region = "Lisbon";
  .country_NTP_value = "WET0WEST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 620;
  .country_Code.cc = "PT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Portugal";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Madeira";
  .country_NTP_value = "WET0WEST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 620;
  .country_Code.cc = "PT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Puerto Rico";
  .country_Continent = "America";
  .country_TZ_Region = "Puerto_Rico";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 630;
  .country_Code.cc = "PR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Qatar";
  .country_Continent = "Asia";
  .country_TZ_Region = "Qatar";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 634;
  .country_Code.cc = "QA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Réunion";
  .country_Continent = "Indian";
  .country_TZ_Region = "Reunion";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 638;
  .country_Code.cc = "RE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Romania";
  .country_Continent = "Europe";
  .country_TZ_Region = "Bucharest";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 642;
  .country_Code.cc = "RO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Anadyr";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Barnaul";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Chita";
  .country_NTP_value = "<+09>-9";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Irkutsk";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Kamchatka";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Krasnoyarsk";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Magadan";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Novokuznetsk";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Novosibirsk";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Omsk";
  .country_NTP_value = "<+06>-6";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Sakhalin";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Srednekolymsk";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Tomsk";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Ust-Nera";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Vladivostok";
  .country_NTP_value = "<+10>-10";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Yakutsk";
  .country_NTP_value = "<+09>-9";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Yekaterinburg";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Astrakhan";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Kaliningrad";
  .country_NTP_value = "EET-2";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Kirov";
  .country_NTP_value = "MSK-3";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Moscow";
  .country_NTP_value = "MSK-3";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Samara";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Saratov";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Ulyanovsk";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Russia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Volgograd";
  .country_NTP_value = "MSK-3";
  .UN_Numeric_Code = 643;
  .country_Code.cc = "RU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Rwanda";
  .country_Continent = "Africa";
  .country_TZ_Region = "Kigali";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 646;
  .country_Code.cc = "RW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Barthélemy";
  .country_Continent = "America";
  .country_TZ_Region = "St_Barthelemy";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 652;
  .country_Code.cc = "BL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Helena Ascension Island Tristan da Cunha";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "St_Helena";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 654;
  .country_Code.cc = "SH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Kitts and Nevis";
  .country_Continent = "America";
  .country_TZ_Region = "St_Kitts";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 659;
  .country_Code.cc = "KN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Lucia";
  .country_Continent = "America";
  .country_TZ_Region = "St_Lucia";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 662;
  .country_Code.cc = "LC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "The Collectivity of Saint-Martin";
  .country_Continent = "America";
  .country_TZ_Region = "Marigot";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 663;
  .country_Code.cc = "MF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Pierre and Miquelon";
  .country_Continent = "America";
  .country_TZ_Region = "Miquelon";
  .country_NTP_value = "<-03>3<-02>,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 666;
  .country_Code.cc = "PM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saint Vincent and the Grenadines";
  .country_Continent = "America";
  .country_TZ_Region = "St_Vincent";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 670;
  .country_Code.cc = "VC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Samoa";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Apia";
  .country_NTP_value = "<+13>-13";
  .UN_Numeric_Code = 882;
  .country_Code.cc = "WS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "San Marino";
  .country_Continent = "Europe";
  .country_TZ_Region = "San_Marino";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 674;
  .country_Code.cc = "SM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "São Tomé and Príncipe";
  .country_Continent = "Africa";
  .country_TZ_Region = "Sao_Tome";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 678;
  .country_Code.cc = "ST";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Saudi Arabia";
  .country_Continent = "Asia";
  .country_TZ_Region = "Riyadh";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 682;
  .country_Code.cc = "SA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Senegal";
  .country_Continent = "Africa";
  .country_TZ_Region = "Dakar";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 686;
  .country_Code.cc = "SN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Serbia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Belgrade";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 688;
  .country_Code.cc = "RS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Seychelles";
  .country_Continent = "Indian";
  .country_TZ_Region = "Mahe";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 690;
  .country_Code.cc = "SC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Sierra Leone";
  .country_Continent = "Africa";
  .country_TZ_Region = "Freetown";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 694;
  .country_Code.cc = "SL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Singapore";
  .country_Continent = "Asia";
  .country_TZ_Region = "Singapore";
  .country_NTP_value = "<+08>-8";
  .UN_Numeric_Code = 702;
  .country_Code.cc = "SG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Sint Maarten";
  .country_Continent = "America";
  .country_TZ_Region = "Lower_Princes";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 534;
  .country_Code.cc = "SX";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Slovakia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Bratislava";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 703;
  .country_Code.cc = "SK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Slovenia";
  .country_Continent = "Europe";
  .country_TZ_Region = "Ljubljana";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 705;
  .country_Code.cc = "SI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Solomon Islands";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Guadalcanal";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 090;
  .country_Code.cc = "SB";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Somalia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Mogadishu";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 706;
  .country_Code.cc = "SO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "South Africa";
  .country_Continent = "Africa";
  .country_TZ_Region = "Johannesburg";
  .country_NTP_value = "SAST-2";
  .UN_Numeric_Code = 710;
  .country_Code.cc = "ZA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "South Georgia and the South Sandwich Islands";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "South_Georgia";
  .country_NTP_value = "<-02>2";
  .UN_Numeric_Code = 239;
  .country_Code.cc = "GS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "South Sudan";
  .country_Continent = "Africa";
  .country_TZ_Region = "Juba";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 728;
  .country_Code.cc = "SS";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Spain";
  .country_Continent = "Atlantic";
  .country_TZ_Region = "Canary";
  .country_NTP_value = "WET0WEST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 724;
  .country_Code.cc = "ES";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Spain";
  .country_Continent = "Africa";
  .country_TZ_Region = "Ceuta";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 724;
  .country_Code.cc = "ES";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Spain";
  .country_Continent = "Europe";
  .country_TZ_Region = "Madrid";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 724;
  .country_Code.cc = "ES";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Sri Lanka";
  .country_Continent = "Asia";
  .country_TZ_Region = "Colombo";
  .country_NTP_value = "<+0530>-5:30";
  .UN_Numeric_Code = 144;
  .country_Code.cc = "LK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Sudan";
  .country_Continent = "Africa";
  .country_TZ_Region = "Khartoum";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 729;
  .country_Code.cc = "SD";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Suriname";
  .country_Continent = "America";
  .country_TZ_Region = "Paramaribo";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 740;
  .country_Code.cc = "SR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Sweden";
  .country_Continent = "Europe";
  .country_TZ_Region = "Stockholm";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 752;
  .country_Code.cc = "SE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Switzerland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Busingen";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 756;
  .country_Code.cc = "CH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Switzerland";
  .country_Continent = "Europe";
  .country_TZ_Region = "Zurich";
  .country_NTP_value = "CET-1CEST,M3.5.0,M10.5.0/3";
  .UN_Numeric_Code = 756;
  .country_Code.cc = "CH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Syria";
  .country_Continent = "Asia";
  .country_TZ_Region = "Damascus";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 760;
  .country_Code.cc = "SY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Taiwan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Taipei";
  .country_NTP_value = "CST-8";
  .UN_Numeric_Code = 158;
  .country_Code.cc = "TW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tajikistan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Dushanbe";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 762;
  .country_Code.cc = "TJ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tanzania";
  .country_Continent = "Africa";
  .country_TZ_Region = "Dar_es_Salaam";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 834;
  .country_Code.cc = "TZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Thailand";
  .country_Continent = "Asia";
  .country_TZ_Region = "Bangkok";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 764;
  .country_Code.cc = "TH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "East Timor";
  .country_Continent = "Asia";
  .country_TZ_Region = "Dili";
  .country_NTP_value = "<+09>-9";
  .UN_Numeric_Code = 626;
  .country_Code.cc = "TL";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Togo";
  .country_Continent = "Africa";
  .country_TZ_Region = "Lome";
  .country_NTP_value = "GMT0";
  .UN_Numeric_Code = 768;
  .country_Code.cc = "TG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tokelau";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Fakaofo";
  .country_NTP_value = "<+13>-13";
  .UN_Numeric_Code = 772;
  .country_Code.cc = "TK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tonga";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Tongatapu";
  .country_NTP_value = "<+13>-13";
  .UN_Numeric_Code = 776;
  .country_Code.cc = "TO";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Trinidad and Tobago";
  .country_Continent = "America";
  .country_TZ_Region = "Port_of_Spain";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 780;
  .country_Code.cc = "TT";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tunisia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Tunis";
  .country_NTP_value = "CET-1";
  .UN_Numeric_Code = 788;
  .country_Code.cc = "TN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Turkey";
  .country_Continent = "Europe";
  .country_TZ_Region = "Istanbul";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 792;
  .country_Code.cc = "TR";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Turkmenistan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Ashgabat";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 795;
  .country_Code.cc = "TM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Turks and Caicos Islands";
  .country_Continent = "America";
  .country_TZ_Region = "Grand_Turk";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 796;
  .country_Code.cc = "TC";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Tuvalu";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Funafuti";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 798;
  .country_Code.cc = "TV";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Uganda";
  .country_Continent = "Africa";
  .country_TZ_Region = "Kampala";
  .country_NTP_value = "EAT-3";
  .UN_Numeric_Code = 800;
  .country_Code.cc = "UG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ukraine";
  .country_Continent = "Europe";
  .country_TZ_Region = "Kiev";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 804;
  .country_Code.cc = "UA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ukraine";
  .country_Continent = "Europe";
  .country_TZ_Region = "Simferopol";
  .country_NTP_value = "MSK-3"; //Disputed
  .UN_Numeric_Code = 804;
  .country_Code.cc = "UA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ukraine";
  .country_Continent = "Europe";
  .country_TZ_Region = "Uzhgorod";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 804;
  .country_Code.cc = "UA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Ukraine";
  .country_Continent = "Europe";
  .country_TZ_Region = "Zaporozhye";
  .country_NTP_value = "EET-2EEST,M3.5.0/3,M10.5.0/4";
  .UN_Numeric_Code = 804;
  .country_Code.cc = "UA";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Arab Emirates";
  .country_Continent = "Asia";
  .country_TZ_Region = "Dubai";
  .country_NTP_value = "<+04>-4";
  .UN_Numeric_Code = 784;
  .country_Code.cc = "AE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Kingdom";
  .country_Continent = "Europe";
  .country_TZ_Region = "Belfast";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 826;
  .country_Code.cc = "UK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Kingdom";
  .country_Continent = "Europe";
  .country_TZ_Region = "Guernsey";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 826;
  .country_Code.cc = "UK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Kingdom";
  .country_Continent = "Europe";
  .country_TZ_Region = "Isle_of_Man";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 826;
  .country_Code.cc = "UK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Kingdom";
  .country_Continent = "Europe";
  .country_TZ_Region = "Jersey";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 826;
  .country_Code.cc = "UK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United Kingdom";
  .country_Continent = "Europe";
  .country_TZ_Region = "London";
  .country_NTP_value = "GMT0BST,M3.5.0/1,M10.5.0";
  .UN_Numeric_Code = 826;
  .country_Code.cc = "UK";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Adak";
  .country_NTP_value = "HST10HDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Anchorage";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Boise";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Chicago";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Denver";
  .country_NTP_value = "MST7MDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Detroit";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Indianapolis";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Knox";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Marengo";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Petersburg";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Tell_City";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Vevay";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Vincennes";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Indiana/Winamac";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Juneau";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Kentucky/Louisville";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Kentucky/Monticello";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Los_Angeles";
  .country_NTP_value = "PST8PDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Menominee";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Metlakatla";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "New_York";
  .country_NTP_value = "EST5EDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Nome";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "North_Dakota/Beulah";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "North_Dakota/Center";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "North_Dakota/New_Salem";
  .country_NTP_value = "CST6CDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Phoenix";
  .country_NTP_value = "MST7";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Sitka";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "America";
  .country_TZ_Region = "Yakutat";
  .country_NTP_value = "AKST9AKDT,M3.2.0,M11.1.0";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Honolulu";
  .country_NTP_value = "HST10";
  .UN_Numeric_Code = 840;
  .country_Code.cc = "US";
  .country_Code.schan = 1;
  .country_Code.nchan = 11;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Uruguay";
  .country_Continent = "America";
  .country_TZ_Region = "Montevideo";
  .country_NTP_value = "<-03>3";
  .UN_Numeric_Code = 858;
  .country_Code.cc = "UY";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Uzbekistan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Samarkand";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 860;
  .country_Code.cc = "UZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Uzbekistan";
  .country_Continent = "Asia";
  .country_TZ_Region = "Tashkent";
  .country_NTP_value = "<+05>-5";
  .UN_Numeric_Code = 860;
  .country_Code.cc = "UZ";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Vanuatu";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Efate";
  .country_NTP_value = "<+11>-11";
  .UN_Numeric_Code = 548;
  .country_Code.cc = "VU";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Wake Island";  // US Outlying Islands
  .country_Continent = "Pacific";
  .country_TZ_Region = "Wake";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 581;
  .country_Code.cc = "UM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Venezuela";
  .country_Continent = "America";
  .country_TZ_Region = "Caracas";
  .country_NTP_value = "<-04>4";
  .UN_Numeric_Code = 862;
  .country_Code.cc = "VE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Vietnam";
  .country_Continent = "Asia";
  .country_TZ_Region = "Ho_Chi_Minh";
  .country_NTP_value = "<+07>-7";
  .UN_Numeric_Code = 704;
  .country_Code.cc = "VN";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "British Virgin Islands";
  .country_Continent = "America";
  .country_TZ_Region = "Tortola";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 092;
  .country_Code.cc = "VG";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "United States Virgin Islands";
  .country_Continent = "America";
  .country_TZ_Region = "St_Thomas";
  .country_NTP_value = "AST4";
  .UN_Numeric_Code = 850;
  .country_Code.cc = "VI";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Wallis and Futuna";
  .country_Continent = "Pacific";
  .country_TZ_Region = "Wallis";
  .country_NTP_value = "<+12>-12";
  .UN_Numeric_Code = 876;
  .country_Code.cc = "WF";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Western Sahara"; // Disputed territory
  .country_Continent = "Africa";
  .country_TZ_Region = "El_Aaiun";
  .country_NTP_value = "<+01>-1";
  .UN_Numeric_Code = 732;
  .country_Code.cc = "EH";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Yemen";
  .country_Continent = "Asia";
  .country_TZ_Region = "Aden";
  .country_NTP_value = "<+03>-3";
  .UN_Numeric_Code = 887;
  .country_Code.cc = "YE";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Zambia";
  .country_Continent = "Africa";
  .country_TZ_Region = "Lusaka";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 894;
  .country_Code.cc = "ZM";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}

country_Database_t select_Country = {
  .country_Name = "Zimbabwe";
  .country_Continent = "Africa";
  .country_TZ_Region = "Harare";
  .country_NTP_value = "CAT-2";
  .UN_Numeric_Code = 716;
  .country_Code.cc = "ZW";
  .country_Code.schan = 1;
  .country_Code.nchan = 13;
  .country_Code.max_tx_power = ;
  .country_Code.policy = WIFI_COUNTRY_POLICY_AUTO;
}


/*

enum country_code_num
  { "AD"=0, "AE", "AF", "AG", "AI", "AL", "AM", "AN", "AO", "AQ", "AR", "AS", "AT", "AU", "AW", "AX", "AZ",
    "BA", "BB", "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BR", "BS", "BT", "BV", "BW", "BY", "BZ",
    "CA", "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CX", "CY", "CZ",
    "DE", "DJ", "DK", "DM", "DO", "DZ",
    "EC", "EE", "EG", "EH", "ER", "ES", "ET",
    "FI", "FJ", "FK", "FM", "FO", "FR",
    "GA", "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS", "GT", "GU", "GW", "GY",
    "HK", "HM", "HN", "HR", "HT", "HU",
    "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR", "IS", "IT",
    "JE", "JM", "JO", "JP",
    "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "KY", "KZ",
    "LA", "LB", "LC", "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY",
    "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK", "ML", "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ",
    "NA", "NC", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ",
    "OM",
    "PA", "PE", "PF", "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY",
    "QA",
    "RE", "RO", "RS", "RU", "RW",
    "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "ST", "SV", "SY", "SZ",
    "TC", "TD", "TF", "TG", "TH", "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ",
    "UA", "UG", "UM", "US", "UY", "UZ",
    "VA", "VC", "VE", "VG", "VI", "VN", "VU",
    "WF", "WS",
    "YE", "YT",
    "ZA", "ZM", "ZW"
  };

const char *country_code[] =
  { "AD", "AE", "AF", "AG", "AI", "AL", "AM", "AN", "AO", "AQ", "AR", "AS", "AT", "AU", "AW", "AX", "AZ",
    "BA", "BB", "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BR", "BS", "BT", "BV", "BW", "BY", "BZ",
    "CA", "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CX", "CY", "CZ",
    "DE", "DJ", "DK", "DM", "DO", "DZ",
    "EC", "EE", "EG", "EH", "ER", "ES", "ET",
    "FI", "FJ", "FK", "FM", "FO", "FR",
    "GA", "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS", "GT", "GU", "GW", "GY",
    "HK", "HM", "HN", "HR", "HT", "HU",
    "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR", "IS", "IT",
    "JE", "JM", "JO", "JP",
    "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "KY", "KZ",
    "LA", "LB", "LC", "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY",
    "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK", "ML", "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ",
    "NA", "NC", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ",
    "OM",
    "PA", "PE", "PF", "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY",
    "QA",
    "RE", "RO", "RS", "RU", "RW",
    "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "ST", "SV", "SY", "SZ",
    "TC", "TD", "TF", "TG", "TH", "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ",
    "UA", "UG", "UM", "US", "UY", "UZ",
    "VA", "VC", "VE", "VG", "VI", "VN", "VU",
    "WF", "WS",
    "YE", "YT",
    "ZA", "ZM", "ZW"
  };

//ISO country names in order of country codes above
const char *country_name[] =
{
"Andorra", "United Arab Emirates", "Afghanistan", "Antigua & Barbuda", "Anguilla", "Albania", "Armenia", "Netherlands Antilles", "Angola", "Antarctica", \
"Argentina", "Samoa (American)", "Austria", "Australia", "Aruba", "Aaland Islands", "Azerbaijan", \
"Bosnia & Herzegovina", "Barbados", "Bangladesh", "Belgium", "Burkina Faso", "Bulgaria", "Bahrain", "Burundi", "Benin", "St Barthelemy", "Bermuda", "Brunei", \
"Bolivia", "Brazil", "Bahamas", "Bhutan", "Bouvet Island", "Botswana", "Belarus", "Belize", \
"Canada", "Cocos (Keeling) Islands", "Congo (Dem. Rep.)", "Central African Rep.", "Congo (Rep.)", "Switzerland", "Cote d'Ivoire", "Cook Islands", "Chile", "Cameroon", \
"China", "Colombia", "Costa Rica", "Cuba", "Cape Verde", "Christmas Island", "Cyprus", "Czech Republic", \
"Germany", "Djibouti", "Denmark", "Dominica", "Dominican Republic", "Algeria", "Ecuador", "Estonia", "Egypt", "Western Sahara", "Eritrea", "Spain", "Ethiopia", \
"Finland", "Fiji", "Falkland Islands", "Micronesia", "Faroe Islands", "France", \
"Gabon", "Britain (UK)", "Grenada", "Georgia", "French Guiana", "Guernsey", "Ghana", "Gibraltar", "Greenland", "Gambia", "Guinea", "Guadeloupe", \
"Equatorial Guinea", "Greece", "South Georgia & the South Sandwich Islands", "Guatemala", "Guam", "Guinea-Bissau", "Guyana", \
"Hong Kong", "Heard Island & McDonald Islands", "Honduras", "Croatia", "Haiti", "Hungary", \
"Indonesia", "Ireland", "Israel", "Isle of Man", "India", "British Indian Ocean Territory", "Iraq", "Iran", "Iceland", "Italy", \
"Jersey", "Jamaica", "Jordan", "Japan", \
"Kenya", "Kyrgyzstan", "Cambodia", "Kiribati", "Comoros", "St Kitts & Nevis", "Korea (North)", "Korea (South)", "Kuwait", "Cayman Islands", "Kazakhstan", \
"Laos", "Lebanon", "St Lucia", "Liechtenstein", "Sri Lanka", "Liberia", "Lesotho", "Lithuania", "Luxembourg", "Latvia", "Libya", \
"Morocco", "Monaco", "Moldova", "Montenegro", "St Martin (French part)", "Madagascar", "Marshall Islands", "Macedonia", "Mali", "Myanmar (Burma)", \
"Mongolia", "Macau", "Northern Mariana Islands", "Martinique", "Mauritania", "Montserrat", "Malta", "Mauritius", "Maldives", "Malawi", "Mexico", "Malaysia", "Mozambique", \
"Namibia", "New Caledonia", "Niger", "Norfolk Island", "Nigeria", "Nicaragua", "Netherlands", "Norway", "Nepal", "Nauru", "Niue", "New Zealand", \
"Oman", "Panama", "Peru", "French Polynesia", "Papua New Guinea", "Philippines", "Pakistan", "Poland", "St Pierre & Miquelon", "Pitcairn", "Puerto Rico", "Palestine", "Portugal", "Palau", "Paraguay", \
"Qatar", "Reunion", "Romania", "Serbia", "Russia", "Rwanda", \
"Saudi Arabia", "Solomon Islands", "Seychelles", "Sudan", "Sweden", "Singapore", "St Helena", "Slovenia", "Svalbard & Jan Mayen", "Slovakia", "Sierra Leone", "San Marino", \
"Senegal", "Somalia", "Suriname", "Sao Tome & Principe", "El Salvador", "Syria", "Swaziland", \
"Turks & Caicos Is", "Chad", "French Southern & Antarctic Lands", "Togo", "Thailand", "Tajikistan", "Tokelau", "East Timor", "Turkmenistan", "Tunisia", "Tonga", \
"Turkey", "Trinidad & Tobago", "Tuvalu", "Taiwan", "Tanzania", \
"Ukraine", "Uganda", "US minor outlying islands", "United States", "Uruguay", "Uzbekistan", \
"Vatican City", "St Vincent", "Venezuela", "Virgin Islands (UK)", "Virgin Islands (US)", "Vietnam", "Vanuatu", \
"Wallis & Futuna", "Samoa (western)", "Yemen", "Mayotte", "South Africa", "Zambia", "Zimbabwe"
};

#endif
*/