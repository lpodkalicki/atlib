/**
 * Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#pragma once

#include "at/config.hpp"
#include <util/delay.h>

#define	sleep(value)	_delay_ms(value)
#define	usleep(value)	_delay_us(value)
