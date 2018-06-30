/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc lab top
 */

#ifndef UART_H_
#define UART_H_
#define BAUD_RATE 9600
#define F_CPU 8000000UL
void UART_vidInit(void);
void UART_vidSendCharacter(u8 data);
void UART_vidSendString(u8 data[]);
u8 UART_u8ReceiveCharacter(void);
void UART_vidSendNumber(u8 number);
#endif /* UART_H_ */
