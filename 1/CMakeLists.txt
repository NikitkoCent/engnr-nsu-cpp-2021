cmake_minimum_required(VERSION 3.17)
project(untitled15)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    target_compile_options(<target>
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(<target>
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()

add_executable(hasher main.cpp Hash.cpp Hash.h)