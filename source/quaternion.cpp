#include "quaternion.hpp"
#include <math.h>
#include <cmath>

namespace cpp_utils {

    Quaternion::Quaternion(double angle, Vector axis):
        w(cos(angle / 2)),
        x(axis.x / axis.mod() * sin(angle / 2)),
        y(axis.y / axis.mod() * sin(angle / 2)),
        z(axis.z / axis.mod() * sin(angle / 2))
        {};

    double Quaternion::mod() const {
        return sqrt((w * w) + (x * x) + (y * y) + (z * z));
    };

    Quaternion Quaternion::conj() const {
        return {w, -x, -y, -z};
    }

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
            (w * that.w) - (x * that.x) - (y * that.y) - (z * that.z),
            (w * that.x) + (x * that.w) + (y * that.z) - (z * that.y),
            (w * that.y) - (x * that.z) + (y * that.w) + (z * that.x),
            (w * that.z) + (x * that.y) - (y * that.x) + (z * that.w)
        );
    };

    Quaternion Quaternion::operator*(const Vector & vec) const {
        return *this * Quaternion(0.0, vec.x, vec.y, vec.z);
    };

    Quaternion operator*(const Vector vec, const Quaternion quat) {
        return Quaternion(0.0, vec.x, vec.y, vec.z) * quat;
    };

}