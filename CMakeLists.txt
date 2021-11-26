cmake_minimum_required(VERSION 3.20)
project(danrt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)

add_executable(danrt src/main.cpp
        src/util/vec3.h src/util/color.h
        src/util/color.cpp src/util/ray.cpp
        src/util/ray.h src/util/hittable.h src/util/sphere.h src/util/sphere.cpp)
