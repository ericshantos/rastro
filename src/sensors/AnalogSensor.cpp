#include "sensors/AnalogSensor.hpp"
#include "configs/SensorConfig.hpp"

#include "hardware/adc.h"

AnalogSensor::AnalogSensor(uint gpio)
    : _gpio(gpio)
    {
        init();
    }

void AnalogSensor::init() {
    adc_gpio_init(_gpio);
}

uint16_t AnalogSensor::read(bool use_mean) {
    uint channel = _gpio - 26;

    adc_select_input(channel);

    if (!use_mean) {
        _reading = adc_read();
        return _reading;
    }

    uint32_t readings = 0;

    for (uint i = 0; i < SensorConfig::MEASUREMENTS; i++) {
        readings += adc_read();
    }

    _reading = readings / SensorConfig::MEASUREMENTS;

    return _reading;
}

bool AnalogSensor::detected(uint threshold) {
    return _reading > threshold;
}