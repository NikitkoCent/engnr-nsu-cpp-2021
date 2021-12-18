cmake_minimum_required(VERSION 3.20)
project(.)
set(CMAKE_CXX_STANDARD 17)

add_executable(. main.cpp hash.hpp hash.cpp)
if (MSVC)
    target_compile_options(.
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(.
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()