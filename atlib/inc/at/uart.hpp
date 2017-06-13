/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include "at/stream.hpp"


namespace at {
class UART : public Stream {
public:
	UART(uint16_t baudrate);
	void write(uint8_t data);
	uint8_t read(void);
}; /* End of class UART */
} /* End of namespace at */

