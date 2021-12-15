cmake_minimum_required(VERSION 3.20)

project(stack_calc)

set(CMAKE_CXX_STANDARD 14)

include_directories(SafeInt/)
add_subdirectory(googletest)

add_executable(stack_calc Excpetions.cpp Excpetions.h)
add_executable(stack_calc_test)

if (MSVC)
    target_compile_options(stack_calc
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
    target_compile_options(stack_calc_test
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(stack_calc
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -Werror      # treat all warnings as errors
            )
    target_compile_options(stack_calc_test
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()



target_sources(stack_calc PRIVATE
               main.cpp
               Actions.cpp
               Actions.h
        SpecificActionCreator.h
        SpecificActionCreator.cpp
               StackCalc.cpp
               StackCalc.h
               Excpetions.cpp
               Excpetions.h)

target_sources(stack_calc_test PRIVATE
               test.cpp
               Actions.cpp
               Actions.h
        SpecificActionCreator.h
        SpecificActionCreator.cpp
               StackCalc.cpp
               StackCalc.h
               Excpetions.cpp
               Excpetions.h)

target_link_libraries(stack_calc_test gtest gtest_main)