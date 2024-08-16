#include "gtest/gtest.h"
#include "../source/quaternion.hpp"
#include "testing.hpp"

namespace cpp_utils {

double pi = 3.1415926535;

TEST(QuaternionTest, DefaultInitTest) {
    Quaternion quat;
    EXPECT_EQ(quat.w, 0);
    EXPECT_EQ(quat.x, 0);
    EXPECT_EQ(quat.y, 0);
    EXPECT_EQ(quat.z, 0);
}

TEST(QuaternionTest, InitTest) {
    Quaternion quat(1, 2, 3, 4);
    EXPECT_EQ(quat.w, 1);
    EXPECT_EQ(quat.x, 2);
    EXPECT_EQ(quat.y, 3);
    EXPECT_EQ(quat.z, 4);
}

TEST(QuaternionTest, ModTest) {
    Quaternion quat1(1, 1, 1, 1);
    EXPECT_NEAR(quat1.mod(), sqrt(4), 0.0001);
}

TEST(QuaternionTest, EqualityTest) {
    Quaternion quat1(1, 0, 1, 1);
    Quaternion quat2(0, 1, 0, 1);

    EXPECT_TRUE(quat1 == quat1);
    EXPECT_FALSE(quat1 == quat2);
}

TEST(QuaternionTest, NotEqualityTest) {
    Quaternion quat1(1, 0, 1, 1);
    Quaternion quat2(0, 1, 0, 1);

    EXPECT_FALSE(quat1 != quat1);
    EXPECT_TRUE(quat1 != quat2);
}

TEST(QuaternionTest, NegativeTest) {
    Quaternion quat1(1, -2, 3, 4);
    Quaternion quat2(-1, 2, -3, -4);

    EXPECT_EQ(-quat1, quat2);
}

TEST(QuaternionTest, MultiplicationTest) {
    Quaternion quat1(1, 2, -1, 3);

    Quaternion Exp1(-2, -4, 2, -6);
    EXPECT_EQ(quat1 * int(-2), Exp1) << "Failed to multiply by negative int";
    EXPECT_EQ(quat1 * float(-2), Exp1) << "Failed to multiply by negative float";

    Quaternion Exp2(0.5, 1.0, -0.5, 1.5);
    Quaternion res = quat1 * float(0.5);
    EXPECT_EQ( quat1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
}

TEST(QuaternionTest, DivisionTest) {
    Quaternion quat1(2, 4, -2, 3);

    Quaternion Exp1(1, 2, -1, 1.5);
    EXPECT_EQ(quat1 / float(2), Exp1);
    EXPECT_EQ(quat1 / int(2), Exp1);
}

TEST(QuaternionTest, AssignmentTest) {
    Quaternion quat1 = {1, {2, 3, 4}};
    Quaternion quat2;
    quat2 = quat1;

    EXPECT_TRUE(quat1 == quat2);
}

TEST(QuaternionTest, productTest) {
    Quaternion quat1 = {1, 0, 0, 0};
    Quaternion quat2 = {0, 2, 3, -6};

    EXPECT_EQ(quat1 * quat2, quat2);
    EXPECT_EQ(quat2 * quat1, quat2);

    Quaternion quat3 = {1, 2, 4, 7};
    Quaternion quat4 = {6, 2, 3, -6};
    Quaternion exp4 = {32, -31, 53, 34};

    EXPECT_EQ(quat3 * quat4, exp4);

    Quaternion quat5 = {1, 0, 1, 0};
    Quaternion quat6 = {0, 2, 3, -6};
    Quaternion exp6 = {3, -4, 3, -8};

    EXPECT_EQ(quat5 * quat6, exp6);
}

TEST(QuaternionTest, VectorMultiplication) {
    Quaternion quat1 = {1, 0, 0, 0};
    Vector vec1 = {2, 3, 4};

    EXPECT_EQ(vec1, quat1.conj() * vec1 * quat1);

    Quaternion quat2 = {cos(pi / 4), 0, 0, sin(pi / 4)};
    Vector vec2 = {1, 0, 0};
    Vector exp2 = {0, 1, 0};

    EXPECT_EQ(exp2, quat2.conj() * vec2 * quat2);

    Quaternion quat3 = {cos(pi / 4), sin(pi / 4), 0, 0};
    Vector vec3 = {0, 1, -3};
    Vector exp3 = {0, 3, 1};

    EXPECT_EQ(exp3, quat3.conj() * vec3 * quat3);

    Quaternion quat4 = {cos(pi / 4), 0, sin(pi / 4), 0};
    Vector vec4 = {1, 0, 2};
    Vector exp4 = {2, 0, -1};

    EXPECT_EQ(exp4, quat4.conj() * vec4 * quat4);

};


TEST(QuaternionTest, VectorRotation) {
    Vector vec1 = {1, 0, 0};
    Quaternion quat1 = {cos(pi/4), 0, 0, sin(pi/4)};
    Vector exp1 = {0, 1, 0};

    EXPECT_EQ(exp1, rotate(vec1, quat1));

    Vector vec2 = {1, 0, 0};
    Quaternion quat2 = {pi/2, {0, 0, 1}};
    Vector exp2 = {0, 1, 0};

    EXPECT_EQ(exp2, rotate(vec2, quat2));
};

}