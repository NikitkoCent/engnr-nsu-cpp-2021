cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

## googletest
#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)
###

add_executable(hasher
		main.cpp
        HashCalc.h
        HashCalc.cpp)

if (MSVC)
	target_compile_options(hasher
			PRIVATE /W4          # warnings level
			PRIVATE /WX          # treat all warnings as errors
			)
else()
	target_compile_options(hasher
			PRIVATE -Wall        # basic set of warnings
			PRIVATE -pedantic    # modern C++ inspections
			PRIVATE -Werror      # treat all warnings as errors
			)
endif()
