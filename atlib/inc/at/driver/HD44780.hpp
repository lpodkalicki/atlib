/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "at/digital.hpp"


namespace at {
class HD44780 {
public:
	HD44780(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	void begin(uint8_t cols = 16, uint8_t rows = 2);
	void up();
	void down();
	void clear();
	void home();
	void setCursor(uint8_t col, uint8_t row);
	void blink(bool yesno);
	void cursor(bool yesno);
	void printf(const char *fmt, ...);

private:
	uint8_t ncols;
	uint8_t nrows;
	uint8_t rowOffsets[4];
	uint8_t functionSetFlags;
	uint8_t displayControlFlags;
	uint8_t entryModeSetFlags;

	Digital RS;
	Digital ENABLE;
	Digital DATA[4];

	/* Commands */
	static const uint8_t CMD_CLEARDISPLAY = 0x01;
	static const uint8_t CMD_RETURNHOME = 0x02;
	static const uint8_t CMD_ENTRYMODESET = 0x04;
	static const uint8_t CMD_DISPLAYCONTROL = 0x08;
	static const uint8_t CMD_CURSORSHIFT = 0x10;
	static const uint8_t CMD_FUNCTIONSET = 0x20;
	static const uint8_t CMD_SETCGRAMADDR = 0x40;
	static const uint8_t CMD_SETDDRAMADDR = 0x80;

	/* flags for function set */
	static const uint8_t FLAG_8BITMODE = 0x10;
	static const uint8_t FLAG_4BITMODE = 0x00;
	static const uint8_t FLAG_2LINE = 0x08;
	static const uint8_t FLAG_1LINE = 0x00;
	static const uint8_t FLAG_5x10DOTS = 0x04;
	static const uint8_t FLAG_5x8DOTS = 0x00;

	/* Flags for display entry mode */
	static const uint8_t FLAG_ENTRYRIGHT = 0x00;
	static const uint8_t FLAG_ENTRYLEFT = 0x02;
	static const uint8_t FLAG_ENTRYSHIFTINCREMENT = 0x01;
	static const uint8_t FLAG_ENTRYSHIFTDECREMENT = 0x00;

	/* Flags for display on/off control */
	static const uint8_t FLAG_DISPLAYON = 0x04;
	static const uint8_t FLAG_DISPLAYOFF = 0x00;
	static const uint8_t FLAG_CURSORON = 0x02;
	static const uint8_t FLAG_CURSOROFF = 0x00;
	static const uint8_t FLAG_BLINKON = 0x01;
	static const uint8_t FLAG_BLINKOFF = 0x00;

	void shiftOut(uint8_t value);
	void send(uint8_t value, uint8_t mode = LOW);

}; /* End of class HD44780 */
} /* End of namespace at */
