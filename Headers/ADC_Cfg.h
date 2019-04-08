/*
* ADC_Cfg.h
*
* Created: 4/7/2019 12:57:46 PM
*  Author: AVE-LAP-040
*/


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADC_RESOLUTION_MODE Bit_Mode_8
#define ADC_PRESCALER_DIVISION DIVIDE_BY_128
#define ADC_TRIGERRING_MODE Free_Running_mode
#define ADC_REFERENCE_VOLTAGE AVCC
/*Todo Adding Single Shot Mode*/
#define ADC_OPERATION_MODE Running_Mode

enum RESOLUTION_MODE
{
	Bit_Mode_8,
	Bit_Mode_10,
};
enum voltage_Refrance
{
	AREF,
	AVCC,
	Internal,
};
enum ADC_PRESCALER
{
	DIVIDE_BY_2,
	DIVIDE_BY_4,
	DIVIDE_BY_8,
	DIVIDE_BY_16,
	DIVIDE_BY_32,
	DIVIDE_BY_64,
	DIVIDE_BY_128,
};

enum OPERATION_MODE
{
	Single_Shot,
	Running_Mode,
};
enum TRIGERRING_MODE
{
	Free_Running_mode,
};

#endif /* ADC_CFG_H_ */