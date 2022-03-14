cmake_minimum_required(VERSION 3.20)

project(css_task4)

set(CMAKE_CXX_STANDARD 17)

add_executable(
	css_task4
	Main.cpp
	LaunchManager.h LaunchManager.cpp
	TaskQueue.h TaskQueue.cpp
	ThreadPool.h ThreadPool.cpp
	UserInterface.h UserInterface.cpp
	WorkManager.h WorkManager.cpp
)

target_compile_features(css_task4 PRIVATE cxx_std_17)

if (MSVC)
	target_compile_options(
			css_task4 
			PRIVATE /W4          # warnings level
			PRIVATE /WX          # treat all warnings as errors
	)
else()
	set(CMAKE_CXX_FLAGS "-pthread")
	target_compile_options(
			css_task4 
			PRIVATE -Wall        # basic set of warnings
			PRIVATE -pedantic    # modern C++ inspections
			PRIVATE -Werror      # treat all warnings as errors
	)
endif()
