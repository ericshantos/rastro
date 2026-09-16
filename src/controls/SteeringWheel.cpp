#include "controls/SteeringWheel.hpp"
#include "motors/Motor.hpp"

#include "pico/stdlib.h"
#include <cstdint>

SteeringWheel::SteeringWheel(Motor& left, Motor& right)
    : _left(left), _right(right) {}

void SteeringWheel::turn_right(uint16_t speed) {
    _left.forward(speed);
    _right.backward(speed);
}

void SteeringWheel::turn_left(uint16_t speed) {
    _left.backward(speed);
    _right.forward(speed);
}

void SteeringWheel::stop() {
    _left.stop();
    _right.stop();
}

void SteeringWheel::forward(uint16_t speed) {
    _left.forward(speed);
    _right.forward(speed);
}