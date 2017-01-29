/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

extern "C" {
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>
}
#include "at/pin.hpp"

#if !(defined(__AVR_ATtiny2313__) || defined(__AVR_ATtiny4313__))
namespace at {
class Analog: public Pin {
public:
	Analog(): Pin() {}
	Analog(uint8_t pin): Pin(pin) {}
	Analog(const Analog& pin): Pin(pin._pin) {}

	uint16_t read() {
		return read(_pin);
	}

        static uint16_t read(uint8_t pin) {
		uint8_t low, high;

		mode(pin, INPUT);

#if	defined(__AVR_ATtiny13__) 	|| \
	defined(__AVR_ATtiny13A__)	|| \
	defined(__AVR_ATtiny25__) 	|| \
	defined(__AVR_ATtiny45__)	|| \
	defined(__AVR_ATtiny85__)

		ADMUX &= ~(_BV(MUX1)|_BV(MUX0));

		switch(pin) {
		case _ADC3: ADMUX |= _BV(MUX0)|_BV(MUX1); break;		// ADC3
		case _ADC2: ADMUX |= _BV(MUX1); break;				// ADC2
		case _ADC1: ADMUX |= _BV(MUX0); break;				// ADC1
		case _ADC0:							// ADC0
		default: break;
		}

#elif 	defined(__AVR_ATmega8__) 	|| \
	defined(__AVR_ATmega168__) 	|| \
	defined(__AVR_ATmega168P__) 	|| \
	defined(__AVR_ATmega328__) 	|| \
	defined(__AVR_ATmega328P__) 	|| \
	defined(__AVR_ATmega16__) 	|| \
	defined(__AVR_ATmega32__)

		ADMUX &= ~(_BV(MUX2)|_BV(MUX1)|_BV(MUX0));
		
		switch(pin) {
		case _ADC7: ADMUX |= _BV(MUX2)|_BV(MUX1)|_BV(MUX0); break;	// ADC7
		case _ADC6: ADMUX |= _BV(MUX2)|_BV(MUX1); break;		// ADC6
		case _ADC5: ADMUX |= _BV(MUX2)|_BV(MUX0); break;		// ADC5
		case _ADC4: ADMUX |= _BV(MUX2); break;				// ADC4
		case _ADC3: ADMUX |= _BV(MUX1)|_BV(MUX0); break;		// ADC3
		case _ADC2: ADMUX |= _BV(MUX1); break;				// ADC2
		case _ADC1: ADMUX |= _BV(MUX0); break;				// ADC1
		case _ADC0:							// ADC0
		default: break;
		}

#endif
		sbi(ADCSRA, ADEN); // Enable ADC
		sbi(ADCSRA, ADSC); // Run single conversion
		while(bit_is_set(ADCSRA, ADSC)); // Wait conversion is done

		/* Read values */
		low = ADCL;
        	high = ADCH;

		/* Combine the two bytes (10bit number) */
        	return (high << 8) | low;
	}

        void write(uint8_t value) {
		return write(_pin, value);
	}

	static void write(uint8_t pin, uint8_t value) {

		mode(pin, OUTPUT); // Make sure the PWM output is enabled for this pin

#if	defined(__AVR_ATtiny13__)	|| \
	defined(__AVR_ATtiny13A__)	|| \
	defined(__AVR_ATtiny25__)	|| \
	defined(__AVR_ATtiny45__) 	|| \
	defined(__AVR_ATtiny85__)	|| \
	defined(__AVR_ATtiny2313__)	|| \
	defined(__AVR_ATtiny4313__)

		switch (pin) {
		case _AIN0:
			/* Set PWM on pin AIN0 (Timer0, channel A) */
			sbi(TCCR0A, COM0A1);
			OCR0A = value;
			break;
		case _AIN1:
			/* Set PWM on pin AIN1 (Timer0, channel B) */
			sbi(TCCR0A, COM0B1);
			OCR0B = value;
			break; 
		default:
			break;
		}

#elif	defined(__AVR_ATmega8__)	|| \
	defined(__AVR_ATmega168__)	|| \
	defined(__AVR_ATmega168P__)	|| \
	defined(__AVR_ATmega328__)	|| \
	defined(__AVR_ATmega328P__)	|| \
	defined(__AVR_ATmega16__) 	|| \
	defined(__AVR_ATmega32__)

#warning "Ups! Analog:write is not implemented for this MCU, yet!"

#endif
	}

}; /* End of class Analog */
} /* End of namespace at */
#endif /* MCU with ADC */
