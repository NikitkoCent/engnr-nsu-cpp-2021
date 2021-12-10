cmake_minimum_required(VERSION 3.20)
project(Cpp_Lab2)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/calculator)
add_subdirectory(src/commands)

enable_testing()

add_subdirectory(libs/googletest)
add_subdirectory(libs/SafeInt)
add_subdirectory(tests)

if (MSVC)
    target_compile_options(calculator
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(calculator
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()
