#include <cmath>

#include <geo_compare.h>
#include <gtest/gtest.h>

TEST(GeoCompareTest, testisFuzzyEqualPoints_1)
{
    const Point firstPoint = Point(1, 1);
    const Point secondPoint = Point(2, 2);
    const double epsilonTest = 0.00002;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstPoint, secondPoint);

    EXPECT_FALSE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualPoints_2)
{
    const Point firstPoint = Point(-2, -2);
    const Point secondPoint = Point(-2, -2);
    const double epsilonTest = 0.00002;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstPoint, secondPoint);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualAngles_45)
{
    const Angle firstAngle = Angle(M_PI_4);
    const Angle secondAngle = Angle(M_PI_4);
    const double epsilonTest = 0.0002;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstAngle, secondAngle);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualAngles_360_0)
{
    const Angle firstAngle = Angle(2 * M_PI);
    const Angle secondAngle = Angle(0);
    const double epsilonTest = 0.000001;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstAngle, secondAngle);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualAngles_270_m90)
{
    const Angle firstAngle = Angle(6 * M_PI_4);
    const Angle secondAngle = Angle(-M_PI_2);
    const double epsilonTest = 0.0001;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstAngle, secondAngle);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualAngles_180_m180)
{
    const Angle firstAngle = Angle(M_PI);
    const Angle secondAngle = Angle(-M_PI);
    const double epsilonTest = 0.00001;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstAngle, secondAngle);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualAngles_90_m270)
{
    const Angle firstAngle = Angle(M_PI_2);
    const Angle secondAngle = Angle(-6 * M_PI_4);
    const double epsilonTest = 0.000001;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(firstAngle, secondAngle);

    EXPECT_TRUE(truth);
}

TEST(GeoCompareTest, testisFuzzyEqualPoses_45)
{
    const Pose poseOne = Pose(Point(0, 0), Angle(M_PI_4));
    const Pose poseTwo = Pose(Point(0, 0), Angle(M_PI_4));
    const double epsilonTest = 0.0002;

    Geo_compare compare = Geo_compare(epsilonTest);

    bool truth = compare.isFuzzyEqual(poseOne, poseTwo);

    EXPECT_TRUE(truth);
}