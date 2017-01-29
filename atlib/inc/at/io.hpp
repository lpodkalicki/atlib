/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

extern "C" {
#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
}

namespace at {
#define	LOW		(0)
#define	HIGH 		(1)
#define	INPUT		(0)
#define	OUTPUT		(1)

#ifndef cbi
# define		cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
# define		sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)

#define	_PB0		(0)
#define	_PB1		(1)
#define	_PB2		(2)
#define	_PB3		(3)
#define	_PB4		(4)
#define	_PB5		(5)

#define	_ADC0		_PB5
#define	_ADC1		_PB2
#define	_ADC2		_PB4
#define	_ADC3		_PB3

#define	_AIN0		_PB0
#define	_AIN1		_PB1

#define	PINSDA		_PB0
#define	PINSCL		_PB2
#define	PINSCK		_PB2
#define	PINMOSI		_BP0
#define	PINMISO		_PB1

#define	PINNUM		(6)

#elif defined(__AVR_ATtiny2313__) || defined(__AVR_ATtiny4313__)

#define	PA		(0)
#define	PB		(1)
#define	PD		(2)

#define	_PA0 		(0)
#define	_PA1 		(1)
#define	_PA2 		(2)
#define	_PB0 		(3)
#define	_PB1 		(4)
#define	_PB2 		(5)
#define	_PB3 		(6)
#define	_PB4 		(7)
#define	_PB5 		(8)
#define	_PB6 		(9)
#define	_PB7 		(10)
#define	_PD0 		(11)
#define	_PD1 		(12)
#define	_PD2 		(13)
#define	_PD3 		(14)
#define	_PD4 		(15)
#define	_PD5 		(16)
#define	_PD6 		(17)

#define	_AIN0		_PB0
#define	_AIN1		_PB1

#define	_AOC0		_PB0
#define	_AOC1		_PB1

#define	PINSDA		(0)
#define	PINSCL		(2)
#define	PINSCK		(2)
#define	PINMOSI		(0)
#define	PINMISO		(1)
#define	PINRXD		(11)
#define	PINTXD		(12)

#define	PINNUM		(18)

#elif defined(__AVR_ATmega8__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

#define	PB		(0)
#define	PC		(1)
#define	PD		(2)

/* Digital I/O pins */
#define	_PB0		(0)
#define	_PB1		(1)
#define	_PB2		(2)
#define	_PB3		(3)
#define	_PB4		(4)
#define	_PB5		(5)
#define	_PB6		(6)
#define	_PB7		(7)
#define	_PC0		(8)
#define	_PC1		(9)
#define	_PC2		(10)
#define	_PC3		(11)
#define	_PC4		(12)
#define	_PC5		(13)
#define	_PC6		(14)
#define	_PD0		(15)
#define	_PD1		(16)
#define	_PD2		(17)
#define	_PD3		(18)
#define	_PD4		(19)
#define	_PD5		(20)
#define	_PD6		(21)
#define	_PD7		(22)

/* Analog I/O pins */
#define	_ADC0		_PC0
#define	_ADC1		_PC1
#define	_ADC2		_PC2
#define	_ADC3		_PC3
#define	_ADC4		_PC4
#define	_ADC5		_PC5
#define	_ADC6		(254) /* Additional ADC pin, TQFP and MLF package */
#define	_ADC7		(255) /* Additional ADC pin, TQFP and MLF package */

#define	_AIN0		_PB0
#define	_AIN1		_PB1

#define	_AOC0		_PB0
#define	_AOC1		_PB1

#define	PINSDA		(12)
#define	PINSCL		(13)
#define	PINSCK		(5)
#define	PINMOSI		(3)
#define	PINMISO		(4)
#define	PINRXD		(15)
#define	PINTXD		(16)

#define	PINNUM		(23)

#elif defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)

#define	PA		(0)
#define	PB		(1)
#define	PC		(2)
#define	PD		(3)

#define	_PA0 		(0)
#define	_PA1		(1)
#define	_PA2		(2)
#define	_PA3		(3)
#define	_PA4		(4)
#define	_PA5		(5)
#define	_PA6		(6)
#define	_PA7		(7)
#define	_PB0		(8)
#define	_PB1		(9)
#define	_PB2		(10)
#define	_PB3		(11)
#define	_PB4		(12)
#define	_PB5		(13)
#define	_PB6		(14)
#define	_PB7		(15)
#define	_PC0		(16)
#define	_PC1		(17)
#define	_PC2		(18)
#define	_PC3		(19)
#define	_PC4		(20)
#define	_PC5		(21)
#define	_PC6		(22)
#define	_PC7		(23)
#define	_PD0		(24)
#define	_PD1		(25)
#define	_PD2		(26)
#define	_PD3		(27)
#define	_PD4		(28)
#define	_PD5		(29)
#define	_PD6		(30)
#define	_PD7		(31)

#define	_ADC0		_PA0
#define	_ADC1		_PA1
#define	_ADC2		_PA2
#define	_ADC3		_PA3
#define	_ADC4		_PA4
#define	_ADC5		_PA5
#define	_ADC6		_PA6
#define	_ADC7		_PA7

#define	_AOC0		_PB3
#define	_AOC1		_PD5
#define	_AOC2		_PD4
#define	_AOC3		_PD7
#define	_AOC4		_PC6
#define	_AOC5		_PC7

#define	PINSDA		_PC1
#define	PINSCL		_PC0
#define	PINSCK		_PB7
#define	PINMOSI		_PB5
#define	PINMISO		_PB6
#define	PINRXD		_PD0
#define	PINTXD		_PD1

#define	PINNUM		(32)

#endif /* !(__AVR_ATmega16__ || __AVR_ATmega32__) */

#if !(defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__))

extern const uint16_t PROGMEM _port2modereg_PGM[];
extern const uint16_t PROGMEM _port2inputreg_PGM[];
extern const uint16_t PROGMEM _port2outputreg_PGM[];
extern const uint8_t PROGMEM _pin2port_PGM[];
extern const uint8_t PROGMEM _pin2bitmask_PGM[];

#define port2mreg(P)	((volatile uint8_t *)pgm_read_word(_port2modereg_PGM+(P)))
#define port2ireg(P)	((volatile uint8_t *)pgm_read_word(_port2inputreg_PGM+(P)))
#define port2oreg(P)	((volatile uint8_t *)pgm_read_word(_port2outputreg_PGM+(P)))
#define pin2port(P)	(pgm_read_byte(_pin2port_PGM+(P)))
#define pin2bitmask(P)	(pgm_read_byte(_pin2bitmask_PGM+(P)))

#endif  /* !(__AVR_ATtiny13__ || __AVR_ATtinyX5__) */
} /* End of namespace at */
