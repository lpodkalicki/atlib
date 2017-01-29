/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include "at/digital.hpp"


namespace at {
class AD9850 {
public:
	/**
 	 * @param[in] reset: reset pin (RESET)
	 * @param[in] fqup: frequency update pin (FQUP)
	 * @param[in] wclk: word load clock pin (WCLK)
	 * @param[in] d7: serial data pin (D7)
	 */
	AD9850(uint8_t reset, uint8_t fqup, uint8_t wclk, uint8_t d7);
	void begin();
	void reset();
	void up();
	void down();
	void setFrequency(unsigned long frequency);
	void setPhase(uint8_t phase);

private:
	void update();
	Digital RESET;
	Digital FQUP;
	Digital WCLK;
	Digital D7;
	unsigned long frequency;
	uint8_t phase;

}; /* End of class AD9850 */
} /* End of namespace at */
