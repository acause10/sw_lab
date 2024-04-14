#include "circle.h"

#include <cmath>

#include "point.h"

Circle::Circle(){};

Circle::~Circle(){};

Circle::Circle(Point center, double radius)
{
    center_ = center;
    radius_ = radius;
}

Circle::Circle(Point center, Point OnLine)
{
    double vector_x = OnLine.getX() - center.getX();
    double vector_y = OnLine.getY() - center.getY();

    center_ = center;
    radius_ = sqrt(vector_x * vector_x + vector_y * vector_y);
}

double Circle::calculateArea()
{
    return M_PI * radius_ * radius_;
}

double Circle::calculatePeriphery()
{
    return 2 * M_PI * radius_;
}
bool Circle::pointInsideCircle(Point one)
{
    double vector_x = one.getX() - center_.getX();
    double vector_y = one.getY() - center_.getY();
    double distance = sqrt(vector_x * vector_x + vector_y * vector_y);

    if (distance > radius_)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Circle Circle::moveCircle(Point newLocation)
{
    center_ = newLocation;
    radius_ = radius_;

    return Circle(newLocation, radius_);
}

Circle Circle::resizeCircle(double newRadius)
{
    center_ = center_;
    radius_ = newRadius;

    return Circle(center_, radius_);
}

double Circle::getRadius()
{
    return radius_;
}

Point Circle::getCenter()
{
    return center_;
}
