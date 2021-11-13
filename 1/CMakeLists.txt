cmake_minimum_required(VERSION 3.20)
project(Lab1)
set(CMAKE_CXX_STANDARD 17)
add_executable(hasher main.cpp hashFunctions.cpp hashFunctions.h)
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
