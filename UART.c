/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */
#include "avr\interrupt.h"
#include "types1.h"
#include "UART.h"

void UART_vidInit(void){
u16 UBRR_value= (((F_CPU/16)/BAUD_RATE))-1; // Calculate the UBRR value for Desired Baud Rate
UBRRL = (u8)UBRR_value;
UBRRH = (u8)(UBRR_value >> 8);
UCSRB |= (1<<TXEN) | (1<<RXEN);     // Enable the UART Transmitter
UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);	// Select to update UCSRC and Select data frame as 8-bit
}

void UART_vidSendCharacter(u8 data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

void UART_vidSendString(u8 data[]){
u8 i;
for(i = 0; data[i] != '\0'; i++){
	UART_vidSendCharacter(data[i]);
}
}

u8 UART_u8ReceiveCharacter(void){
	while(!(UCSRA &(1<<RXC)));
	return UDR;
}

void UART_vidSendNumber(u8 number){
u8 temp = 1;
u8 reminder1;
	if(number == 0)UART_vidSendCharacter('0');
	while(number != 0){
		reminder1 = number % 10;
		number /= 10;
		temp = temp * 10 +reminder1;
		}
	while(temp != 1){
		reminder1 = temp % 10;
		temp /= 10;
		UART_vidSendCharacter(reminder1+48);
		}
}
