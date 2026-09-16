#pragma once

#ifndef STREERING_WHEEL_HPP
#define STREERING_WHEEL_HPP

#include "motors/Motor.hpp"

#include "pico/stdlib.h"
#include <cstdint>

class SteeringWheel {
    private:
        Motor& _left;
        Motor& _right;

    public:
        SteeringWheel(Motor& left, Motor& right);

        void turn_right(uint16_t speed);
        void turn_left(uint16_t speed);
        void forward(uint16_t speed);
        void stop();
};

#endif