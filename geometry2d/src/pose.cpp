#include "pose.h"

#include <iostream>

#include "angle.h"
#include "geo_compare.h"

Pose::Pose(Point position, Angle orientation)
{
    position_ = position;
    orientation_ = orientation;
}

Pose::~Pose()
{
    std::cout << "Destructor: Destroy Pose" << std::endl;
}

Point Pose::getPosition()
{
    return position_;
}

Angle Pose::getOrientation()
{
    return orientation_;
}

double Pose::distanceTo(Pose two)
{
    return position_.distanceTo(two.getPosition());
}

Angle Pose::getRelativeOrientationTo(Point point)
{
    // Angle ang_1 = Angle(position_, point);
    // Angle new_ang = orientation_.subtractAngles(ang_1);
    // return new_ang;
    Angle ang = Angle(position_, point);
    return Angle{ang.subtractAngles(orientation_)};
}

bool Pose::isEqual(Pose two)
{
    Geo_compare compare = Geo_compare(0.00001);
    return compare.isFuzzyEqual(Pose(position_, orientation_), two);
}

Pose Pose::addPoses(Pose two)
{
    orientation_ = orientation_.addAngles(two.orientation_);
    position_ = position_.addPoints(two.position_);
    return Pose{position_, orientation_};
}

Pose Pose::subtractPoses(Pose two)
{
    orientation_ = orientation_.subtractAngles(two.orientation_);
    position_ = position_.subtractPoints(two.position_);
    return Pose{position_, orientation_};
}
