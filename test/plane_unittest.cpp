#include "gtest/gtest.h"
#include "../source/plane.hpp"

namespace cpp_utils {

    TEST(PlaneTest, DefaultInitTest) {
        Vector point(0, 0, 0), normal(norm, norm, norm);
        Plane plane;
        EXPECT_TRUE(plane.point == point);
        EXPECT_TRUE(plane.normal == normal);
    }

    TEST(PlaneTest, InitTest) {
        Vector point(1, 2, 3), normal(4, 5, 6);
        Plane plane(point, normal);
        EXPECT_TRUE(plane.point == point);
        EXPECT_TRUE(plane.normal == normal.normalise());
    }

    TEST(PlaneTest, EqualityTest) {

        Vector vec00,
               vec01(1, 0, 0), vec02(0, 1, 0), vec03(0, 0, 1),
               vec04(-1, 0, 0), vec05(0, -1, 0), vec06(0, 0, -1),
               vec07(1, 1, 1),
               vec08(1, 0, -1), vec09(-1, 1, 0), vec10(0, -1, 1),
               vec11(-1, 0, 1), vec12(1, -1, 0), vec13(0, 1, -1),
               vec14(-1, -1, -1);

        Plane plane00,
              plane01(vec06, vec01), plane02(vec04, vec02), plane03(vec05, vec03),
              plane04(vec02, vec04), plane05(vec03, vec05), plane06(vec01, vec06),
              plane07(vec00, vec07),
              plane08(vec02, vec08), plane09(vec03, vec09), plane10(vec01, vec10),
              plane11(vec05, vec11), plane12(vec06, vec12), plane13(vec04, vec13),
              plane14(vec00, vec14);

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
    
        Vector vec00,
               vec01(1, 0, 0), vec02(0, 1, 0), vec03(0, 0, 1),
               vec04(-1, 0, 0), vec05(0, -1, 0), vec06(0, 0, -1),
               vec07(1, 1, 1),
               vec08(1, 0, -1), vec09(-1, 1, 0), vec10(0, -1, 1),
               vec11(-1, 0, 1), vec12(1, -1, 0), vec13(0, 1, -1),
               vec14(-1, -1, -1);

        Plane plane00,
              plane01(vec06, vec01), plane02(vec04, vec02), plane03(vec05, vec03),
              plane04(vec02, vec04), plane05(vec03, vec05), plane06(vec01, vec06),
              plane07(vec00, vec07),
              plane08(vec02, vec08), plane09(vec03, vec09), plane10(vec01, vec10),
              plane11(vec05, vec11), plane12(vec06, vec12), plane13(vec04, vec13),
              plane14(vec00, vec14);

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
        Vector point0(0, 1, 1), point1(1, 1, 1), point2(1, 0, 1);
        Plane plane(point0, point1);

        EXPECT_TRUE(plane.isOnPlane(point0));
        EXPECT_FALSE(plane.isOnPlane(point1));
        EXPECT_TRUE(plane.isOnPlane(point2));
    }

    TEST(PlaneTest, IntersectionTest) {
        Vector point0, point1(1, -1, 1), point2(1, 0, -1);
        Line line1(point0, point1), line2(point1, point1),
             line3(point0, point2), line4(point1, point2);
        Plane plane;

        EXPECT_EQ(plane.intersection(line1), point0);
        EXPECT_EQ(plane.intersection(line2), point0);
        EXPECT_THROW(plane.intersection(line3), value_error);
        EXPECT_THROW(plane.intersection(line4), value_error);
    }

    TEST(PlaneTest, BetweenTest) {
        Vector point0,
               point1(1, 1, 1),
               point2(1, 0, -1),
               point3(0.5, 0.5, 0.5),
               point4(-0.5, -0.5, -0.5),
               point5(1.5, 1.5, 1.5);

        Line line0, line1(point2, point2), line2(point3, point2), line3(point4, point2), line4(point5, point2);

        Plane plane0, plane1(point1, point1), plane2(point0, point2);

        EXPECT_FALSE(cpp_utils::between(line1, plane0, plane0));
        EXPECT_TRUE(cpp_utils::between(line2, plane0, plane1));
        EXPECT_FALSE(cpp_utils::between(line3, plane0, plane1));
        EXPECT_FALSE(cpp_utils::between(line4, plane0, plane1));
        EXPECT_FALSE(cpp_utils::between(line0, plane0, plane1));
        EXPECT_FALSE(cpp_utils::between(line0, plane0, plane2));
    }

}
