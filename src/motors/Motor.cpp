#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <stdint.h>

#include "motors/Motor.hpp"
#include "configs/MotorConfig.hpp"


Motor::Motor(uint pin_a, uint pin_b)
    : _pin_a(pin_a),
      _pin_b(pin_b),
      _slice(pwm_gpio_to_slice_num(pin_a)),
      _speed(0)
{
    gpio_set_function(_pin_a, GPIO_FUNC_PWM);
    gpio_set_function(_pin_b, GPIO_FUNC_PWM);

    pwm_config config = pwm_get_default_config();

    pwm_config_set_wrap(&config, MotorConfig::PWM_WRAP);
    pwm_config_set_clkdiv(&config, 15.0f);

    pwm_init(_slice, &config, false);

    pwm_set_gpio_level(_pin_a, 0);
    pwm_set_gpio_level(_pin_b, 0);

    pwm_set_enabled(_slice, true);
}

uint16_t Motor::percentage_to_pwm(uint8_t percentage)
{
    if (percentage > 100) {
        percentage = 100;
    }

    return static_cast<uint16_t>(
        (percentage * MotorConfig::PWM_WRAP) / 100
    );
}

void Motor::set_pwm(uint pin, uint16_t speed)
{
    if (speed > MotorConfig::MAX_SPEED) {
        speed = MotorConfig::MAX_SPEED;
    }

    pwm_set_gpio_level(pin, speed);
}

void Motor::forward(uint8_t percentage) {
    uint16_t pwm = percentage_to_pwm(percentage);

    set_pwm(_pin_a, 0);
    set_pwm(_pin_b, pwm);

    _speed = pwm;
};

void Motor::backward(uint8_t percentage) {
    uint16_t pwm = percentage_to_pwm(percentage);

    set_pwm(_pin_b, 0);
    set_pwm(_pin_a, pwm);

    _speed = pwm;
}

void Motor::stop() {
    set_pwm(_pin_a, 0);
    set_pwm(_pin_b, 0);

    _speed = 0;
};