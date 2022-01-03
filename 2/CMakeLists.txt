cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(SafeInt)
add_subdirectory(googletest)
add_executable(2  main.cpp exception.hpp calculator.cpp calculator.hpp CommandPreprocessing.cpp tests.cpp)
include_directories(googletest/googletest/include)
include_directories(SafeInt/Test)
target_link_libraries(2
        gtest
        gmock_main
        )
target_include_directories(2 PRIVATE "../libs/googletest/googletest/include")
enable_testing()
add_test(NAME googletest COMMAND 2)