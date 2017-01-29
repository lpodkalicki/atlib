/**
 * Copyright (c) 2017, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * Example code of using driver AD9850.
 */

#include <at/driver/AD9850.hpp>

using namespace at;

AD9850 dds(/*reset=*/_PB0, /*fqfp=*/_PB1, /*wclk=*/_PB2, /*d7=*/_PB3);

int
main()
{
	/* setup */
	dds.begin();

	/* set frequency 12345Hz */
	dds.setFrequency(12345UL);

	/* loop */
	while (1);
}

