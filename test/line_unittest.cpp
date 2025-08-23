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

    TEST(LineTest, BasicEqualityTest) {
        EXPECT_TRUE(Line() == Line());
        EXPECT_FALSE(Line() == Line({1, 0, 0}, {0, 3, 6}));
    }

    TEST(LineTest, EqualityTest_DirectionChanges) {
        // Same Line but direction reversal
        Line line01({0, 0, 0}, {1, 0, 0});
        Line line02({0, 0, 0}, {-1, 0, 0});
        EXPECT_TRUE(line01 == line02);

        Line line02a({0, 0, 0}, {0, 2, 2});
        Line line02b({0, 0, 0}, {0, -2, -2});
        EXPECT_TRUE(line02a == line02b);

        Line line02c({0, 0, 0}, {0, -2, 2});
        Line line02d({0, 0, 0}, {0, 2, -2});
        EXPECT_TRUE(line02c == line02d);

        // same point different direction
        Line line07({1, 0, 0}, {1, 0, 0});
        Line line08({1, 0, 0}, {0, 1, 0});
        EXPECT_FALSE(line07 == line08);
    }

    TEST(LineTest, EqualityTest_PointChanges) {
        // Different points - same direction - different line
        Line line03({1, 0, 0}, {1, 0, 0});
        Line line04({0, 1, 0}, {1, 0, 0});
        EXPECT_FALSE(line03 == line04);

        // Different points but the same line
        Line line05({1, 0, 0}, {1, 0, 0});
        Line line06({0, 0, 0}, {1, 0, 0});
        EXPECT_TRUE(line05 == line06);
    }

    TEST(LineTest, EqualityTest_Composite) {
        // different point - reversed direction - same line
        Line line09({0, 0, 0}, {0, 1, 1});
        Line line10({0, 2, 2}, {0, -1, -1});
        EXPECT_TRUE(line09 == line10);
    }

    TEST(LineTest, BasicNotEqualityTest) {
        EXPECT_FALSE(Line() != Line());
        EXPECT_TRUE(Line() != Line({1, 0, 0}, {0, 3, 6}));
    }

    TEST(LineTest, NotEqualityTest_DirectionChanges) {
        // Same Line but direction reversal
        Line line01({0, 0, 0}, {1, 0, 0});
        Line line02({0, 0, 0}, {-1, 0, 0});
        EXPECT_FALSE(line01 != line02);

        Line line02a({0, 0, 0}, {0, 2, 2});
        Line line02b({0, 0, 0}, {0, -2, -2});
        EXPECT_FALSE(line02a != line02b);

        Line line02c({0, 0, 0}, {0, -2, 2});
        Line line02d({0, 0, 0}, {0, 2, -2});
        EXPECT_FALSE(line02c != line02d);

        // same point different direction
        Line line07({1, 0, 0}, {1, 0, 0});
        Line line08({1, 0, 0}, {0, 1, 0});
        EXPECT_TRUE(line07 != line08);
    }

    TEST(LineTest, NotEqualityTest_PointChanges) {
        // Different points - same direction - different line
        Line line03({1, 0, 0}, {1, 0, 0});
        Line line04({0, 1, 0}, {1, 0, 0});
        EXPECT_TRUE(line03 != line04);

        // Different points but the same line
        Line line05({1, 0, 0}, {1, 0, 0});
        Line line06({0, 0, 0}, {1, 0, 0});
        EXPECT_FALSE(line05 != line06);
    }

    TEST(LineTest, NotEqualityTest_Composite) {
        // different point - reversed direction - same line
        Line line09({0, 0, 0}, {0, 1, 1});
        Line line10({0, 2, 2}, {0, -1, -1});
        EXPECT_FALSE(line09 != line10);
    }

    TEST(LineTest, IsOnTest_UnitChecks) {
        // Direction {1, 0, 0}
        Line line0({1, 0, 0}, {1, 0, 0}),
             line1({0, 1, 0}, {1, 0, 0}),
             line2({0, 0, 1}, {1, 0, 0});

        EXPECT_TRUE(line0.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line0.isOnLine({2, 0, 0}));
        EXPECT_TRUE(line0.isOnLine({0, 0, 0}));
        EXPECT_FALSE(line0.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line0.isOnLine({0, 0, 1}));

        EXPECT_TRUE(line1.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line1.isOnLine({1, 1, 0}));
        EXPECT_TRUE(line1.isOnLine({-1, 1, 0}));
        EXPECT_FALSE(line1.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line1.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line1.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line2.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line2.isOnLine({1, 0, 1}));
        EXPECT_TRUE(line2.isOnLine({-1, 0, 1}));
        EXPECT_FALSE(line2.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line2.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line2.isOnLine({0, 0, 0}));

        // Direction {0, 1, 0}
        Line line3({1, 0, 0}, {0, 1, 0}),
             line4({0, 1, 0}, {0, 1, 0}),
             line5({0, 0, 1}, {0, 1, 0});

        EXPECT_TRUE(line3.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line3.isOnLine({1, 1, 0}));
        EXPECT_TRUE(line3.isOnLine({1, -1, 0}));
        EXPECT_FALSE(line3.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line3.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line3.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line4.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line4.isOnLine({0, 2, 0}));
        EXPECT_TRUE(line4.isOnLine({0, 0, 0}));
        EXPECT_FALSE(line4.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line4.isOnLine({1, 0, 0}));

        EXPECT_TRUE(line5.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line5.isOnLine({0, 1, 1}));
        EXPECT_TRUE(line5.isOnLine({0, -1, 1}));
        EXPECT_FALSE(line5.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line5.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line5.isOnLine({0, 0, 0}));

        // Direction {0, 0, 1}
        Line line6({1, 0, 0}, {0, 0, 1}),
             line7({0, 1, 0}, {0, 0, 1}),
             line8({0, 0, 1}, {0, 0, 1});

        EXPECT_TRUE(line6.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line6.isOnLine({1, 0, 1}));
        EXPECT_TRUE(line6.isOnLine({1, 0, -1}));
        EXPECT_FALSE(line6.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line6.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line6.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line7.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line7.isOnLine({0, 1, 1}));
        EXPECT_TRUE(line7.isOnLine({0, 1, -1}));
        EXPECT_FALSE(line7.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line7.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line7.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line8.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line8.isOnLine({0, 0, 2}));
        EXPECT_TRUE(line8.isOnLine({0, 0, 0}));
        EXPECT_FALSE(line8.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line8.isOnLine({0, 1, 0}));
    }

    TEST(LineTest, IsOnTest_PointChanges) {
        // Direction {1, -1, 0}
        Line line0({1, 0, 0}, {1, -1, 0}),
             line1({0, 1, 0}, {1, -1, 0}),
             line2({0, 0, 1}, {1, -1, 0});

        EXPECT_TRUE(line0.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line0.isOnLine({2, -1, 0}));
        EXPECT_TRUE(line0.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line0.isOnLine({1, -1, 0}));
        EXPECT_FALSE(line0.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line1.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line1.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line1.isOnLine({-1, 2, 0}));
        EXPECT_FALSE(line1.isOnLine({1, -1, 0}));
        EXPECT_FALSE(line1.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line2.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line2.isOnLine({1, -1, 1}));
        EXPECT_TRUE(line2.isOnLine({-1, 1, 1}));
        EXPECT_FALSE(line2.isOnLine({1, -1, 0}));
        EXPECT_FALSE(line2.isOnLine({0, 0, 0}));

        // Direction {0, 1, -1}
        Line line3({1, 0, 0}, {0, 1, -1}),
             line4({0, 1, 0}, {0, 1, -1}),
             line5({0, 0, 1}, {0, 1, -1});

        EXPECT_TRUE(line3.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line3.isOnLine({1, 1, -1}));
        EXPECT_TRUE(line3.isOnLine({1, -1, 1}));
        EXPECT_FALSE(line3.isOnLine({0, 1, -1}));
        EXPECT_FALSE(line3.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line4.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line4.isOnLine({0, 2, -1}));
        EXPECT_TRUE(line4.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line4.isOnLine({0, 1, -1}));
        EXPECT_FALSE(line4.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line5.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line5.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line5.isOnLine({0, -1, 2}));
        EXPECT_FALSE(line5.isOnLine({0, 1, -1}));
        EXPECT_FALSE(line5.isOnLine({0, 0, 0}));

        // Direction {-1, 0, 1}
        Line line6({1, 0, 0}, {-1, 0, 1}),
             line7({0, 1, 0}, {-1, 0, 1}),
             line8({0, 0, 1}, {-1, 0, 1});

        EXPECT_TRUE(line6.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line6.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line6.isOnLine({2, 0, -1}));
        EXPECT_FALSE(line6.isOnLine({-1, 0, 1}));
        EXPECT_FALSE(line6.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line7.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line7.isOnLine({-1, 1, 1}));
        EXPECT_TRUE(line7.isOnLine({1, 1, -1}));
        EXPECT_FALSE(line7.isOnLine({-1, 0, 1}));
        EXPECT_FALSE(line7.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line8.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line8.isOnLine({-1, 0, 2}));
        EXPECT_TRUE(line8.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line8.isOnLine({-1, 0, 1}));
        EXPECT_FALSE(line8.isOnLine({0, 0, 0}));
    }

    TEST(LineTest, IsOnTest_DirectionChanges) {
        // Point {1, -1, 0}
        Line line0({1, -1, 0}, {1, 0, 0}),
             line1({1, -1, 0}, {0, 1, 0}),
             line2({1, -1, 0}, {0, 0, 1});

        EXPECT_TRUE(line0.isOnLine({1, -1, 0}));
        EXPECT_TRUE(line0.isOnLine({2, -1, 0}));
        EXPECT_TRUE(line0.isOnLine({0, -1, 0}));
        EXPECT_FALSE(line0.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line0.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line1.isOnLine({1, -1, 0}));
        EXPECT_TRUE(line1.isOnLine({1, 0, 0}));
        EXPECT_TRUE(line1.isOnLine({1, -2, 0}));
        EXPECT_FALSE(line1.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line1.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line2.isOnLine({1, -1, 0}));
        EXPECT_TRUE(line2.isOnLine({1, -1, 1}));
        EXPECT_TRUE(line2.isOnLine({1, -1, -1}));
        EXPECT_FALSE(line2.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line2.isOnLine({0, 0, 0}));

        // Point {0, 1, -1}
        Line line3({0, 1, -1}, {1, 0, 0}),
             line4({0, 1, -1}, {0, 1, 0}),
             line5({0, 1, -1}, {0, 0, 1});

        EXPECT_TRUE(line3.isOnLine({0, 1, -1}));
        EXPECT_TRUE(line3.isOnLine({1, 1, -1}));
        EXPECT_TRUE(line3.isOnLine({-1, 1, -1}));
        EXPECT_FALSE(line3.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line3.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line4.isOnLine({0, 1, -1}));
        EXPECT_TRUE(line4.isOnLine({0, 2, -1}));
        EXPECT_TRUE(line4.isOnLine({0, 0, -1}));
        EXPECT_FALSE(line4.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line4.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line5.isOnLine({0, 1, -1}));
        EXPECT_TRUE(line5.isOnLine({0, 1, 0}));
        EXPECT_TRUE(line5.isOnLine({0, 1, -2}));
        EXPECT_FALSE(line5.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line5.isOnLine({0, 0, 0}));

        // Point {-1, 0, 1}
        Line line6({-1, 0, 1}, {1, 0, 0}),
             line7({-1, 0, 1}, {0, 1, 0}),
             line8({-1, 0, 1}, {0, 0, 1});

        EXPECT_TRUE(line6.isOnLine({-1, 0, 1}));
        EXPECT_TRUE(line6.isOnLine({0, 0, 1}));
        EXPECT_TRUE(line6.isOnLine({-2, 0, 1}));
        EXPECT_FALSE(line6.isOnLine({1, 0, 0}));
        EXPECT_FALSE(line6.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line7.isOnLine({-1, 0, 1}));
        EXPECT_TRUE(line7.isOnLine({-1, 1, 1}));
        EXPECT_TRUE(line7.isOnLine({-1, -1, 1}));
        EXPECT_FALSE(line7.isOnLine({0, 1, 0}));
        EXPECT_FALSE(line7.isOnLine({0, 0, 0}));

        EXPECT_TRUE(line8.isOnLine({-1, 0, 1}));
        EXPECT_TRUE(line8.isOnLine({-1, 0, 2}));
        EXPECT_TRUE(line8.isOnLine({-1, 0, 0}));
        EXPECT_FALSE(line8.isOnLine({0, 0, 1}));
        EXPECT_FALSE(line8.isOnLine({0, 0, 0}));
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
