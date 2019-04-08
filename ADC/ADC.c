/*
* ADC.c
*
* Created: 4/7/2019 12:56:29 PM
*  Author: AVE-LAP-040
*/

#include <stdint-gcc.h>
#include "avr/io.h"
#include "BitwiseOperation.h"
#include "ADC_Cfg.h"
#include "ADC.h"
#include "avr/interrupt.h"

#define NULL ((void *)0x00)
void (*Pointer_To_Func)(void) = NULL;
uint16_t Value;

void ADC_Initialize(void)
{
	/*Chose Voltage*/
	switch(ADC_REFERENCE_VOLTAGE)
	{
		case AREF:
		ADMUX &=~(1<<REFS0);
		ADMUX &=~(1<<REFS1);
		break;
		case AVCC:
		ADMUX |= (1<<REFS0);
		ADMUX &=~(1<<REFS1);
		break;
		case  Internal:
		ADMUX |= (1<<REFS0);
		ADMUX |=(1<<REFS1);
		break;
	};
	/*Switch Prescaler*/
	switch(ADC_PRESCALER_DIVISION)
	{
		case DIVIDE_BY_2:
		Clear_Bit(ADCSRA,ADPS0);
		Clear_Bit(ADCSRA,ADPS1);
		Clear_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_4:
		Clear_Bit(ADCSRA,ADPS0);
		Set_Bit(ADCSRA,ADPS1);
		Clear_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_8:
		Set_Bit(ADCSRA,ADPS0);
		Set_Bit(ADCSRA,ADPS1);
		Clear_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_16:
		Clear_Bit(ADCSRA,ADPS0);
		Clear_Bit(ADCSRA,ADPS1);
		Set_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_32:
		Set_Bit(ADCSRA,ADPS0);
		Clear_Bit(ADCSRA,ADPS1);
		Set_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_64:
		Clear_Bit(ADCSRA,ADPS0);
		Set_Bit(ADCSRA,ADPS1);
		Set_Bit(ADCSRA,ADPS2);
		break;
		case DIVIDE_BY_128:
		Set_Bit(ADCSRA,ADPS0);
		Set_Bit(ADCSRA,ADPS1);
		Set_Bit(ADCSRA,ADPS2);
		break;
	};
	/*Chose Operational Mode*/
	switch(ADC_TRIGERRING_MODE)
	{
		case Free_Running_mode:
		/*Enable Free Running Mode*/
		Set_Bit(ADCSRA,ADATE);
		Clear_Bit(SFIOR,ADTS0);
		Clear_Bit(SFIOR,ADTS1);
		Clear_Bit(SFIOR,ADTS2);
		break;
	};
	/*Chose ADC Resolution If it 8-bit Mode Or 10-Bit Mode*/
	switch(ADC_RESOLUTION_MODE)
	{
		case Bit_Mode_8:
		Set_Bit(ADMUX,ADLAR);
		break;
		case Bit_Mode_10:
		Clear_Bit(ADMUX, ADLAR);
		break;
	}
}

/*Start Conversion , Async Func*/
uint16_t ADC_StartConversion(uint8_t Ch)
{
	switch(Ch)
	{
		case ADC0:
		ADMUX &=~(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC1:
		ADMUX |=(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC2:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC3:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC4:
		ADMUX &=~(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC5:
		ADMUX |=(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC6:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC7:
		ADMUX |=(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
	};
	ADCSRA |= (1<<ADSC);
	/*Waite Until Conversion Is Finished*/
	while(Get_Bit(ADCSRA , ADIF) == 0);
	Set_Bit(ADCSRA , ADIF);
	switch(ADC_RESOLUTION_MODE)
	{
		case Bit_Mode_8:
		Value = ADCH;
		break;
		case Bit_Mode_10:
		Value = ADCL;
		Value |= (8<<ADCH);
		break;
	}
	return Value;
}

/*Get Converted Value*/
uint16_t ADC_GetConvertedValue(uint8_t Ch)
{
	/*Chose Channel*/
	switch(Ch)
	{
		case ADC0:
		ADMUX &=~(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC1:
		ADMUX |=(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC2:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC3:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX &=~(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC4:
		ADMUX &=~(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC5:
		ADMUX |=(1<<MUX0);
		ADMUX &=~(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC6:
		ADMUX &=~(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
		case ADC7:
		ADMUX |=(1<<MUX0);
		ADMUX |=(1<<MUX1);
		ADMUX |=(1<<MUX2);
		ADMUX &=~(1<<MUX3);
		break;
	};
	/*Chose ADC Resolution If it 8-bit Mode Or 10-Bit Mode*/
	switch(ADC_RESOLUTION_MODE)
	{
		case Bit_Mode_8:
		Value = ADCH;
		break;
		case Bit_Mode_10:
		Value = ADCL;
		Value |= (ADCH<<8);
		break;
	}
	return Value;
}
/*Enable ADC*/
void ADC_Enable(void)
{
	ADCSRA|=(1<<ADEN);
}
/*Disable ADC*/
void ADC_Disable(void)
{
	Clear_Bit(ADCSRA ,ADEN );
}

/*Enable Interrupt*/
void ADC_InterruptEnable(void)
{
	Set_Bit(ADCSRA , ADIE);
}
/*Disable Interrupt*/
void ADC_InterruptDisable(void)
{
	Clear_Bit(ADCSRA , ADIE);
}

/*Set Call Back Function*/
void ADC_setCallBack(void (*ptr)(void))
{
	Pointer_To_Func = ptr;
}

#if 0
/*ISR Function*/
void ISR(ADC_vect)
{
	Pointer_To_Func();
}
#endif