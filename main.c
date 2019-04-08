/*
* UART_Test.c
*
* Created: 2/27/2019 5:07:38 PM
* Author : AVE-LAP-040
*/
#define F_CPU 16000000UL
#include <stdint-gcc.h>
#include "UART.h"
#include "UART_CFG.h"
#include "LEDS.h"
#include "LCD_Cfg.h"
#include "LCD.h"
#include "avr/io.h"
#include "ADC_Cfg.h"
#include "ADC.h"
#include "TempSensor.h"
#include "avr/delay.h"

uint8_t Temp = 0;

int main(void)
{
	/*Fill Structure of baud rate */
	UART_Config_S.BaudRate      = BAUD_RATE;   /* Set BaudRate */
	UART_Config_S.No_StopBits   = UART_TwoStopBit; /* Set Numbers of Stop Bits ( 1 or 2) */
	UART_Config_S.ParityMode    = UART_DisableParityBit;  /* Set Parity Mode (No Parity , Even , Odd) */
	UART_Config_S.DataSize      = UART_8_Bits;    /* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
	UART_Config_S.SpeedMode     = UART_NormalSpeedMode;   /* Set Speed Mode ( Normal or Double ) */
	UART_Config_S.ClockPolarity = UART_RisingPol;   /* Set UART Clock Polarity ( Rising Edge or Falling Edge ) */
	/*LCD Init*/
	LCD_init();
	/*Inalize Buzzer As OUTPUT*/
	DDRB |= (1<<PINB3);
	/* init UART */
	UART_Init ();
	/*Led init*/
	led_One_Init();
	led_Two_Init();
	/*Initalize ADC*/
	ADC_Initialize();
	/*Inalizlie Direction For ADC*/
	DDRA &=~(1<<PINA0);
	/*Enable ADC*/
	ADC_Enable();
	
	_delay_ms(50);
	while (1)
	{
		/*Read Temp*/
		Temp = TempSensor_ReadValue(ID_0);
		/*Send Temp Over UART*/
		USART_Transmit((uint8_t)Temp);
		/*Display Temp*/
		LCD_displayString("Temp : ");
		/*Display Three Digits */
		LCD_displayChar(Temp /100 + '0');
		LCD_displayChar(Temp / 10 + '0');
		LCD_displayChar(Temp % 10 + '0');
		_delay_ms(500);
		LCD_clear();
		_delay_ms(5);
		/*If Temp > 40 Turn On Buzzer*/
		if(Temp > 40)
		{
			/*Turn On Buzzer*/
			PORTB |= (1<<PINB3);
		}
		/*If Temp < 40 Turn Of Buzzer*/
		else
		{
			/*Turn Off Buzzer*/
			PORTB &=~(1<<PINB3);
		}
		Led_One_Toggle();
		Led_Two_Toggle();
		_delay_ms(500);
	}
}
