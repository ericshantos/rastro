#include <stdio.h>
#include "pico/stdlib.h"
#include "Engine.hpp"
#include "AnalogSensor.hpp"
#include "Pins.hpp"


int main() {
    stdio_init_all();

    AnalogSensor sensor_left(Pins::Analog::LEFT, 0);
    AnalogSensor sensor_right(Pins::Analog::RIGHT, 1);

    Engine left(
        Pins::Engine::LEFT_1,
        Pins::Engine::LEFT_2
    );

    Engine right(
        Pins::Engine::RIGHT_1,
        Pins::Engine::RIGHT_2
    );

    while (true) {
        float sL = sensor_right.read_normalized();
        float sR = sensor_left.read_normalized();

        printf("Sensor left: %f| Sensor right: %f", sL, sR);

        sleep_ms(500);
    }
}
