//
// Created by dan on 14/10/2021.
//

#ifndef DANRT_HITTABLE_H
#define DANRT_HITTABLE_H

#include "ray.h"

namespace danrt {
    struct HitRecord {
        Vec3f p;
        Vec3f n;
        double t;
    };

    template <typename T>
    concept Hittable = requires(T h,
            const Ray& r, double t_min, double t_max,
            HitRecord& hr) {
        { h.hit(r, t_min, t_max, hr) } -> std::same_as<bool>;
    };

}

#endif //DANRT_HITTABLE_H
