# CMakeList.txt : CMake project for Lab_2_fabric, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Lab_2_fabric")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(SafeInt)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
add_executable(Lab_2_fabric "Lab_2.cpp" "Lab_2.h" "Functions.cpp" "Fabric.cpp" "Fabric.h" "Operations.cpp" "Operations.h" "Fabric.h" "Exceptions.cpp" )
add_executable(Tests_lab tests.cpp
               Lab_2.h 
               Functions.cpp
               Fabric.cpp
               Fabric.h
               Operations.cpp 
               Operations.h
               Fabric.h  
               Exceptions.cpp )

target_link_libraries(Tests_lab
                    gtest 
                    gtest_main)

enable_testing()
add_test(google_test Tests_lab)
if (MSVC)
    target_compile_options(Lab_2_fabric
            PRIVATE /W4          # warnings level
            )
    target_compile_options(Tests_lab
            PRIVATE /W4          # warnings level
            )
else ()
    target_compile_options(Lab_2_fabric
            PRIVATE -Wall        # basic set of warnings
            )
    target_compile_options(Tests_lab
            PRIVATE -Wall        # basic set of warnings
            )
endif () 
