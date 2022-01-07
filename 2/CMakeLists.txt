# CMakeList.txt : CMake project for Lab_2_fabric, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Lab_2_fabric")

set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (Lab_2_fabric "Lab_2.cpp" "Lab_2.h" "Functions.cpp" "Fabric.cpp" "Exceptions.cpp" "Operation.cpp")

add_subdirectory(SafeInt)
add_subdirectory(googletest)
#add_subdirectory(tests)
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
