//
// Created by dan on 14/10/2021.
//

#ifndef DANRT_SPHERE_H
#define DANRT_SPHERE_H

#include "hittable.h"

namespace danrt {
    class Sphere {
    public:
        Sphere(Vec3f c, double r)
            : center(c)
            , radius(r)
        {}

        auto hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const -> bool;
    private:
        Vec3f center;
        double radius;
    };
}

#endif //DANRT_SPHERE_H
