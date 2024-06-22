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

/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-i2c-communication-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
/*
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define I2C_SDA 33
#define I2C_SCL 32

#define SEALEVELPRESSURE_HPA (1013.25)

TwoWire I2CBME = TwoWire(0);
Adafruit_BME280 bme;

unsigned long delayTime;

void setup() {
  Serial.println(F("BME280 test"));
  I2CBME.begin(I2C_SDA, I2C_SCL, 100000);

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76, &I2CBME);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
}

void loop() { 
  printValues();
  delay(delayTime);
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  // Convert temperature to Fahrenheit
  //Serial.print("Temperature = ");
  //Serial.print(1.8 * bme.readTemperature() + 32);
  //Serial.println(" *F");
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}

*/
//#include "ESP32_Nixie.h"
/*
void BME280_Init(void)
{
    uint8_t ID,VER;
    uint8_t reg;
    ID = DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_CHIPID);
    
    if(ID != 0X60)
    {
        Serial.printf("Error:Not found BME280 \r\n");
        return;
    }
    VER = DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_VERSION);
    printf("BME280 VERSION = %d",VER);
    reg = BME280_HUM_OSRS_1;
    DEV_I2C_Write_Byte(BME280_I2C_ADDR, BME280_REGISTER_CONTROLHUMID, reg);
    reg =BME280_PRESS_OSRS_1 | BME280_TEMP_OSRS_1| BME280_MODE_NORMAL;
    DEV_I2C_Write_Byte(BME280_I2C_ADDR, BME280_REGISTER_CONTROL, reg);

    reg =BME280_TIME_STANDBY_1000MS|BME280_FILTER_OFF|BME280_SPI3W_DIS;
    DEV_I2C_Write_Byte(BME280_I2C_ADDR, BME280_REGISTER_CONFIG, reg);

}
void BME280_Reset(void)
{
    uint8_t reg;
    reg = BME280_RESET;
    DEV_I2C_Write_Byte(BME280_I2C_ADDR, BME280_REGISTER_SOFTRESET, reg);

}
void BME280_Read_Calib_Data(bme280_calib_data *data)
{
  data->dig_T1 = (uint16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_T1);
  data->dig_T2 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_T2);
  data->dig_T3 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_T3);

  data->dig_P1 = (uint16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P1);
  data->dig_P2 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P2);
  data->dig_P3 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P3);
  data->dig_P4 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P4);
  data->dig_P5 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P5);
  data->dig_P6 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P6);
  data->dig_P7 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P7);
  data->dig_P8 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P8);
  data->dig_P9 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_P9);

  data->dig_H1 = (uint8_t)DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H1);
  data->dig_H2 = (int16_t)DEV_I2C_Read_Register(BME280_I2C_ADDR, BME280_REGISTER_DIG_H2);
  data->dig_H3 = (uint8_t)DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H3);
  data->dig_H4 = (DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H4) << 4) | (DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H4+1) & 0xF);
  data->dig_H5 = (DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H5+1) << 4) | (DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H5) >> 4);
  data->dig_H6 = (int8_t)DEV_I2C_Read_Byte(BME280_I2C_ADDR, BME280_REGISTER_DIG_H6);

}
uint32_t BME280_Get_Temp_Calib(bme280_calib_data *cal, uint32_t adc_T)
{
     int32_t var1  = ((((adc_T>>3) - ((int32_t)cal->dig_T1 <<1))) *
     ((int32_t)cal->dig_T2)) >> 11;

  int32_t var2  = (((((adc_T>>4) - ((int32_t)cal->dig_T1)) *
       ((adc_T>>4) - ((int32_t)cal->dig_T1))) >> 12) *
     ((int32_t)cal->dig_T3)) >> 14;

  return var1 + var2;
}

void BME280_Read_RawData(bme280_raw_data * data)
{
    uint8_t buf[8];
    uint32_t press,temp,hum;
    DEV_I2C_Read_nByte(BME280_I2C_ADDR, BME280_REGISTER_PRESSUREDATA, buf, 8);
    press = (buf[0]<<12) | (buf[1] <<4)| (buf[2]>>4);
    temp = (buf[3]<<12) | (buf[4] <<4)| (buf[5]>>4);
    hum  = (buf[6] <<8)| (buf[7]);
    data->pressure=press;
    data->temperature=temp;
    data->humidity=hum;
}

float BME280_Compensate_Temperature(int32_t t_fine) {
  float T  = (t_fine * 5 + 128) >> 8;
  return T/100;
}

float BME280_Compensate_Pressure(int32_t adc_P, bme280_calib_data *cal, int32_t t_fine) {
  int64_t var1, var2, p;

  var1 = ((int64_t)t_fine) - 128000;
  var2 = var1 * var1 * (int64_t)cal->dig_P6;
  var2 = var2 + ((var1*(int64_t)cal->dig_P5)<<17);
  var2 = var2 + (((int64_t)cal->dig_P4)<<35);
  var1 = ((var1 * var1 * (int64_t)cal->dig_P3)>>8) +
    ((var1 * (int64_t)cal->dig_P2)<<12);
  var1 = (((((int64_t)1)<<47)+var1))*((int64_t)cal->dig_P1)>>33;

  if (var1 == 0) {
    return 0;  // avoid exception caused by division by zero
  }
  p = 1048576 - adc_P;
  p = (((p<<31) - var2)*3125) / var1;
  var1 = (((int64_t)cal->dig_P9) * (p>>13) * (p>>13)) >> 25;
  var2 = (((int64_t)cal->dig_P8) * p) >> 19;

  p = ((p + var1 + var2) >> 8) + (((int64_t)cal->dig_P7)<<4);
  return (float)p/256;
}

float BME280_Compensate_Humidity(int32_t adc_H, bme280_calib_data *cal, int32_t t_fine) {
  int32_t v_x1_u32r;

  v_x1_u32r = (t_fine - ((int32_t)76800));

  v_x1_u32r = (((((adc_H << 14) - (((int32_t)cal->dig_H4) << 20) -
      (((int32_t)cal->dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) *
         (((((((v_x1_u32r * ((int32_t)cal->dig_H6)) >> 10) *
        (((v_x1_u32r * ((int32_t)cal->dig_H3)) >> 11) + ((int32_t)32768))) >> 10) +
      ((int32_t)2097152)) * ((int32_t)cal->dig_H2) + 8192) >> 14));

  v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) *
           ((int32_t)cal->dig_H1)) >> 4));

  v_x1_u32r = (v_x1_u32r < 0) ? 0 : v_x1_u32r;
  v_x1_u32r = (v_x1_u32r > 419430400) ? 419430400 : v_x1_u32r;
  float h = (v_x1_u32r>>12);
  return  h / 1024.0;
}
float BME280_Get_Altitude(float pressure)
{
    return 44330.0 * (1.0 - pow(pressure / MEAN_SEA_LEVEL_PRESSURE, 0.190294957));
}

// set address
bool reserved_addr(uint8_t addr) {
  return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}


*/