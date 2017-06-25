/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include "at/analog.hpp"


namespace at {
class ACS712 {
public:
	static uint8_t VER5A;
	static uint8_t VER20A;
	static uint8_t VER30A;
	ACS712(uint8_t pin, uint8_t version = VER5A, float vref = 5.0);
	float read(void);
private:
	Analog an;
	uint16_t mv;
	float k; 
}; /* End of class ACS712 */
} /* End of namespace at */

