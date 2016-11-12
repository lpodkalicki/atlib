/**
 * Copyright (c) 2016, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * Simple blinky with delay function.
 */

#include <at.hpp>

using namespace at;

Digital led(_PB0);

int
main(void)
{

	while (1) {
		led.toggle();
		sleep(500);
	}
}
