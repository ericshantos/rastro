#pragma once

#include "pico/stdlib.h"
#include <cstdint>

class AnalogSensor {
private:
    uint _gpio;
    uint16_t _reading;

public:
    AnalogSensor(uint gpio);

    void init();

    uint16_t read(bool use_mean = false);

    bool detected(uint threshold);
};