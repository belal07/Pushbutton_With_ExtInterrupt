/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */
#include <avr\io.h>
#include "types1.h"
#include "DIO.h"
#include "ADC.h"

void ADC_vidInit(void){
	/*DIO_vidSetPinDirection(0,0,0);		//Set Pin A0 as Input
	DIO_vidSetPinValue(0,0,1);*/			// Enable The pull Up Resistance
	ADMUX |= (1<<6) | (1<<7); 	//Set The Reference voltage source as internal 2.56 V using ADC0 as the analog input
	ADCSRA |= (1<<5);   // Enable ADC Auto Trigger
	ADCSRA |= (1<<3);   // Enable ADC Interrupt
	ADCSRA |= (1<<1) | (1<<2);   // SET ADC Prescaler as 64
	SFIOR |= (1<<5) | (1<<7); // Specify the trigger source as timer1 Compare match B
	ADCSRA |= (1<<7);       // Enable The ADC
}

u8 ADC_u8GetTemp(void){
u16 * ADC_value = &ADCL;		// a Variable to Read The Digital Result From ADC module
u8 temperature;		// a Variable to Save The Temperature Value
temperature = (u8)((*ADC_value)/4);  // Division by 4 Operation to convert the result W.R.T Step Size of Temp Sensor
return temperature;
}
