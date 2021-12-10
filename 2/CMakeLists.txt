cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib/SafeInt/)

## googletest
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
###

add_executable(cpp_labs_2
		main.cpp
                StackCalculator.cpp
                StackCalculator.hpp
                CommandFactory.h
				CommandFactory.cpp
                Commands.h)

add_executable(cpp_labs_2_test
		test.cpp
                StackCalculator.cpp
                StackCalculator.hpp
                CommandFactory.h
				CommandFactory.cpp
                Commands.h)

target_link_libraries(cpp_labs_2_test gtest gtest_main)

enable_testing()

add_test(google_test cpp_labs_2_test)

if (MSVC)
	target_compile_options(cpp_labs_2
			PRIVATE /W4          # warnings level
			PRIVATE /WX          # treat all warnings as errors
			)
	target_compile_options(cpp_labs_2_test
			PRIVATE /W4          # warnings level
			PRIVATE /WX          # treat all warnings as errors
			)
else()
	target_compile_options(cpp_labs_2
			PRIVATE -Wall        # basic set of warnings
			PRIVATE -pedantic    # modern C++ inspections
			PRIVATE -Werror      # treat all warnings as errors
			)
	target_compile_options(cpp_labs_2_test
			PRIVATE -Wall        # basic set of warnings
			PRIVATE -pedantic    # modern C++ inspections
			PRIVATE -Werror      # treat all warnings as errors
			)
endif()
