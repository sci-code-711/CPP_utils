
#include <math.h>
#include <cmath>

#include "vector.hpp"

namespace cpp_utils {

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {};

double Vector::mod() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

bool Vector::operator==(const Vector & that) const {
    double test_precision = std::fmax(precision, that.precision);
    if ((x < (that.x - test_precision)) || (x > (that.x + test_precision))) {
        return false;
    }
    if ((y < (that.y - test_precision)) || (y > (that.y + test_precision))) {
        return false;
    }
    if ((z < (that.z - test_precision)) || (z > (that.z + test_precision))) {
        return false;
    }
    return true;
}

Vector Vector::operator+(const Vector & that) const {
    return Vector(this->x + that.x, this->y + that.y, this->z + that.z);
}

Vector Vector::operator-(const Vector & that) const {
    return Vector(this->x - that.x, this->y - that.y, this->z - that.z);
}

Vector Vector::operator*(const double & that) const {
    return Vector(x * that, y * that, z * that);
}

double Vector::operator*(const Vector & that) const {
    return (x * that.x) + (y * that.y) + (z * that.z);
}

Vector Vector::operator^(const Vector & that) const {
    return Vector(
        (y * that.z) - (z * that.y),
        (z * that.x) - (x * that.z),
        (x * that.y) - (y * that.x)
    );
}

}
