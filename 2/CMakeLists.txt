cmake_minimum_required(VERSION 3.20)
project(Cpp_Lab2)
set(CMAKE_CXX_STANDARD 17)
add_executable(Calculator main.cpp StackCalc.cpp StackCalc.h)
if (MSVC)
    target_compile_options(Calculator
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(Calculator
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()