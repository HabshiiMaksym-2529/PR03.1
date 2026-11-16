#include "RightAngled.h"

#include <cmath>
#include <stdexcept>

RightAngled::RightAngled()
    : RightAngled(1.0, 1.0)
{
}

RightAngled::RightAngled(double firstLeg, double secondLeg)
    : Pair(firstLeg, secondLeg)
{
    Validate(firstLeg, secondLeg);
}

RightAngled::RightAngled(const RightAngled& other) = default;

void RightAngled::Validate(double firstLeg, double secondLeg) const
{
    Pair::Validate(firstLeg, secondLeg);

    if (firstLeg <= 0.0 || secondLeg <= 0.0)
    {
        throw std::invalid_argument("Both triangle legs must be positive.");
    }
}

double RightAngled::Hypotenuse() const
{
    return std::hypot(GetFirst(), GetSecond());
}

double RightAngled::Area() const
{
    const double first = GetFirst();
    const double second = GetSecond();

    if (first >= second)
    {
        return (first * 0.5) * second;
    }

    return first * (second * 0.5);
}

RightAngled& RightAngled::operator=(const RightAngled& other) = default;