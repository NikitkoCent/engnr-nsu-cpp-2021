cmake_minimum_required(VERSION 3.20)
project(Cpp_Lab2)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/calculator)
add_subdirectory(src/commands)

enable_testing()

add_subdirectory(libs/googletest)
add_subdirectory(libs/SafeInt)
add_subdirectory(tests)

