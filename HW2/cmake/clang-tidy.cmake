#clang-tidy
find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)

	add_custom_target(
	tidy
	COMMAND clang-tidy ${CMAKE_SOURCE_DIR}/src/*.cpp -header-filter=.* -- -std=c++17 -O2 -I ${CMAKE_SOURCE_DIR}/inc
	)
endif()