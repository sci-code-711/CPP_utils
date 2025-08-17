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
    EXPECT_TRUE(plane.normal == (1 / normal.mod()) * normal);
}

TEST(PlaneTest, EqualityTest) {
    cpp_utils::Vector vec0;
    cpp_utils::Vector vec1(-1, -1, -1);
    cpp_utils::Vector vec2(1, 0, -1);
    cpp_utils::Plane plane0;
    cpp_utils::Plane plane1(vec1, vec1);
    cpp_utils::Plane plane2(vec0, vec2);
    cpp_utils::Plane plane3(vec2, vec1);  

    EXPECT_TRUE(plane0 == plane0);
    EXPECT_FALSE(plane0 == plane1);
    EXPECT_FALSE(plane0 == plane2);
    EXPECT_TRUE(plane0 == plane3);
    EXPECT_FALSE(plane1 == plane2);
    EXPECT_FALSE(plane2 == plane3);
}

TEST(PlaneTest, NotEqualityTest) {
    cpp_utils::Vector vec0;
    cpp_utils::Vector vec1(-1, -1, -1);
    cpp_utils::Vector vec2(1, 0, -1);
    cpp_utils::Plane plane0;
    cpp_utils::Plane plane1(vec1, vec1);
    cpp_utils::Plane plane2(vec0, vec2);
    cpp_utils::Plane plane3(vec2, vec1);  

    EXPECT_FALSE(plane0 != plane0);
    EXPECT_TRUE(plane0 != plane1);
    EXPECT_TRUE(plane0 != plane2);
    EXPECT_FALSE(plane0 != plane3);
    EXPECT_TRUE(plane1 != plane2);
    EXPECT_TRUE(plane2 != plane3);
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
