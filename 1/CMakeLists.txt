cmake_minimum_required(VERSION 3.16)
project(1)

set(CMAKE_CXX_STANDARD 14)

add_executable(1 main.cpp funk_adl_sum.cpp funk_adl_sum.h)


if (MSVC)
    target_compile_options(1
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(1
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()
