cmake_minimum_required(VERSION 3.17)
project(StackCalc)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs/SafeInt/)

add_executable(
	StackCalc
	Main.cpp
	Errors.h
	MemStack.h MemStack.cpp
	Command.h Command.cpp
	PeekCommand.h PeekCommand.cpp
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