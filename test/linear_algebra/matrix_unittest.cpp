#include "gtest/gtest.h"
#include <math.h>
#include "../../source/linear_algebra/matrix.hpp"

TEST(MatrixTest, DefaultInitTest) {
    cpp_utils::linalg::Matrix iMat;
    EXPECT_EQ(iMat.xx, 1); EXPECT_EQ(iMat.xy, 0); EXPECT_EQ(iMat.xz, 0);
    EXPECT_EQ(iMat.yx, 0); EXPECT_EQ(iMat.yy, 1); EXPECT_EQ(iMat.yz, 0);
    EXPECT_EQ(iMat.zx, 0); EXPECT_EQ(iMat.zy, 0); EXPECT_EQ(iMat.zz, 1);
}

TEST(MatrixTest, InitTest) {
    cpp_utils::linalg::Matrix Mat1(0, 1, 2, 3, 4, 5, 6, 7, 8);
    EXPECT_EQ(Mat1.xx, 0); EXPECT_EQ(Mat1.xy, 1); EXPECT_EQ(Mat1.xz, 2);
    EXPECT_EQ(Mat1.yx, 3); EXPECT_EQ(Mat1.yy, 4); EXPECT_EQ(Mat1.yz, 5);
    EXPECT_EQ(Mat1.zx, 6); EXPECT_EQ(Mat1.zy, 7); EXPECT_EQ(Mat1.zz, 8);
}

TEST(MatrixTest, DetTest) {
    cpp_utils::linalg::Matrix Mat1(2, 0, 0, 0, 2, 0, 0, 0, 2);
    EXPECT_NEAR(Mat1.det(), 8, 0.0001);
}

TEST(MatrixTest, EqualityTest) {
    cpp_utils::linalg::Matrix Mat1(1, 0, 1, 0, 1, 0, 1, 0, 1);
    cpp_utils::linalg::Matrix Mat2(0, 1, 0, 1, 0, 1, 0, 1, 0);
    
    EXPECT_TRUE(Mat1 == Mat1);
    EXPECT_FALSE(Mat1 == Mat2);
}

TEST(MatrixTest, NotEqualityTest) {
    cpp_utils::linalg::Matrix Mat1(1, 0, 1, 0, 1, 0, 1, 0, 1);
    cpp_utils::linalg::Matrix Mat2(0, 1, 0, 1, 0, 1, 0, 1, 0);
    
    EXPECT_FALSE(Mat1 != Mat1);
    EXPECT_TRUE(Mat1 != Mat2);
}

TEST(MatrixTest, AdditionTest) {
    cpp_utils::linalg::Matrix Mat1(1, 0, 1, 0, 1, 0, 1, 0, 1);
    cpp_utils::linalg::Matrix Mat2(0, 1, 0, 1, 0, 1, 0, 1, 0);

    cpp_utils::linalg::Matrix ExpMat(1, 1, 1, 1, 1, 1, 1, 1, 1);
    EXPECT_EQ(Mat1 + Mat2, ExpMat);
}

TEST(MatrixTest, SubtractionTest) {
    cpp_utils::linalg::Matrix Mat1(1, 0, 1, 0, 1, 0, 1, 0, 1);
    cpp_utils::linalg::Matrix Mat2(0, 1, 0, 1, 0, 1, 0, 1, 0);

    cpp_utils::linalg::Matrix ExpMat(1, -1, 1, -1, 1, -1, 1, -1, 1);
    EXPECT_EQ(Mat1 - Mat2, ExpMat);
    EXPECT_EQ(Mat2 - Mat1, -ExpMat);
}

TEST(MatrixTest, NegativeTest) {
    cpp_utils::linalg::Matrix Mat1(0, -1, 2, -3, 4, -5, 6, -7, 8);
    cpp_utils::linalg::Matrix Mat2(0, 1, -2, 3, -4, 5, -6, 7, -8);

    EXPECT_EQ(-Mat1, Mat2);
}

TEST(MatrixTest, MultiplicationTest) {
    cpp_utils::linalg::Matrix Mat1(0, 1, 2, 3, 4, -1, -2, -3, -4);

    cpp_utils::linalg::Matrix Exp1(0, -2, -4, -6, -8, 2, 4, 6, 8);
    EXPECT_EQ(Mat1 * int(-2), Exp1) << "Failed to multiply by negative int";
    EXPECT_EQ(Mat1 * float(-2), Exp1) << "Failed to multiply by negative float";

    cpp_utils::linalg::Matrix Exp2(0.0, 0.5, 1.0, 1.5, 2.0, -0.5, -1.0, -1.5, -2.0);
    cpp_utils::linalg::Matrix res = Mat1 * float(0.5);
    EXPECT_EQ(Mat1 * float(0.5), Exp2) << "Failed to multiply by decimal value";
}

TEST(MatrixTest, DivisionTest) {
    cpp_utils::linalg::Matrix Mat1(0, 2, 4, 6, 8, -2, -4, -6, -8);
    
    cpp_utils::linalg::Matrix Exp1(0, 1, 2, 3, 4, -1, -2, -3, -4);
    EXPECT_EQ(Mat1 / float(2), Exp1);
    EXPECT_EQ(Mat1 / int(2), Exp1);
}

TEST(MatrixTest, ZeroDivisionTest) {
    cpp_utils::linalg::Matrix Mat1;
    std::invalid_argument Excep("Division by zero is not possible");
}

TEST(MatrixTest, MatrixMultiplicationTest) {
    cpp_utils::linalg::Matrix Mat1(1, 1, 0, 0, 1, 0, 0, 0, 0);
    cpp_utils::linalg::Matrix Mat2(0, 1, 2, 3, 4, 5, 6, 7, 8);
    cpp_utils::linalg::Matrix Mat3(3, 5, 7, 3, 4, 5, 0, 0, 0);
    
    EXPECT_TRUE(Mat1 * Mat2 == Mat3);
    EXPECT_FALSE(Mat2 * Mat1 == Mat3);
}

TEST(MatrixTest, VectorMultiplicationTest) {
    cpp_utils::linalg::Matrix Mat1(1, 1, 0, 0, 1, 0, 0, 0, 0);
    cpp_utils::linalg::Vector Vec1(0, 1, 2);
    cpp_utils::linalg::Vector Vec2(1, 1, 0);

    EXPECT_TRUE(Mat1 * Vec1 == Vec2);
    EXPECT_FALSE(Mat1 * Vec2 == Vec1);
}

TEST(MatrixTest, InverseTest) {
    cpp_utils::linalg::Matrix Mat1(0, 1, 2, 3, 4, 5, 6, 7, 8);
    cpp_utils::linalg::Matrix Mat2(0, 0, 0, 0, 0, 0, 0, 0, 0);
    cpp_utils::linalg::Matrix Mat3(0, 0, -1, 0, 1, 0, 1, 0, 0);
    cpp_utils::linalg::Matrix Mat4(0, 0, 1, 0, 1, 0, -1, 0, 0);
    cpp_utils::linalg::Matrix Mat5(0, 0, 1, 0, 1, 0, 1, 0, 0);

    EXPECT_TRUE(Mat1.inverse() == Mat2);
    EXPECT_TRUE(Mat2.inverse() == Mat2);
    EXPECT_TRUE(Mat3.inverse() == Mat4);
    EXPECT_TRUE(Mat4.inverse() == Mat3);
    EXPECT_TRUE(Mat5.inverse() == Mat5);
}
