#ifndef SEL_CIRCLE_H
#define SEL_CIRCLE_H

#include "point.h"

class Point;

class Circle
{
  public:
    Circle();
    Circle(Point center, double radius);
    Circle(Point center, Point OnCircle);
    ~Circle();

    double getRadius();
    Point getCenter();
    double calculateArea();
    double calculatePeriphery();
    bool pointInsideCircle(Point one);
    Circle moveCircle(Point newLocation);
    Circle resizeCircle(double newRadius);

  private:
    Point center_;
    double radius_;
};

#endif  // SEL_CIRCLE_H
