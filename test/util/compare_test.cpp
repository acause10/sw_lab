#include "compare.h"

#include <cmath>

#include <gtest/gtest.h>

TEST(CompareTest, testisFuzzyEqualexpectTrueSameValues)
{
    const double value1 = 2;
    const double value2 = 2;
    const double epsilon = 0.1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectTrueValue1BiggerValue2)
{
    const double value1 = 2;
    const double value2 = 1;
    const double epsilon = 2;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectTrueValue1SmallerValue2)
{
    const double value1 = 1;
    const double value2 = 2;
    const double epsilon = 2;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);

    EXPECT_TRUE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectFalseSameValues)
{
    const double value1 = 2;
    const double value2 = 2;
    const double epsilon = 0;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectFalseValue1BiggerValue2)
{
    const double value1 = 2;
    const double value2 = 1;
    const double epsilon = 0;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectFalseValue1SmallerValue2)
{
    const double value1 = 1;
    const double value2 = 2;
    const double epsilon = 0;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectFalseValuesFarApart)
{
    const double value1 = 5;
    const double value2 = 87;
    const double epsilon = 2;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectTrueNegativeValues)
{
    const double value1 = -3;
    const double value2 = -2.8;
    const double epsilon = 0.3;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testisFuzzyEqualexpectFalseNegativeValues)
{
    const double value1 = -3;
    const double value2 = -2;
    const double epsilon = 0.5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyEqual(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzyGreaterPosValues)
{
    const double value1 = 3.5;
    const double value2 = 2.5;
    const double epsilon = 3;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsFuzzyGreaterNegVal1)
{
    const double value1 = -3.2;
    const double value2 = 5.9;
    const double epsilon = 1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzyGreaterNegValues)
{
    const double value1 = -2;
    const double value2 = -10;
    const double epsilon = -22.33;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzyGreaterPosEps)
{
    const double value1 = -5;
    const double value2 = -19;
    const double epsilon = 10;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsFuzzyGreaterNegVal2)
{
    const double value1 = 33.33;
    const double value2 = -23;
    const double epsilon = 10;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsFuzzyGreaterNegEps)
{
    const double value1 = 14.2;
    const double value2 = 15;
    const double epsilon = -2;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzySmallerPosValues)
{
    const double value1 = 3.5;
    const double value2 = 2.5;
    const double epsilon = 3;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsFuzzySmallerNegVal1)
{
    const double value1 = -3.2;
    const double value2 = 5.9;
    const double epsilon = 1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsFuzzySmallerNegValues)
{
    const double value1 = -2;
    const double value2 = -10;
    const double epsilon = -22.33;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzySmallerPosEps)
{
    const double value1 = -5;
    const double value2 = -19;
    const double epsilon = 10;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzySmallerNegNegVal2)
{
    const double value1 = 33.33;
    const double value2 = -23;
    const double epsilon = 10;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsFuzzySmallerNegEps)
{
    const double value1 = 14.2;
    const double value2 = 19;
    const double epsilon = -2;

    Compare compare = Compare(epsilon);

    const bool result = compare.isFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterSameValues)
{
    const double value1 = 4;
    const double value2 = 4;
    const double epsilon = 0.1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterexpectTrue)
{
    const double value1 = 7;
    const double value2 = 6;
    const double epsilon = 0.5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIssStrictFuzzyGreaterNegValuesExpectFalse)
{
    const double value1 = -18;
    const double value2 = -15;
    const double epsilon = 1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterBigEpsilonExpectFalse)
{
    const double value1 = 10;
    const double value2 = 7;
    const double epsilon = 5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterBigEpsilonExpectTrue)
{
    const double value1 = 20;
    const double value2 = 7;
    const double epsilon = 5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterNegValuesExpectTrue)
{
    const double value1 = -19;
    const double value2 = -33;
    const double epsilon = 0.5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsStrictFuzzyGreaterVerySmallEpsilon)
{
    const double value1 = 27.5;
    const double value2 = 27.45;
    const double epsilon = 0.05;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzyGreater(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzySmallerExpectTrue)
{
    const double value1 = 6;
    const double value2 = 10;
    const double epsilon = 0.1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsStrictFuzzySmallerExpectFalse)
{
    const double value1 = 87;
    const double value2 = 39;
    const double epsilon = 0.8;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzySmaller(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzySmallerNegValues)
{
    const double value1 = -14;
    const double value2 = -3;
    const double epsilon = 1;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}

TEST(CompareTest, testIsStrictFuzzySmallerBigEpsilonExpectFalse)
{
    const double value1 = 4;
    const double value2 = 7;
    const double epsilon = 5;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzySmaller(value1, value2);
    EXPECT_FALSE(result);
}

TEST(CompareTest, testIsStrictFuzzySmallerBigEpsilonExpectTrue)
{
    const double value1 = 1;
    const double value2 = 19;
    const double epsilon = 8;

    Compare compare = Compare(epsilon);

    const bool result = compare.isStrictFuzzySmaller(value1, value2);
    EXPECT_TRUE(result);
}
