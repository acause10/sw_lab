#include "compare.h"

#include <cmath>

Compare::Compare() {}

Compare::Compare(double epsilon)
{
    epsilon_ = epsilon;
}

Compare::~Compare() {}

bool Compare::isFuzzyEqual(double value1, double value2)
{
    return fabs(value1 - value2) < epsilon_;
}

bool Compare::isFuzzyGreater(double value1, double value2)
{
    return value1 + epsilon_ > value2;
}

bool Compare::isFuzzySmaller(double value1, double value2)
{
    return value1 < epsilon_ + value2;
}

bool Compare::isStrictFuzzyGreater(double value1, double value2)
{
    return value1 > epsilon_ + value2;
}

bool Compare::isStrictFuzzySmaller(double value1, double value2)
{
    return value1 + epsilon_ < value2;
}