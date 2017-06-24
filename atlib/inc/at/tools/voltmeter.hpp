/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "at/analog.hpp"

namespace at {
class Voltmeter {
public:
        Voltmeter(uint8_t pin, uint16_t r1, uint16_t r2, float vref) {
                gpio = Analog(pin);
                k = vref / ((float)r2 / (float)(r1 + r2));
        }
        float read(void) {
                return ((float)gpio.read() / 1024.0) * k;
        }
private:
        Analog gpio;
        float k;
}; /* End of class Voltmeter */
} /* End of namespace at */

