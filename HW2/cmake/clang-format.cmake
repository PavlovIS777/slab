if(NOT CLANG_FORMAT)
    find_program(CLANG_FORMAT "clang-format")
endif()

if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/inc/*.h
        ${PROJECT_SOURCE_DIR}/tests/*.h
        ${PROJECT_SOURCE_DIR}/tests/*.cpp
    )

    add_custom_target(
        format
        COMMAND clang-format -i -style=file ${ALL_CXX_SOURCE_FILES}
    )
endif()