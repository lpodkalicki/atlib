/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "at/digital.hpp"
#include "at/driver/ACS712.hpp"

using namespace at;

#define	ACS712_OFFSET	(2500)

uint8_t ACS712::VER5A = 185;
uint8_t ACS712::VER20A = 100;
uint8_t ACS712::VER30A = 66;

ACS712::ACS712(uint8_t pin, uint8_t version, float vref)
{
	an = Analog(pin);
	k = (version == VER5A || version == VER20A || version == VER30A) ? version : VER30A;
	mv = (uint16_t)(vref * 1000); 		// convert Vref to milivolts 
}

float
ACS712::read(void)
{
	uint16_t value;
	double result;
	value = an.read(); 			// read ADC value
	result = ((float)value / 1024.) * mv; 	// convert ADC value to milivolts
 	result = (result - ACS712_OFFSET) / k;  // calculate amps
	if (result < 0)
		return (0.0);
	return (float)result;
}

