cmake_minimum_required(VERSION 3.17)
project(untitled15)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-v)
add_link_options(-v)

add_executable(hasher main.cpp Hash.cpp Hash.h)