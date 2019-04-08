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

#define VREF 5000
#define Bit_Mode 254
uint16_t Result;
double Mille_Volt;
double Degree;
uint8_t TempSensor_ReadValue(uint8_t ID)
{
	switch(ID)
	{
		case ID_0:
		Result = ADC_StartConversion(ID);
		Mille_Volt = ( ( Result * VREF ) / Bit_Mode );
		Degree = Mille_Volt / ( double )TempSensors_config_Arr[ID].Sensor_Mille_Volt_Per_Degree;
		break;
	}
	return (uint8_t)Degree;
}