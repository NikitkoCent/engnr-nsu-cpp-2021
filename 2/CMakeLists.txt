cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(SafeInt)
add_executable(2  main.cpp exception.hpp calculator.cpp calculator.hpp CommandPreprocessing.cpp tests.cpp)
#target_link_libraries(2
#        calculator_lib
#        gtest
#        gmock_main
#        )
enable_testing()
add_test(NAME googletest COMMAND 2)