#pragma once

#include "pico/stdlib.h"

class Button {
private:
    uint _gpio;
    bool _last_state;

    void init();

public:
    explicit Button(uint gpio);

    bool is_pressed() const;

    bool was_clicked();
};