#include "controls/Button.hpp"

Button::Button(uint gpio)
    : _gpio(gpio),
      _last_state(false) {
    init();
}

void Button::init() {
    gpio_init(_gpio);

    gpio_set_dir(_gpio, GPIO_IN);

    gpio_pull_up(_gpio);

    _last_state = false;
}

bool Button::is_pressed() const {
    return !gpio_get(_gpio);
}

bool Button::was_clicked() {
    bool current_state = is_pressed();

    bool clicked = current_state && !_last_state;

    _last_state = current_state;

    return clicked;
}