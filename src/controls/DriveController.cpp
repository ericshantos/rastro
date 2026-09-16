#include "controls/DriveController.hpp"

DriveController::DriveController(
    Motor& left_motor,
    Motor& right_motor,
    float base_speed,
    float max_speed
)
    : _left_motor(left_motor),
      _right_motor(right_motor),
      _base_speed(base_speed),
      _max_speed(max_speed) {}

void DriveController::drive(float correction)
{
    float left_speed = _base_speed + correction;
    float right_speed = _base_speed - correction;

    if (left_speed > _max_speed)
        left_speed = _max_speed;

    if (left_speed < 0.0f)
        left_speed = 0.0f;

    if (right_speed > _max_speed)
        right_speed = _max_speed;

    if (right_speed < 0.0f)
        right_speed = 0.0f;

    _left_motor.forward(left_speed);
    _right_motor.forward(right_speed);
}