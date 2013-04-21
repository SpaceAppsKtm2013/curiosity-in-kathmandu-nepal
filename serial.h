/*
 * serial.h
 *
 * Created: 5/1/2012 12:19:37 PM
 *  Author: Bishal Paudel
 *  http://www.giga100.com
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_


	/*********************** Function Prototypes*******************/
void serial_begin();
void serial_end();
void serial_write( unsigned char data );
unsigned char serial_read( void );
int serial_available();
void serial_print(char *data);


	/******************************* UCSRA bits:*************************************/
	/*
	Bit 7 – RXCIE: RX Complete Interrupt Enable
	Bit 6 – TXCIE: TX Complete Interrupt Enable
	Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
	Bit 4 - RXEN: Receiver Enable
	Bit 3 – TXEN: Transmitter Enable
	Bit 2 – UCSZ2: Character Size
	Bit 1 – RXB8: Receive Data Bit 8
	Bit 0 – TXB8: Transmit Data Bit 8
	*/
	/****************************** UCSRB bits *****************************************/
	/*
	Bit 7 – RXCIE: RX Complete Interrupt Enable
	Bit 6 – TXCIE: TX Complete Interrupt Enable
	Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
	Bit 4 – RXEN: Receiver Enable
	Bit 3 – TXEN: Transmitter Enable
	Bit 2 – UCSZ2: Character Size
	Bit 1 – RXB8: Receive Data Bit 8
	Bit 0 – TXB8: Transmit Data Bit 8
	*/
	/*************************** UCSRC bits *********************************************/
	/*
	Bit 7 – URSEL: Register Select 8
	Bit 6 – UMSEL: USART Mode Select
	Bit 5:4 – UPM1:0: Parity Mode
	Bit 3 – USBS: Stop Bit Select
	Bit 2:1 – UCSZ1:0: Character Size
	Bit 0 – UCPOL: Clock Polarity
	*/
	
#endif /* SERIAL_H_ */