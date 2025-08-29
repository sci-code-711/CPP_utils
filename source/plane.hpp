#ifndef PLANE_HPP
#define PLANE_HPP

#include "line.hpp"

namespace cpp_utils {

    class Plane {
        public:
            Vector point, normal;
            inline Plane() : point(0, 0, 0), normal(norm, norm, norm) {};
            Plane(Vector _point, Vector _normal);

            bool operator==(const Plane &that) const;
            inline bool operator!=(const Plane &that) const {
                return true != (*this == that);
            };

            bool isOnPlane(const Vector &that) const;

            Vector intersection(const Line &that) const;
    };

    bool isBetween(const Line line, const Plane &plane1, const Plane &plane2);

}

#endif
