/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "at/driver/AD9850.hpp"

using namespace at;

#ifndef AD9850_EXTERNAL_CLOCK
# define	AD9850_EXTERNAL_CLOCK	(125000000UL)
#endif

#define	pulse(pin)	{(pin).high(); (pin).low();}

AD9850::AD9850(uint8_t reset, uint8_t fqup, uint8_t wclk, uint8_t d7) {
	RESET.setPinNum(reset);
	FQUP.setPinNum(fqup);
	WCLK.setPinNum(wclk);
	D7.setPinNum(d7); 
	frequency = 0;
	phase = 0;
}

void
AD9850::begin()
{
	RESET.out().low();
	FQUP.out().low();
	WCLK.out().low();
	D7.out().low();
	pulse(RESET);
	pulse(WCLK);
	pulse(FQUP);
}

void
AD9850::reset() {
	pulse(RESET);
	pulse(WCLK);
	pulse(FQUP);
	update();
}

void
AD9850::up() {
	update();
}

void
AD9850::down() {
	pulse(FQUP);
	uint8_t p = 0x04;
	for (uint8_t i = 0; i < 8; ++i, p >>= 1) {
		D7.write(p & (uint8_t)0x01);
		pulse(WCLK);
	}
	pulse(FQUP);
}

void
AD9850::setFrequency(unsigned long frequency) {
	this->frequency = frequency;
	update();
}

void
AD9850::setPhase(uint8_t phase) {
	this->phase = phase;
	update();
}

void
AD9850::update() {
	unsigned long f = (frequency * 4294967296.0) / AD9850_EXTERNAL_CLOCK;
	for (uint8_t i = 0; i < 32; ++i, f >>= 1) {
		D7.write(f & (uint32_t)0x00000001);
		pulse(WCLK);
	}
	uint8_t p = phase << 3;
	for (uint8_t i = 0; i < 8; ++i, p >>= 1) {
		D7.write(p & (uint8_t)0x01);
		pulse(WCLK);
	}
	pulse(FQUP);
}
