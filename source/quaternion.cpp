#include "quaternion.hpp"
#include <math.h>
#include <cmath>

namespace cpp_utils {

    double Quaternion::mod() const {
        return sqrt((w * w) + (x * x) + (y * y) + (z * z));
    };

    Quaternion Quaternion::operator*(const double & that) const {
        return Quaternion(w * that, x * that, y * that, z * that);
    };

    bool Quaternion::operator==(const Quaternion &that) const {
        double testRelPrecision = std::fmax(relPrecision, that.relPrecision);
        double testPrecision = std::fmax(mod(), that.mod()) * testRelPrecision;

        return !(
            std::abs(x - that.x) > testPrecision
            || std::abs(y - that.y) > testPrecision
            || std::abs(z - that.z) > testPrecision
        );
    };

    Quaternion Quaternion::operator*(const Quaternion &that) const {
        return Quaternion(
            w * that.w - (x * that.x + y * that.y + z * that.z),
            w * that.x + x * that.w + y * that.z - z * that.y,
            w * that.y - x * that.z + y * that.w + z * that.x,
            w * that.z + x * that.y - y * that.x + z * that.w
        );
    };

    Vector Quaternion::operator*(const Vector & vec) const {
        Quaternion result = Quaternion(0.0, vec.x, vec.y, vec.z) * *this;
        return Vector(result.x, result.y, result.z);
    };

    Vector operator*(const Vector vec, const Quaternion quat) {
        Quaternion result = quat * Quaternion(0.0, vec.x, vec.y, vec.z);
        return Vector(result.x, result.y, result.z);
    };




}