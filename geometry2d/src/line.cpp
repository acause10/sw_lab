#include "line.h"

#include <cmath>
#include <iostream>

using namespace std;

Line::Line(Point start, Angle angle, double distance)
{
    start_ = start;
    end_ = start.addPoints(Point(distance, angle));
}

Line::Line(Point start, Point end)
{
    start_ = start;
    end_ = end;
}

Line::Line() {}

Line::~Line()
{
    return;
}

Angle Line::getDirection()
{
    return Angle(start_, end_);
}

double Line::getLength()
{
    return start_.distanceTo(end_);
}

void Line::shiftParallel(Point point)
{
    Point direction = end_.subtractPoints(start_);
    start_ = point;
    end_ = start_.addPoints(direction);
}

Point Line::getPerpendicularPoint(Point point)
{
    // Create a triangle with point, line.start and line.end. Find orthogonal point via trigonometry

    Line hypotenuse = {point, start_};
    Angle angle = Angle(start_, end_, point);
    Point line_direction = end_.subtractPoints(start_);

    double adjacent_side_length = cos(angle.getAngle()) * hypotenuse.getLength();
    line_direction = line_direction.multiplyPoint(1 / line_direction.getLength());  // direction vector length set
                                                                                    // to one

    Point distance_to_projection = line_direction.multiplyPoint(adjacent_side_length);
    Point result = start_.addPoints(distance_to_projection);

    return result;
}

Point Line::getStart()
{
    return start_;
}

Point Line::getEnd()
{
    return end_;
}
