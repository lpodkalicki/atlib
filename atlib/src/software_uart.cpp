/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "at/digital.hpp"
#include "at/uart.hpp"


using namespace at;

SoftwareUART::SoftwareUART(uint8_t transmit_pin, uint8_t receive_pin): Stream()
{
	tx_pin = transmit_pin;
	rx_pin = receive_pin;
}

void
SoftwareUART::begin(uint32_t baudrate)
{
	bit_delay = (F_CPU / baudrate) / 4;
	Digital(tx_pin).high();
}

void
SoftwareUART::write(uint8_t data)
{
#if !(defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__))
	uint8_t i, sreg, port, bitmask;
	volatile uint8_t *oreg;

	port = pin2port(tx_pin);
	oreg = port2oreg(port);
	bitmask = pin2bitmask(tx_pin);

	sreg = SREG;
	cli();

	// start bit
	*oreg &= ~bitmask;
	_delay_loop_2(bit_delay);

	// data bits
	for (i = 0; i < 8; ++i, data >>= 1) {
		if (data & 1) {
			*oreg |= bitmask;
		} else {
			*oreg &= ~bitmask;
		}
		_delay_loop_2(bit_delay);
	}

	// stop bit
	*oreg |= bitmask;
	_delay_loop_2(bit_delay);

	SREG = sreg;		
#else
	#warning "SoftwareUART::write is not imeplemented for MCUs of __AVR_ATtiny13__ and __AVR_ATtinyX5__, yet!"	
#endif  /* !(__AVR_ATtiny13__ || __AVR_ATtinyX5__) */
}

uint8_t
SoftwareUART::read(void)
{
	#warning "SoftwareUART::write is not imeplemented, yet!"
	return (0);
}

