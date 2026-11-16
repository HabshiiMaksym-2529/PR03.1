#include "Pair.h"

#include <cmath>
#include <istream>
#include <ostream>
#include <sstream>
#include <stdexcept>

Pair::Pair() = default;

Pair::Pair(double first, double second)
{
    SetValues(first, second);
}

Pair::Pair(const Pair& other) = default;

Pair::~Pair() = default;

void Pair::Validate(double first, double second) const
{
    if (!std::isfinite(first) || !std::isfinite(second))
    {
        throw std::invalid_argument("Both numbers must be finite.");
    }
}

double Pair::GetFirst() const
{
    return first;
}

double Pair::GetSecond() const
{
    return second;
}

void Pair::SetFirst(double value)
{
    SetValues(value, second);
}

void Pair::SetSecond(double value)
{
    SetValues(first, value);
}

void Pair::SetValues(double first, double second)
{
    Validate(first, second);

    this->first = first;
    this->second = second;
}

double Pair::Product() const
{
    return first * second;
}

Pair& Pair::operator=(const Pair& other)
{
    SetValues(other.first, other.second);
    return *this;
}

Pair::operator std::string() const
{
    std::ostringstream output;
    output << *this;
    return output.str();
}

std::istream& operator>>(std::istream& input, Pair& pair)
{
    double first{};
    double second{};

    if (input >> first >> second)
    {
        pair.SetValues(first, second);
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Pair& pair)
{
    return output << '(' << pair.first << ", " << pair.second << ')';
}