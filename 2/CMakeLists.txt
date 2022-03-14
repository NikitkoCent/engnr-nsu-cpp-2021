cmake_minimum_required(VERSION 3.17)

project(StackCalc)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/googletest)

add_subdirectory(libs/SafeInt)

add_subdirectory(test)

enable_testing()

add_library(
	StackCalcLib
	Errors.h
	MemStack.h MemStack.cpp
	Command.h Command.cpp
	PeekCommand.h PeekCommand.cpp
	Calculator.h Calculator.cpp
)

target_include_directories(
	StackCalcLib
	PUBLIC "libs/SafeInt"
)

add_executable(
	StackCalc
	Main.cpp
)

target_link_libraries(
	StackCalc
	StackCalcLib
)

if (MSVC)
	target_compile_options(
		StackCalc
		PRIVATE /W4          # warnings level
	)
else()
	target_compile_options(
		StackCalc
		PRIVATE -Wall        # basic set of warnings
	)
endif()