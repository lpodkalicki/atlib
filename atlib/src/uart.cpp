/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "at/uart.hpp"


using namespace at;

UART::UART(uint16_t baudrate): Stream()
{
#if defined(__AVR_ATmega8__)
	uint16_t baudrate_calc = (F_CPU / 4 / baudrate - 1) / 2;

	/* Set PD1 (TXD) as output */
	DDRD |= _BV(PD1);

	/* Set calculated baud rate */
	UBRRH = baudrate_calc >> 8;
	UBRRL = baudrate_calc;

	/* Double the USART transmition speed */
	UCSRA = _BV(U2X);

	/* Enable transmition */
	UCSRB = _BV(TXEN);

	/* Set format 8N1 */
	UCSRC = _BV(URSEL) | _BV(UCSZ1) | _BV(UCSZ0);
#endif
}

void
UART::write(uint8_t data)
{
#if defined(__AVR_ATmega8__)
	/* Wait for empty transmit buffer */
	while (!(UCSRA & _BV(UDRE)));
	/* Put data into buffer, sends the data */
	UDR = data;
#endif		
}

uint8_t
UART::read(void)
{
#if defined(__AVR_ATmega8__)
	return (0);
#endif
}

