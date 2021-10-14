#include <iostream>
#include "util/vec3.h"
#include "util/color.h"
#include "util/ray.h"

using namespace danrt;

auto hit_sphere(const Vec3f& cent, double rad, const Ray& ray) -> bool {
    const auto origin_to_centre = ray.origin() - cent;
    const auto a = dot(ray.dir(), ray.dir());
    const auto b = 2.0 * dot(origin_to_centre, ray.dir());
    const auto c = dot(origin_to_centre, origin_to_centre) - rad * rad;
    const auto discr = b * b - 4 * a * c;
    return (discr > 0);
}
auto ray_color(const Ray& ray) -> Vec3f {
    if (hit_sphere(Vec3f(0.0, 0.0, -1.0), 0.5, ray)) {
        return Vec3f(1.0, 0.0, 0.0);
    }
    const auto unit_dir = unit_vec<double>(ray.dir());
    const auto t = 0.5 * (unit_dir.y() + 1.0);

    return (1.0 - t) * Vec3f(1.0, 1.0, 1.0) + t * Vec3f(0.5, 0.7, 1.0);
}



int main() {
    // Camera
    const auto aspect_ratio = 16.0 / 9.0;
    const auto image_width = 1920;
    const auto image_height = static_cast<int>(image_width / aspect_ratio);

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Vec3f(0.0, 0.0, 0.0);
    auto horiz = Vec3f(viewport_width, 0.0, 0.0);
    auto vert = Vec3f(0.0, viewport_height, 0.0);
    auto lower_left = origin - (horiz / 2.0) - (vert / 2.0) - Vec3f(0.0, 0.0, focal_length);

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

    Vec3f vec(1.0, 2.0, 3.0);

    return 0;
}
