cmake_minimum_required(VERSION 3.20)
project(stack_calculator)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest)
add_subdirectory(lib/SafeInt)

include_directories(lib/googletest/googletest/include)
include_directories(lib/SafeInt/Test)

add_executable(stack_calculator main.cpp Calculator.cpp Calculator.h command_processing.h Calculator.cpp Calculator.h command_processing.h)
target_link_libraries(stack_calculator gtest gtest_main)