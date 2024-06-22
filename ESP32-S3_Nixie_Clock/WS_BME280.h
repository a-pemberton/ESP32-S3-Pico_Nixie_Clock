//---------------------------------------------------------------------------------------------
//
// Module:              Waveshare Nixie Clock BME280 Environment module source file
// Filename:            WS_BME280.c
// Version:             1.0
// Date:                09/SEP/2023
// Author:              Waveshare modified by A.Pemberton
// Function:            BME280 Environment monitor chip file
// Change History:      None
//
//---------------------------------------------------------------------------------------------

#ifndef _WS_BME280_H_
#define _WS_BME280_H_

// i2c slave address of the BME280 chip
#define BME280_I2C_ADDR (0x76)

#define BME280_REGISTER_DIG_T1 (0x88)
#define BME280_REGISTER_DIG_T2 (0x8A)
#define BME280_REGISTER_DIG_T3 (0x8C)
#define BME280_REGISTER_DIG_P1 (0x8E)
#define BME280_REGISTER_DIG_P2 (0x90)
#define BME280_REGISTER_DIG_P3 (0x92)
#define BME280_REGISTER_DIG_P4 (0x94)
#define BME280_REGISTER_DIG_P5 (0x96)
#define BME280_REGISTER_DIG_P6 (0x98)
#define BME280_REGISTER_DIG_P7 (0x9A)
#define BME280_REGISTER_DIG_P8 (0x9C)
#define BME280_REGISTER_DIG_P9 (0x9E)
#define BME280_REGISTER_DIG_H1 (0xA1)
#define BME280_REGISTER_DIG_H2 (0xE1)
#define BME280_REGISTER_DIG_H3 (0xE3)
#define BME280_REGISTER_DIG_H4 (0xE4)
#define BME280_REGISTER_DIG_H5 (0xE5)
#define BME280_REGISTER_DIG_H6 (0xE7)
#define BME280_REGISTER_CHIPID (0xD0)
#define BME280_REGISTER_VERSION (0xD1)
#define BME280_REGISTER_SOFTRESET (0xE0)
#define BME280_RESET (0xB6)
#define BME280_REGISTER_CAL26 (0xE1)
#define BME280_REGISTER_CONTROLHUMID (0xF2)
#define BME280_REGISTER_CONTROL (0xF4)
#define BME280_REGISTER_CONFIG (0xF5)
#define BME280_REGISTER_PRESSUREDATA (0xF7)
#define BME280_REGISTER_TEMPDATA (0xFA)
#define BME280_REGISTER_HUMIDDATA (0xFD)

#define MEAN_SEA_LEVEL_PRESSURE (1013)

enum
{
  BME280_HUM_OSRS_SKIP = 0x00,
  BME280_HUM_OSRS_1 = 0x01,
  BME280_HUM_OSRS_2 = 0x02,
  BME280_HUM_OSRS_4 = 0x03,
  BME280_HUM_OSRS_8 = 0x04,
  BME280_HUM_OSRS_16 = 0x05,
};

enum
{
  BME280_PRESS_OSRS_SKIP = 0x00,
  BME280_PRESS_OSRS_1 = 0x20,
  BME280_PRESS_OSRS_2 = 0x40,
  BME280_PRESS_OSRS_4 = 0x60,
  BME280_PRESS_OSRS_8 = 0x80,
  BME280_PRESS_OSRS_16 = 0xA0,
};

enum
{
  BME280_TEMP_OSRS_SKIP = 0x00,
  BME280_TEMP_OSRS_1 = 0x04,
  BME280_TEMP_OSRS_2 = 0x08,
  BME280_TEMP_OSRS_4 = 0x0c,
  BME280_TEMP_OSRS_8 = 0x10,
  BME280_TEMP_OSRS_16 = 0x14,
};

enum
{
  BME280_MODE_SLEEP = 0x00,
  BME280_MODE_FORCED = 0x01,
  BME280_MODE_NORMAL = 0x03,
};

enum
{
  BME280_TIME_STANDBY_0_5MS = 0x00,
  BME280_TIME_STANDBY_62_5MS = 0x20,
  BME280_TIME_STANDBY_125MS = 0x40,
  BME280_TIME_STANDBY_250MS = 0x60,
  BME280_TIME_STANDBY_500MS = 0x80,
  BME280_TIME_STANDBY_1000MS = 0xA0,
  BME280_TIME_STANDBY_10MS = 0xC0,
  BME280_TIME_STANDBY_20MS = 0xE0,
};
enum
{
  BME280_FILTER_OFF = 0x00,
  BME280_FILTER_2 = 0x04,
  BME280_FILTER_4 = 0x08,
  BME280_FILTER_8 = 0x0C,
  BME280_FILTER_16 = 0x10,
};
#define BME280_SPI3W_EN (0X01)
#define BME280_SPI3W_DIS (0X00)

/*
 * Immutable calibration data read from bme280
 */
typedef struct
{
  uint16_t dig_T1;
  int16_t dig_T2;
  int16_t dig_T3;

  uint16_t dig_P1;
  int16_t dig_P2;
  int16_t dig_P3;
  int16_t dig_P4;
  int16_t dig_P5;
  int16_t dig_P6;
  int16_t dig_P7;
  int16_t dig_P8;
  int16_t dig_P9;

  uint8_t dig_H1;
  int16_t dig_H2;
  uint8_t dig_H3;
  int16_t dig_H4;
  int16_t dig_H5;
  int8_t dig_H6;
} bme280_calib_data;

/*
 * Raw sensor measurement data from bme280
 */
typedef struct
{
  uint32_t temperature;
  uint32_t pressure;
  uint32_t humidity;
} bme280_raw_data;

void BME280_Init(void);
void BME280_Reset(void);

void BME280_Read_Calib_Data(bme280_calib_data *data);
uint32_t BME280_Get_Temp_Calib(bme280_calib_data *cal, uint32_t adc_T);


void BME280_Read_RawData(bme280_raw_data *data);
float BME280_Compensate_Temperature(int32_t t_fine);
float BME280_Compensate_Pressure(int32_t adc_P, bme280_calib_data *cal, int32_t t_fine);
float BME280_Compensate_Humidity(int32_t adc_H, bme280_calib_data *cal, int32_t t_fine);
float BME280_Get_Altitude(float pressure);
#endif
