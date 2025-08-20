#include "line.hpp"

namespace cpp_utils {

    Line::Line(Vector pnt, Vector dir) : point(pnt) {
        Vector normDir = dir.normalise();
        if ((normDir.x < 0) || (normDir.x == 0 && normDir.y < 0) || (normDir.x == 0 && normDir.y == 0 && normDir.z < 0)) {
            direction = -normDir;
        } else {
            direction = normDir;
        }
    };

    bool Line::operator==(const Line &that) const {
        bool on = this->isOnLine(that.point);
        if (direction == that.direction && on) {
            return true;
        } else {
            return false;
        }
    };

    bool Line::isOnLine(const Vector &that) const {
        bool isOn = true;
        try {
            this->whereOnLine(that);
        } catch (std::overflow_error) {
            isOn = false;
        }
        return isOn;
    }

    double Line::whereOnLine(const Vector &that) const {
        Vector vecDiff = that - point;
        double scalarX, scalarY, scalarZ;

        if (direction.x == 0) {scalarX = vecDiff.x;} else {scalarX = vecDiff.x / direction.x;}
        if (direction.y == 0) {scalarY = vecDiff.z;} else {scalarY = vecDiff.y / direction.y;}
        if (direction.z == 0) {scalarZ = vecDiff.z;} else {scalarZ = vecDiff.z / direction.z;}

        if ((scalarX == scalarY && scalarX == scalarZ) ||
            (scalarY == 0 && scalarX == scalarZ && direction.y == 0) ||
            (scalarZ == 0 && scalarX == scalarY && direction.z == 0) ||
            (scalarY == 0 && scalarZ == 0 && direction.y == 0 && direction.z == 0)) {
            return scalarX;
        } else if ((scalarX == 0 && scalarY == scalarZ && direction.x == 0) ||
                    (scalarX == 0 && scalarZ == 0 && direction.x == 0 && direction.z == 0)) {
            return scalarY;
        } else if ((scalarX == 0 && scalarY == 0 && direction.x == 0 && direction.y == 0)) {
            return scalarZ;
        } else {
            throw std::overflow_error("Point not on line.");
        }
    };

}
