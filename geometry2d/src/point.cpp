#include "point.h"

#include <cmath>

#include "geo_compare.h"

Point::Point(double x_coord, double y_coord)
{
    x = x_coord;
    y = y_coord;
}

Point::Point(double distance, Angle angle)
{
    x = distance * cos(angle.getValueBetweenMinusPiAndPi());
    y = distance * sin(angle.getValueBetweenMinusPiAndPi());
}

Point::Point() {}

Point::~Point()
{
    return;
}

bool Point::isEqual(Point point)
{
    Geo_compare compare = Geo_compare(0.00001);
    return compare.isFuzzyEqual(Point(x, y), point);
}

double Point::getLength()
{
    return sqrt(x * x + y * y);
}

double Point::distanceTo(Point point)
{
    return subtractPoints(point).getLength();
}

Point Point::subtractPoints(Point point)
{
    return Point(x - point.x, y - point.y);
}

Point Point::addPoints(Point point)
{
    return Point(x + point.x, y + point.y);
}

Point Point::multiplyPoint(double factor)
{
    return Point(x * factor, y * factor);
}

void Point::rotate(Angle angle)
{
    double angleValue = angle.getValueBetweenMinusPiAndPi();
    double xVal = x * cos(angleValue) - y * sin(angleValue);
    double yVal = x * sin(angleValue) + y * cos(angleValue);
    x = xVal;
    y = yVal;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}
