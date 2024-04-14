#include "circle.h"

#include <cmath>

#include <gtest/gtest.h>

TEST(CircleGoogleTest, testCalculateAreaFirstConstructor)
{
    Point center = Point(1, 1);
    double radius = 3;
    double expectedArea = M_PI * 9;
    Circle circle = Circle(center, radius);

    double trueArea = circle.calculateArea();

    EXPECT_EQ(trueArea, expectedArea);
}

TEST(CircleGoogleTest, testCalculateAreaSecondConstructor)
{
    Point center = Point(1, 0);
    Point OnCircle = Point(4, 0);
    double expectedArea = M_PI * 9;
    Circle circle = Circle(center, OnCircle);

    double trueArea = circle.calculateArea();

    EXPECT_EQ(trueArea, expectedArea);
}

TEST(CircleGoogleTest, testCalculatePeripheryFirstConstructor)
{
    Point center = Point(-1, 3);
    double radius = 4;
    double expectedPeriphery = M_PI * 8;
    Circle circle = Circle(center, radius);

    double truePeriphery = circle.calculatePeriphery();

    EXPECT_EQ(truePeriphery, expectedPeriphery);
}

TEST(CircleGoogleTest, testCalculatePeripherySecondConstructor)
{
    Point center = Point(0, -1);
    Point OnCircle = Point(0, 3);
    double expectedPeriphery = M_PI * 8;
    Circle circle = Circle(center, OnCircle);

    double truePeriphery = circle.calculatePeriphery();

    EXPECT_EQ(truePeriphery, expectedPeriphery);
}

TEST(CircleGoogleTest, testPointInsideCircleTDD1)
{
    Point center = Point(0, 0);
    Point one = Point(2, 3);
    double radius = 6;
    Circle circle = Circle(center, radius);

    double result = circle.pointInsideCircle(one);

    EXPECT_TRUE(result);
}

TEST(CircleGoogleTest, testPointInsideCircleTDD2)
{
    Point center = Point(0, 0);
    Point one = Point(2, 3);
    double radius = 1;
    Circle circle = Circle(center, radius);

    double result = circle.pointInsideCircle(one);

    EXPECT_FALSE(result);
}

TEST(CircleGoogleTest, testNewLocation)
{
    Point center = Point(0, 0);
    Point newCenter = Point(1, 1);
    double radius = 4;
    Circle circle1 = Circle(center, radius);
    Circle circle2 = circle1.moveCircle(newCenter);

    Point expectedNewLocation = circle2.getCenter();
    double expected_x = expectedNewLocation.getX();
    double expected_y = expectedNewLocation.getY();

    EXPECT_EQ(expected_x, 1.0);
    EXPECT_EQ(expected_y, 1.0);
}

TEST(CircleGoogleTest, testNewRadius)
{
    Point center = Point(0, 0);
    double newRadius = 6;
    double radius = 4;
    Circle circle1 = Circle(center, radius);
    Circle circle2 = circle1.resizeCircle(newRadius);

    double expectedNewRadius = circle2.getRadius();

    EXPECT_EQ(expectedNewRadius, newRadius);
}