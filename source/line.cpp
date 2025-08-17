#include "line.hpp"

namespace cpp_utils {

    Line::Line(Vector setPoint, Vector setDirection) : point(setPoint) {
        double magnitude = setDirection.mod(); 
        Vector normDir = (1 / magnitude) * setDirection;
        if(normDir.x < 0) {
            direction = -normDir;
        } else {
            direction = normDir;
        }
    };

    bool Line::operator==(const Line &that) const {
        if(direction == that.direction && this->isOnLine(that.point).first) {
            return true;
        } else {
            return false;
        }
    };

    std::pair<bool,double> Line::isOnLine(const Vector &that) const {
        Vector vecDiff = that - point;
        double scalarX, scalarY, scalarZ;

        if(point.x == 0) {scalarX = vecDiff.x;} else {scalarX = vecDiff.x / point.x;}
        if(point.y == 0) {scalarY = vecDiff.y;} else {scalarY = vecDiff.y / point.y;}
        if(point.z == 0) {scalarZ = vecDiff.z;} else {scalarZ = vecDiff.z / point.z;}

        if(scalarX == scalarY && scalarX == scalarZ) {
            return std::pair<bool,double> (true, scalarX);
        } else {
            return std::pair<bool,double> (false, 0);
        }
    };

}
