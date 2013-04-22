#define F_CPU 8000000UL
// Defining CPU frequency




// initializing header files
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include <string.h> 
#include <stdbool.h>



#define BAUDRATE 9600
#define BAUD_PRESCALE ( ((F_CPU)/(BAUDRATE*16UL))-1)



volatile char xbeedata,msgbuffer;

void serial_begin();


int main()
{
// Initializing input and output ports
DDRB=0b00001111;

DDRC=0b00000011;

serial_begin();
sei();

while(1)
{
// for wireless control over the robot
	if(msgbuffer=='w')
	{
	PORTB=0b00001010;
	_delay_ms(10);
	}

	else if(msgbuffer=='s')
	{
	PORTB=0b00000101;
	_delay_ms(10);
	}

	else if(msgbuffer=='a')
	{
	PORTB=0b00000110;
	_delay_ms(10);
	}

	else if(msgbuffer=='d')
	{
	PORTB=0b00001001;
	_delay_ms(10);
	}
	
	else if(msgbuffer=='j')
	{
	PORTB=0b00000000;
	_delay_ms(10);
	PORTC=0b00000010;
	_delay_ms(10);
	}

	else if(msgbuffer=='k')
	{
	PORTB=0b00000000;
	_delay_ms(10);
	PORTC=0b00000001;
	_delay_ms(10);
	}
	
	else if(msgbuffer=='l')
	{
	PORTB=0b00000000;
	_delay_ms(10);
	PORTC=0b00000000;
	_delay_ms(10);
	}
	
	
}
return 0;
}



void serial_begin() 
// serial data transmission begins
{
	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;
	
	/****************************** UCSRB bits *****************************************/	
	UCSRB |= (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);	                       /* TX enable */	
	//UCSRB |= (1<<RXEN);
	
	/*************************** UCSRC bits *********************************************/
	//UCSRC |= (1 << URSEL);                     /* USART register select. The URSEL must be one when writing the UCSRC */
	//UCSRC |= ((1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1));         /* combine with UCSZ2 from UCSRB for other character size combinations */
}




// serial data receiving through interrupt
ISR(USART_RXC_vect)
{
	msgbuffer = UDR;
	
}
