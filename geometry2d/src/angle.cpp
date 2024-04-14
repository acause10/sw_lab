#include "angle.h"

#include <cmath>
#include <iostream>

#include "compare.h"
#include "point.h"

using namespace std;

Angle::Angle(double angle)  //*
{
    value = angle;
    std::cout << "Constructor: Create Angle" << std::endl;
}

Angle::Angle() {}

Angle::Angle(Point start, Point end)
{
    Point positionDifference = end.subtractPoints(start);
    value = atan2(positionDifference.getY(), positionDifference.getX());
    value = fixAngleRange();
}

Angle::Angle(Point source, Point targetOne, Point targetTwo)
{
    Compare compare = Compare(0.001);

    if (!compare.isFuzzyEqual(source.distanceTo(targetOne), 0) &&
        !compare.isFuzzyEqual(source.distanceTo(targetTwo), 0))
    {
        Angle ang = Angle(source, targetOne).subtractAngles(Angle(source, targetTwo)).abs();
        value = ang.getAngle();
    }
    else
        value = {0};
}

Angle::~Angle()
{
    std::cout << "Destructor: Destroy Angle" << std::endl;
}

double Angle::getAngle()
{
    return value;
}

double Angle::fixAngleRange()  //*
{
    while (value <= M_PI)
    {
        value += 2 * M_PI;
    }

    value -= 2 * M_PI * static_cast<unsigned int>(value / (2 * M_PI));

    return value > M_PI ? value - 2 * M_PI : value;
}

Angle Angle::convertFromDegreeToRadiant()  //*
{
    return Angle(value / 180 * M_PI);
}

Angle Angle::getHalfRotation()
{
    return Angle{M_PI};
}

Angle Angle::getQuarterRotation()
{
    return Angle{M_PI_2};
}

Angle Angle::getFullRotation()
{
    return {};
}

Angle Angle::getEighthRotation()
{
    return Angle{M_PI_4};
}

double Angle::getValueBetweenMinusPiAndPi()  //*
{
    return fixAngleRange();
}

double Angle::getValueBetweenZeroAndTwoPi()  //*
{
    value = fixAngleRange();
    return value < 0 ? value + 2 * M_PI : value;
}

Angle Angle::multiplyAngle(double factor)  //*
{
    value = value * factor;
    return Angle{fixAngleRange()};
}

Angle Angle::addAngles(Angle two)  //*
{
    value = value + two.value;
    value = getValueBetweenMinusPiAndPi();
    return Angle{fixAngleRange()};
}

Angle Angle::subtractAngles(Angle two)  //*
{
    value = value - two.value;
    value = getValueBetweenMinusPiAndPi();
    return Angle{fixAngleRange()};
}

bool Angle::isEqual(Angle two)  //*
{
    return getValueBetweenMinusPiAndPi() == two.getValueBetweenMinusPiAndPi();
}

bool Angle::isObtuse()  //*
{
    return fabs(getValueBetweenMinusPiAndPi()) > M_PI_2;
}

Angle Angle::abs()  //*
{
    return Angle{fabs(getValueBetweenMinusPiAndPi())};
}
