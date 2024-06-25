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

#ifndef __iso3166_H__
#define __iso3166_H__
/*
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

#define country_Name_Size         50 // Size must be greater than the longest country name
#define country_Continent_Size    20
#define country_TZ_Region_Size    40
#define country_NTP_value_Size    50
#define UN_Numeric_Code_Size      4  //Three digits
#define country_Code_cc_Size      3  // Two characters as per ISO3166


typedef struct country_Database_t {
  char country_Name[country_Name_Size];
  char country_Continent[country_Continent_Size];
  char country_TZ_Region[country_TZ_Region_Size];
  char country_NTP_value[country_NTP_value_Size];
  char UN_Numeric_Code[UN_Numeric_Code_Size];
  char country_Code_cc[country_Code_cc_Size];
  country_Database_t *next;
  country_Database_t *prior;
} country_Database_t;


country_Database_t select_Country[] = {

{ "Afghanistan", "Asia", "Kabul", "<+0430>-4:30", "004", "AF"},
{ "Åland", "Europe", "Helsinki", "EET-2EEST,M3.5.0/3,M10.5.0/4", "248", "AX"},
{ "Albania", "Europe", "Tirane", "CET-1CEST,M3.5.0,M10.5.0/3", "008", "AL"},
{ "Algeria","Africa", "Algiers", "CET-1", "012", "DZ"},
{ "American Samoa", "Pacific", "Midway", "SST11", "581", "UM"},
{ "American Samoa", "Pacific", "Pago_Pago", "SST11", "016", "AS"},
{ "Andorra", "Europe", "Andorra", "CET-1CEST,M3.5.0,M10.5.0/3", "020", "AD"},
{ "Angola", "Africa", "Luanda", "WAT-1", "024", "AO"},
{ "Anguilla", "America", "Anguilla", "AST4", "660", "AI"},
{ "Antarctica", "Antarctica", "Casey", "<+11>-11", "010", "AQ"},
{ "Antarctica", "Antarctica", "Davis", "<+07>-7", "010", "AQ"},
{ "Antarctica", "Antarctica", "DumontDUrville", "<+10>-10", "010", "AQ"},
{ "Antarctica", "Antarctica", "Macquarie", "AEST-10AEDT,M10.1.0,M4.1.0/3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Mawson", "<+05>-5", "010", "AQ"},
{ "Antarctica", "Antarctica", "McMurdo", "NZST-12NZDT,M9.5.0,M4.1.0/3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Palmer", "<-03>3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Rothera", "<-03>3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Syowa", "<+03>-3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Troll", "<+00>0<+02>-2,M3.5.0/1,M10.5.0/3", "010", "AQ"},
{ "Antarctica", "Antarctica", "Vostok", "<+06>-6", "010", "AQ"},
{ "Arctic", "Arctic", "Longyearbyen", "CET-1CEST,M3.5.0,M10.5.0/3", "578", "NO"},
{ "Antigua and Barbuda", "America", "Antigua", "AST4", "028", "AG"},
{ "Argentina", "America", "Buenos Aires", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Catamarca", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Cordoba", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Jujuy", "<-03>3", "032", "AR"},
{ "Argentina", "America", "La_Rioja", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Mendoza", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Rio Gallegos", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Salta", "<-03>3", "032", "AR"},
{ "Argentina", "America", "San Juan", "<-03>3", "032", "AR"},
{ "Argentina", "America", "San Luis", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Tucuman", "<-03>3", "032", "AR"},
{ "Argentina", "America", "Ushuaia", "<-03>3", "032", "AR"},
{ "Armenia", "Asia", "Yerevan", "<+04>-4", "051", "AM"},
{ "Aruba", "America", "Aruba", "AST4", "533", "AW"},
{ "Australia", "Australia", "Adelaide", "ACST-9:30ACDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Australia", "Australia", "Brisbane", "AEST-10", "036", "AU"},
{ "Australia", "Australia", "Broken Hill", "ACST-9:30ACDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Australia", "Australia", "Currie", "AEST-10AEDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Australia", "Australia", "Darwin", "ACST-9:30", "036", "AU"},
{ "Australia", "Australia", "Eucla", "<+0845>-8:45", "036", "AU"},
{ "Australia", "Australia", "Hobart", "AEST-10AEDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Australia", "Australia", "Lindeman", "AEST-10", "036", "AU"},
{ "Australia", "Australia", "Lord Howe", "<+1030>-10:30<+11>-11,M10.1.0,M4.1.0", "036", "AU"},
{ "Australia", "Australia", "Melbourne", "AEST-10AEDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Australia", "Australia", "Perth", "AWST-8", "036", "AU"},
{ "Australia", "Australia", "Sydney", "AEST-10AEDT,M10.1.0,M4.1.0/3", "036", "AU"},
{ "Austria", "Europe", "Vienna", "CET-1CEST,M3.5.0,M10.5.0/3", "040", "AT"},
{ "Azerbaijan", "Asia", "Baku", "<+04>-4", "031", "AZ"},
{ "The Bahamas", "America", "Nassau", "EST5EDT,M3.2.0,M11.1.0", "044", "BS"},
{ "Bahrain", "Asia", "Bahrain", "<+03>-3", "048", "BH"},
{ "Bangladesh", "Asia", "Dhaka", "<+06>-6", "050", "BD"},
{ "Barbados", "America", "Barbados", "AST4", "052", "BB"},
{ "Belarus", "Europe", "Minsk", "<+03>-3", "112", "BY"},
{ "Belgium", "Europe", "Brussels", "CET-1CEST,M3.5.0,M10.5.0/3", "056", "BE"},
{ "Belize", "America", "Belize", "CST6", "084", "BZ"},
{ "Benin", "Africa", "Porto-Novo", "WAT-1", "204", "BJ"},
{ "Bermuda", "Atlantic", "Bermuda", "AST4ADT,M3.2.0,M11.1.0", "060", "BM"},
{ "Bhutan", "Asia", "Thimphu", "<+06>-6", "064", "BT"},
{ "Bolivia", "America", "La Paz", "<-04>4", "068", "BO"},
{ "Bonaire, Sint Eustatius and Saba", "America", "Kralendijk", "AST4", "535", "NL"},
{ "Bosnia and Herzegovina", "Europe", "Sarajevo", "CET-1CEST,M3.5.0,M10.5.0/3", "070", "BA"},
{ "Botswana", "Africa", "Gaborone", "CAT-2", "072", "BW"},
{ "Brazil", "America", "Araguaina", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Bahia", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Belem", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Boa_Vista", "<-04>4", "076", "BR"},
{ "Brazil", "America", "Campo_Grande", "<-04>4", "076", "BR"},
{ "Brazil", "America", "Cuiaba", "<-04>4", "076", "BR"},
{ "Brazil", "America", "Eirunepe", "<-05>5", "076", "BR"},
{ "Brazil", "America", "Fortaleza", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Maceio", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Manaus", "<-04>4", "076", "BR"},
{ "Brazil", "America", "Noronha", "<-02>2", "076", "BR"},
{ "Brazil", "America", "Porto_Velho", "<-04>4", "076", "BR"},
{ "Brazil", "America", "Recife", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Rio_Branco", "<-05>5", "076", "BR"},
{ "Brazil", "America", "Santarem", "<-03>3", "076", "BR"},
{ "Brazil", "America", "Sao Paulo", "<-03>3", "076", "BR"},
{ "British Indian Ocean Territory", "Indian", "Chagos", "<+06>-6", "086", "IO"},
{ "Brunei", "Asia", "Brunei", "<+08>-8", "096", "BN"},
{ "Bulgaria", "Europe", "Sofia", "EET-2EEST,M3.5.0/3,M10.5.0/4", "100", "BG"},
{ "Burkina Faso", "Africa", "Ouagadougou", "GMT0", "854", "BF"},
{ "Burundi", "Africa", "Bujumbura", "CAT-2", "108", "BI"},
{ "Cape Verde", "Atlantic", "Cape Verde", "<-01>1", "132", "CV"},
{ "Cambodia", "Asia", "Phnom Penh", "<+07>-7", "116", "KH"},
{ "Cameroon", "Africa", "Douala", "WAT-1", "120", "CM"},
{ "Canada", "America", "Atikokan", "EST5", "124", "CA"},
{ "Canada", "America", "Blanc-Sablon", "AST4", "124", "CA"},
{ "Canada", "America", "Cambridge_Bay", "MST7MDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Creston", "MST7", "124", "CA"},
{ "Canada", "America", "Dawson", "MST7", "124", "CA"},
{ "Canada", "America", "Dawson Creek", "MST7", "124", "CA"},
{ "Canada", "America", "Edmonton", "MST7MDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Fort_Nelson", "MST7", "124", "CA"},
{ "Canada", "America", "Goose_Bay", "AST4ADT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Glace_Bay", "AST4ADT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Halifax", "AST4ADT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Inuvik", "MST7MDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Iqaluit", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Moncton", "AST4ADT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Montreal", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Nipigon", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Pangnirtung", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Rainy River", "CST6CDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Rankin Inlet", "CST6CDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Regina", "CST6", "124", "CA"},
{ "Canada", "America", "Resolute", "CST6CDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "St_Johns", "NST3:30NDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Swift Current", "CST6", "124", "CA"},
{ "Canada", "America", "Thunder Bay", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Toronto", "EST5EDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Vancouver", "PST8PDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Whitehorse", "MST7", "124", "CA"},
{ "Canada", "America", "Winnipeg", "CST6CDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Canada", "America", "Yellowknife", "MST7MDT,M3.2.0,M11.1.0", "124", "CA"},
{ "Cayman Islands", "America", "Cayman", "EST5", "136", "KY"},
{ "Chad", "Africa", "Bangui", "WAT-1", "140", "CF"},
{ "Central African Republic", "Africa", "Ndjamena", "WAT-1", "148", "TD"},
{ "Chile", "America", "Punta_Arenas", "<-03>3", "152", "CL"},
{ "Chile", "America", "Santiago", "<-04>4<-03>,M9.1.6/24,M4.1.6/24", "152", "CL"},
{ "Chile", "Pacific", "Easter", "<-06>6<-05>,M9.1.6/22,M4.1.6/22", "152", "CL"},
{ "China", "Asia", "Khandyga", "<+09>-9", "156", "CN"},
{ "China", "Asia", "Shanghai", "CST-8", "156", "CN"},
{ "China", "Asia", "Urumqi", "<+06>-6", "156", "CN"},
{ "Christmas Island", "Indian", "Christmas", "<+07>-7", "162", "CX"},
{ "Cocos (Keeling) Islands", "Indian", "Cocos", "<+0630>-6:30", "166", "CC"},
{ "Colombia", "America", "Bogota", "<-05>5", "170", "CO"},
{ "Comoros", "Indian", "Comoro", "EAT-3", "174", "KM"},
{ "Democratic Republic of the Congo", "Africa", "Kinshasa", "WAT-1", "180", "CD"},
{ "Democratic Republic of the Congo", "Africa", "Lubumbashi", "CAT-2", "180", "CD"},
{ "Republic of the Congo", "Africa", "Brazzaville", "WAT-1", "178", "CG"},
{ "Cook Islands", "Pacific", "Rarotonga", "<-10>10", "184", "CK"},
{ "Ivory Coast", "Africa", "Abidjan", "GMT0", "384", "CI"},
{ "Croatia", "Europe", "Zagreb", "CET-1CEST,M3.5.0,M10.5.0/3", "191", "HR"},
{ "Cuba", "America", "Havana", "CST5CDT,M3.2.0/0,M11.1.0/1", "192", "CU"},
{ "Curaçao", "America", "Curacao", "AST4", "531", "CW"},
{ "Cyprus", "Asia", "Nicosia", "EET-2EEST,M3.5.0/3,M10.5.0/4", "196", "CY"},
{ "Cyprus", "Asia", "Famagusta", "EET-2EEST,M3.5.0/3,M10.5.0/4", "196", "CY"},
{ "Czech Republic", "Europe", "Prague", "CET-1CEST,M3.5.0,M10.5.0/3", "203", "CZ"},
{ "Denmark", "Europe", "Copenhagen", "CET-1CEST,M3.5.0,M10.5.0/3", "208", "DK"},
{ "Djibouti", "Africa", "Djibouti", "EAT-3", "262", "DJ"},
{ "Dominica", "America", "Dominica", "AST4", "212", "DM"},
{ "Dominican Republic", "America", "Santo_Domingo", "AST4", "214", "DO"},
{ "Ecuador", "Pacific", "Galapagos", "<-06>6", "218", "EC"},
{ "Ecuador", "America", "Guayaquil", "<-05>5", "218", "EC"},
{ "Egypt", "Africa", "Cairo", "EET-2EEST,M4.5.5/0,M10.5.4/24", "818", "EG"},
{ "El Salvador", "America", "El_Salvador", "CST6", "222", "SV"},
{ "Equatorial Guinea", "Africa", "Malabo", "WAT-1", "226", "GQ"},
{ "Eritrea", "Africa", "Asmara", "EAT-3", "232", "ER"},
{ "Estonia", "Europe", "Tallinn", "EET-2EEST,M3.5.0/3,M10.5.0/4", "233", "EE"},
{ "Eswatini", "Africa", "Mbabane", "SAST-2", "748", "SZ"},
{ "Ethiopia", "Africa", "Addis_Ababa", "EAT-3", "231", "ET"},
{ "Falkland Islands", "Atlantic", "Stanley", "<-03>3", "238", "FK"},
{ "Faroe Islands", "Atlantic", "Faroe", "WET0WEST,M3.5.0/1,M10.5.0", "234", "FO"},
{ "Fiji", "Pacific", "Fiji", "<+12>-12", "242", "FJ"},
{ "Finland", "Europe", "Helsinki", "EET-2EEST,M3.5.0/3,M10.5.0/4", "246", "FI"},
{ "Finland", "Europe", "Mariehamn", "EET-2EEST,M3.5.0/3,M10.5.0/4", "248", "AX"},
{ "France", "Europe", "Paris", "CET-1CEST,M3.5.0,M10.5.0/3", "250", "FR"},
{ "French Guiana", "America", "Cayenne", "<-03>3", "254", "GF"},
{ "French Polynesia", "Pacific", "Gambier", "<-09>9", "258", "PF"},
{ "French Polynesia", "Pacific", "Marquesas", "<-0930>9:30", "258", "PF"},
{ "French Polynesia", "Pacific", "Tahiti", "<-10>10", "258", "PF"},
{ "French Southern and Antarctic Lands", "Antarctica", "DumontDUrville", "<+10>-10", "260", "TF"},
{ "French Southern and Antarctic Lands", "Indian", "Kerguelen", "<+05>-5", "260", "TF"},
{ "Gabon", "Africa", "Libreville", "WAT-1", "266", "GA"},
{ "The Gambia", "Africa", "Banjul", "GMT0", "270", "GM"},
{ "Georgia", "Asia", "Tbilisi", "<+04>-4", "268", "GE"},
{ "Germany", "Europe", "Berlin", "CET-1CEST,M3.5.0,M10.5.0/3", "276", "DE"},
{ "Ghana", "Africa", "Accra", "GMT0", "288", "GH"},
{ "Gibraltar", "Europe", "Gibraltar", "CET-1CEST,M3.5.0,M10.5.0/3", "292", "GI"},
{ "Greece", "Europe", "Athens", "EET-2EEST,M3.5.0/3,M10.5.0/4", "300", "GR"},
{ "Greenland", "America", "Danmarkshavn", "GMT0", "304", "GL"},
{ "Greenland", "America", "Godthab", "<-02>2<-01>,M3.5.0/-1,M10.5.0/0", "304", "GL"},
{ "Greenland", "America", "Nuuk", "<-02>2<-01>,M3.5.0/-1,M10.5.0/0", "304", "GL"},
{ "Greenland", "America", "Scoresbysund", "<-01>1<+00>,M3.5.0/0,M10.5.0/1", "304", "GL"},
{ "Greenland", "America", "Thule", "AST4ADT,M3.2.0,M11.1.0", "304", "GL"},
{ "Grenada", "America", "Grenada", "AST4", "308", "GD"},
{ "Guadeloupe", "America", "Guadeloupe", "AST4", "312", "GP"},
{ "Guam", "Pacific", "Guam", "ChST-10", "316", "GU"},
{ "Guatemala", "America", "Guatemala", "CST6", "320", "GT"},
{ "Bailiwick of Guernsey", "Europe", "Guernsey", "GMT0BST,M3.5.0/1,M10.5.0", "831", "GG"},
{ "Guinea", "Africa", "Conakry", "GMT0", "324", "GN"},
{ "Guinea-Bissau", "Africa", "Bissau", "GMT0", "624", "GW"},
{ "Guyana", "America", "Guyana", "<-04>4", "328", "GY"},
{ "Haiti", "America", "Port-au-Prince", "EST5EDT,M3.2.0,M11.1.0", "332", "HT"},
{ "Holy See", "Europe", "Vatican", "CET-1CEST,M3.5.0,M10.5.0/3", "336", "VA"},
{ "Honduras", "America", "Tegucigalpa", "CST6", "340", "HN"},
{ "Hong Kong", "Asia", "Hong_Kong", "HKT-8", "344", "HK"},
{ "Hungary", "Europe", "Budapest", "CET-1CEST,M3.5.0,M10.5.0/3", "348", "HU"},
{ "Iceland", "Atlantic", "Reykjavik", "GMT0", "352", "IS"},
{ "India", "Asia", "Kolkata", "IST-5:30", "356", "IN"},
{ "Indonesia", "Asia", "Jakarta", "WIB-7", "356", "ID"},
{ "Indonesia", "Asia", "Pontianak", "WIB-7", "356", "ID"},
{ "Indonesia", "Asia", "Jayapura", "WIT-9", "356", "ID"},
{ "Indonesia", "Asia", "Makassar", "WITA-8", "356", "ID"},
{ "Iran", "Asia", "Tehran", "<+0330>-3:30", "364", "IR"},
{ "Iraq", "Asia", "Baghdad", "<+03>-3", "368", "IQ"},
{ "Republic of Ireland", "Europe", "Dublin", "IST-1GMT0,M10.5.0,M3.5.0/1", "372", "IE"},
{ "Isle of Man", "Europe", "Isle_of_Man", "GMT0BST,M3.5.0/1,M10.5.0", "833", "IM"},
{ "Israel", "Asia", "Jerusalem", "IST-2IDT,M3.4.4/26,M10.5.0", "376", "IL"},
{ "Italy", "Europe", "Rome", "CET-1CEST,M3.5.0,M10.5.0/3", "380", "IT"},
{ "Jamaica", "America", "Jamaica", "EST5", "388", "JM"},
{ "Japan", "Asia", "Tokyo", "JST-9", "392", "JP"},
{ "Jersey", "Europe", "Jersey", "GMT0BST,M3.5.0/1,M10.5.0", "832", "JE"},
{ "Jordan", "Asia", "Amman", "<+03>-3", "400", "JO"},
{ "Kazakhstan", "Asia", "Almaty", "<+06>-6", "398", "KZ"},
{ "Kazakhstan", "Asia", "Aqtau", "<+05>-5", "398", "KZ"},
{ "Kazakhstan", "Asia", "Aqtobe", "<+05>-5", "398", "KZ"},
{ "Kazakhstan", "Asia", "Atyrau", "<+05>-5", "398", "KZ"},
{ "Kazakhstan", "Asia", "Oral", "<+05>-5", "398", "KZ"},
{ "Kazakhstan", "Asia", "Qyzylorda", "<+05>-5", "398", "KZ"},
{ "Kenya", "Africa", "Nairobi", "EAT-3", "404", "KE"},
{ "Kiribati", "Pacific", "Enderbury", "<+13>-13", "296", "KI"},
{ "Kiribati", "Pacific", "Kiritimati", "<+14>-14", "296", "KI"},
{ "Kiribati", "Pacific", "Tarawa", "<+12>-12", "296", "KI"},
{ "North Korea", "Asia", "Pyongyang", "KST-9", "408", "KP"},
{ "South Korea", "Asia", "Seoul", "KST-9", "410", "KR"},
{ "Kuwait", "Asia", "Kuwait", "<+03>-3", "414", "KW"},
{ "Kyrgyzstan", "Asia", "Bishkek", "<+06>-6", "417", "KG"},
{ "Laos", "Asia", "Vientiane", "<+07>-7", "418", "LA"},
{ "Latvia", "Europe", "Riga", "EET-2EEST,M3.5.0/3,M10.5.0/4", "428", "LV"},
{ "Lebanon", "Asia", "Beirut", "EET-2EEST,M3.5.0/0,M10.5.0/0", "422", "LB"},
{ "Lesotho", "Africa", "Maseru", "SAST-2", "426", "LS"},
{ "Liberia", "Africa", "Monrovia", "GMT0", "430", "LR"},
{ "Libya", "Africa", "Tripoli", "EET-2", "434", "LY"},
{ "Liechtenstein", "Europe", "Vaduz", "CET-1CEST,M3.5.0,M10.5.0/3", "438", "LI"},
{ "Lithuania", "Europe", "Vilnius", "EET-2EEST,M3.5.0/3,M10.5.0/4", "440", "LT"},
{ "Luxembourg", "Europe", "Luxembourg", "CET-1CEST,M3.5.0,M10.5.0/3", "442", "LU"},
{ "Macau", "Asia", "Macau", "CST-8", "446", "MO"},
{ "North Macedonia", "Europe", "Skopje", "CET-1CEST,M3.5.0,M10.5.0/3", "807", "MK"},
{ "Madagascar", "Indian", "Antananarivo", "EAT-3", "450", "MG"},
{ "Malawi", "Africa", "Blantyre", "CAT-2", "454", "MW"},
{ "Malaysia", "Asia", "Kuala_Lumpur", "<+08>-8", "458", "MY"},
{ "Malaysia", "Asia", "Kuching", "<+08>-8", "458", "MY"},
{ "Maldives", "Indian", "Maldives", "<+05>-5", "462", "MV"},
{ "Mali", "Africa", "Bamako", "GMT0", "466", "ML"},
{ "Malta", "Europe", "Malta", "CET-1CEST,M3.5.0,M10.5.0/3", "470", "MT"},
{ "Marshall Islands", "Pacific", "Kwajalein", "<+12>-12", "584", "MH"},
{ "Marshall Islands", "Pacific", "Majuro", "<+12>-12", "584", "MH"},
{ "Martinique", "America", "Martinique", "AST4", "474", "MQ"},
{ "Mauritania", "Africa", "Nouakchott", "GMT0", "478", "MR"},
{ "Mauritius", "Indian", "Mauritius", "<+04>-4", "480", "MU"},
{ "Mayotte", "Indian", "Mayotte", "EAT-3", "175", "YT"},
{ "Mexico", "America", "Bahia_Banderas", "CST6", "484", "MX"},
{ "Mexico", "America", "Cancun", "EST5", "484", "MX"},
{ "Mexico", "America", "Chihuahua", "CST6", "484", "MX"},
{ "Mexico", "America", "Hermosillo", "MST7", "484", "MX"},
{ "Mexico", "America", "Matamoros", "CST6CDT,M3.2.0,M11.1.0", "484", "MX"},
{ "Mexico", "America", "Mazatlan", "MST7", "484", "MX"},
{ "Mexico", "America", "Merida", "CST6", "484", "MX"},
{ "Mexico", "America", "Mexico_City", "CST6", "484", "MX"},
{ "Mexico", "America", "Monterrey", "CST6", "484", "MX"},
{ "Mexico", "America", "Ojinaga", "CST6CDT,M3.2.0,M11.1.0", "484", "MX"},
{ "Mexico", "America", "Tijuana", "PST8PDT,M3.2.0,M11.1.0", "484", "MX"},
{ "Micronesia", "Pacific", "Chuuk", "<+10>-10", "583", "FM"},
{ "Micronesia", "Pacific", "Kosrae", "<+11>-11", "583", "FM"},
{ "Micronesia", "Pacific", "Pohnpei", "<+11>-11", "583", "FM"},
{ "Moldova", "Europe", "Chisinau", "EET-2EEST,M3.5.0,M10.5.0/3", "498", "MD"},
{ "Monaco", "Europe", "Monaco", "CET-1CEST,M3.5.0,M10.5.0/3", "492", "MC"},
{ "Mongolia", "Asia", "Choibalsan", "<+08>-8", "496", "MN"},
{ "Mongolia", "Asia", "Hovd", "<+07>-7", "496", "MN"},
{ "Mongolia", "Asia", "Ulaanbaatar", "<+08>-8", "496", "MN"},
{ "Montenegro", "Europe", "Podgorica", "CET-1CEST,M3.5.0,M10.5.0/3", "499", "ME"},
{ "Montserrat", "America", "Montserrat", "AST4", "500", "MS"},
{ "Morocco", "Africa", "Casablanca", "<+01>-1", "504", "MA"},
{ "Mozambique", "Africa", "Maputo", "CAT-2", "508", "MZ"},
{ "Myanmar", "Asia", "Yangon", "<+0630>-6:30", "104", "MM"},
{ "Namibia", "Africa", "Windhoek", "CAT-2", "516", "NA"},
{ "Nauru", "Pacific", "Nauru", "<+12>-12", "520", "NR"},
{ "Nepal", "Asia", "Kathmandu", "<+0545>-5:45", "524", "NP"},
{ "Netherlands", "Europe", "Amsterdam", "CET-1CEST,M3.5.0,M10.5.0/3", "528", "NL"},
{ "New Caledonia", "Pacific", "Noumea", "<+11>-11", "540", "NC"},
{ "New Zealand", "Pacific", "Auckland", "NZST-12NZDT,M9.5.0,M4.1.0/3", "554", "NZ"},
{ "New Zealand", "Pacific", "Chatham", "<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45", "554", "NZ"},
{ "Nicaragua", "America", "Managua", "CST6", "558", "NI"},
{ "Niger", "Africa", "Niamey", "WAT-1", "562", "NE"},
{ "Nigeria", "Africa", "Lagos", "WAT-1", "566", "NG"},
{ "Niue", "Pacific", "Niue", "<-11>11", "570", "NU"},
{ "Norfolk Island", "Pacific", "Norfolk", "<+11>-11<+12>,M10.1.0,M4.1.0/3", "574", "NF"},
{ "Northern Mariana Islands", "Pacific", "Saipan", "ChST-10", "580", "MP"},
{ "Norway", "Europe", "Oslo", "CET-1CEST,M3.5.0,M10.5.0/3", "578", "NO"},
{ "Oman", "Asia", "Muscat", "<+04>-4", "512", "OM"},
{ "Pakistan", "Asia", "Karachi", "PKT-5", "586", "PK"},
{ "Palau", "Pacific", "Palau", "<+09>-9", "585", "PW"},
{ "Palestine", "Asia", "Gaza", "EET-2EEST,M3.4.4/50,M10.4.4/50", "275", "PS"},
{ "Palestine", "Asia", "Hebron", "EET-2EEST,M3.4.4/50,M10.4.4/50", "275", "PS"},
{ "Panama", "America", "Panama", "EST5", "591", "PA"},
{ "Papua New Guinea", "Pacific", "Bougainville", "<+11>-11", "598", "PG"},
{ "Papua New Guinea", "Pacific", "Port_Moresby", "<+10>-10", "598", "PG"},
{ "Paraguay", "America", "Asuncion", "<-04>4<-03>,M10.1.0/0,M3.4.0/0", "600", "PY"},
{ "Peru", "America", "Lima", "<-05>5", "604", "PE"},
{ "Philippines", "Asia", "Manila", "PST-8", "608", "PH"},
{ "Pitcairn Islands", "Pacific", "Pitcairn", "<-08>8", "612", "PN"},
{ "Poland", "Europe", "Warsaw", "CET-1CEST,M3.5.0,M10.5.0/3", "616", "PL"},
{ "Portugal", "Atlantic", "Azores", "<-01>1<+00>,M3.5.0/0,M10.5.0/1", "620", "PT"},
{ "Portugal", "Europe", "Lisbon", "WET0WEST,M3.5.0/1,M10.5.0", "620", "PT"},
{ "Portugal", "Atlantic", "Madeira", "WET0WEST,M3.5.0/1,M10.5.0", "620", "PT"},
{ "Puerto Rico", "America", "Puerto_Rico", "AST4", "630", "PR"},
{ "Qatar", "Asia", "Qatar", "<+03>-3", "634", "QA"},
{ "Réunion", "Indian", "Reunion", "<+04>-4", "638", "RE"},
{ "Romania", "Europe", "Bucharest", "EET-2EEST,M3.5.0/3,M10.5.0/4", "642", "RO"},
{ "Russia", "Asia", "Anadyr", "<+12>-12", "643", "RU"},
{ "Russia", "Asia", "Barnaul", "<+07>-7", "643", "RU"},
{ "Russia", "Asia", "Chita", "<+09>-9", "643", "RU"},
{ "Russia", "Asia", "Irkutsk", "<+08>-8", "643", "RU"},
{ "Russia", "Asia", "Kamchatka", "<+12>-12", "643", "RU"},
{ "Russia", "Asia", "Krasnoyarsk", "<+07>-7", "643", "RU"},
{ "Russia", "Asia", "Magadan", "<+11>-11", "643", "RU"},
{ "Russia", "Asia", "Novokuznetsk", "<+07>-7", "643", "RU"},
{ "Russia", "Asia", "Novosibirsk", "<+07>-7", "643", "RU"},
{ "Russia", "Asia", "Omsk", "<+06>-6", "643", "RU"},
{ "Russia", "Asia", "Sakhalin", "<+11>-11", "643", "RU"},
{ "Russia", "Asia", "Srednekolymsk", "<+11>-11", "643", "RU"},
{ "Russia", "Asia", "Tomsk", "<+07>-7", "643", "RU"},
{ "Russia", "Asia", "Ust-Nera", "<+10>-10", "643", "RU"},
{ "Russia", "Asia", "Vladivostok", "<+10>-10", "643", "RU"},
{ "Russia", "Asia", "Yakutsk", "<+09>-9", "643", "RU"},
{ "Russia", "Asia", "Yekaterinburg", "<+05>-5", "643", "RU"},
{ "Russia", "Europe", "Astrakhan", "<+04>-4", "643", "RU"},
{ "Russia", "Europe", "Kaliningrad", "EET-2", "643", "RU"},
{ "Russia", "Europe", "Kirov", "MSK-3", "643", "RU"},
{ "Russia", "Europe", "Moscow", "MSK-3", "643", "RU"},
{ "Russia", "Europe", "Samara", "<+04>-4", "643", "RU"},
{ "Russia", "Europe", "Saratov", "<+04>-4", "643", "RU"},
{ "Russia", "Europe", "Ulyanovsk", "<+04>-4", "643", "RU"},
{ "Russia", "Europe", "Volgograd", "MSK-3", "643", "RU"},
{ "Rwanda", "Africa", "Kigali", "CAT-2", "646", "RW"},
{ "Saint Barthélemy", "America", "St_Barthelemy", "AST4", "652", "BL"},
{ "Saint Helena Ascension Island Tristan da Cunha", "Atlantic", "St_Helena", "GMT0", "654", "SH"},
{ "Saint Kitts and Nevis", "America", "St_Kitts", "AST4", "659", "KN"},
{ "Saint Lucia", "America", "St_Lucia", "AST4", "662", "LC"},
{ "The Collectivity of Saint-Martin", "America", "Marigot", "AST4", "663", "MF"},
{ "Saint Pierre and Miquelon", "America", "Miquelon", "<-03>3<-02>,M3.2.0,M11.1.0", "666", "PM"},
{ "Saint Vincent and the Grenadines", "America", "St_Vincent", "AST4", "670", "VC"},
{ "Samoa", "Pacific", "Apia", "<+13>-13", "882", "WS"},
{ "San Marino", "Europe", "San_Marino", "CET-1CEST,M3.5.0,M10.5.0/3", "674", "SM"},
{ "São Tomé and Príncipe", "Africa", "Sao_Tome", "GMT0", "678", "ST"},
{ "Saudi Arabia", "Asia", "Riyadh", "<+03>-3", "682", "SA"},
{ "Senegal", "Africa", "Dakar", "GMT0", "686", "SN"},
{ "Serbia", "Europe", "Belgrade", "CET-1CEST,M3.5.0,M10.5.0/3", "688", "RS"},
{ "Seychelles", "Indian", "Mahe", "<+04>-4", "690", "SC"},
{ "Sierra Leone", "Africa", "Freetown", "GMT0", "694", "SL"},
{ "Singapore", "Asia", "Singapore", "<+08>-8", "702", "SG"},
{ "Sint Maarten", "America", "Lower_Princes", "AST4", "534", "SX"},
{ "Slovakia", "Europe", "Bratislava", "CET-1CEST,M3.5.0,M10.5.0/3", "703", "SK"},
{ "Slovenia", "Europe", "Ljubljana", "CET-1CEST,M3.5.0,M10.5.0/3", "705", "SI"},
{ "Solomon Islands", "Pacific", "Guadalcanal", "<+11>-11", "090", "SB"},
{ "Somalia", "Africa", "Mogadishu", "EAT-3", "706", "SO"},
{ "South Africa", "Africa", "Johannesburg", "SAST-2", "710", "ZA"},
{ "South Georgia and the South Sandwich Islands", "Atlantic", "South_Georgia", "<-02>2", "239", "GS"},
{ "South Sudan", "Africa", "Juba", "CAT-2", "728", "SS"},
{ "Spain", "Atlantic", "Canary", "WET0WEST,M3.5.0/1,M10.5.0", "724", "ES"},
{ "Spain", "Africa", "Ceuta", "CET-1CEST,M3.5.0,M10.5.0/3", "724", "ES"},
{ "Spain", "Europe", "Madrid", "CET-1CEST,M3.5.0,M10.5.0/3", "724", "ES"},
{ "Sri Lanka", "Asia", "Colombo", "<+0530>-5:30", "144", "LK"},
{ "Sudan", "Africa", "Khartoum", "CAT-2", "729", "SD"},
{ "Suriname", "America", "Paramaribo", "<-03>3", "740", "SR"},
{ "Sweden", "Europe", "Stockholm", "CET-1CEST,M3.5.0,M10.5.0/3", "752", "SE"},
{ "Switzerland", "Europe", "Busingen", "CET-1CEST,M3.5.0,M10.5.0/3", "756", "CH"},
{ "Switzerland", "Europe", "Zurich", "CET-1CEST,M3.5.0,M10.5.0/3", "756", "CH"},
{ "Syria", "Asia", "Damascus", "<+03>-3", "760", "SY"},
{ "Taiwan", "Asia", "Taipei", "CST-8", "158", "TW"},
{ "Tajikistan", "Asia", "Dushanbe", "<+05>-5", "762", "TJ"},
{ "Tanzania", "Africa", "Dar_es_Salaam", "EAT-3", "834", "TZ"},
{ "Thailand", "Asia", "Bangkok", "<+07>-7", "764", "TH"},
{ "East Timor", "Asia", "Dili", "<+09>-9", "626", "TL"},
{ "Togo", "Africa", "Lome", "GMT0", "768", "TG"},
{ "Tokelau", "Pacific", "Fakaofo", "<+13>-13", "772", "TK"},
{ "Tonga", "Pacific", "Tongatapu", "<+13>-13", "776", "TO"},
{ "Trinidad and Tobago", "America", "Port_of_Spain", "AST4", "780", "TT"},
{ "Tunisia", "Africa", "Tunis", "CET-1", "788", "TN"},
{ "Turkey", "Europe", "Istanbul", "<+03>-3", "792", "TR"},
{ "Turkmenistan", "Asia", "Ashgabat", "<+05>-5", "795", "TM"},
{ "Turks and Caicos Islands", "America", "Grand_Turk", "EST5EDT,M3.2.0,M11.1.0", "796", "TC"},
{ "Tuvalu", "Pacific", "Funafuti", "<+12>-12", "798", "TV"},
{ "Uganda", "Africa", "Kampala", "EAT-3", "800", "UG"},
{ "Ukraine", "Europe", "Kiev", "EET-2EEST,M3.5.0/3,M10.5.0/4", "804", "UA"},
{ "Ukraine", "Europe", "Simferopol", "MSK-3", "804", "UA"},
{ "Ukraine", "Europe", "Uzhgorod", "EET-2EEST,M3.5.0/3,M10.5.0/4", "804", "UA"},
{ "Ukraine", "Europe", "Zaporozhye", "EET-2EEST,M3.5.0/3,M10.5.0/4", "804", "UA"},
{ "United Arab Emirates", "Asia", "Dubai", "<+04>-4", "784", "AE"},
{ "United Kingdom", "Europe", "Belfast", "GMT0BST,M3.5.0/1,M10.5.0", "826", "UK"},
{ "United Kingdom", "Europe", "Guernsey", "GMT0BST,M3.5.0/1,M10.5.0", "826", "UK"},
{ "United Kingdom", "Europe", "Isle_of_Man", "GMT0BST,M3.5.0/1,M10.5.0", "826", "UK"},
{ "United Kingdom", "Europe", "Jersey", "GMT0BST,M3.5.0/1,M10.5.0", "826", "UK"},
{ "United Kingdom", "Europe", "London", "GMT0BST,M3.5.0/1,M10.5.0", "826", "UK"},
{ "United States", "America", "Adak", "HST10HDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Anchorage", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Boise", "MST7MDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Chicago", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Denver", "MST7MDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Detroit", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Indianapolis", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Knox", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Marengo", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Petersburg", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Tell_City", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Vevay", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Vincennes", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Indiana/Winamac", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Juneau", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Kentucky/Louisville", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Kentucky/Monticello", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Los_Angeles", "PST8PDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Menominee", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Metlakatla", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "New_York", "EST5EDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Nome", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "North_Dakota/Beulah", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "North_Dakota/Center", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "North_Dakota/New_Salem", "CST6CDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Phoenix", "MST7", "840", "US"},
{ "United States", "America", "Sitka", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "America", "Yakutat", "AKST9AKDT,M3.2.0,M11.1.0", "840", "US"},
{ "United States", "Pacific", "Honolulu", "HST10", "840", "US"},
{ "Uruguay", "America", "Montevideo", "<-03>3", "858", "UY"},
{ "Uzbekistan", "Asia", "Samarkand", "<+05>-5", "860", "UZ"},
{ "Uzbekistan", "Asia", "Tashkent", "<+05>-5", "860", "UZ"},
{ "Vanuatu", "Pacific", "Efate", "<+11>-11", "548", "VU"},
{ "Wake Island", "Pacific", "Wake", "<+12>-12", "581", "UM"},
{ "Venezuela", "America", "Caracas", "<-04>4", "862", "VE"},
{ "Vietnam", "Asia", "Ho_Chi_Minh", "<+07>-7", "704", "VN"},
{ "British Virgin Islands", "America", "Tortola", "AST4", "092", "VG"},
{ "United States Virgin Islands", "America", "St_Thomas", "AST4", "850", "VI"},
{ "Wallis and Futuna", "Pacific", "Wallis", "<+12>-12", "876", "WF"},
{ "Western Sahara", "Africa", "El_Aaiun", "<+01>-1", "732", "EH"},
{ "Yemen", "Asia", "Aden", "<+03>-3", "887", "YE"},
{ "Zambia", "Africa", "Lusaka", "CAT-2", "894", "ZM"},
{ "Zimbabwe", "Africa", "Harare", "CAT-2", "716", "ZW"},

{ "\0", "\0", "\0", "\0", "\0", "\0"}

};

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
*/
#endif
