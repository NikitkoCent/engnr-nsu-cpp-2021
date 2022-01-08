cmake_minimum_required(VERSION 3.17)
project(2)

set(CMAKE_CXX_STANDARD 14)



add_subdirectory(googletest)
add_subdirectory(SafeInt)
add_subdirectory(test)

enable_testing()

include_directories(googletest/googletest/include)
include_directories(SafeInt/Test)

add_library(cl STATIC Calc.cpp Calc.h)

add_executable(2 main.cpp)

target_link_libraries(2 cl)