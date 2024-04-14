#include <cmath>

#include <geo_compare.h>
#include <gtest/gtest.h>
#include <pose.h>

TEST(PoseGoogleTest, testDistanceTo_samePoses)
{
    Pose poseOne = Pose(Point(0, 0), Angle(M_PI_2));
    Pose poseTwo = Pose(Point(0, 0), Angle(M_PI_2));

    const double expectedValue = 0.0;
    const double returnedValue = poseOne.distanceTo(poseTwo);

    EXPECT_EQ(returnedValue, expectedValue);
}

TEST(PoseGoogleTest, testDistanceTo_differentPoses)
{
    Pose poseOne = Pose(Point(9, 8), Angle(M_PI_4));
    Pose poseTwo = Pose(Point(6, 4), Angle(M_PI_2));

    const double expectedValue = 5.0;
    const double returnedValue = poseOne.distanceTo(poseTwo);

    EXPECT_EQ(returnedValue, expectedValue);
}

TEST(PoseGoogleTest, testDistanceTo_differentPosesNeg)
{
    Pose poseOne = Pose(Point(6, 4), Angle(M_PI_4));
    Pose poseTwo = Pose(Point(9, 8), Angle(M_PI));

    const double expectedValue = 5.0;
    const double returnedValue = poseOne.distanceTo(poseTwo);

    EXPECT_EQ(returnedValue, expectedValue);
}

TEST(PoseGoogleTest, testGetRelativeOrientationTo)
{
    Pose testPose = Pose(Point(0, 3), Angle(M_PI));
    Point testPoint = Point(3, 0);

    Angle expectedAngle = Angle(3 * M_PI_4);
    Angle returnedAngle = testPose.getRelativeOrientationTo(testPoint);

    Geo_compare compare = Geo_compare(0.0000001);

    bool truth = compare.isFuzzyEqual(expectedAngle, returnedAngle);

    EXPECT_TRUE(truth);
}

TEST(PoseGoogleTest, testIsEqual_Poses1)
{
    Pose poseOne = Pose(Point(0, 0), Angle(2 * M_PI));
    Pose poseTwo = Pose(Point(0, 0), Angle(2 * M_PI));

    bool truth = poseOne.isEqual(poseTwo);

    EXPECT_TRUE(truth);
}

TEST(PoseGoogleTest, testIsEqual_Poses2)
{
    Pose poseOne = Pose(Point(3, 4), Angle(3 * M_PI));
    Pose poseTwo = Pose(Point(3, 4), Angle(3 * M_PI));

    bool truth = poseOne.isEqual(poseTwo);

    EXPECT_TRUE(truth);
}

TEST(PoseGoogleTest, testIsEqual_Poses3)
{
    Point point_1 = Point(-3, -4);
    Point point_2 = Point(-3, -4);
    Angle angle_1 = Angle(-M_PI_2);
    Angle angle_2 = Angle(-M_PI_2);
    Pose poseOne = Pose(point_1, angle_1);
    Pose poseTwo = Pose(point_2, angle_2);

    const bool truth = poseOne.isEqual(poseTwo);

    EXPECT_TRUE(truth);
}

TEST(PoseGoogleTest, testAddPoses)
{
    Pose poseOne = Pose(Point(1, 1), Angle(M_PI_2));
    Pose poseTwo = Pose(Point(3, 2), Angle(M_PI_2));

    Pose expectedPose = Pose(Point(4, 3), Angle(M_PI));
    Pose returnedPose = poseOne.addPoses(poseTwo);

    Geo_compare compare = Geo_compare(0.00001);

    bool truth = compare.isFuzzyEqual(expectedPose, returnedPose);

    EXPECT_TRUE(truth);
}

TEST(PoseGoogleTest, testSubtractPoses)
{
    Pose poseOne = Pose(Point(5, 3), Angle(M_PI_2));
    Pose poseTwo = Pose(Point(8, 2), Angle(M_PI_2));

    Pose expectedPose = Pose(Point(-3, 1), Angle(0));
    Pose returnedPose = poseOne.subtractPoses(poseTwo);

    Geo_compare compare = Geo_compare(0.00002);

    bool truth = compare.isFuzzyEqual(returnedPose, expectedPose);

    EXPECT_TRUE(truth);
}
