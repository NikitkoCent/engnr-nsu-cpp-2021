cmake_minimum_required(VERSION 3.10)
project(stack_calc)
add_subdirectory(SafeInt)
add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 14)

add_executable (
        stack_calc
        main.cpp
        Helper.h
        Helper.cpp
        Command.h
        Command.cpp
        Context.h
        Context.cpp
        CommandCreator.cpp
        AppException.cpp
)

if (MSVC)
    target_compile_options(stack_calc
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(stack_calc
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()
