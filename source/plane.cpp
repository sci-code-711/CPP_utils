#include "plane.hpp"

namespace cpp_utils {

    Plane::Plane(Vector _point, Vector _normal) : point(_point) {
        Vector normNor = _normal.normalise();
        if ((normNor.x < 0) || (normNor.x == 0 && normNor.y < 0) || (normNor.x == 0 && normNor.y == 0 && normNor.z < 0)) {
            normal = -normNor;
        } else {
            normal = normNor;
        }
    };

    bool Plane::operator==(const Plane &that) const {
        return normal == that.normal && this->isOnPlane(that.point);
    };

    bool Plane::isOnPlane(const Vector &that) const {
        Vector vecDiff = that - point;
        return vecDiff * normal == 0;
    };

    Vector Plane::intersection(const Line &that) const {
        double cosAngle = that.direction * normal;
        Vector vecDiff = that.point - point;
        double dotProd = vecDiff * normal;
        if (cosAngle == 0) {
            throw value_error("Line lies in plane or is parallel to plane.");
        } else if (dotProd == 0) {
            return that.point;
        } else {
            double scalar = -dotProd / cosAngle;
            return that.point + (scalar * that.direction);
        }
    };

    bool isBetween(const Line line, const Plane &plane1, const Plane &plane2) {
        if (plane1.normal != plane2.normal || line.direction * plane1.normal != 0) {
            return false;
        } else {
            double abovePlane1 = (line.point - plane1.point) * plane1.normal;
            double abovePlane2 = (line.point - plane2.point) * plane2.normal;
            return abovePlane1 * abovePlane2 < 0;
        }
    };

}
