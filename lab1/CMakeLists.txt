cmake_minimum_required(VERSION 3.19)
project(Lab1)
set(CMAKE_CXX_STANDARD 14)
add_executable(hasher main.cpp Hash.cpp Hash.h)
if (MSVC)
    target_compile_options(hasher
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(hasher
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()