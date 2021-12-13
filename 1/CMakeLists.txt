cmake_minimum_required(VERSION 3.20)

project(Hasher CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hasher
		main.cpp
		hash_funcs.h
		hash_funcs.cpp
		)

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
