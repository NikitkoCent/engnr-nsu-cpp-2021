cmake_minimum_required(VERSION 3.17)

project(StackCalcTest)

add_executable(
	StackCalcTest
	tests.cpp
)

target_link_libraries(
	StackCalcTest
	StackCalcLib
	gtest
	gmock_main
)

target_include_directories(
	StackCalcTest
	PUBLIC "../libs/googletest/googletest/include"
	PUBLIC "../"
)

enable_testing()

add_test(NAME googletest COMMAND StackCalcTest)