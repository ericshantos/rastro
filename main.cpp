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
#include "controls/SteeringWheel.hpp"
#include "controls/Button.hpp"

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

    SteeringWheel steering(motor_left, motor_right);

    Button btn(Pins::Button::START);

    while(btn.is_pressed()) {
        sleep_ms(100);
    }

    while (true) {
        
        uint16_t left_reading = sensor_left.read();
        uint16_t right_reading = sensor_right.read();

        bool left_detected = sensor_left.detected(
            SensorConfig::LEFT_THRESHOLD
        );

        bool right_detected = sensor_right.detected(
            SensorConfig::RIGHT_THRESHOLD
        );

        if (left_detected && right_detected) {
            steering.stop();
        }

        else if (!left_detected && right_detected) {
            steering.turn_right(
                MotorConfig::BASE_PERCENTACE
            );
        }

        else if (left_detected && !right_detected) {
            steering.turn_left(
                MotorConfig::BASE_PERCENTACE
            );
        }

        else {
            steering.forward(
                MotorConfig::BASE_PERCENTACE
            );
        }

        printf("L = %u -> (%d) | R = %u -> (%d)",
            left_reading,
            left_detected,
            right_reading,
            right_detected    
        );
    }

    return 0;
}