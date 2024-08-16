#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <exception>
#include "vector.hpp"

namespace cpp_utils {

class Matrix{
    public:
        const double xx, xy, xz, yx, yy, yz, zx, zy, zz;
        inline Matrix() : xx(1), xy(0), xz(0), yx(0), yy(1), yz(0), zx(0), zy(0), zz(1) {};
        Matrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz);
        double det() const;

        bool operator==(const Matrix & that) const;
        inline bool operator!=(const Matrix & that) const {
            return true != (*this == that);
        };
        Matrix operator+(const Matrix & that) const;
        Matrix operator-(const Matrix & that) const;
        Matrix operator*(const double & that) const;
        inline Matrix operator/(const double & that) const {return *this * (1/that);};
        inline Matrix operator-() {return *this * -1;};
        Matrix operator*(const Matrix & that) const;
        Vector operator*(const Vector & that) const;
        Matrix inverse() const;
    private:
        double precision = 0.0001;
};

Vector operator*(Vector that, const Matrix & those);
Matrix operator*(double that, const Matrix & those);

}

#endif
