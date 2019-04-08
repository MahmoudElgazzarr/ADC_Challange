/*
 * Temp_Sensor.h
 *
 * Created: 4/8/2019 5:45:06 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

uint8_t TempSensor_ReadValue(uint8_t ID);

enum
{
	ID_0,
	ID_1,
	ID_2,
	ID_3,
	ID_4,
	ID_5,
	ID_6,
	ID_7,
};

#endif /* TEMP_SENSOR_H_ */