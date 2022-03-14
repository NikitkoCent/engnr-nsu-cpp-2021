cmake_minimum_required(VERSION 3.20)

project(cpp_task2_StackCalk)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googleTest)

add_subdirectory(lib/SafeInt)

add_subdirectory(Tests)

enable_testing()

add_library(
	cpp_task2_StackCalk_Lib
	Memory.h Memory.cpp
	MError.h
	Operation.h Operation.cpp
	OperationHandler.h OperationHandler.cpp
	StackCalculator.h StackCalculator.cpp
)

target_include_directories(
	cpp_task2_StackCalk_Lib
	PUBLIC "lib/SafeInt"
)

add_executable(cpp_task2_StackCalk Main.cpp)

target_link_libraries(cpp_task2_StackCalk cpp_task2_StackCalk_Lib)