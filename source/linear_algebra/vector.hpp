#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>


namespace cpp_utils::linalg {

class Vector{
    public:
        float x, y, z;
        inline Vector() : x(0), y(0), z(0) {};
        Vector(int x, int y, int z);
        Vector(float x, float y, float z);
        Vector(double x, double y, double z);
        float mod() const;

        bool operator==(const Vector & that) const;
        inline bool operator!=(const Vector & that) const {
            return true != (*this == that);
        };
        Vector operator+(const Vector & that) const;
        Vector operator-(const Vector & that) const;
        Vector operator*(const float & that) const;
        inline Vector operator*(const int & that) const {return *this * float(that);};
        inline Vector operator/(const float & that) const {return *this * (1/that);};
        inline Vector operator/(const int & that) const {return *this / float(that);};
        inline Vector operator-() {return *this * -1;};
        float operator*(const Vector & that) const;
        Vector operator^(const Vector & that) const;
    private:
        float precision = 0.0001;
};

}

#endif
