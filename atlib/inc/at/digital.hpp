/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include "at/sleep.hpp"
#include "at/pin.hpp"


namespace at {
class Digital: public Pin {
public:
	Digital(): Pin(255) {}
	Digital(uint8_t pin): Pin(pin) {}
	Digital(const Digital& pin): Pin(pin._pin) {}

        bool read() const {
		return read(_pin);
	}

	static bool read(uint8_t pin) {

		if (pin >= PINNUM)
			return (false);

		mode(pin, INPUT); // make sure it's input pin

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
		return (PINB & (1 << pin)) > 0;
#else
		uint8_t retval;
        	volatile uint8_t *reg;

		retval = pin2port(pin);
		reg = port2ireg(retval);
        	retval = pin2bitmask(pin);
        	return ((*reg & retval) > 0);
#endif
	}

        void write(bool value) const {
		write(_pin, value);
	}

	static void write(uint8_t pin, bool value) {
		uint8_t sreg;

		if (pin >= PINNUM)
			return;

		mode(pin, OUTPUT); // make sure it's output pin

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)

		if (value == HIGH) {
                        sreg = SREG;
                        cli();
                        PORTB |= 1 << pin;
                        SREG = sreg;
                } else { // value == LOW
                        sreg = SREG;
                        cli();
                        PORTB &= ~(1 << pin);
                        SREG = sreg;
                }
#else

		uint8_t retval;
        	volatile uint8_t *reg;

		retval = pin2port(pin);
		reg = port2oreg(retval);
        	retval = pin2bitmask(pin);

        	if (value == HIGH) {
                	sreg = SREG;
                	cli();
                	*reg |= retval;
                	SREG = sreg;
        	} else { // value == LOW
                	sreg = SREG;
                	cli();
                	*reg &= ~retval;
                	SREG = sreg;
        	}
#endif

	}

	const Digital& high() const {
		write(HIGH);
		return *this;
	}

	const Digital& low() const {
		write(LOW);
		return *this;
	}

	const Digital& in() const {
		mode(INPUT);
		return *this;
	}

	const Digital& out() const {
		mode(OUTPUT);
		return *this;
	}

        void toggle() const {
		toggle(_pin);
	}

	static void toggle(uint8_t pin) {
		uint8_t sreg;

		if (pin >= PINNUM)
			return;

		mode(pin, OUTPUT); // make sure it's output pin

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)

		sreg = SREG;
                cli();
                PORTB ^= 1 << pin;
                SREG = sreg;
#else

		uint8_t retval;
        	volatile uint8_t *reg;

		retval = pin2port(pin);
		reg = port2oreg(retval);
        	retval = pin2bitmask(pin);

        	sreg = SREG;
        	cli();
        	*reg ^= retval;
        	SREG = sreg;
#endif

	}
}; /* End of class Digital */
} /* End of namespace at */
