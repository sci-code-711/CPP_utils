#include "gtest/gtest.h"
#include "../source/vector.hpp"

namespace cpp_utils {

    TEST(VectorTest, DefaultInitTest) {
        Vector NullVec;
        EXPECT_EQ(NullVec.x, 0);
        EXPECT_EQ(NullVec.y, 0);
        EXPECT_EQ(NullVec.z, 0);
    }

    TEST(VectorTest, InitTest) {
        Vector Vec1(1, 2, 3);
        EXPECT_EQ(Vec1.x, 1);
        EXPECT_EQ(Vec1.y, 2);
        EXPECT_EQ(Vec1.z, 3);
    }

    TEST(VectorTest, ModTest) {
        Vector Vec1(1, 1, 1);
        EXPECT_NEAR(Vec1.mod(), sqrt(3), 0.0001);
    }

    TEST(VectorTest, EqualityTest) {
        Vector Vec1(1, 0, 1);
        Vector Vec2(0, 1, 0);

        EXPECT_TRUE(Vec1 == Vec1);
        EXPECT_FALSE(Vec1 == Vec2);
    }

    TEST(VectorTest, NotEqualityTest) {
        Vector Vec1(1, 0, 1);
        Vector Vec2(0, 1, 0);

        EXPECT_FALSE(Vec1 != Vec1);
        EXPECT_TRUE(Vec1 != Vec2);
    }

    TEST(VectorTest, AdditionTest) {
        Vector Vec1(1, 0, 1);
        Vector Vec2(0, 1, 0);

        Vector ExpVec(1, 1, 1);
        EXPECT_EQ(Vec1 + Vec2, ExpVec);
    }

    TEST(VectorTest, SubtractionTest) {
        Vector Vec1(1, 0, 1);
        Vector Vec2(0, 1, 1);

        Vector ExpVec(1, -1, 0);
        EXPECT_EQ(Vec1 - Vec2, ExpVec);
        EXPECT_EQ(Vec2 - Vec1, -ExpVec);
    }

    TEST(VectorTest, NegativeTest) {
        Vector Vec1(1, -2, 3);
        Vector Vec2(-1, 2, -3);

        EXPECT_EQ(-Vec1, Vec2);
    }

    TEST(VectorTest, MultiplicationTest) {
        Vector Vec1(1, 2, -1);

        Vector Exp1(-2, -4, 2);
        EXPECT_EQ(Vec1 * int(-2), Exp1) << "Failed to multiply by negative int";
        EXPECT_EQ(int(-2) * Vec1, Exp1) << "Failed to multiply by negative int";
        EXPECT_EQ(Vec1 * float(-2), Exp1) << "Failed to multiply by negative float";
        EXPECT_EQ(float(-2) * Vec1, Exp1) << "Failed to multiply by negative float";

        Vector Exp2(0.5, 1.0, -0.5);
        EXPECT_EQ(Vec1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
        EXPECT_EQ(float(0.5) * Vec1, Exp2) << "Failed to multiply by decimal value";
    }

    TEST(VectorTest, DivisionTest) {
        Vector Vec1(2, 4, -2);

        Vector Exp1(1, 2, -1);
        EXPECT_EQ(Vec1 / float(2), Exp1);
        EXPECT_EQ(Vec1 / int(2), Exp1);
    }

    TEST(VectorTest, ZeroDivisionTest) {
        Vector Vec1;
        std::invalid_argument Excep("Division by zero is not possible");

    }

    TEST(VectorTest, DotProductTest) {
        Vector Vec1(1, 0, 0);
        Vector Vec2(0, 1, 2);
        Vector Vec3(2, 0, 3);

        EXPECT_NEAR(Vec1 * Vec2, 0, 0.0001);
        EXPECT_NEAR(Vec1 * Vec3, 2, 0.0001);
        EXPECT_NEAR(Vec2 * Vec3, 6, 0.0001);
    }

    TEST(VectorTest, CrossProductTest) {
        Vector Vecx(1, 0, 0);
        Vector Vecy(0, 1, 0);
        Vector Vecz(0, 0, 1);

        EXPECT_EQ(Vecx ^ Vecy, Vecz);
        EXPECT_EQ(Vecy ^ Vecx, -Vecz);
    }

}
