cmake_minimum_required(VERSION 3.20)
project(danrt)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

add_executable(danrt src/main.cpp src/util/vec3.h src/util/color.h src/util/color.cpp src/util/ray.cpp src/util/ray.h)
