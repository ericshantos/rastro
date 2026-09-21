#include "AnalogSensor.hpp"
#include "hardware/adc.h"

#include <cstdint>

AnalogSensor::AnalogSensor(uint gpio, uint adc_channel)
    : gpio(gpio), adc_channel(adc_channel) {

        init();
    }

void AnalogSensor::init() {
    adc_init();
    adc_gpio_init(gpio);
}

uint16_t AnalogSensor::read(bool mean) {
    adc_select_input(adc_channel);

    if (mean) {
        uint32_t readings = 0;

        for (int i = 0; i < 5; i++) {
            readings += adc_read();
        }

        return readings / 5;
    }

    return adc_read();
}

float AnalogSensor::read_normalized() {
    return static_cast<float>(read()) / 4095.0f;
}