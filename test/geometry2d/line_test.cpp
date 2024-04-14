#include "line.h"

#include <cmath>

#include <gtest/gtest.h>

TEST(createLineGoogleTest, createLinePosDistance)
{
    Point start = Point(1.0, 1.0);
    Angle angle = {0};
    const double distance = 3.0;

    Point TrueEnd = Point(4.0, 1.0);
    Line result = Line(start, angle, distance);

    Point start_line = result.getStart();
    Point end_line = result.getEnd();

    bool compare1 = start.isEqual(start_line);
    bool compare2 = TrueEnd.isEqual(end_line);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(createLineGoogleTest, createLineNegDistance)
{
    Point start = Point(1.0, 1.0);
    const Angle angle = {0};
    const double distance = -3.0;
    Point TrueEnd = Point(-2.0, 1.0);

    Line result = Line(start, angle, distance);

    Point start_line = result.getStart();
    Point end_line = result.getEnd();

    bool compare1 = start.isEqual(start_line);
    bool compare2 = TrueEnd.isEqual(end_line);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(createLineGoogleTest, createLinePI_2)
{
    Point start = Point(3.0, 2.0);
    const Angle angle = {M_PI_2};
    const double distance = 2.0;

    Point TrueEnd = Point(3.0, 4.0);
    Line result = Line(start, angle, distance);

    Point start_line = result.getStart();
    Point end_line = result.getEnd();

    bool compare1 = start.isEqual(start_line);
    bool compare2 = TrueEnd.isEqual(end_line);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(createLineGoogleTest, createLine2PI)
{
    Point start = Point(3.0, 0.0);
    const Angle angle = {2 * M_PI};
    const double distance = 2.0;

    Point TrueEnd = Point(5.0, 0.0);
    Line result = Line(start, angle, distance);

    Point start_line = result.getStart();
    Point end_line = result.getEnd();

    bool compare1 = start.isEqual(start_line);
    bool compare2 = TrueEnd.isEqual(end_line);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(getDirectionGoogleTest, getDirectionPosValues)
{
    Line line = Line(Point(1, 1), Point(2, 2));
    const double TrueAngle = M_PI_4;
    Angle result = line.getDirection();

    EXPECT_EQ(TrueAngle, result.getAngle());
}

TEST(getDirectionGoogleTest, getDirectionMixedValues)
{
    Line line = Line(Point(2, -3), Point(2, 1));
    const double TrueAngle = M_PI_2;
    Angle result = line.getDirection();

    EXPECT_EQ(TrueAngle, result.getAngle());
}

TEST(getDirectionGoogleTest, getDirectionNegStart)
{
    Line line = Line(Point(-2, 1), Point(-3, 1));
    const double TrueAngle = M_PI;
    Angle result = line.getDirection();

    EXPECT_EQ(TrueAngle, result.getAngle());
}

TEST(getDirectionGoogleTest, getDirectionNegEnd)
{
    Line line = Line(Point(3, 0), Point(3, -2));
    const double TrueAngle = -M_PI_2;
    Angle result = line.getDirection();

    EXPECT_EQ(TrueAngle, result.getAngle());
}

TEST(getDirectionGoogleTest, getDirectionScalar)
{
    Line line = Line(Point(0, -2), Point(4.5, -2));
    const double TrueAngle = 0;
    Angle result = line.getDirection();

    EXPECT_EQ(TrueAngle, result.getAngle());
}

TEST(getLengthGoogleTest, getLengthPosValues)
{
    Line line = Line(Point(0, 0), Point(1, 1));
    const double TrueLength = sqrt(2);
    const double result = line.getLength();

    EXPECT_EQ(TrueLength, result);
}

TEST(getLengthGoogleTest, getLengthNegValues)
{
    Line line = Line(Point(-3, -4), Point(-1, -2));
    const double TrueLength = sqrt(8);
    const double result = line.getLength();

    EXPECT_EQ(TrueLength, result);
}

TEST(getLengthGoogleTest, getLengthNegStart)
{
    Line line = Line(Point(-1, 0), Point(0, 1));
    const double TrueLength = sqrt(2);
    const double result = line.getLength();

    EXPECT_EQ(TrueLength, result);
}

TEST(getLengthGoogleTest, getLengthNegEnd)
{
    Line line = Line(Point(3, 1), Point(-5, -7));
    const double TrueLength = sqrt(128);
    const double result = line.getLength();

    EXPECT_EQ(TrueLength, result);
}

TEST(shiftParallelGoogleTest, shiftParallelPosValues)
{
    Point TrueLineEnd = Point(1, 3);

    Line TrueLine = Line(Point(1, 3), Point(2, 3));
    Line& line = TrueLine;

    Point point = Point(0, 3);

    line.shiftParallel(point);

    Point start = line.getStart();
    Point end = line.getEnd();

    bool compare1 = point.isEqual(start);
    bool compare2 = TrueLineEnd.isEqual(end);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(shiftParallelGoogleTest, shiftParallelNegStart)
{
    Point TrueLineEnd = Point(7, 3);

    Line TrueLine = Line(Point(-3, 1), Point(5, 7));
    Line& line = TrueLine;

    Point point = Point(-1, -3);

    line.shiftParallel(point);

    Point start = line.getStart();
    Point end = line.getEnd();

    bool compare1 = point.isEqual(start);
    bool compare2 = TrueLineEnd.isEqual(end);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(shiftParallelGoogleTest, shiftParallelNegEnd)
{
    Point TrueLineEnd = Point(-2, -14);

    Line TrueLine = Line(Point(1, 4), Point(-6, -9));
    Line& line = TrueLine;

    Point point = Point(5, -1);

    line.shiftParallel(point);

    Point start = line.getStart();
    Point end = line.getEnd();

    bool compare1 = point.isEqual(start);
    bool compare2 = TrueLineEnd.isEqual(end);

    EXPECT_TRUE(compare1);
    EXPECT_TRUE(compare2);
}

TEST(getPerpendicularPoint, test_pointOnLine)
{
    Point point = Point(0, 0);
    Line line = Line(Point(-3, 0), Point(3, 0));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(0, 0);

    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_pointNotOnLine_LineOnXAxis)
{
    Point point = Point(0, 1);
    Line line = Line(Point(-5, 0), Point(5, 0));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(0, 0);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_pointNotonLine_LineOnYAxis)
{
    Point point = Point(-3, 6);
    Line line = Line(Point(0, -10), Point(0, 14));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(0, 6);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_LineParalleltoXAxis)
{
    Point point = Point(-4, 1);
    Line line = Line(Point(-8, 3), Point(11, 3));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(-4, 3);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_LineParalleltoYAxis)
{
    Point point = Point(-4, 1);
    Line line = Line(Point(-1, 5), Point(-1, -4));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(-1, 1);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_LineAngleBisectorOrigin)
{
    Point point = Point(0, 2);
    Line line = Line(Point(-10, -10), Point(10, 10));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(1, 1);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}

TEST(getPerpendicularPoint, test_SlopedLine)
{
    Point point = Point(-3.5, 2);
    Line line = Line(Point(0, 0), Point(3, 1.5));
    Point result = line.getPerpendicularPoint(point);
    Point expected_result = Point(-2, -1);
    bool compare = result.isEqual(expected_result);
    EXPECT_TRUE(compare);
}
