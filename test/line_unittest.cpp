#include "gtest/gtest.h"
#include "../source/line.hpp"

TEST(LineTest, DefaultInitTest) {
    cpp_utils::Vector point(0, 0, 0);
    cpp_utils::Vector direction(norm, norm, norm);
    cpp_utils::Line line;
    EXPECT_TRUE(line.point == point);
    EXPECT_TRUE(line.direction == direction);
}

TEST(LineTest, InitTest) {
    cpp_utils::Vector point(1, 2, 3);
    cpp_utils::Vector direction(4, 5, 6);
    cpp_utils::Line line(point, direction);
    EXPECT_TRUE(line.point == point);
    EXPECT_TRUE(line.direction == direction.normalise());
}

TEST(LineTest, EqualityTest) {
    cpp_utils::Vector vec00;
    cpp_utils::Vector vec01(1, 0, 0);
    cpp_utils::Vector vec02(0, 1, 0);
    cpp_utils::Vector vec03(0, 0, 1);
    cpp_utils::Vector vec04(-1, 0, 0);
    cpp_utils::Vector vec05(0, -1, 0);
    cpp_utils::Vector vec06(0, 0, -1);
    cpp_utils::Vector vec07(1, 1, 1);
    cpp_utils::Vector vec08(-1, 1, 1);
    cpp_utils::Vector vec09(1, -1, 1);
    cpp_utils::Vector vec10(1, 1, -1);
    cpp_utils::Vector vec11(1, -1, -1);
    cpp_utils::Vector vec12(-1, 1, -1);
    cpp_utils::Vector vec13(-1, -1, 1);
    cpp_utils::Vector vec14(-1, -1, -1);
    cpp_utils::Line line00;
    cpp_utils::Line line01(vec04, vec01);
    cpp_utils::Line line02(vec05, vec02);
    cpp_utils::Line line03(vec06, vec03);
    cpp_utils::Line line04(vec01, vec04);
    cpp_utils::Line line05(vec02, vec05);
    cpp_utils::Line line06(vec03, vec06);
    cpp_utils::Line line07(vec14, vec07);
    cpp_utils::Line line08(vec11, vec08);
    cpp_utils::Line line09(vec12, vec09);
    cpp_utils::Line line10(vec13, vec10);
    cpp_utils::Line line11(vec08, vec11);
    cpp_utils::Line line12(vec09, vec12);
    cpp_utils::Line line13(vec10, vec13);
    cpp_utils::Line line14(vec07, vec14);

    EXPECT_TRUE(line00 == line00);
    EXPECT_FALSE(line00 == line01);
    EXPECT_TRUE(line01 == line04);
    EXPECT_FALSE(line00 == line02);
    EXPECT_TRUE(line02 == line05);
    EXPECT_FALSE(line00 == line03);
    EXPECT_TRUE(line03 == line06);
    EXPECT_TRUE(line00 == line07);
    EXPECT_TRUE(line07 == line14);
    EXPECT_FALSE(line00 == line08);
    EXPECT_TRUE(line08 == line11);
    EXPECT_FALSE(line00 == line09);
    EXPECT_TRUE(line09 == line12);
    EXPECT_FALSE(line00 == line10);
    EXPECT_TRUE(line10 == line13);
}

TEST(LineTest, NotEqualityTest) {
    cpp_utils::Vector vec00;
    cpp_utils::Vector vec01(1, 0, 0);
    cpp_utils::Vector vec02(0, 1, 0);
    cpp_utils::Vector vec03(0, 0, 1);
    cpp_utils::Vector vec04(-1, 0, 0);
    cpp_utils::Vector vec05(0, -1, 0);
    cpp_utils::Vector vec06(0, 0, -1);
    cpp_utils::Vector vec07(1, 1, 1);
    cpp_utils::Vector vec08(-1, 1, 1);
    cpp_utils::Vector vec09(1, -1, 1);
    cpp_utils::Vector vec10(1, 1, -1);
    cpp_utils::Vector vec11(1, -1, -1);
    cpp_utils::Vector vec12(-1, 1, -1);
    cpp_utils::Vector vec13(-1, -1, 1);
    cpp_utils::Vector vec14(-1, -1, -1);
    cpp_utils::Line line00;
    cpp_utils::Line line01(vec04, vec01);
    cpp_utils::Line line02(vec05, vec02);
    cpp_utils::Line line03(vec06, vec03);
    cpp_utils::Line line04(vec01, vec04);
    cpp_utils::Line line05(vec02, vec05);
    cpp_utils::Line line06(vec03, vec06);
    cpp_utils::Line line07(vec14, vec07);
    cpp_utils::Line line08(vec11, vec08);
    cpp_utils::Line line09(vec12, vec09);
    cpp_utils::Line line10(vec13, vec10);
    cpp_utils::Line line11(vec08, vec11);
    cpp_utils::Line line12(vec09, vec12);
    cpp_utils::Line line13(vec10, vec13);
    cpp_utils::Line line14(vec07, vec14);

    EXPECT_FALSE(line00 != line00);
    EXPECT_TRUE(line00 != line01);
    EXPECT_FALSE(line01 != line04);
    EXPECT_TRUE(line00 != line02);
    EXPECT_FALSE(line02 != line05);
    EXPECT_TRUE(line00 != line03);
    EXPECT_FALSE(line03 != line06);
    EXPECT_FALSE(line00 != line07);
    EXPECT_FALSE(line07 != line14);
    EXPECT_TRUE(line00 != line08);
    EXPECT_FALSE(line08 != line11);
    EXPECT_TRUE(line00 != line09);
    EXPECT_FALSE(line09 != line12);
    EXPECT_TRUE(line00 != line10);
    EXPECT_FALSE(line10 != line13);
}

TEST(LineTest, IsOnTest) {
    cpp_utils::Vector point0(0, 1, 1);
    cpp_utils::Vector point1(-1, 1, -1);
    cpp_utils::Vector point2(-1, 2, 0);
    cpp_utils::Line line0(point0, point1);
    
    cpp_utils::Vector point3(1, 0, 1);
    cpp_utils::Vector point4(-1, -1, 1);
    cpp_utils::Vector point5(2, 1, 0);
    cpp_utils::Line line1(point3, point4);
    
    cpp_utils::Vector point6(1, 1, 0);
    cpp_utils::Vector point7(1, -1, -1);
    cpp_utils::Vector point8(0, 2, 1);
    cpp_utils::Line line2(point6, point7);

    EXPECT_TRUE(line0.isOnLine(point0));
    EXPECT_FALSE(line0.isOnLine(point1));
    EXPECT_TRUE(line0.isOnLine(point2));

    EXPECT_TRUE(line1.isOnLine(point3));
    EXPECT_FALSE(line1.isOnLine(point4));
    EXPECT_TRUE(line1.isOnLine(point5));

    EXPECT_TRUE(line2.isOnLine(point6));
    EXPECT_FALSE(line2.isOnLine(point7));
    EXPECT_TRUE(line2.isOnLine(point8));
}

TEST(LineTest, WhereOnTest) {
    cpp_utils::Vector point0(0, 1, 1);
    cpp_utils::Vector point1(-1, 1, -1);
    cpp_utils::Vector point2(-1, 2, 0);
    cpp_utils::Line line0(point0, point1);
    
    cpp_utils::Vector point3(1, 0, 1);
    cpp_utils::Vector point4(-1, -1, 1);
    cpp_utils::Vector point5(2, 1, 0);
    cpp_utils::Line line1(point3, point4);
    
    cpp_utils::Vector point6(1, 1, 0);
    cpp_utils::Vector point7(1, -1, -1);
    cpp_utils::Vector point8(0, 2, 1);
    cpp_utils::Line line2(point6, point7);

    EXPECT_EQ(line0.whereOnLine(point0), 0);
    EXPECT_THROW(line0.whereOnLine(point1), value_error);
    EXPECT_EQ(line0.whereOnLine(point2), - 1 / norm);

    EXPECT_EQ(line1.whereOnLine(point3), 0);
    EXPECT_THROW(line1.whereOnLine(point4), value_error);
    EXPECT_EQ(line1.whereOnLine(point5), 1 / norm);

    EXPECT_EQ(line2.whereOnLine(point6), 0);
    EXPECT_THROW(line2.whereOnLine(point7), value_error);
    EXPECT_EQ(line2.whereOnLine(point8), - 1 / norm);
}
