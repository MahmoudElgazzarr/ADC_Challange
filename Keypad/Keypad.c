/*
 * Keypad.c
 *
 * Created: 2/18/2019 2:42:59 PM
 *  Author: AVE-LAP-040
 */ 

#include "Keypad.h"
#include "Keypad_cfg.h"

void Keypad_init()
{
	//Coloumns INPUT
	DIO_SetPinDirection(Keypad_Coloumn1_PIN,INPUT);
	DIO_SetPinDirection(Keypad_Coloumn2_PIN,INPUT);
	DIO_SetPinDirection(Keypad_Coloumn3_PIN,INPUT);
	
	//PUll UP Column
	DIO_WritePin(Keypad_Coloumn1_PIN,HIGH);
	DIO_WritePin(Keypad_Coloumn2_PIN,HIGH);
	DIO_WritePin(Keypad_Coloumn3_PIN,HIGH);
	
	//ROWS OUTPUT
	DIO_SetPinDirection(Keypad_ROW1_PIN,OUTPUT);
	DIO_SetPinDirection(Keypad_ROW2_PIN,OUTPUT);
	DIO_SetPinDirection(Keypad_ROW3_PIN,OUTPUT);

}

uint8 Keypad_getPressedKey()
{
	uint8 Pushed_Button = 0 ;
	DIO_WritePin(Keypad_ROW1_PIN,LOW);
	DIO_WritePin(Keypad_ROW2_PIN,HIGH);
	DIO_WritePin(Keypad_ROW3_PIN,HIGH);
	if(DIO_ReadPin(Keypad_Coloumn1_PIN) == 0)
	{
		Pushed_Button = 1;
	}
	else if(DIO_ReadPin(Keypad_Coloumn2_PIN) == 0)
	{
		Pushed_Button = 2;
	}
	else if(DIO_ReadPin(Keypad_Coloumn3_PIN) == 0)
	{
		Pushed_Button = 3;
	}
	DIO_WritePin(Keypad_ROW1_PIN,HIGH);
	DIO_WritePin(Keypad_ROW2_PIN,LOW);
	DIO_WritePin(Keypad_ROW3_PIN,HIGH);
	if(DIO_ReadPin(Keypad_Coloumn1_PIN) == 0)
	{
			Pushed_Button = 4;
	}
	else if(DIO_ReadPin(Keypad_Coloumn2_PIN) == 0)
	{
			Pushed_Button = 5;
	}
	else if(DIO_ReadPin(Keypad_Coloumn3_PIN) == 0)
	{
			Pushed_Button = 6;
	}
		DIO_WritePin(Keypad_ROW1_PIN,HIGH);
		DIO_WritePin(Keypad_ROW2_PIN,HIGH);
		DIO_WritePin(Keypad_ROW3_PIN,LOW);
		if(DIO_ReadPin(Keypad_Coloumn1_PIN) == 0)
		{
			Pushed_Button = 7;
		}
		else if(DIO_ReadPin(Keypad_Coloumn2_PIN) == 0)
		{
			Pushed_Button = 8;
		}
		else if(DIO_ReadPin(Keypad_Coloumn3_PIN) == 0)
		{
			Pushed_Button = 9;
		}
		return Pushed_Button;
	
}