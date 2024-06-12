#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <exception>
#include "vector.hpp"

namespace cpp_utils::linalg {
    
class Matrix{
    public:
        float xx, xy, xz, yx, yy, yz, zx, zy, zz;
        inline Matrix() : xx(1), xy(0), xz(0), yx(0), yy(1), yz(0), zx(0), zy(0), zz(1) {};
        Matrix(int xx, int xy, int xz, int yx, int yy, int yz, int zx, int zy, int zz);
        Matrix(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz);
        Matrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz);
        float det() const;

        bool operator==(const Matrix & that) const;
        inline bool operator!=(const Matrix & that) const {
            return true != (*this == that);
        };
        Matrix operator+(const Matrix & that) const;
        Matrix operator-(const Matrix & that) const;
        Matrix operator*(const float & that) const;
        inline Matrix operator*(const int & that) const {return *this * float(that);};
        inline Matrix operator/(const float & that) const {return *this * (1/that);};
        inline Matrix operator/(const int & that) const {return *this / float(that);};
        inline Matrix operator-() {return *this * -1;};
        Matrix operator*(const Matrix & that) const;
        Vector operator*(const Vector & that) const;
        Matrix inverse() const;
    private:
        float precision = 0.0001;
};

}

#endif
