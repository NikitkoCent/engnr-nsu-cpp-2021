cmake_minimum_required(VERSION 3.17)

project(cpp_task2_StackCalk_Test)

add_executable(
	cpp_task2_StackCalk_Test
	Test.cpp
)

target_link_libraries(
	cpp_task2_StackCalk_Test
	cpp_task2_StackCalk_Lib
	gtest
	gmock_main
)

target_include_directories(
	cpp_task2_StackCalk_Test
	PUBLIC "../lib/googleTest/googletest/include"
	PUBLIC "../"
)

enable_testing()

add_test(NAME googletest COMMAND cpp_task2_StackCalk_Test)