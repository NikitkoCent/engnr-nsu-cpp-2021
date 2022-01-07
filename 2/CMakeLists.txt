cmake_minimum_required(VERSION 3.17)
project(calc CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/SafeInt)
add_executable(calc main.cpp src/Command.cpp src/Command.h)



#target_link_libraries(calc SafeInt)
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