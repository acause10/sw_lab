#include "point.h"

#include <cmath>

#include <gtest/gtest.h>

#include "geo_compare.h"

TEST(PointTest, testcreatePoint)
{
    const double distance = 5;
    const Angle angle = Angle{M_PI_2};
    Point result = Point(distance, angle);
    const Point expected_result = Point(0, 5);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testcreatePointOrigin)
{
    const double distance = 0;
    const Angle angle = Angle{M_PI};
    Point result = Point(distance, angle);
    const Point expected_result = Point(0, 0);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testcreatePointBigAngle)
{
    const double distance = 6;
    const Angle angle = Angle{4 * M_PI};
    Point result = Point(distance, angle);
    const Point expected_result = Point(6, 0);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testisEqualSamePoints)
{
    Point point1 = Point(2, 4);
    Point point2 = Point(2, 4);
    const bool result = point1.isEqual(point2);
    EXPECT_TRUE(result);
}

TEST(PointTest, testisEqualClosePoints)
{
    Point point1 = Point(1, 6);
    Point point2 = Point(2, 5);
    const bool result = point1.isEqual(point2);
    EXPECT_FALSE(result);
}

TEST(PointTest, testisEqualFarAwayPoints)
{
    Point point1 = Point(6, 2);
    Point point2 = Point(19, -6);
    const bool result = point1.isEqual(point2);
    EXPECT_FALSE(result);
}

TEST(PointTest, testaddPoints)
{
    Point point1 = Point(2, 4);
    Point point2 = Point(4, 8);
    Point result = point1.addPoints(point2);
    Point expected_result = Point(6, 12);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testaddPointNegValues)
{
    Point point1 = Point(-3, 7);
    Point point2 = Point(-1, -10);
    Point result = point1.addPoints(point2);
    Point expected_result = Point(-4, -3);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testsubtractPoints)
{
    Point point1 = Point(6, 17);
    Point point2 = Point(5, 3);
    Point result = point1.subtractPoints(point2);
    Point expected_result = Point(1, 14);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testsubtractPointsNegValues)
{
    Point point1 = Point(-5, 28);
    Point point2 = Point(-17, -10);
    Point result = point1.subtractPoints(point2);
    Point expected_result = Point(12, 38);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testmultiplyPoints)
{
    Point point = Point(20, 17);
    const double factor = 2;
    Point result = point.multiplyPoint(factor);
    Point expected_result = Point(40, 34);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testmultiplyPointNegFactor)
{
    Point point = Point(4, 5);
    const double factor = -3;
    Point result = point.multiplyPoint(factor);
    Point expected_result = Point(-12, -15);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testmultiplyPointOrigin)
{
    Point point = Point(0, 0);
    const double factor = 7;
    Point result = point.multiplyPoint(factor);
    Point expected_result = Point(0, 0);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testmultiplyPointByZero)
{
    Point point = Point(18, -5);
    const double factor = 0;
    Point result = point.multiplyPoint(factor);
    Point expected_result = Point(0, 0);
    const bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testgetLength)
{
    Point point = Point(3, 4);
    const double result = point.getLength();
    const double expected_result = 5;
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testgetLengthNegValues)
{
    Point point = Point(-2, -5);
    const double result = point.getLength();
    const double expected_result = sqrt(29);
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testgetLengthOrigin)
{
    Point point = Point(0, 0);
    const double result = point.getLength();
    const double expected_result = 0;
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testdistanceTo)
{
    Point point1 = Point(8, 12);
    Point point2 = Point(9, 2);
    const double result = point1.distanceTo(point2);
    const double expected_result = sqrt(101);
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testdistanceToOrigin)
{
    Point point1 = Point(3, 4);
    Point point2 = Point(0, 0);
    const double result = point1.distanceTo(point2);
    const double expected_result = 5;
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testdistanceToNegValues)
{
    Point point1 = Point(4, -1);
    Point point2 = Point(-3, -9);
    const double result = point1.distanceTo(point2);
    const double expected_result = sqrt(113);
    EXPECT_EQ(expected_result, result);
}

TEST(PointTest, testrotate)
{
    Point point = Point(1, 0);
    const Point expected_result = Point(-1, 0);
    const Angle angle = Angle{M_PI};
    point.rotate(angle);
    const bool compare = point.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testrotateNegAngle)
{
    Point point = Point(2, 3);
    Point expected_result = Point(3.53553, 0.707107);
    Angle angle = Angle{-M_PI_4};
    point.rotate(angle);
    const bool compare = point.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testrotateBigAngle)
{
    Point point = Point(-2, -1);
    const Point expected_result = Point(1, -2);
    const Angle angle = Angle{M_PI_2 + 8 * M_PI};
    point.rotate(angle);
    const bool compare = point.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(PointTest, testrotateOrigin)
{
    Point point = Point(0, 0);
    const Point expected_result = Point(0, 0);
    const Angle angle = Angle{M_PI};
    point.rotate(angle);
    const bool compare = point.isEqual(expected_result);
    EXPECT_TRUE(compare);
}