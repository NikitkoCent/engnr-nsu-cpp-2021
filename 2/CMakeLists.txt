cmake_minimum_required(VERSION 3.20)
project(2lab)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/googletest)
add_subdirectory(libs/SafeInt)

include_directories(libs/googletest/googletest/include)
include_directories(libs/SafeInt/Test)

add_executable(2lab main.cpp Calculator.h command_processing.h)
target_link_libraries(2lab)

