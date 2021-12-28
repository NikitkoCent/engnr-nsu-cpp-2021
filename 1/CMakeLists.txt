cmake_minimum_required(VERSION 3.20)
project(hasher)

set(CMAKE_CXX_STANDARD 17)

add_executable(hasher main.cpp)

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
