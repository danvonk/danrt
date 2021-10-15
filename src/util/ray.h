//
// Created by dan on 13/10/2021.
//

#ifndef DANRT_RAY_H
#define DANRT_RAY_H

#include "vec3.h"

namespace danrt {
    class Ray {
    public:
        Ray(const Vec3f& o, const Vec3f& d)
        : origin_(o)
        , dir_(d)
        {}

        [[nodiscard]] auto origin() const-> Vec3f {
            return origin_;
        }

        [[nodiscard]] auto dir() const -> Vec3f {
            return dir_;
        }

        /**
         * Returns a point along the ray
         * @param t scalar multiple of dir
         * @return point along ray
         */
        inline auto at(double t) const -> Vec3f {
            return origin_ + t * dir_;
        }


    private:
        Vec3f origin_;
        Vec3f dir_;
    };
}


#endif //DANRT_RAY_H
