#pragma once

#include "pico/stdio.h"
#include <cstdint>

namespace MotorConfig {

    constexpr uint16_t PWM_WRAP = 5000;

    constexpr uint16_t MAX_SPEED = PWM_WRAP;
    constexpr uint16_t BASE_PERCENTACE = 100;

}