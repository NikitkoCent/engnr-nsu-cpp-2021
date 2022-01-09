# CMakeList.txt : CMake project for Lab_2_fabric, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.20)

project ("Lab_2_fabric")

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)
add_subdirectory(SafeInt)
add_subdirectory(tests)

enable_testing()

include_directories(googletest/googletest/include)
include_directories(SafeInt/Test)

add_library(calculator_lib STATIC Lab_2.h Functions.cpp Fabric.cpp Fabric.h Operations.cpp Operations.h Fabric.h Exceptions.cpp)

add_executable(Lab_2_fabric Lab_2.cpp)

target_link_libraries(Lab_2_fabric calc_functions)

# TODO: Add tests and install targets if needed.
if (MSVC)
    target_compile_options( Lab_2_fabric
        PRIVATE /W4          # warnings level
#        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options( Lab_2_fabric
           PRIVATE -Wall        # basic set of warnings
    )
endif()


