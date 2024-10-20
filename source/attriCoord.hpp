#ifndef ATTRICOORD_HPP
#define ATTRICOORD_HPP

#include <iostream>
#include "vector.hpp"

namespace cpp_utils {

class AttriCoord{
    public:
        double x, y, z, a, b;
        inline AttriCoord() : x(0), y(0), z(0), a(0), b(0) {};
        AttriCoord(double x, double y, double z, double a, double b);
        AttriCoord(Vector vec, double a, double b);
        double mod() const;

        bool operator==(const AttriCoord & that) const;
        inline bool operator!=(const AttriCoord & that) const {
            return true != (*this == that);
        };
        AttriCoord operator+(const Vector & that) const;
        AttriCoord operator-(const Vector & that) const;
        AttriCoord operator*(const double & that) const;
        inline AttriCoord operator/(const double & that) const {return *this * (1/that);};
        inline AttriCoord operator-() {return *this * -1;};
    private:
        double precision = 0.0001;
};

inline std::ostream &operator<<(std::ostream &os, AttriCoord const &attri) {
    return os << "Vec(" << attri.x << ", " << attri.y << ", "<< attri.z << ")\n";
};

}

#endif
