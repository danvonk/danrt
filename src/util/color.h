//
// Created by dan on 13/10/2021.
//

#ifndef DANRT_COLOR_H
#define DANRT_COLOR_H

#include <iostream>
#include "vec3.h"

namespace danrt {
    auto write_color(std::ostream &out, Vec3f color) -> void;
}

#endif //DANRT_COLOR_H
