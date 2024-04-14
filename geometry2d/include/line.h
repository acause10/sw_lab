#ifndef SEL_LINE_H
#define SEL_LINE_H

#include "angle.h"
#include "point.h"

class Angle;

class Point;

class Line
{
  public:
    Line(Point start, Point end);
    ~Line();

    Line();
    Line(Point start, Angle angle, double distance);

    Angle getDirection();
    double getLength();
    void shiftParallel(Point point);
    Point getPerpendicularPoint(Point point);
    Point getStart();
    Point getEnd();

  private:
    Point start_;
    Point end_;
};

#endif  // SEL_LINE_H
