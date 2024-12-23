#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace cpp_utils {

class Vector{
    public:
        double x, y, z;
        inline Vector() : x(0), y(0), z(0) {};
        Vector(double x, double y, double z);
        double mod() const;

        bool operator==(const Vector & that) const;
        inline bool operator!=(const Vector & that) const {
            return true != (*this == that);
        };
        Vector operator+(const Vector & that) const;
        Vector operator-(const Vector & that) const;
        Vector operator*(const double & that) const;
        inline Vector operator/(const double & that) const {return *this * (1/that);};
        inline Vector operator-() {return *this * -1;};
        double operator*(const Vector & that) const;
        Vector operator^(const Vector & that) const;
    protected:
        double precision = 0.0001;
};

inline std::ostream &operator<<(std::ostream &os, Vector const &vec) {
    return os << "Vec(" << vec.x << ", " << vec.y << ", "<< vec.z << ")\n";
};

}

#endif
