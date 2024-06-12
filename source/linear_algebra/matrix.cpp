#include <math.h>
#include <cmath>
#include "matrix.hpp"

namespace cpp_utils::linalg {

Matrix::Matrix(int xx, int xy, int xz, int yx, int yy, int yz, int zx, int zy, int zz) : xx(xx), xy(xy), xz(xz), yx(yx), yy(yy), yz(yz), zx(zx), zy(zy), zz(zz) {};
Matrix::Matrix(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz) : xx(xx), xy(xy), xz(xz), yx(yx), yy(yy), yz(yz), zx(zx), zy(zy), zz(zz) {};
Matrix::Matrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz) : xx(xx), xy(xy), xz(xz), yx(yx), yy(yy), yz(yz), zx(zx), zy(zy), zz(zz) {};

float Matrix::det() const{
    return xx*(yy*zz-yz*zy)-xy*(yx*zz-yz*zx)+xz*(yx*zy-yy*zx);
}

bool Matrix::operator==(const Matrix & that) const {
    float test_precision = std::fmax(precision, that.precision);
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

Matrix Matrix::operator*(const float & that) const {
    return Matrix(xx * that, xy * that, xz * that, yx * that, yy * that, yz * that, zx * that, zy * that, zz * that);
}

Matrix Matrix::operator*(const Matrix & that) const {
    return Matrix((xx * that.xx) + (xy * that.yx) + (xz * that.zx), (xx * that.xy) + (xy * that.yy) + (xz * that.zy), (xx * that.xz) + (xy * that.yz) + (xz * that.zz),
                  (yx * that.xx) + (yy * that.yx) + (yz * that.zx), (yx * that.xy) + (yy * that.yy) + (yz * that.zy), (yx * that.xz) + (yy * that.yz) + (yz * that.zz),
                  (zx * that.xx) + (zy * that.yx) + (zz * that.zx), (zx * that.xy) + (zy * that.yy) + (zz * that.zy), (zx * that.xz) + (zy * that.yz) + (zz * that.zz));
}

Vector Matrix::operator*(const Vector & that) const {
    return Vector((xx * that.x) + (xy * that.y) + (xz * that.z), (yx * that.x) + (yy * that.y) + (yz * that.z), (zx * that.x) + (zy * that.y) + (zz * that.z));
}

Matrix Matrix::inverse() const {
    if(this->det() == 0) {
        return Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    return Matrix( (1/det()) * ((yy * zz) - (zy * yz)), -(1/det()) * ((xy * zz) - (zy * xz)),  (1/det()) * ((xy * yz) - (yy * xz)),
                  -(1/det()) * ((yx * zz) - (zx * yz)),  (1/det()) * ((xx * zz) - (zx * xz)), -(1/det()) * ((xx * yz) - (yx * xz)),
                   (1/det()) * ((yx * zy) - (zx * yy)), -(1/det()) * ((xx * zy) - (zx * xy)),  (1/det()) * ((xx * yy) - (yx * xy)));
}

}