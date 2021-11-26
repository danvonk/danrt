#include <iostream>
#include "util/vec3.h"
#include "util/color.h"
#include "util/ray.h"
#include "util/sphere.h"

using namespace danrt;

auto hit_sphere(const Vec3f& cent, double rad, const Ray& ray) -> double {
    const auto origin_to_centre = ray.origin() - cent;
    const auto a = dot(ray.dir(), ray.dir());
    const auto half_b = dot(origin_to_centre, ray.dir());
    const auto c = origin_to_centre.length_squared() - rad * rad;
    const auto discr = half_b * half_b - 4 * a * c;
    if (discr < 0) {
        return -1.0;
    } else {
        return (-half_b - std::sqrt(discr)) / (2.0 * a);
    }
}
auto ray_color(const Ray& ray) -> Vec3f {
    auto t = hit_sphere(Vec3f(0.0, 0.0, -1.0), 0.5, ray);
    if (t > 0.0) {
        const auto n = unit_vec(ray.at(t) - Vec3f(0,0,-1));
        return 0.5 * Vec3f(n.x() + 1, n.y() + 1, n.z() + 1);
    }
    const auto unit_dir = unit_vec<double>(ray.dir());
    t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0 - t) * Vec3f(1.0, 1.0, 1.0) + t * Vec3f(0.5, 0.7, 1.0);
}



int main() {
    // Camera
    const auto aspect_ratio = 16.0 / 9.0;
    const auto image_width = 640;
    const auto image_height = static_cast<int>(image_width / aspect_ratio);

    const auto viewport_height = 2.0;
    const auto viewport_width = aspect_ratio * viewport_height;
    const auto focal_length = 1.0;

    const auto origin = Vec3f(0.0, 0.0, 0.0);
    const auto horiz = Vec3f(viewport_width, 0.0, 0.0);
    const auto vert = Vec3f(0.0, viewport_height, 0.0);
    const auto lower_left = origin - (horiz / 2.0) - (vert / 2.0) - Vec3f(0.0, 0.0, focal_length);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // render row-by-row
    for (auto j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << '\n';
        for (auto i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);

            Ray r(origin, lower_left + u * horiz + v * vert - origin);
            const auto pixel = ray_color(r);
            write_color(std::cout, pixel);
        }
    }
    std::cerr << "\nDone.";

    return 0;
}
