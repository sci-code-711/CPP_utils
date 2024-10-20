
#include <math.h>
#include <cmath>

#include "attriCoord.hpp"

namespace cpp_utils {

AttriCoord::AttriCoord(double x, double y, double z, double a, double b) : x(x), y(y), z(z), a(a), b(b) {};

AttriCoord::AttriCoord(Vector vec, double a, double b) : x(vec.x), y(vec.y), z(vec.z),  a(a), b(b) {};

double AttriCoord::mod() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

bool AttriCoord::operator==(const AttriCoord & that) const {
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
    if ((a < (that.a - test_precision)) || (a > (that.a + test_precision))) {
        return false;
    }
    if ((b < (that.b - test_precision)) || (b > (that.b + test_precision))) {
        return false;
    }
    return true;
}

AttriCoord AttriCoord::operator+(const Vector & that) const {
    return AttriCoord(this->x + that.x, this->y + that.y, this->z + that.z, this->a, this->b);
}

AttriCoord AttriCoord::operator-(const Vector & that) const {
    return AttriCoord(this->x - that.x, this->y - that.y, this->z - that.z, this-> a, this->b);
}

AttriCoord AttriCoord::operator*(const double & that) const {
    return AttriCoord(x * that, y * that, z * that, a, b);
}

}
