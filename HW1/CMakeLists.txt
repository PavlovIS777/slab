cmake_minimum_required(VERSION 3.16)
project(LFU)

include_directories(inc src testSys/idealCache testSys/unittests)
add_compile_options(-std=c++17 -O2)

add_executable(cachelfu driver_LFU_Cache.cpp)
add_executable(idcache driver_Ideal_Cache.cpp)
add_executable(unittest testSys/unittests/unittest.cpp)