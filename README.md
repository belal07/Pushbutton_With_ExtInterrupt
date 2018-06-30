# Pushbutton_With_ExtInterrupt
This project investigate the problems to control a LED using a push button, the push button state is detected using external interrupt.

#Objective
----------------------
This application was written to perform the following Tasks:
Controlling LED using switch as interrupt, when the switch is pressed,it should Toggle the LED.
send the State of the switch when it is pressed and The State of the LED through Serial communication.
Transmit Temperature measured by an LM35 Sensor through Serial Communication every 3 Seconds.

#Set-up instructions
-----------------------
This application was written to a specific platform (AVR ATMEGA32) using Eclipse IDE in addition to WINAVR Compiler on Windows OS,
However the code was written to be modifiable as much as possible to be used in another platform.

##SoftWare Setup Instructions
-------------------------------
-To run This Application you need to use all The source Files(.c) and The Header Files (.h) included And compile it using the previously mentioned IDE and compiler. 

-Another Solution is to use the XIOT.hex file directly and Flash it on ATMEGA32 Microcontroller.

-if you are going To use Another Microcontroller,you will need to modify all the device drivers in addition to the ISRs to what
it is appropriate for your microcontroller.

-The most important point is to Specify the Oscillator frequency,i used an 8 MHZ Oscillator,if you will be using different Oscillator, everything will
be modified automaticly,however you need to care about the overflow problem which could happen with one of the following Registers
(OCR0,OCR1A,OCR1B,UBRR),also you need to specify the Baud Rate for the Serial Communication, the used baud rate was 9600 bps
   
