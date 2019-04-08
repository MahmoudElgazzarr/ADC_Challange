/*
* ADC.h
*
* Created: 4/7/2019 12:57:15 PM
*  Author: AVE-LAP-040
*/


#ifndef ADC_H_
#define ADC_H_

enum Channels
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
};
void ADC_Initialize(void);
uint16_t ADC_StartConversion(uint8_t Ch);
uint16_t ADC_GetConvertedValue(uint8_t Ch);
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
void ADC_setCallBack(void (*ptr)(void));


#endif /* ADC_H_ */