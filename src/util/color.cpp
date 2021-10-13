//
// Created by dan on 13/10/2021.
//
#include "color.h"

using namespace danrt;

auto danrt::write_color(std::ostream& out, Vec3f color) -> void {
    out << static_cast<int>(255.999 * color.x()) << ' '
        << static_cast<int>(255.999 * color.y()) << ' '
        << static_cast<int>(255.999 * color.z()) << '\n';
}
