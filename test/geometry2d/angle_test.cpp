#include "angle.h"

#include <cmath>

#include <gtest/gtest.h>

#include "compare.h"
#include "point.h"

TEST(AngleGoogleTest, testFixAngleRangeneg3PI)
{
    Angle angleValue = Angle(-3 * M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI);
}

TEST(AngleGoogleTest, testFixAngleRangeneg5PI_2)
{
    Angle angleValue = Angle(-5 * M_PI_2);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, -M_PI_2);
}

TEST(AngleGoogleTest, testFixAngleRangeneg2PI)
{
    Angle angleValue = Angle(-2 * M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, 0);
}

TEST(AngleGoogleTest, testFixAngleRangenegPI)
{
    Angle angleValue = Angle(-M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI);
}

TEST(AngleGoogleTest, testFixAngleRangenegPI_2)
{
    Angle angleValue = Angle(-M_PI_2);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, -M_PI_2);
}

TEST(AngleGoogleTest, testFixAngleRange0PI)
{
    Angle angleValue = Angle(0);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, 0);
}

TEST(AngleGoogleTest, testFixAngleRangePI_2)
{
    Angle angleValue = Angle(M_PI_2);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI_2);
}

TEST(AngleGoogleTest, testFixAngleRangePI)
{
    Angle angleValue = Angle(M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI);
}

TEST(AngleGoogleTest, testFixAngleRange2PI)
{
    Angle angleValue = Angle(2 * M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, 0);
}

TEST(AngleGoogleTest, testFixAngleRange5PI_2)
{
    Angle angleValue = Angle(5 * M_PI_2);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI_2);
}

TEST(AngleGoogleTest, testFixAngleRange3PI)
{
    Angle angleValue = Angle(3 * M_PI);
    const double result = angleValue.fixAngleRange();

    EXPECT_EQ(result, M_PI);
}

TEST(AngleGoogleTest, testConvertFromDegreeToRadiant90Degrees)
{
    Angle angle = Angle(90);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = angle.convertFromDegreeToRadiant();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testConvertFromDegreeToRadiant450Degrees)
{
    Angle angle = Angle(450);
    Angle TrueAngle = Angle(5 * M_PI_2);
    Angle result = angle.convertFromDegreeToRadiant();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testConvertFromDegreeToRadiantneg180Degrees)
{
    Angle angle = Angle(-180);
    Angle TrueAngle = Angle(-M_PI);
    Angle result = angle.convertFromDegreeToRadiant();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetHalfRotation)
{
    Angle result = Angle();
    result = result.getHalfRotation();
    Angle TrueAngle = Angle(M_PI);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetHalfRotation)
{
    Angle result = Angle();
    result = result.getHalfRotation();
    Angle TrueAngle = Angle(M_PI);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetQuarterRotation)
{
    Angle result = Angle();
    result = result.getQuarterRotation();
    Angle TrueAngle = Angle(M_PI_2);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetFullRotation)
{
    Angle result = Angle();
    result = result.getFullRotation();
    Angle TrueAngle = Angle();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetEighthRotation)
{
    Angle result = Angle();
    result = result.getEighthRotation();
    Angle TrueAngle = Angle(M_PI_4);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetValueBetweenMinusPiAndPinegPI_2)
{
    Angle angle = Angle(-M_PI_2);
    Angle TrueAngle = Angle(-M_PI_2);
    Angle result = angle.getValueBetweenMinusPiAndPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetValueBetweenMinusPiAndPi0)
{
    Angle angle = Angle(0);
    Angle TrueAngle = Angle(0);
    Angle result = angle.getValueBetweenMinusPiAndPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testGetValueBetweenMinusPiAndPiPI_2)
{
    Angle angle = Angle{M_PI_2};
    Angle TrueAngle = Angle{M_PI_2};
    Angle result = angle.getValueBetweenMinusPiAndPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetValueBetweenZeroAndTwoPinegPI)
{
    Angle angle = Angle(-M_PI);
    Angle TrueAngle = Angle(M_PI);
    Angle result = angle.getValueBetweenZeroAndTwoPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetValueBetweenZeroAndTwoPinegPI_2)
{
    Angle angle = Angle(-M_PI_2);
    Angle TrueAngle = Angle(3 * M_PI_2);
    Angle result = angle.getValueBetweenZeroAndTwoPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetValueBetweenZeroAndTwoPi0)
{
    Angle angle = Angle(0);
    Angle TrueAngle = Angle(0);
    Angle result = angle.getValueBetweenZeroAndTwoPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetValueBetweenZeroAndTwoPiPI_2)
{
    Angle angle = Angle(M_PI_2);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = angle.getValueBetweenZeroAndTwoPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testgetValueBetweenZeroAndTwoPiPI)
{
    Angle angle = Angle(M_PI);
    Angle TrueAngle = Angle(M_PI);
    Angle result = angle.getValueBetweenZeroAndTwoPi();

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testmMultiplyAnglenegM_PI3)
{
    const double factor = 3;
    Angle angle = Angle(-M_PI);
    Angle TrueAngle = Angle(M_PI);
    Angle result = angle.multiplyAngle(factor);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testmMultiplyAnglenegM_PI_4_3)
{
    const double factor = 2;
    Angle angle = Angle(-M_PI_4);
    Angle TrueAngle = Angle(-M_PI_2);
    Angle result = angle.multiplyAngle(factor);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testmMultiplyAngleM_PI_4_3)
{
    const double factor = 2;
    Angle angle = Angle(M_PI_4);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = angle.multiplyAngle(factor);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testmMultiplyAngleM_PI3)
{
    const double factor = 3;
    Angle angle = Angle(-M_PI);
    Angle TrueAngle = Angle(M_PI);
    Angle result = angle.multiplyAngle(factor);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testAddAnglesnegPI)
{
    Angle one = Angle(-M_PI);
    Angle two = Angle(-M_PI);
    Angle TrueAngle = Angle(0);
    Angle result = one.addAngles(two);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testAddAnglesnegPI_4)
{
    Angle one = Angle(-M_PI_4);
    Angle two = Angle(-M_PI_4);
    Angle TrueAngle = Angle(-M_PI_2);
    Angle result = one.addAngles(two);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testAddAnglesPI_4)
{
    Angle one = Angle(M_PI_4);
    Angle two = Angle(M_PI_4);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = one.addAngles(two);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testAddAnglesPI)
{
    Angle one = Angle(M_PI);
    Angle two = Angle(M_PI);
    Angle TrueAngle = Angle(0);
    Angle result = one.addAngles(two);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testSubtractAnglesNegPI_2)
{
    Angle angle1 = Angle(-M_PI);
    Angle angle2 = Angle(-M_PI_2);
    Angle TrueAngle = Angle(-M_PI_2);
    Angle result = angle1.subtractAngles(angle2);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testSubtractAnglesNegResult)
{
    Angle angle1 = Angle(M_PI_4);
    Angle angle2 = Angle(M_PI);
    Angle TrueAngle = Angle(-3 * M_PI_4);
    Angle result = angle1.subtractAngles(angle2);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testSubtractAnglesPosResult)
{
    Angle angle1 = Angle(M_PI);
    Angle angle2 = Angle(M_PI_2);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = angle1.subtractAngles(angle2);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testSubtractAnglesOutOfNegPItoPIarea)
{
    Angle angle1 = Angle(3 * M_PI);
    Angle angle2 = Angle(5 * M_PI_2);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = angle1.subtractAngles(angle2);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testCreateAnglePI_2)
{
    Point start = Point(0, 1);
    Point end = Point(0, 3);
    Angle TrueAngle = Angle(M_PI_2);
    Angle result = Angle(start, end);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testCreateAnglePI)
{
    Point start = Point(-1, 5);
    Point end = Point(-2, 5);
    Angle TrueAngle = Angle(M_PI);
    Angle result = Angle(start, end);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testCreateAngleNegPI_2)
{
    Point start = Point(4, 1);
    Point end = Point(4, 0);
    Angle TrueAngle = (-M_PI_2);
    Angle result = Angle(start, end);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testCreateAngleZero)
{
    Point start = Point(2, 2);
    Point end = Point(4, 2);
    Angle TrueAngle = Angle(0);
    Angle result = Angle(start, end);

    EXPECT_EQ(result.getAngle(), TrueAngle.getAngle());
}

TEST(AngleGoogleTest, testisEqualexpectTrue)
{
    Angle one = Angle(M_PI);
    Angle two = Angle(M_PI);
    // const bool expected_result = true;
    const bool result = one.isEqual(two);

    EXPECT_TRUE(result);
}

TEST(AngleGoogleTest, testisEqualexpectFalse)
{
    Angle one = Angle(M_PI);
    Angle two = Angle(M_PI_2);
    // const bool expected_result = false;
    const bool result = one.isEqual(two);

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisEqualNegAngles)
{
    Angle one = Angle(-M_PI_2);
    Angle two = Angle(-M_PI_2);
    // const bool expected_result = true;
    const bool result = one.isEqual(two);

    EXPECT_TRUE(result);
}

TEST(AngleGoogleTest, testisEqualBigAnglesExpectTrue)
{
    Angle one = Angle(7 * M_PI);
    Angle two = Angle(7 * M_PI);
    // const bool expected_result = true;
    const bool result = one.isEqual(two);

    EXPECT_TRUE(result);
}

TEST(AngleGoogleTest, testisEqualBigAnglesExpectFalse)
{
    Angle one = Angle(8 * M_PI);
    Angle two = Angle(7 * M_PI);
    // const bool expected_result = false;
    const bool result = one.isEqual(two);

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisEqualCloseAngles)
{
    Angle one = Angle(0);
    Angle two = Angle(0.1);
    // const bool expected_result = false;
    const bool result = one.isEqual(two);

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisObtuseExpectFalse)
{
    Angle angle = Angle(M_PI_4);
    // const bool expected_result = false;
    const bool result = angle.isObtuse();

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisObtuseExpectTrue)
{
    Angle angle = Angle(M_PI);
    // const bool expected_result = true;
    const bool result = angle.isObtuse();

    EXPECT_TRUE(result);
}

TEST(AngleGoogleTest, testisObtuseNegAngleExpectFalse)
{
    Angle angle = Angle(-M_PI_4);
    // const bool expected_result = false;
    const bool result = angle.isObtuse();

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisObtuseBigAngle)
{
    Angle angle = Angle(4 * M_PI);
    // const bool expected_result = false;
    const bool result = angle.isObtuse();

    EXPECT_FALSE(result);
}

TEST(AngleGoogleTest, testisObtuseNegAngleExpectTrue)
{
    Angle angle = Angle(-3 * M_PI_4);
    // const bool expected_result = true;
    const bool result = angle.isObtuse();

    EXPECT_TRUE(result);
}

TEST(AngleGoogleTest, testabs)
{
    Angle angle = Angle(M_PI_2);
    Angle expected_result = Angle(M_PI_2);
    Angle result = angle.abs();

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testabsNegAngle)
{
    Angle angle = Angle(-M_PI_2);
    Angle expected_result = Angle(M_PI_2);
    Angle result = angle.abs();

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testabsBigAngle)
{
    Angle angle = Angle(8 * M_PI);
    Angle expected_result = Angle(0);
    Angle result = angle.abs();

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testabsVeryNegAngle)
{
    Angle angle = Angle(-M_PI_4 - 2 * M_PI);
    Angle expected_result = Angle(M_PI_4);
    Angle result = angle.abs();

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testcreateAngle2SamePoints)
{
    Point source = Point(1, 1);
    Point targetOne = Point(1, 1);
    Point targetTwo = Point(1, 1);
    Angle expected_result = Angle(0);
    Angle result = Angle(source, targetOne, targetTwo);

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testcreateAngle2PositiveValues)
{
    Point source = Point(1, 1);
    Point targetOne = Point(4, 1);
    Point targetTwo = Point(1, 8);
    Angle expected_result = Angle(M_PI_2);
    Angle result = Angle(source, targetOne, targetTwo);

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}

TEST(AngleGoogleTest, testcreateAngle2NegativeValues)
{
    Point source = Point(-3, -6);
    Point targetOne = Point(-5, -8);
    Point targetTwo = Point(-5, -6);
    Angle expected_result = Angle(M_PI_4);
    Angle result = Angle(source, targetOne, targetTwo);

    EXPECT_EQ(result.getAngle(), expected_result.getAngle());
}
