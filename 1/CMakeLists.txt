cmake_minimum_required(VERSION 3.20)
project(hash1)
set(CMAKE_CXX_STANDARD 17)
add_executable(1 main.cpp hash.hpp hash.cpp)
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