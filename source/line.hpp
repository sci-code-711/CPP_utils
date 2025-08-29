#ifndef LINE_HPP
#define LINE_HPP

#include "vector.hpp"

const double norm = (1 / sqrt(3));

namespace cpp_utils {

    class Line {
        public:
            Vector point, direction;
            inline Line() : point(0, 0, 0), direction(norm, norm, norm) {};
            Line(Vector _point, Vector _direction);

            bool operator==(const Line &that) const;
            inline bool operator!=(const Line &that) const {
                return true != (*this == that);
            };

            bool isOnLine(const Vector &that) const;

            double whereOnLine(const Vector &that) const;
    };

}

#endif
