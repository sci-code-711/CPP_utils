#include "gtest/gtest.h"
#include <math.h>
#include "../source/attriCoord.hpp"

TEST(AttriCoordTest, DefaultInitTest) {
    cpp_utils::AttriCoord NullAttri;
    EXPECT_EQ(NullAttri.x, 0);
    EXPECT_EQ(NullAttri.y, 0);
    EXPECT_EQ(NullAttri.z, 0);
    EXPECT_EQ(NullAttri.a, 0);
    EXPECT_EQ(NullAttri.b, 0);
}

TEST(AttriCoordTest, InitTest) {
    cpp_utils::AttriCoord Attri1(1, 2, 3, 4, 5);
    EXPECT_EQ(Attri1.x, 1);
    EXPECT_EQ(Attri1.y, 2);
    EXPECT_EQ(Attri1.z, 3);
    EXPECT_EQ(Attri1.a, 4);
    EXPECT_EQ(Attri1.b, 5);
}

TEST(AttriCoordTest, ModTest) {
    cpp_utils::AttriCoord Attri1(1, 1, 1, 1, 1);
    EXPECT_NEAR(Attri1.mod(), sqrt(3), 0.0001);
}

TEST(AttriCoordTest, EqualityTest) {
    cpp_utils::AttriCoord Attri1(1, 0, 1, 0, 1);
    cpp_utils::AttriCoord Attri2(0, 1, 0, 1, 0);

    EXPECT_TRUE(Attri1 == Attri1);
    EXPECT_FALSE(Attri1 == Attri2);
}

TEST(AttriCoordTest, NotEqualityTest) {
    cpp_utils::AttriCoord Attri1(1, 0, 1, 0, 1);
    cpp_utils::AttriCoord Attri2(0, 1, 0, 1, 0);

    EXPECT_FALSE(Attri1 != Attri1);
    EXPECT_TRUE(Attri1 != Attri2);
}

TEST(AttriCoordTest, AdditionTest) {
    cpp_utils::AttriCoord Attri1(1, 0, 1, 0, 1);
    cpp_utils::Vector Vec1(0, 1, 0);

    cpp_utils::AttriCoord ExpAttri(1, 1, 1, 0, 1);

    EXPECT_EQ(Attri1 + Vec1, ExpAttri);
}

TEST(AttriCoordTest, SubtractionTest) {
    cpp_utils::AttriCoord Attri1(1, 0, 1, 0, 1);
    cpp_utils::Vector Vec1(0, 1, 1);

    cpp_utils::AttriCoord ExpAttri(1, -1, 0, 0, 1);
    EXPECT_EQ(Attri1 - Vec1, ExpAttri);
}

TEST(AttriCoordTest, NegativeTest) {
    cpp_utils::AttriCoord Attri1(1, -2, 3, -4, 5);
    cpp_utils::AttriCoord Attri2(-1, 2, -3, -4, 5);

    EXPECT_EQ(-Attri1, Attri2);
}

TEST(AttriCoordTest, MultiplicationTest) {
    cpp_utils::AttriCoord Attri1(1, 2, -1, -2, 1);

    cpp_utils::AttriCoord Exp1(-2, -4, 2, -2, 1);
    EXPECT_EQ(Attri1 * int(-2), Exp1) << "Failed to multiply by negative int";
    EXPECT_EQ(Attri1 * float(-2), Exp1) << "Failed to multiply by negative float";

    cpp_utils::AttriCoord Exp2(0.5, 1.0, -0.5, -2, 1);
    cpp_utils::AttriCoord res = Attri1 * float(0.5);
    EXPECT_EQ(Attri1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
}

TEST(AttriCoordTest, DivisionTest) {
    cpp_utils::AttriCoord Attri1(2, 4, -2, -4, 2);

    cpp_utils::AttriCoord Exp1(1, 2, -1, -4, 2);
    EXPECT_EQ(Attri1 / float(2), Exp1);
    EXPECT_EQ(Attri1 / int(2), Exp1);
}

TEST(AttriCoordTest, ZeroDivisionTest) {
    cpp_utils::AttriCoord Attri1;
    std::invalid_argument Excep("Division by zero is not possible");
}
