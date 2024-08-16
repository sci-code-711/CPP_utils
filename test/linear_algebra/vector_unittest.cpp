#include "gtest/gtest.h"
#include <math.h>
#include "../../source/linear_algebra/vector.hpp"

TEST(VectorTest, DefaultInitTest) {
    cpp_utils::Vector NullVec;
    EXPECT_EQ(NullVec.x, 0);
    EXPECT_EQ(NullVec.y, 0);
    EXPECT_EQ(NullVec.z, 0);
}

TEST(VectorTest, InitTest) {
    cpp_utils::Vector Vec1(1, 2, 3);
    EXPECT_EQ(Vec1.x, 1);
    EXPECT_EQ(Vec1.y, 2);
    EXPECT_EQ(Vec1.z, 3);
}

TEST(VectorTest, ModTest) {
    cpp_utils::Vector Vec1(1, 1, 1);
    EXPECT_NEAR(Vec1.mod(), sqrt(3), 0.0001);
}

TEST(VectorTest, EqualityTest) {
    cpp_utils::Vector Vec1(1, 0, 1);
    cpp_utils::Vector Vec2(0, 1, 0);

    EXPECT_TRUE(Vec1 == Vec1);
    EXPECT_FALSE(Vec1 == Vec2);
}

TEST(VectorTest, NotEqualityTest) {
    cpp_utils::Vector Vec1(1, 0, 1);
    cpp_utils::Vector Vec2(0, 1, 0);

    EXPECT_FALSE(Vec1 != Vec1);
    EXPECT_TRUE(Vec1 != Vec2);
}

TEST(VectorTest, AdditionTest) {
    cpp_utils::Vector Vec1(1, 0, 1);
    cpp_utils::Vector Vec2(0, 1, 0);

    cpp_utils::Vector ExpVec(1, 1, 1);

    EXPECT_EQ(Vec1 + Vec2, ExpVec);
}

TEST(VectorTest, SubtractionTest) {
    cpp_utils::Vector Vec1(1, 0, 1);
    cpp_utils::Vector Vec2(0, 1, 1);

    cpp_utils::Vector ExpVec(1, -1, 0);
    EXPECT_EQ(Vec1 - Vec2, ExpVec);
    EXPECT_EQ(Vec2 - Vec1, -ExpVec);
}

TEST(VectorTest, NegativeTest) {
    cpp_utils::Vector Vec1(1, -2, 3);
    cpp_utils::Vector Vec2(-1, 2, -3);

    EXPECT_EQ(-Vec1, Vec2);
}

TEST(VectorTest, MultiplicationTest) {
    cpp_utils::Vector Vec1(1, 2, -1);

    cpp_utils::Vector Exp1(-2, -4, 2);
    EXPECT_EQ(Vec1 * int(-2), Exp1) << "Failed to multiply by negative int";
    EXPECT_EQ(Vec1 * float(-2), Exp1) << "Failed to multiply by negative float";

    cpp_utils::Vector Exp2(0.5, 1.0, -0.5);
    cpp_utils::Vector res = Vec1 * float(0.5);
    EXPECT_EQ( Vec1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
}

TEST(VectorTest, DivisionTest) {
    cpp_utils::Vector Vec1(2, 4, -2);

    cpp_utils::Vector Exp1(1, 2, -1);
    EXPECT_EQ(Vec1 / float(2), Exp1);
    EXPECT_EQ(Vec1 / int(2), Exp1);
}

TEST(VectorTest, ZeroDivisionTest) {
    cpp_utils::Vector Vec1;
    std::invalid_argument Excep("Division by zero is not possible");

}

TEST(VectorTest, DotProductTest) {
    cpp_utils::Vector Vec1(1, 0, 0);
    cpp_utils::Vector Vec2(0, 1, 2);
    cpp_utils::Vector Vec3(2, 0, 3);

    EXPECT_NEAR(Vec1 * Vec2, 0, 0.0001);
    EXPECT_NEAR(Vec1 * Vec3, 2, 0.0001);
    EXPECT_NEAR(Vec2 * Vec3, 6, 0.0001);
}

TEST(VectorTest, CrossProductTest) {
    cpp_utils::Vector Vecx(1, 0, 0);
    cpp_utils::Vector Vecy(0, 1, 0);
    cpp_utils::Vector Vecz(0, 0, 1);

    EXPECT_EQ(Vecx ^ Vecy, Vecz);
    EXPECT_EQ(Vecy ^ Vecx, -Vecz);
}
