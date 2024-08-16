#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <cmath>
#include "vector.hpp"

namespace cpp_utils {

class Quaternion {
    public:
        double w, x, y, z;
        inline Quaternion() : w(0), x(0), y(0), z(0) {};
        inline Quaternion(double w, double x, double y, double z):
            w(w),  x(x), y(y), z(z) {};
        Quaternion(double angle, Vector axis);
        double mod() const;

        bool operator==(const Quaternion & that) const;
        inline bool operator!=(const Quaternion & that) const {
            return true != (*this == that);
        };
        Quaternion operator*(const double & that) const;
        inline Quaternion operator/(const double & that) const {
            return *this * (1/that);
        };
        inline Quaternion operator-() {return *this * -1;};
        Quaternion operator*(const Quaternion & that) const;
        Vector operator*(const Vector & vec) const;
    private:
        double relPrecision = 0.0001;

};

Vector operator*(const Vector vec, const Quaternion quat);

inline Vector rotate(Vector vec, Quaternion quat) {
    return quat * vec * - quat / quat.mod();
};

}

#endif