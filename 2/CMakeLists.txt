cmake_minimum_required(VERSION 3.20)
project(cpp_task2_StackCalk)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/SafeInt/)

add_executable (
	cpp_task2_StackCalk
	Main.cpp
	Memory.cpp Memory.h
	MError.cpp MError.h
	Operation.cpp Operation.h
	OperationHandler.cpp OperationHandler.h
	StackCalculator.cpp StackCalculator.h
)

if (MSVC)
	target_compile_options (	
		cpp_task2_StackCalk 
			PRIVATE /W4          # warnings level
			# PRIVATE /WX          # treat all warnings as errors
	)
else()
	target_compile_options (
		cpp_task2_StackCalk 
			PRIVATE -Wall        # basic set of warnings
			# PRIVATE -pedantic    # modern C++ inspections
			# PRIVATE -Werror      # treat all warnings as errors
	)
endif()