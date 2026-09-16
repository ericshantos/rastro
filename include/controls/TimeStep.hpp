#pragma once

#ifndef TIME_STEP_HPP
#define TIME_STEP_HPP

#include "pico/stdlib.h"

class TimeStep {
    private:
        absolute_time_t _previous_time;

    public:
        TimeStep();

        float elapsed();
};

#endif