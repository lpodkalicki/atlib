/**
 * Copyright (c) 2017, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "at/analog.hpp"

namespace at {
class Ammeter {
public:
        Ammeter(uint8_t pin, float resistor, float vref) {
                gpio = Analog(pin);
                r = resistor;
                v = vref;
        }
        float read(void) {
                float voltage;
                voltage = ((float)gpio.read() / 1024.0) / v;
                return (voltage / r);
        }
private:
        Analog gpio;
        float r;
        float v;
}; /* End of class Ammeter */
} /* End of namespace at */

