#include "controls/PID.hpp"

PID::PID(float kp, float ki, float kd)
    : _kp(kp),
      _ki(ki),
      _kd(kd),
      _previous_error(0.0f),
      _integral(0.0f) {}

float PID::operator()(float error, float dt) {

    if (dt <= 0.0f) {
        return 0.0f;
    }

    float proportional = error;

    _integral += error * dt;

    float derivative = (error - _previous_error) / dt;

    _previous_error = error;

    return (_kp * proportional)
         + (_ki * _integral)
         + (_kd * derivative);
}