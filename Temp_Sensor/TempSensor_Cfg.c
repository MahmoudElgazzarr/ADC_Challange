/*
 * TempSensor_Cfg.c
 *
 * Created: 4/8/2019 6:17:14 PM
 *  Author: AVE-LAP-040
 */
#include <stdint-gcc.h>
#include "TempSensor.h"
#include "TempSensor_Cfg.h"

#define Sensor_Max_Degree 150
#define Sensor_Mille_Volt_Per_Degree 10
 
TempSensors_config_t TempSensors_config_Arr[Max_Elemnts]={{ID_0,Sensor_Mille_Volt_Per_Degree,0,Sensor_Max_Degree}};