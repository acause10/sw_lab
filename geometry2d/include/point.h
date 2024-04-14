#ifndef SEL_POINT_H
#define SEL_POINT_H

#include "angle.h"

class Angle;

class Point
{
  public:
    Point(double x_coord, double y_coord);
    ~Point();

    Point();
    Point(double distance, Angle angle);  // createPoint(double distane, Angle angle)

    bool isEqual(Point point);
    Point addPoints(Point point);
    Point subtractPoints(Point point);
    Point multiplyPoint(double factor);

    double getLength();
    double distanceTo(Point point);
    void rotate(Angle angle);

    double getX();  // getter functions
    double getY();

  private:
    double x;
    double y;
};

#endif  // SEL_POINT_H
