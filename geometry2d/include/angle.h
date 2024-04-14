#ifndef SEL_ANGLE_H
#define SEL_ANGLE_H

#include "point.h"

class Point;

class Angle
{

  public:
    Angle(double angle);  //*
    Angle();              //*
    Angle(Point start, Point end);
    Angle(Point source, Point targetOne, Point targetTwo);
    ~Angle();  //*

    double fixAngleRange();                //*
    double getValueBetweenMinusPiAndPi();  //*
    double getValueBetweenZeroAndTwoPi();  //*
    bool isObtuse();                       //*
    Angle abs();                           //*

    Angle addAngles(Angle two);          //*
    Angle subtractAngles(Angle two);     //*
    Angle multiplyAngle(double factor);  //*
    bool isEqual(Angle two);             //*

    Angle getHalfRotation();             //?
    Angle getQuarterRotation();          //?
    Angle getFullRotation();             //?
    Angle getEighthRotation();           //?
    Angle convertFromDegreeToRadiant();  //*
    double getAngle();

  private:
    double value{0.0};  //*
};

#endif  // SEL_ANGLE_H
