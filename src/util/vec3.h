//
// Created by dan on 13/10/2021.
//

#ifndef DANRT_VEC3_H
#define DANRT_VEC3_H

#include <array>
#include <complex>
#include <cmath>

namespace danrt {
    template <typename T>
    class Vec3 {
    public:
        explicit Vec3(T x = T(), T y = T(), T z = T())
            : xyz{x,y,z}
        {}
        /**
         * Accessor for 1st component
         * @return 1st component val
         */
        [[nodiscard]] constexpr auto x() const -> T {
            return xyz[0];
        }
        /**
         * Accessor for 2nd component
         * @return 2nd component val
         */
        [[nodiscard]] constexpr auto y() const -> T {
            return xyz[1];
        }
        /**
         * Accessor for 3rd component
         * @return 3rd component val
         */
        [[nodiscard]] constexpr auto z() const -> T {
            return xyz[2];
        }
        /**
         * Scalar multiplication
         * @return ref to result
         */
        inline constexpr auto operator*=(const T& x) -> Vec3<T>& {
            xyz[0] *= x;
            xyz[1] *= x;
            xyz[2] *= x;
            return *this;
        }
        /**
         * Scalar division
         * @return ref to result
         */
        inline constexpr auto operator/=(const T& x) -> Vec3<T>& {
            xyz[0] /= x;
            xyz[1] /= x;
            xyz[2] /= x;
            return *this;
        }
        /**
         * Negate the vector
         * @return ref to result
         */
        inline constexpr auto operator-() -> Vec3<T>& {
            xyz[0] *= -T();
            xyz[1] *= -T();
            xyz[2] *= -T();
            return *this;
        }
        /**
         * Vector addition
         * @param w other vec
         * @return ref to result
         */
        inline constexpr auto operator+=(const Vec3<T>& w) -> Vec3<T>& {
            xyz[0] += w.x();
            xyz[1] += w.y();
            xyz[2] += w.z();
            return *this;
        }
        /**
         * Square of the magnitude
         * @return val of magnitude squared
         */
        inline constexpr auto length_squared() const -> T {
            return x() * x() + y() * y() + z() * z();
        }
        /**
         * Magnitude of vector
         * @return value type magnitude
         */
        inline constexpr auto length() const -> T {
            return std::sqrt(length_squared());
        }
        /**
         * Scalar product
         * @return val of scalar (dot) product
         */
        inline constexpr auto dot(const Vec3<T>& v, const Vec3<T>& w) const -> T {
            return v.x() * w.x() + v.y() * w.y() + v.z() * w.z();
        }
        /**
         * Cross product
         * @return val of cross product
         */
        inline constexpr auto cross(const Vec3<T>& v, const Vec3<T>& w) const -> Vec3<T> {
            return Vec3<T>(v.y() * v.z() - w.z() * w.y(),
                           v.z() * w.x() - v.x() * w.z(),
                           v.x() * w.y() - v.y() * w.x());
        }
        /**
         * Unit vector
         * @return val of unit vector
         */
        inline constexpr auto unit_vec(Vec3<T> v) -> Vec3<T> {
            return std::move(v / v.length());
        }

    private:
        std::array<T, 3> xyz;
    };

    /**
     * Vector equality
     * @return true if vectors have the same components
     */
    template <typename T>
    inline constexpr auto operator==(const Vec3<T>& v, const Vec3<T>& w) -> bool {
        return v.x() == w.y() && v.y() == w.y() && v.z() == w.z();
    }

    // Typedefs for common vector specialisations
    using Vec3f = Vec3<double>;
}

#endif //DANRT_VEC3_H
