#include "geo_compare.h"

Geo_compare::Geo_compare() {}

Geo_compare::Geo_compare(double epsilon)
{
    epsilon_ = epsilon;
}

Geo_compare::~Geo_compare() {}

bool Geo_compare::isFuzzyEqual(Point one, Point two)
{
    Compare compare = Compare(epsilon_);
    return compare.isFuzzyEqual(one.getX(), two.getX()) && compare.isFuzzyEqual(one.getY(), two.getY());
}

bool Geo_compare::isFuzzyEqual(Angle one, Angle two)
{
    Compare compare = Compare(epsilon_);
    return compare.isFuzzyEqual(one.getValueBetweenMinusPiAndPi(), two.getValueBetweenMinusPiAndPi()) ||
           compare.isFuzzyEqual(one.getValueBetweenZeroAndTwoPi(), two.getValueBetweenZeroAndTwoPi());
}

bool Geo_compare::isFuzzyEqual(Pose one, Pose two)
{
    Geo_compare compare = Geo_compare(epsilon_);
    return compare.isFuzzyEqual(one.getPosition(), two.getPosition()) &&
           compare.isFuzzyEqual(one.getOrientation(), two.getOrientation());
}
