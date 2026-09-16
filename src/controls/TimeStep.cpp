#include "controls/TimeStep.hpp"

TimeStep::TimeStep()
    : _previous_time(get_absolute_time())
{
}

float TimeStep::elapsed()
{
    absolute_time_t current_time = get_absolute_time();

    float dt = absolute_time_diff_us(
        _previous_time,
        current_time
    ) / 1'000'000.0f;

    _previous_time = current_time;

    return dt;
}