cmake_minimum_required (VERSION 3.18)

project (Lab1)
set(CMAKE_CXX_STANDARD 17)
add_executable(worker main.cpp HashFunc.cpp HashFunc.h)

if (MSVC)
    target_compile_options(worker
        PRIVATE /W4          # warnings level
        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options(worker
        PRIVATE -Wall        # basic set of warnings
        PRIVATE -pedantic    # modern C++ inspections
        PRIVATE -Werror      # treat all warnings as errors
    )
endif()
