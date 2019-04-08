/*
 * Keypad.h
 *
 * Created: 2/18/2019 2:43:15 PM
 *  Author: AVE-LAP-040
 */ 

#include "Types.h"
#include "DIO_Definitions.h"
#include "DIO.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

void Keypad_init();
uint8 Keypad_getPressedKey();


#endif /* KEYPAD_H_ */