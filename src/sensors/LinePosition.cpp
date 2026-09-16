#include "sensors/LinePosition.hpp"

float LinePosition::operator()(float left, float right) const
{
    float total = left + right;

    if (total <= 0.0f) {
        return 0.0f;
    }

    return (right - left) / total;
}