cmake_minimum_required(VERSION 3.20)
project(css_task4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(css_task4 Program.cpp Task.h UserInterface.cpp UserInterface.h Worker.cpp Worker.h WorkerPool.cpp WorkerPool.h WorkerResult.cpp WorkerResult.h)

target_compile_features(css_task4 PRIVATE cxx_std_17)

if (MSVC)
	target_compile_options(css_task4 
			PRIVATE /W4          # warnings level
			PRIVATE /WX          # treat all warnings as errors
			)
else()
	target_compile_options(css_task4 
			PRIVATE -Wall        # basic set of warnings
			PRIVATE -pedantic    # modern C++ inspections
			PRIVATE -Werror      # treat all warnings as errors
			)
endif()
