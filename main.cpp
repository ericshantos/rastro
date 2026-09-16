#include "pico/stdio.h"
#include "pico/stdlib.h"

#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#include <stdint.h>
#include <stdio.h>
#include <cstdint>

#include "motors/Motor.hpp"

#include "sensors/AnalogSensor.hpp"
#include "LinePosition.hpp"

#include "controls/SteeringWheel.hpp"
#include "controls/Button.hpp"
#include "controls/PID.hpp"
#include "controls/TimeStep.hpp"
#include "controls/DriveController.hpp"

#include "configs/SensorConfig.hpp"
#include "configs/MotorConfig.hpp"

#include "configs/Pins.hpp"


int main()
{
    stdio_init_all();

    adc_init();

    AnalogSensor sensor_left(Pins::Sensor::LEFT);
    AnalogSensor sensor_right(Pins::Sensor::RIGHT);
    
    Motor motor_left(
        Pins::Motor::LEFT_A,
        Pins::Motor::LEFT_B
    );

    Motor motor_right(
        Pins::Motor::RIGHT_A,
        Pins::Motor::RIGHT_B
    );

    DriveController drive(
        motor_left,
        motor_right,
        MotorConfig::BASE_SPEED,
        MotorConfig::MAX_SPEED
    );

    PID pid(2.0f, 0.1f, 0.0f);

    TimeStep timer;

    LinePosition position_estimator;

    Button btn(Pins::Button::START);

    while(btn.is_pressed()) {
        sleep_ms(100);
    }

    while (true) {
        uint16_t left_reading = sensor_left.read();
        uint16_t right_reading = sensor_right.read();

        float error = line_estimator(left_reading, left_reading);

        float dt = timer.elapsed()

        float correction = pid(error, dt);

        drive.drive(correction);
    }

    return 0;
}