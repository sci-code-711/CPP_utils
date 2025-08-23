#include "line.hpp"

namespace cpp_utils {

    Line::Line(Vector _point, Vector _direction) : point(_point) {
        Vector normDir = _direction.normalise();
        if ((normDir.x < 0) || (normDir.x == 0 && normDir.y < 0) || (normDir.x == 0 && normDir.y == 0 && normDir.z < 0)) {
            direction = -normDir;
        } else {
            direction = normDir;
        }
    };

    bool Line::operator==(const Line &that) const {
        return direction == that.direction && this->isOnLine(that.point);
    };

    /**
     * Determines whether a point lies on the line.
     */
    bool Line::isOnLine(const Vector &that) const {
        bool isOn = true;
        try {
            this->whereOnLine(that);
        } catch (value_error) {
            isOn = false;
        }
        return isOn;
    };

    /**
     * Determines where on the line a point lies.
     */
    double Line::whereOnLine(const Vector &that) const {
        Vector vecDiff = that - point;
        double scalarX, scalarY, scalarZ;
        
        if (direction.x == 0) {scalarX = vecDiff.x;} else {scalarX = vecDiff.x / direction.x;}
        if (direction.y == 0) {scalarY = vecDiff.y;} else {scalarY = vecDiff.y / direction.y;}
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
            throw value_error("Point not on line.");
        }
    };
    
}
