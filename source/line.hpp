#ifndef LINE_HPP
#define LINE_HPP

#include "vector.hpp"

const double norm = (1 / sqrt(3));

namespace cpp_utils {

    class Line {
        public:
            double scalar;
            Vector point, direction;
            inline Line() : point(0, 0, 0), direction(norm, norm, norm) {};
            Line(Vector pnt, Vector dir);

            bool operator==(const Line &that);
            inline bool operator!=(const Line &that) {
                return true != (*this == that);
            };

            bool isOnLine(const Vector &that);

            double whereOnLine(const Vector &that);
    };

}

#endif
