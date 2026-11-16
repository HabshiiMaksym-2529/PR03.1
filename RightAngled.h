#pragma once

#include "Pair.h"

class RightAngled final : public Pair
{
protected:
    void Validate(double firstLeg, double secondLeg) const override;

public:
    RightAngled();
    RightAngled(double firstLeg, double secondLeg);
    RightAngled(const RightAngled& other);

    double Hypotenuse() const;
    double Area() const;

    RightAngled& operator=(const RightAngled& other);
};