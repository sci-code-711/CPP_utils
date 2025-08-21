#include "gtest/gtest.h"
#include "../source/line.hpp"

namespace cpp_utils {

    TEST(LineTest, DefaultInitTest) {
        Vector point(0, 0, 0);
        Vector direction(norm, norm, norm);
        Line line;
        EXPECT_TRUE(line.point == point);
        EXPECT_TRUE(line.direction == direction);
    }

    TEST(LineTest, InitTest) {
        Vector point(1, 2, 3);
        Vector direction(4, 5, 6);
        Line line(point, direction);
        EXPECT_TRUE(line.point == point);
        EXPECT_TRUE(line.direction == direction.normalise());
    }

    TEST(LineTest, EqualityTest) {

        Vector vec00,
               vec01(1, 0, 0), vec02(0, 1, 0), vec03(0, 0, 1),
               vec04(-1, 0, 0), vec05(0, -1, 0), vec06(0, 0, -1),
               vec07(1, 1, 1),
               vec08(-1, 1, 1), vec09(1, -1, 1), vec10(1, 1, -1),
               vec11(1, -1, -1), vec12(-1, 1, -1), vec13(-1, -1, 1),
               vec14(-1, -1, -1);

        Line line00,
             line01(vec04, vec01), line02(vec05, vec02), line03(vec06, vec03),
             line04(vec01, vec04), line05(vec02, vec05), line06(vec03, vec06),
             line07(vec14, vec07),
             line08(vec11, vec08), line09(vec12, vec09), line10(vec13, vec10),
             line11(vec08, vec11), line12(vec09, vec12), line13(vec10, vec13),
             line14(vec07, vec14);

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

        Vector vec00,
               vec01(1, 0, 0), vec02(0, 1, 0), vec03(0, 0, 1),
               vec04(-1, 0, 0), vec05(0, -1, 0), vec06(0, 0, -1),
               vec07(1, 1, 1),
               vec08(-1, 1, 1), vec09(1, -1, 1), vec10(1, 1, -1),
               vec11(1, -1, -1), vec12(-1, 1, -1), vec13(-1, -1, 1),
               vec14(-1, -1, -1);

        Line line00,
             line01(vec04, vec01), line02(vec05, vec02), line03(vec06, vec03),
             line04(vec01, vec04), line05(vec02, vec05), line06(vec03, vec06),
             line07(vec14, vec07),
             line08(vec11, vec08), line09(vec12, vec09), line10(vec13, vec10),
             line11(vec08, vec11), line12(vec09, vec12), line13(vec10, vec13),
             line14(vec07, vec14);

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

        Vector point0(0, 1, 1);
        Vector point1(-1, 1, -1);
        Vector point2(-1, 2, 0);
        Line line0(point0, point1);
        
        Vector point3(1, 0, 1);
        Vector point4(-1, -1, 1);
        Vector point5(2, 1, 0);
        Line line1(point3, point4);
        
        Vector point6(1, 1, 0);
        Vector point7(1, -1, -1);
        Vector point8(0, 2, 1);
        Line line2(point6, point7);

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
        
        Vector point0(0, 1, 1);
        Vector point1(-1, 1, -1);
        Vector point2(-1, 2, 0);
        Line line0(point0, point1);
        
        Vector point3(1, 0, 1);
        Vector point4(-1, -1, 1);
        Vector point5(2, 1, 0);
        Line line1(point3, point4);
        
        Vector point6(1, 1, 0);
        Vector point7(1, -1, -1);
        Vector point8(0, 2, 1);
        Line line2(point6, point7);

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

}
