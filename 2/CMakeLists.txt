cmake_minimum_required(VERSION 3.19)
project(2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
add_subdirectory(SafeInt)
add_subdirectory(tests)

enable_testing()

include_directories(googletest/googletest/include)
include_directories(SafeInt/Test)

add_library(calculator_lib STATIC calc.h Exeptions.h Exeptions.cpp calc.cpp)

add_executable(2 main.cpp)

target_link_libraries(2 calculator_lib)