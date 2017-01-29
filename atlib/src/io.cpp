/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include "at/io.hpp"


#if !(defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__))

namespace at {

/**
 * ATTINY2313
 */
#if defined(__AVR_ATtiny2313__) || defined(__AVR_ATtiny4313__)

const uint16_t PROGMEM _port2modereg_PGM[] = {
	(uint16_t)&DDRA,
	(uint16_t)&DDRB,
	(uint16_t)&DDRD
};

const uint16_t PROGMEM _port2outputreg_PGM[] = {
	(uint16_t)&PORTA,
	(uint16_t)&PORTB,
	(uint16_t)&PORTD
};

const uint16_t PROGMEM _port2inputreg_PGM[] = {
	(uint16_t)&PINA,
	(uint16_t)&PINB,
	(uint16_t)&PIND
};

const uint8_t PROGMEM _pin2port_PGM[] = {
	PA,	/* PA0 -> 0 (XTAL1) */
	PA, 	/* PA1 -> 1 (XTAL2) */
	PA,	/* PA2 -> 2 (RESET) */
	PB,	/* PB0 -> 3 */
	PB,	/* PB1 -> 4 */
	PB,	/* PB2 -> 5 */
	PB,	/* PB3 -> 6 */
	PB,	/* PB4 -> 7 */
	PB,	/* PB5 -> 8 */
	PB, 	/* PB6 -> 9 */
	PB, 	/* PB7 -> 10 */
	PD, 	/* PD0 -> 11 */
	PD,	/* PD1 -> 12 */
	PD,	/* PD2 -> 13 */
	PD,	/* PD3 -> 14 */
	PD,	/* PD4 -> 15 */
	PD,	/* PD5 -> 16 */
	PD	/* PD6 -> 17 */
};

const uint8_t PROGMEM _pin2bitmask_PGM[] = {
	_BV(0), /* 0, port A */
	_BV(1),
	_BV(2),
	_BV(0),	/* 3, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 11, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6)
};


/**
 * ATMEGA8
 * ATMEGA168
 * ATMEGA238
 */
#elif defined(__AVR_ATmega8__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168A__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

const uint16_t PROGMEM _port2modereg_PGM[] = {
	(uint16_t)&DDRB,
	(uint16_t)&DDRC,
	(uint16_t)&DDRD
};

const uint16_t PROGMEM _port2outputreg_PGM[] = {
	(uint16_t)&PORTB,
	(uint16_t)&PORTC,
	(uint16_t)&PORTD
};

const uint16_t PROGMEM _port2inputreg_PGM[] = {
	(uint16_t)&PINB,
	(uint16_t)&PINC,
	(uint16_t)&PIND
};

const uint8_t PROGMEM _pin2port_PGM[] = {
	PB, 	/* PB0 -> 0 */
	PB,	/* PB1 -> 1 */
	PB,	/* PB2 -> 2 */
	PB,	/* PB3 -> 3 */
	PB,	/* PB4 -> 4 */
	PB,	/* PB5 -> 5 */
	PB,	/* PB6 -> 6 */
	PB,	/* PB7 -> 7 */
	PC, 	/* PC0 -> 8 */
	PC, 	/* PC1 -> 9 */
	PC, 	/* PC2 -> 10 */
	PC,	/* PC3 -> 11 */
	PC,	/* PC4 -> 12 */
	PC,	/* PC5 -> 13 */
	PC,	/* PC6 -> 14 */
	PD,	/* PD0 -> 15 */
	PD,	/* PD1 -> 16 */
	PD,	/* PD2 -> 17 */
	PD,	/* PD3 -> 18 */
	PD,	/* PD4 -> 19 */
	PD,	/* PD5 -> 20 */
	PD,	/* PD6 -> 21 */
	PD	/* PD7 -> 22 */
};

const uint8_t PROGMEM _pin2bitmask_PGM[] = {
	_BV(0), /* 0, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(0), /* 15, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7)
};


/**
 * ATMEGA16
 * ATMEGA32
 */
#elif defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)

const uint16_t PROGMEM _port2modereg_PGM[] = {
	(uint16_t)&DDRA,
	(uint16_t)&DDRB,
	(uint16_t)&DDRC,
	(uint16_t)&DDRD
};

const uint16_t PROGMEM _port2outputreg_PGM[] = {
	(uint16_t)&PORTA,
	(uint16_t)&PORTB,
	(uint16_t)&PORTC,
	(uint16_t)&PORTD
};

const uint16_t PROGMEM _port2inputreg_PGM[] = {
	(uint16_t)&PINA,
	(uint16_t)&PINB,
	(uint16_t)&PINC,
	(uint16_t)&PIND
};

const uint8_t PROGMEM _pin2port_PGM[] = {
	PA,	/* PA0 -> 40 */
	PA,	/* PA1 -> 39 */
	PA,	/* PA2 -> 38 */
	PA,	/* PA3 -> 37 */
	PA,	/* PA4 -> 36 */
	PA,	/* PA5 -> 35 */
	PA,	/* PA6 -> 34 */
	PA,	/* PA7 -> 33 */

	PB,	/* PB0 -> 1 */
	PB,	/* PB1 -> 2 */
	PB,	/* PB2 -> 3 */
	PB,	/* PB3 -> 4 */
	PB,	/* PB4 -> 5 */
	PB,	/* PB5 -> 6 */
	PB,	/* PB6 -> 7 */
	PB,	/* PB7 -> 8 */

	PC,	/* PC0 -> 22 */
	PC,	/* PC1 -> 23 */
	PC,	/* PC2 -> 24 */
	PC,	/* PC3 -> 25 */
	PC,	/* PC4 -> 26 */
	PC,	/* PC5 -> 27 */
	PC,	/* PC6 -> 28 */
	PC,	/* PC7 -> 29 */

	PD,	/* PD0 -> 14 */
	PD,	/* PD1 -> 15 */
	PD,	/* PD2 -> 16 */
	PD,	/* PD3 -> 17 */
	PD,	/* PD4 -> 18 */
	PD,	/* PD5 -> 19 */
	PD,	/* PD6 -> 20 */
	PD	/* PD7 -> 21 */
};

const uint8_t PROGMEM _pin2bitmask_PGM[] = {
	_BV(0),	/* PA0 -> 40 */
	_BV(1),	/* PA1 -> 39 */
	_BV(2),	/* PA2 -> 38 */
	_BV(3),	/* PA3 -> 37 */
	_BV(4),	/* PA4 -> 36 */
	_BV(5),	/* PA5 -> 35 */
	_BV(6),	/* PA6 -> 34 */
	_BV(7),	/* PA7 -> 33 */

	_BV(0),	/* PB0 -> 1 */
	_BV(1),	/* PB1 -> 2 */
	_BV(2),	/* PB2 -> 3 */
	_BV(3),	/* PB3 -> 4 */
	_BV(4),	/* PB4 -> 5 */
	_BV(5),	/* PB5 -> 6 */
	_BV(6),	/* PB6 -> 7 */
	_BV(7),	/* PB7 -> 8 */

	_BV(0),	/* PC0 -> 22 */
	_BV(1),	/* PC1 -> 23 */
	_BV(2),	/* PC2 -> 24 */
	_BV(3),	/* PC3 -> 25 */
	_BV(4),	/* PC4 -> 26 */
	_BV(5),	/* PC5 -> 27 */
	_BV(6),	/* PC6 -> 28 */
	_BV(7),	/* PC7 -> 29 */

	_BV(0),	/* PD0 -> 14 */
	_BV(1),	/* PD1 -> 15 */
	_BV(2),	/* PD2 -> 16 */
	_BV(3),	/* PD3 -> 17 */
	_BV(4),	/* PD4 -> 18 */
	_BV(5),	/* PD5 -> 19 */
	_BV(6),	/* PD6 -> 20 */
	_BV(7)	/* PD7 -> 21 */
};
#else /* Other mcu */
#error "AT: not supported MCU type."
#endif 

} /* End of namespace at */

#endif /* ATiny13/25/45/85 */

