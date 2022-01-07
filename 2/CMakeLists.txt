cmake_minimum_required(VERSION 3.17)
project(Calc)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/calculator)
add_subdirectory(src/commands)

enable_testing()
add_subdirectory(libs/SafeInt)
add_subdirectory(libs/googletest)
add_subdirectory(tests)

if (MSVC)
    target_compile_options(calc
            PRIVATE /W4
            #            PRIVATE /WX
            )
else()
    target_compile_options(calc
            PRIVATE -Wall
            PRIVATE -pedantic
            )
endif()