/*
 * DIO.c
 *
 *  Created on: Mar 31, 2018
 *      Author: pc lab top
 */
#include <avr\io.h>
#include "types1.h"
#include "types.h"
void DIO_vidSetPortDirection(u8 port,u8 value){
	switch (port){
		case 0:
		DDRA = value;
		break;
		case 1:
			DDRB = value;
			break;
		case 2:
			DDRC = value;
			break;
		case 3:
			DDRD = value;
			break;
	}
}

void DIO_vidSetPortValue(u8 port,u8 value){
	switch (port){
		case 0:
			PORTA = value;
			break;
		case 1:
			PORTB = value;
			break;
		case 2:
			PORTC = value;
			break;
		case 3:
			PORTD = value;
			break;
	}
}

void DIO_vidSetPinDirection(u8 port,u8 pin,u8 value){
	switch (port){
		case 0:
			if(value == 1)SET_BIT(DDRA,pin);
			else if(value == 0)CLEAR_BIT(DDRA,pin);
			break;
		case 1:
			if(value == 1)SET_BIT(DDRB,pin);
			else if(value == 0)CLEAR_BIT(DDRB,pin);
			break;
		case 2:
			if(value == 1)SET_BIT(DDRC,pin);
			else if(value == 0)CLEAR_BIT(DDRC,pin);
			break;
		case 3:
			if(value == 1)SET_BIT(DDRD,pin);
			else if(value == 0)CLEAR_BIT(DDRD,pin);
			break;
	}
}

void DIO_vidSetPinValue(u8 port,u8 pin,u8 value){
	switch (port){
		case 0:
			if(value == 1)SET_BIT(PORTA,pin);
			else if(value == 0)CLEAR_BIT(PORTA,pin);
			break;
		case 1:
			if(value == 1)SET_BIT(PORTB,pin);
			else if(value == 0)CLEAR_BIT(PORTB,pin);
			break;
		case 2:
			if(value == 1)SET_BIT(PORTC,pin);
			else if(value == 0)CLEAR_BIT(PORTC,pin);
			break;
		case 3:
			if(value == 1)SET_BIT(PORTD,pin);
			else if(value == 0)CLEAR_BIT(PORTD,pin);
			break;
	}
}

u8 DIO_u8ReadPortValue(u8 port){
	u8 value;
	switch(port){
	case 0:
		value = PINA;
		break;
	case 1:
		value = PINB;
		break;
	case 2:
		value = PINC;
		break;
	case 3:
		value = PIND;
		break;
	}
	return value;
}

u8 DIO_u8ReadPinValue(u8 port,u8 pin){
	u8 value = 0;
	switch (port){
	case 0:
		value = GET_BIT(PINA,pin);
		break;
	case 1:
		value = GET_BIT(PINB,pin);
		break;
	case 2:
		value = GET_BIT(PINC,pin);
				break;
	case 3:
		value = GET_BIT(PIND,pin);
				break;
	}
	return value;
}
