#include "gtest/gtest.h"
#include "../source/quaternion.hpp"

TEST(QuaternionTest, DefaultInitTest) {
    cpp_utils::Quaternion quat;
    EXPECT_EQ(quat.w, 0);
    EXPECT_EQ(quat.x, 0);
    EXPECT_EQ(quat.y, 0);
    EXPECT_EQ(quat.z, 0);
}

TEST(QuaternionTest, InitTest) {
    cpp_utils::Quaternion quat(1, 2, 3, 4);
    EXPECT_EQ(quat.w, 1);
    EXPECT_EQ(quat.x, 2);
    EXPECT_EQ(quat.y, 3);
    EXPECT_EQ(quat.z, 4);
}

TEST(QuaternionTest, ModTest) {
    cpp_utils::Quaternion quat1(1, 1, 1, 1);
    EXPECT_NEAR(quat1.mod(), sqrt(4), 0.0001);
}

TEST(QuaternionTest, EqualityTest) {
    cpp_utils::Quaternion quat1(1, 0, 1, 1);
    cpp_utils::Quaternion quat2(0, 1, 0, 1);

    EXPECT_TRUE(quat1 == quat1);
    EXPECT_FALSE(quat1 == quat2);
}

TEST(QuaternionTest, NotEqualityTest) {
    cpp_utils::Quaternion quat1(1, 0, 1, 1);
    cpp_utils::Quaternion quat2(0, 1, 0, 1);

    EXPECT_FALSE(quat1 != quat1);
    EXPECT_TRUE(quat1 != quat2);
}

TEST(QuaternionTest, NegativeTest) {
    cpp_utils::Quaternion quat1(1, -2, 3, 4);
    cpp_utils::Quaternion quat2(-1, 2, -3, -4);

    EXPECT_EQ(-quat1, quat2);
}

TEST(QuaternionTest, MultiplicationTest) {
    cpp_utils::Quaternion quat1(1, 2, -1, 3);

    cpp_utils::Quaternion Exp1(-2, -4, 2, -6);
    EXPECT_EQ(quat1 * int(-2), Exp1) << "Failed to multiply by negative int";
    EXPECT_EQ(quat1 * float(-2), Exp1) << "Failed to multiply by negative float";

    cpp_utils::Quaternion Exp2(0.5, 1.0, -0.5, 1.5);
    cpp_utils::Quaternion res = quat1 * float(0.5);
    EXPECT_EQ( quat1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
}

TEST(QuaternionTest, DivisionTest) {
    cpp_utils::Quaternion quat1(2, 4, -2, 3);

    cpp_utils::Quaternion Exp1(1, 2, -1, 1.5);
    EXPECT_EQ(quat1 / float(2), Exp1);
    EXPECT_EQ(quat1 / int(2), Exp1);
}

TEST(QuaternionTest, ZeroDivisionTest) {
    cpp_utils::Quaternion quat1;
    std::invalid_argument Excep("Division by zero is not possible");
}

TEST(QuaternionTest, AssignmentTest) {
    cpp_utils::Quaternion quat1 = {1, {2, 3, 4}};
    cpp_utils::Quaternion quat2;
    quat2 = quat1;

    EXPECT_TRUE(quat1 == quat2);
}