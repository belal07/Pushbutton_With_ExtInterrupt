/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */
#include <avr\interrupt.h>
#include "types1.h"
#include "types.h"
#include "UART.h"
#include "ADC.h"
#include "TIMER.h"
#include "EXTINT.h"
#include "DIO.h"
#define LED_PIN 1
int main(){
	DIO_vidSetPinDirection(0,LED_PIN,1); // Set LED Pin As Output
	DIO_vidSetPinValue(0,LED_PIN,0);	//Start with LED in Off state
	EXTINT_vidInit();				//Initialize External Interrupt
	UART_vidInit();					//Initialize UART Serial communication
	ADC_vidInit();					//Initialize ADC Module
	TIMER1_vidInit();				// Initialize Timer1 and Run it
	TIMER0_vidInit();				//Configure Timer0 without Running it
	sei();
	while(1){
	}
	return 0;
}

ISR(TIMER0_COMP_vect){
static u8 counter = 0;
TCCR0 &=~ ((1<<0) | (1<<1) | (1<<2)); // Disable Timer0
SET_BIT(GIFR,6); 	// CLEAR The External interrupt 0 Flag
SET_BIT(GICR,6);   	// Enable External Interrupt on Pin 0
if((DIO_u8ReadPinValue(3,2)) == 0U){
	counter++;
	switch(counter){
	case 1:
		TOGGLE_BIT(PORTA,LED_PIN);
		UART_vidSendString("PRESSED ");
		UART_vidSendString("(LED ON)");
		break;
	case 2:
		TOGGLE_BIT(PORTA,LED_PIN);
		UART_vidSendString("PRESSED ");
		UART_vidSendString("(LED OFF)");
		counter = 0;
		break;
		}
	}
}

ISR(INT0_vect){
CLEAR_BIT(GICR,6); 	// Disable The External Interrupt
TCCR0 |= (1<<0) | (1<<2); 	// Start Timer 0 With Prescaler 1024
}

ISR(ADC_vect){
	SET_BIT(TIFR,3);  	// Clear Timer1 Compare Match Interrupt Flag
	UART_vidSendNumber(ADC_u8GetTemp()); // Send The Temperature to Serial Monitor
}
