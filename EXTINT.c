/*
 * EXTINT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */
//Generic Initialization function for External interrupts of AVR-Atmega32 in any mode.
#include <avr\interrupt.h>
#include "types1.h"
#include "DIO.h"
#include "types.h"
#include "EXTINT.h"
#define MODE FALLING_EDGE
#define INT_PIN 0
void EXTINT_vidInit(void){
#if INT_PIN == 0
	DIO_vidSetPinDirection(3,INT0,0);
	DIO_vidSetPinValue(3,INT0,1);
	SET_BIT(GICR,6);
	#if MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	#elif MODE == FALLING_EDGE
	SET_BIT(MCUCR,1);
	#elif MODE == RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#endif
#elif INT_PIN == 1
	DIO_vidSetPinDirection(3,INT1,0);
	DIO_vidSetPinValue(3,INT1,1);
	SET_BIT(GICR,7);
	#if MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR,2);
	#elif MODE == FALLING_EDGE
	SET_BIT(MCUCR,3);
	#elif MODE == RISING_EDGE
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#endif
#elif INT_PIN == 2
	DIO_vidSetPinDirection(1,INT2,0);
	DIO_vidSetPinValue(1,INT2,1);
	SET_BIT(GICR,5);
	#if MODE == FALLING_EDGE
	CLEAR_BIT(MCUCSR,6);
	#elif MODE == RISING_EDGE
	SET_BIT(MCUCSR,6);
	#endif
#endif
}
/*
void Set_ExtIntCallBack(void(*ptr)(void)){
	int_ptr= ptr;
}*/
