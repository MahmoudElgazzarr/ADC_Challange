/*
 * Temp_Sensor.c
 *
 * Created: 4/8/2019 5:44:21 PM
 *  Author: AVE-LAP-040
 */ 
#include <stdint-gcc.h>
#include "ADC.h"
#include "TempSensor_Cfg.h"
#include "TempSensor.h"


uint16_t Result;
double Volt;
uint32_t Degree;
uint8_t TempSensor_ReadValue(uint8_t ID)
{
	switch(ID)
	{
		case ID_0:
		Result = ADC_StartConversion(ID);
		Volt =  ( (double) ( Result * VREF ) / Bit_Mode );
		Degree = ( (Volt * 1000) / TempSensors_config_Arr[ID].Sensor_Mille_Volt_Per_Degree);
		break;
	}
	return (uint8_t)Degree;
}