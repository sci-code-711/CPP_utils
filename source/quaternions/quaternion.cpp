#include "./quaternion.hpp";
#include <math.h>

namespace cpp_utils::quat {

    float Quaternion::mod() const {
        return sqrt((w * w) + (x * x) + (y * y) + (z * z));
    };

    Quaternion Quaternion::operator*(const double & that) const {
        return Quaternion(w * that, x * that, y * that, z * that);
    };


}