#include <iostream>
#include "util/vec3.h"
#include "util/color.h"

using namespace danrt;

int main() {
    // Image
    const auto image_width = 256;
    const auto image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // render row-by-row
    for (auto j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << '\n';
        for (auto i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            Vec3f pixel(r,g,b);
            write_color(std::cout, pixel);
        }
    }
    std::cerr << "\nDone.";

    Vec3f vec(1.0, 2.0, 3.0);

    return 0;
}
