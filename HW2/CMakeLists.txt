cmake_minimum_required(VERSION 3.16)
project(TriangleIntersection)

add_executable(main TriangleIntersaction.cpp)
#add_executable(driver driver.cpp)

include_directories(inc src)
add_compile_options(-std=c++17 -O2)