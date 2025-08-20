#include "gtest/gtest.h"
#include "../source/plane.hpp"

TEST(PlaneTest, DefaultInitTest) {
    cpp_utils::Vector point(0, 0, 0);
    cpp_utils::Vector normal(norm, norm, norm);
    cpp_utils::Plane plane;
    EXPECT_TRUE(plane.point == point);
    EXPECT_TRUE(plane.normal == normal);
}

TEST(PlaneTest, InitTest) {
    cpp_utils::Vector point(1, 2, 3);
    cpp_utils::Vector normal(4, 5, 6);
    cpp_utils::Plane plane(point, normal);
    EXPECT_TRUE(plane.point == point);
    EXPECT_TRUE(plane.normal == normal.normalise());
}

TEST(PlaneTest, EqualityTest) {
    cpp_utils::Vector vec00;
    cpp_utils::Vector vec01(1, 0, 0);
    cpp_utils::Vector vec02(0, 1, 0);
    cpp_utils::Vector vec03(0, 0, 1);
    cpp_utils::Vector vec04(-1, 0, 0);
    cpp_utils::Vector vec05(0, -1, 0);
    cpp_utils::Vector vec06(0, 0, -1);
    cpp_utils::Vector vec07(1, 1, 1);
    cpp_utils::Vector vec08(1, 0, -1);
    cpp_utils::Vector vec09(-1, 1, 0);
    cpp_utils::Vector vec10(0, -1, 1);
    cpp_utils::Vector vec11(-1, 0, 1);
    cpp_utils::Vector vec12(1, -1, 0);
    cpp_utils::Vector vec13(0, 1, -1);
    cpp_utils::Vector vec14(-1, -1, -1);
    cpp_utils::Plane plane00;
    cpp_utils::Plane plane01(vec06, vec01);
    cpp_utils::Plane plane02(vec04, vec02);
    cpp_utils::Plane plane03(vec05, vec03);
    cpp_utils::Plane plane04(vec02, vec04);
    cpp_utils::Plane plane05(vec03, vec05);
    cpp_utils::Plane plane06(vec01, vec06);
    cpp_utils::Plane plane07(vec00, vec07);
    cpp_utils::Plane plane08(vec02, vec08);
    cpp_utils::Plane plane09(vec03, vec09);
    cpp_utils::Plane plane10(vec01, vec10);
    cpp_utils::Plane plane11(vec05, vec11);
    cpp_utils::Plane plane12(vec06, vec12);
    cpp_utils::Plane plane13(vec04, vec13);
    cpp_utils::Plane plane14(vec00, vec14);

    EXPECT_TRUE(plane00 == plane00);
    EXPECT_FALSE(plane00 == plane01);
    EXPECT_TRUE(plane01 == plane04);
    EXPECT_FALSE(plane00 == plane02);
    EXPECT_TRUE(plane02 == plane05);
    EXPECT_FALSE(plane00 == plane03);
    EXPECT_TRUE(plane03 == plane06);
    EXPECT_TRUE(plane00 == plane07);
    EXPECT_TRUE(plane07 == plane14);
    EXPECT_FALSE(plane00 == plane08);
    EXPECT_TRUE(plane08 == plane11);
    EXPECT_FALSE(plane00 == plane09);
    EXPECT_TRUE(plane09 == plane12);
    EXPECT_FALSE(plane00 == plane10);
    EXPECT_TRUE(plane10 == plane13);
}

TEST(PlaneTest, NotEqualityTest) {
    cpp_utils::Vector vec00;
    cpp_utils::Vector vec01(1, 0, 0);
    cpp_utils::Vector vec02(0, 1, 0);
    cpp_utils::Vector vec03(0, 0, 1);
    cpp_utils::Vector vec04(-1, 0, 0);
    cpp_utils::Vector vec05(0, -1, 0);
    cpp_utils::Vector vec06(0, 0, -1);
    cpp_utils::Vector vec07(1, 1, 1);
    cpp_utils::Vector vec08(1, 0, -1);
    cpp_utils::Vector vec09(-1, 1, 0);
    cpp_utils::Vector vec10(0, -1, 1);
    cpp_utils::Vector vec11(-1, 0, 1);
    cpp_utils::Vector vec12(1, -1, 0);
    cpp_utils::Vector vec13(0, 1, -1);
    cpp_utils::Vector vec14(-1, -1, -1);
    cpp_utils::Plane plane00;
    cpp_utils::Plane plane01(vec06, vec01);
    cpp_utils::Plane plane02(vec04, vec02);
    cpp_utils::Plane plane03(vec05, vec03);
    cpp_utils::Plane plane04(vec02, vec04);
    cpp_utils::Plane plane05(vec03, vec05);
    cpp_utils::Plane plane06(vec01, vec06);
    cpp_utils::Plane plane07(vec00, vec07);
    cpp_utils::Plane plane08(vec02, vec08);
    cpp_utils::Plane plane09(vec03, vec09);
    cpp_utils::Plane plane10(vec01, vec10);
    cpp_utils::Plane plane11(vec05, vec11);
    cpp_utils::Plane plane12(vec06, vec12);
    cpp_utils::Plane plane13(vec04, vec13);
    cpp_utils::Plane plane14(vec00, vec14);

    EXPECT_FALSE(plane00 != plane00);
    EXPECT_TRUE(plane00 != plane01);
    EXPECT_FALSE(plane01 != plane04);
    EXPECT_TRUE(plane00 != plane02);
    EXPECT_FALSE(plane02 != plane05);
    EXPECT_TRUE(plane00 != plane03);
    EXPECT_FALSE(plane03 != plane06);
    EXPECT_FALSE(plane00 != plane07);
    EXPECT_FALSE(plane07 != plane14);
    EXPECT_TRUE(plane00 != plane08);
    EXPECT_FALSE(plane08 != plane11);
    EXPECT_TRUE(plane00 != plane09);
    EXPECT_FALSE(plane09 != plane12);
    EXPECT_TRUE(plane00 != plane10);
    EXPECT_FALSE(plane10 != plane13);
}

TEST(PlaneTest, IsOnTest) {
    cpp_utils::Vector point0(0, 1, 1);
    cpp_utils::Vector point1(1, 1, 1);
    cpp_utils::Vector point2(1, 0, 1);
    cpp_utils::Plane plane(point0, point1);

    EXPECT_TRUE(plane.isOnPlane(point0));
    EXPECT_FALSE(plane.isOnPlane(point1));
    EXPECT_TRUE(plane.isOnPlane(point2));
}

TEST(PlaneTest, IntersectionTest) {
    cpp_utils::Vector point0;
    cpp_utils::Vector point1(1, -1, 1);
    cpp_utils::Vector point2(1, 0, -1);
    cpp_utils::Line line1(point0, point1);
    cpp_utils::Line line2(point1, point1);
    cpp_utils::Line line3(point0, point2);
    cpp_utils::Line line4(point1, point2);
    cpp_utils::Plane plane;

    EXPECT_EQ(plane.intersection(line1), point0);
    EXPECT_EQ(plane.intersection(line2), point0);
    EXPECT_THROW(plane.intersection(line3), std::exception);
    EXPECT_THROW(plane.intersection(line4), std::exception);
}

TEST(PlaneTest, BetweenTest) {
    cpp_utils::Vector point0;
    cpp_utils::Vector point1(1, 1, 1);
    cpp_utils::Vector point2(1, 0, -1);
    cpp_utils::Vector point3(0.5, 0.5, 0.5);
    cpp_utils::Vector point4(-0.5, -0.5, -0.5);
    cpp_utils::Vector point5(1.5, 1.5, 1.5);

    cpp_utils::Line line0;
    cpp_utils::Line line1(point2, point2);
    cpp_utils::Line line2(point3, point2);
    cpp_utils::Line line3(point4, point2);
    cpp_utils::Line line4(point5, point2);

    cpp_utils::Plane plane0;
    cpp_utils::Plane plane1(point1, point1);
    cpp_utils::Plane plane2(point0, point2);

    EXPECT_FALSE(cpp_utils::between(line1, plane0, plane0));
    EXPECT_TRUE(cpp_utils::between(line2, plane0, plane1));
    EXPECT_FALSE(cpp_utils::between(line3, plane0, plane1));
    EXPECT_FALSE(cpp_utils::between(line4, plane0, plane1));
    EXPECT_FALSE(cpp_utils::between(line0, plane0, plane1));
    EXPECT_FALSE(cpp_utils::between(line0, plane0, plane2));
}
