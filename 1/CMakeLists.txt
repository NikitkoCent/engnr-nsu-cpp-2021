cmake_minimum_required(VERSION 3.17)
project(HashCalc)

set(CMAKE_CXX_STANDARD 14)

add_executable(
	HashCalc
	Main.cpp
	Help.h Help.cpp
	Adler32.h Adler32.cpp
	Sum64.h Sum64.cpp
)

if (MSVC)
	target_compile_options(
		HashCalc
		PRIVATE /W4          # warnings level
		PRIVATE /WX          # treat all warnings as errors
	)
else()
	target_compile_options(
		HashCalc
		PRIVATE -Wall        # basic set of warnings
		PRIVATE -pedantic    # modern C++ inspections
		PRIVATE -Werror      # treat all warnings as errors
	)
endif()