#pragma once

#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "pico/stdlib.h"
#include <stdint.h>

class Motor {
    private:
        uint _pin_a;
        uint _pin_b;
        uint _slice;
        uint16_t _speed;

        void set_pwm(uint pin, uint16_t speed);

        uint16_t percentage_to_pwm(uint8_t percentage);

    public:
        Motor(uint pin_a, uint pin_b);

        void forward(uint16_t pwm);
        void backward(uint16_t pwm);
        void stop();
};

#endif