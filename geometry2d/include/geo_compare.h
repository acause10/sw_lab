#ifndef SEL_GEOCOMPARE_H
#define SEL_GEOCOMPARE_H

#include "compare.h"
#include "pose.h"

class Compare;

class Geo_compare
{

  public:
    Geo_compare();
    Geo_compare(double epsilon);
    ~Geo_compare();

    bool isFuzzyEqual(Point one, Point two);
    bool isFuzzyEqual(Angle one, Angle two);
    bool isFuzzyEqual(Pose one, Pose two);

  private:
    double epsilon_;
};

#endif  // SEL_GEOCOMPARE_H
