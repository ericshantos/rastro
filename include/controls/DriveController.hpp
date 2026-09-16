#pragma once

#include "motors/Motor.hpp"

class DriveController {
private:
    Motor& _left_motor;
    Motor& _right_motor;

    float _base_speed;
    float _max_speed;

public:
    DriveController(
        Motor& left_motor,
        Motor& right_motor,
        float base_speed,
        float max_speed
    );

    void drive(float correction);

    void stop();
};