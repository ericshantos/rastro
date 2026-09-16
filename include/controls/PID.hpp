#pragma once

#ifndef PID_HPP
#define PID_HPP

class PID {
    private:
        float _kd;
        float _ki; 
        float _kp;

        float _integral;
        float _previous_error;

    public:
        PID(float kd, float ki, float kp);

        float operator()(float error, float dt);
};

#endif