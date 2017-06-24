/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include "at/stream.hpp"


namespace at {
class UART: public Stream {
public:
	UART(uint16_t baudrate);
	void write(uint8_t data);
	uint8_t read(void);
}; /* End of class UART */

class SoftwareUART: public Stream {
public:
	SoftwareUART(uint8_t transmit_pin, uint8_t receive_pin);
	void begin(uint32_t baudrate);
	void write(uint8_t data);
        uint8_t read(void);
private:
	uint8_t tx_pin;
	uint8_t rx_pin;
	uint16_t bit_delay;
}; /* End of class SoftwareUART */

} /* End of namespace at */

