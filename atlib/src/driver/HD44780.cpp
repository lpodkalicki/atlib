/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include <stdint.h>
#include <stdio.h>
#include "at/sleep.hpp"
#include "peripheral/HD44780.hpp"

using namespace at;
using namespace at::driver;

/* Pulse must be > 450ns and commands need > 37us to settle */
#define	pulse(pin)	{(pin).high(); usleep(1); (pin).low(); usleep(100); }

HD44780::HD44780(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
	RS = Digital(rs);
	ENABLE = Digital(enable);
	DATA[0] = Digital(d4);
	DATA[1] = Digital(d5);
	DATA[2] = Digital(d6);
	DATA[3] = Digital(d7);
	functionSetFlags = FLAG_5x8DOTS | FLAG_4BITMODE;
	displayControlFlags = FLAG_DISPLAYON | FLAG_CURSOROFF | FLAG_BLINKOFF;
	entryModeSetFlags = FLAG_ENTRYLEFT | FLAG_ENTRYSHIFTDECREMENT;
}

void
HD44780::begin(uint8_t cols, uint8_t rows)
{
	ncols = cols;
	nrows = rows;

	/* Calc offsets */
	rowOffsets[0] = 0x00;
  	rowOffsets[1] = 0x40;
  	rowOffsets[2] = 0x00 + ncols;
  	rowOffsets[3] = 0x40 + ncols;

	/* Set flag informing that we want to use one or more LCD lines */
	functionSetFlags |= (nrows > 1) ? FLAG_2LINE : FLAG_1LINE;

	/* Set I/O pins as OUTPUT with LOW state */
	RS.out().low();
	ENABLE.out().low();
	for (uint8_t i = 0; i < 4; ++i) {
		DATA[i].out().low();
	}

	sleep(50); // ??

	/* We start in 8bit mode so let's set 4 bit mode */
	send(0x03);
    	usleep(4500); 	// wait min 4.1ms

    	/* Second try */
    	send(0x03);
    	usleep(4500); 	// wait min 4.1ms

    	/* Third, go! */
    	send(0x03);
    	usleep(150);

    	/* Switch to 4-bit interface */
    	send(0x02);

	/* Set number of lines, font size, etc. */
  	send(CMD_FUNCTIONSET|functionSetFlags);
  	send(CMD_DISPLAYCONTROL|displayControlFlags);
  	send(CMD_ENTRYMODESET|entryModeSetFlags);

  	/* Clear it off */
  	clear();
}

void
HD44780::up()
{
	displayControlFlags |= FLAG_DISPLAYON;
	send(CMD_DISPLAYCONTROL|displayControlFlags);
}

void
HD44780::down()
{
	displayControlFlags &= ~FLAG_DISPLAYON;
	send(CMD_DISPLAYCONTROL|displayControlFlags);
}

void
HD44780::clear()
{
	send(CMD_CLEARDISPLAY);		// Clear display and set cursor position to "home",
	usleep(2000);			// this command takes a long time!
}

void
HD44780::home()
{
	send(CMD_RETURNHOME);		// Set cursor position to zero,
  	usleep(2000);			// this command takes a long time, too!
}

void
HD44780::setCursor(uint8_t col, uint8_t row)
{
 	const uint8_t max = sizeof(rowOffsets)/sizeof(*rowOffsets);

	if (row >= max) row = max - 1;
  	if (row >= nrows) row = nrows - 1;

  	send(CMD_SETDDRAMADDR|(col+rowOffsets[row]));
}

void
HD44780::blink(bool yesno)
{
	if (yesno)	displayControlFlags |= FLAG_BLINKON;
	else		displayControlFlags &= ~FLAG_BLINKON;
	send(CMD_DISPLAYCONTROL|displayControlFlags);
}

void
HD44780::cursor(bool yesno)
{
	if (yesno)	displayControlFlags |= FLAG_CURSORON;
	else		displayControlFlags &= ~FLAG_CURSORON;
	send(CMD_DISPLAYCONTROL|displayControlFlags);
}

void
HD44780::printf(const char *fmt, ...)
{
	va_list args;
	char buff[32], *p;

	va_start(args, fmt);
#ifdef	HAVE_VSNPRINTF
	vsnprintf(buff, sizeof(buff), fmt, args);	// this is safe
#else
	vsprintf(buff, fmt, args); 			// this is not so safe
#endif
	va_end(args);

	p = buff;
	while(*p) send(*(p++), HIGH);
}

void
HD44780::shiftOut(uint8_t value)
{
	for (uint8_t i = 0; i < 4; ++i) {
    		DATA[i].write((value >> i) & 0x01);
  	}
	pulse(ENABLE);
}

void
HD44780::send(uint8_t value, uint8_t mode)
{
	RS.write(mode);
	shiftOut(value >> 4);
	shiftOut(value);
}
