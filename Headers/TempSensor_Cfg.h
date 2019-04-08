/*
 * TempSensor_Cfg.h
 *
 * Created: 4/8/2019 6:13:47 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef TEMPSENSOR_CFG_H_
#define TEMPSENSOR_CFG_H_

/*Definionations About ADC*/
#define VREF 5
#define Bit_Mode 253

#define  Max_Elemnts 6

typedef struct Temp
{
uint8_t ID;
uint8_t Sensor_Mille_Volt_Per_Degree;
uint8_t Sensor_Min_Degree;
uint8_t Sensor_Max_Degree;
}TempSensors_config_t;

extern TempSensors_config_t TempSensors_config_Arr[Max_Elemnts];

#endif /* TEMPSENSOR_CFG_H_ */