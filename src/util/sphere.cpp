//
// Created by dan on 14/10/2021.
//

#include <cmath>
#include "sphere.h"

#include "hittable.h"
#include "ray.h"

using namespace danrt;

auto Sphere::hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const -> bool {
    auto origin_to_centre = r.origin() - center;
    auto a = r.dir().length_squared();
    auto half_b = dot(origin_to_centre, r.dir());
    auto c = origin_to_centre.length_squared() - radius * radius;

    const auto discr = half_b * half_b - a * c;
    if (discr < 0) {
        return false;
    }

    const auto discr_sqrt = std::sqrt(discr);
    // find nearest root
    auto root = (-half_b - discr_sqrt) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + discr_sqrt) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.n = (rec.p - center) / radius;
    return true;
}