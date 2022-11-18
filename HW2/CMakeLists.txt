cmake_minimum_required(VERSION 3.16)
project(TriangleIntersection)

include(./src/srcs.cmake)

include_directories(inc src)
add_compile_options(-std=c++17 -O0)
add_executable(main TriangleIntersaction.cpp ${all_cpp_files})

#clang-tidy
include(./cmake/clang-tidy.cmake)


#clang-format
include(./cmake/clang-format.cmake)

include_directories(tests)
add_compile_options(-g -fsanitize=address)
add_executable(test_libs ./tests/testMain.cpp ${all_cpp_files})
target_link_libraries(test_libs -fsanitize=address)
target_link_libraries(test_libs gtest gmock pthread)

add_executable(test_intersection ./tests/octTreeFunctionalTest.cpp ${all_cpp_files})
add_compile_options(-g -fsanitize=address)
target_link_libraries(test_intersection -fsanitize=address)