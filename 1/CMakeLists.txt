project(cpp_labs)

cmake_minimum_required(VERSION 3.21)

add_compile_options(-Wall -pedantic)

target_executable(cpp_labs_1
        main.cpp
        HashCalc.h
        HashCalc.cpp)
