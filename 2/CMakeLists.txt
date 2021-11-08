cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -pedantic)

include_directories(lib/SafeInt/)

## googletest
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
###

add_executable(cpp_labs_2
		main.cpp
                StackCalculator.cpp
                StackCalculator.hpp
                CommandFactory.h
                Commands.h)

add_executable(cpp_labs_2_test
		test.cpp
                StackCalculator.cpp
                StackCalculator.hpp
                CommandFactory.h
                Commands.h)

target_link_libraries(cpp_labs_2_test gtest gtest_main)

add_test(google_test cpp_labs_2_test)
set_tests_properties(google_test PROPERTIES PASS_REGULAR_EXPRESSION "[  PASSED  ]")
