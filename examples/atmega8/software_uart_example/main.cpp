/**
 * Copyright (c) 2016, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * Example of Software UART.
 */

#include <at.hpp>
#include <at/uart.hpp>

using namespace at;

SoftwareUART serial(_PB2, 0);

int
main(void)
{
	serial.begin(9600);

	while (1) {
		serial.println("Hello :)");
		sleep(1000);
	}
}
