cmake_minimum_required(VERSION 3.16)
project(LFU)

include_directories(inc src testSys/idealCache)
add_compile_options(-std=c++17 -O2)

add_executable(cachelfu main.cpp)
add_executable(driver driver.cpp)
add_executable(idcache testSys/idealCache/iCache.cpp)