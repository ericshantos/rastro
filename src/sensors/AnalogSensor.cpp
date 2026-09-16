#include "sensors/AnalogSensor.hpp"

#include "hardware/adc.h"

AnalogSensor::AnalogSensor(uint gpio)
    : _gpio(gpio)
    {
        init();
    }

void AnalogSensor::init() {
    adc_gpio_init(_gpio);
}

uint16_t AnalogSensor::read() {
    uint channel = _gpio - 26;

    adc_select_input(channel);
    _reading = adc_read();

    return _reading;
}

bool AnalogSensor::detected(uint threshold) {
    return _reading > threshold;
}