#include "plane.hpp"

namespace cpp_utils {

    Plane::Plane(Vector setPoint, Vector setNormal) : point(setPoint) {
        double magnitude = setNormal.mod(); 
        Vector normNor = (1 / magnitude) * setNormal;
        if(normNor.x < 0) {
            normal = -normNor;
        } else {
            normal = normNor;
        }
    };

    bool Plane::operator==(const Plane &that) const {
        if(normal == that.normal && this->isOnPlane(that.point)) {
            return true;
        } else {
            return false;
        }
    };

    bool Plane::isOnPlane(const Vector &that) const {
        Vector vecDiff = that - point;
        if(vecDiff * normal == 0) {
            return true;
        } else {
            return false;
        }
    };

    Vector Plane::intersection(const Line &that) const {
        double cosAngle = that.direction * normal;
        Vector vecDiff = that.point - point;
        double dotProd = vecDiff * normal;
        if(cosAngle == 0) {
                throw std::overflow_error("Line lies in plane or it parallel to plane.");
        } else if(dotProd == 0) {
            return that.point;
        } else {
            double scalar = -dotProd / cosAngle;
            return that.point + (scalar * that.direction);
        }
    };

    bool between(const Line line, const Plane &plane1, const Plane &plane2) {
        if(plane1.normal != plane2.normal || line.direction * plane1.normal != 0) {
            return false;
        } else {
            double abovePlane1 = (line.point - plane1.point) * plane1.normal;
            double abovePlane2 = (line.point - plane2.point) * plane2.normal;
            if(abovePlane1 * abovePlane2 < 0) {
                return true;
            } else {
                return false;
            }
        }
    };

}
