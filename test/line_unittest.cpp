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
    EXPECT_TRUE(line.direction == (1 / direction.mod()) * direction);
}

TEST(LineTest, EqualityTest) {
    cpp_utils::Vector vec0;
    cpp_utils::Vector vec1(-1, -1, -1);
    cpp_utils::Vector vec2(1, 0, 1);
    cpp_utils::Line line0;
    cpp_utils::Line line1(vec1, vec1);
    cpp_utils::Line line2(vec0, vec2);
    cpp_utils::Line line3(vec2, vec1);    

    EXPECT_TRUE(line0 == line0);
    EXPECT_TRUE(line0 == line1);
    EXPECT_FALSE(line0 == line2);
    EXPECT_FALSE(line1 == line2);
    EXPECT_FALSE(line0 == line3);
    EXPECT_FALSE(line1 == line3);
    EXPECT_FALSE(line2 == line3);
}

TEST(LineTest, NotEqualityTest) {
    cpp_utils::Vector vec0;
    cpp_utils::Vector vec1(-1, -1, -1);
    cpp_utils::Vector vec2(1, 0, 1);
    cpp_utils::Line line0;
    cpp_utils::Line line1(vec1, vec1);
    cpp_utils::Line line2(vec0, vec2);
    cpp_utils::Line line3(vec2, vec1);    

    EXPECT_FALSE(line0 != line0);
    EXPECT_FALSE(line0 != line1);
    EXPECT_TRUE(line0 != line2);
    EXPECT_TRUE(line1 != line2);
    EXPECT_TRUE(line0 != line3);
    EXPECT_TRUE(line1 != line3);
    EXPECT_TRUE(line2 != line3);
}

TEST(LineTest, IsOnTest) {
    cpp_utils::Vector point0(0, 1, 1);
    cpp_utils::Vector point1(1, 1, 1);
    cpp_utils::Vector point2(1, 2, 2);    
    cpp_utils::Line line(point0, point1);

    std::pair<bool,double> isOnLine0 = line.isOnLine(point0);
    std::pair<bool,double> isOnLine1 = line.isOnLine(point1);
    std::pair<bool,double> isOnLine2 = line.isOnLine(point2);

    EXPECT_TRUE(isOnLine0.first);
    EXPECT_FALSE(isOnLine1.first);
    EXPECT_TRUE(isOnLine2.first);

    EXPECT_EQ(isOnLine0.second, 0);
    EXPECT_EQ(isOnLine1.second, 0);
    EXPECT_EQ(isOnLine2.second, 1);    
}
