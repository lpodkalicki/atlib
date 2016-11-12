/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

extern "C" {
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <avr/interrupt.h>
}
#include "at/io.hpp"
#include "at/pin.hpp"


namespace at {
class Pin {
public:
	Pin(): _pin(255) {}
	Pin(uint8_t pin): _pin(pin) {}

	void setPinNum(uint8_t pin) {
		_pin = pin;
	}
	
	void mode(uint8_t value) const {
		mode(_pin, value);	
	}

	static void mode(uint8_t pin, uint8_t value) {
		uint8_t sreg;

		if (pin >= PINNUM)
			return;

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)		
		if (value == OUTPUT) {
		        sreg = SREG;
		        cli();
		        DDRB |= _BV(pin);
		        SREG = sreg;
		} else { // mode == INPUT
		        sreg = SREG;
		        cli();
		        DDRB &= ~_BV(pin);
		        SREG = sreg;
		}
#else

		uint8_t retval;
		volatile uint8_t *reg;

		retval = pin2port(pin);
		reg = port2mreg(retval);
		retval = pin2bitmask(pin);

		if (value == OUTPUT) {
			sreg = SREG;
			cli();
			*reg |= retval;
			SREG = sreg;
		} else { // value == INPUT
			sreg = SREG;
	       	 	cli();
			*reg &= ~retval;
			SREG = sreg;
		}
#endif
	}

protected:
	uint8_t _pin;

}; /* End of class Pin */
} /* End of namespace at */

