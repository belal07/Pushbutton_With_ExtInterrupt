/*
 * TIMER.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */
#include <avr\io.h>
#include "TIMER.h"
#include "types1.h"
void TIMER0_vidInit(void){
TCCR0 |= (1<<WGM01);  	// Select The Timer Mode As CLEAR On Timer Compare (CTC)
TIMSK |= (1<<OCIE0);   	// Enable Timer Compare Match Interrupt
OCR0 = 234;       // which applies a delay of 30 millisecond
}

void TIMER1_vidInit(void){
u16 OCR_value;
TCCR1B |= (1<<3); // Specify the Mode of operation as CTC Mode using OCRx Register as Top Value
OCR_value = TIMER1_DELAY/(PRE_SCALER/F_CPU);
OCR1BH |= (OCR_value>>8);
OCR1BL |= OCR_value;
OCR1AH |= (OCR_value>>8);
OCR1AL |= OCR_value;
TCCR1B |= (1<<0) | (1<<2);	// Start The timer with Clock-Prescaler 1024
}
