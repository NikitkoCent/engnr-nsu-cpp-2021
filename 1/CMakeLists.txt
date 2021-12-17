# CMakeList.txt : CMake project for Lab_2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Lab1")

# Add source to this project's executable.
add_executable (Lab1 "Lab1.cpp" "Lab1.h" "Functions.cpp")

# TODO: Add tests and install targets if needed.
if (MSVC)
    target_compile_options(lab1
        PRIVATE /W4          # warnings level
        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options(lab1
        PRIVATE -Wall        # basic set of warnings
        PRIVATE -pedantic    # modern C++ inspections
        PRIVATE -Werror      # treat all warnings as errors
    )
endif()
