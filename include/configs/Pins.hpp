#pragma once

#include "pico/stdlib.h"

namespace Pins {

    namespace Motor {
        constexpr uint LEFT_A  = 3;
        constexpr uint LEFT_B  = 2;

        constexpr uint RIGHT_A = 5;
        constexpr uint RIGHT_B = 4;
    }

    namespace Sensor {
        constexpr uint LEFT  = 26;
        constexpr uint RIGHT = 27;
    }

    namespace Button {
        constexpr uint START = 1;
    }

}