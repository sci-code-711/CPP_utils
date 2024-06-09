

namespace cpp_utils::quat {

    class Quaternion {
        public:
            const float w, x, y, z;
            inline Quaternion() : w(0), x(0), y(0), z(0) {};
            inline Quaternion(int w, int x, int y, int z):
                w(float(w)),  x(float(x)), y(float(y)), z(float(z)) {};
            inline Quaternion(float w, float x, float y, float z):
                w(w),  x(x), y(y), z(z) {};
            inline Quaternion(double w, double x, double y, double z):
                w(float(w)),  x(float(x)), y(float(y)), z(float(z)) {};
            float mod() const;

            bool operator==(const Quaternion & that) const;
            inline bool operator!=(const Quaternion & that) const {
                return true != (*this == that);
            };
            Quaternion operator*(const float & that) const;
            inline Quaternion operator*(const int & that) const {return *this * float(that);};
            inline Quaternion operator/(const float & that) const {return *this * (1/that);};
            inline Quaternion operator/(const int & that) const {return *this / float(that);};
            inline Quaternion operator-() {return *this * -1;};
            float operator*(const Quaternion & that) const;
            Quaternion operator^(const Quaternion & that) const;
        private:
            float precision = 0.0001;

    };
}