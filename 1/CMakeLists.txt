cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -pedantic)

## googletest
#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)
###

add_executable(hasher
		main.cpp
        HashCalc.h
        HashCalc.cpp)
