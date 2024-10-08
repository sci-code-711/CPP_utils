#include <math.h>
#include <cmath>
#include "matrix.hpp"

namespace cpp_utils {

    Matrix::Matrix(
        double xx, double xy, double xz,
        double yx, double yy, double yz,
        double zx, double zy, double zz
    ): xx(xx), xy(xy), xz(xz), yx(yx), yy(yy), yz(yz), zx(zx), zy(zy), zz(zz) {};

    Matrix::Matrix(double xx, double yy, double zz): xx(xx), xy(0), xz(0), yx(0), yy(yy), yz(0), zx(0), zy(0), zz(zz) {
        Matrix diagonalMatrix(xx, 0, 0, 0, yy, 0, 0, 0, zz);
    };

    double Matrix::det() const {
        return xx*(yy*zz-yz*zy)-xy*(yx*zz-yz*zx)+xz*(yx*zy-yy*zx);
    }

    bool Matrix::operator==(const Matrix & that) const {
        double test_precision = std::fmax(precision, that.precision);
        if ((xx < (that.xx - test_precision)) || (xx > (that.xx + test_precision))) {
        return false;
        }
        if ((xy < (that.xy - test_precision)) || (xy > (that.xy + test_precision))) {
            return false;
        }
        if ((xz < (that.xz - test_precision)) || (xz > (that.xz + test_precision))) {
            return false;
        }
        if ((yx < (that.yx - test_precision)) || (yx > (that.yx + test_precision))) {
            return false;
        }
        if ((yy < (that.yy - test_precision)) || (yy > (that.yy + test_precision))) {
            return false;
        }
        if ((yz < (that.yz - test_precision)) || (yz > (that.yz + test_precision))) {
            return false;
        }
        if ((zx < (that.zx - test_precision)) || (zx > (that.zx + test_precision))) {
            return false;
        }
        if ((zy < (that.zy - test_precision)) || (zy > (that.zy + test_precision))) {
            return false;
        }
        if ((zz < (that.zz - test_precision)) || (zz > (that.zz + test_precision))) {
            return false;
        }
        return true;
    }

    Matrix Matrix::operator+(const Matrix & that) const {
        return Matrix(this->xx + that.xx, this->xy + that.xy, this->xz + that.xz, this->yx + that.yx, this->yy + that.yy, this->yz + that.yz, this->zx + that.zx, this->zy + that.zy, this->zz + that.zz);
    }

    Matrix Matrix::operator-(const Matrix & that) const {
        return Matrix(this->xx - that.xx, this->xy - that.xy, this->xz - that.xz, this->yx - that.yx, this->yy - that.yy, this->yz - that.yz, this->zx - that.zx, this->zy - that.zy, this->zz - that.zz);
    }

    Matrix Matrix::operator*(const double & that) const {
        return Matrix(xx * that, xy * that, xz * that, yx * that, yy * that, yz * that, zx * that, zy * that, zz * that);
    }

    Matrix operator*(double that, const Matrix & those) {
        return those * that;
    }

    Matrix Matrix::operator*(const Matrix & that) const {
        return Matrix((xx * that.xx) + (xy * that.yx) + (xz * that.zx), (xx * that.xy) + (xy * that.yy) + (xz * that.zy), (xx * that.xz) + (xy * that.yz) + (xz * that.zz),
                      (yx * that.xx) + (yy * that.yx) + (yz * that.zx), (yx * that.xy) + (yy * that.yy) + (yz * that.zy), (yx * that.xz) + (yy * that.yz) + (yz * that.zz),
                      (zx * that.xx) + (zy * that.yx) + (zz * that.zx), (zx * that.xy) + (zy * that.yy) + (zz * that.zy), (zx * that.xz) + (zy * that.yz) + (zz * that.zz));
    }

    Vector Matrix::operator*(const Vector & that) const {
        return Vector((xx * that.x) + (xy * that.y) + (xz * that.z), (yx * that.x) + (yy * that.y) + (yz * that.z), (zx * that.x) + (zy * that.y) + (zz * that.z));
    }

    Vector operator*(Vector that, const Matrix & those) {
        return Vector((that.x * those.xx) + (that.y * those.yx) + (that.z * those.zx), (that.x * those.xy) + (that.y * those.yy) + (that.z * those.zy), (that.x * those.xz) + (that.y * those.yz) + (that.z * those.zz));
    }

    Matrix Matrix::inverse() const {
        if(this->det() == 0) {
            throw std::overflow_error("No inverse due to zero value of determinant.");
        }
        return (1/det()) * Matrix( ((yy * zz) - (zy * yz)), -((xy * zz) - (zy * xz)),  ((xy * yz) - (yy * xz)),
                                  -((yx * zz) - (zx * yz)),  ((xx * zz) - (zx * xz)), -((xx * yz) - (yx * xz)),
                                   ((yx * zy) - (zx * yy)), -((xx * zy) - (zx * xy)),  ((xx * yy) - (yx * xy)));
    }

}
