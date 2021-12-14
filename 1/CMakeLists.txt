cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

add_executable(hasher
        main.cpp HashFunc.h HashFunc.cpp)

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