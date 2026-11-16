#pragma once

#include <iosfwd>
#include <string>

class Pair
{
private:
    double first{};
    double second{};

protected:
    virtual void Validate(double first, double second) const;

public:
    Pair();
    Pair(double first, double second);
    Pair(const Pair& other);
    virtual ~Pair();

    double GetFirst() const;
    double GetSecond() const;

    void SetFirst(double value);
    void SetSecond(double value);
    void SetValues(double first, double second);

    double Product() const;

    Pair& operator=(const Pair& other);
    explicit operator std::string() const;

    friend std::istream& operator>>(std::istream& input, Pair& pair);
    friend std::ostream& operator<<(std::ostream& output, const Pair& pair);
};