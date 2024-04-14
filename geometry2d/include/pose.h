#ifndef SEL_POSE_H
#define SEL_POSE_H

#include "angle.h"
#include "point.h"

class Point;
class Angle;

class Pose
{
  public:
    Pose(Point position, Angle orientation);      //*
    ~Pose();                                      //*
    double distanceTo(Pose two);                  //*
    Angle getRelativeOrientationTo(Point point);  //*

    bool isEqual(Pose two);
    Pose addPoses(Pose two);       //*
    Pose subtractPoses(Pose two);  //*

    Point getPosition();     //*
    Angle getOrientation();  //*
  private:
    Point position_;
    Angle orientation_;
};

#endif  // SEL_POSE_H
