cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest)
add_subdirectory(lib/safeint)
add_subdirectory(tests)
enable_testing()
include_directories(googletest/googletest/include)
include_directories(SafeInt/Test)

add_library(commands STATIC
        Commands.cpp
        Commands.h
        Errors.h
        Operations.h
        Operations.cpp)

add_executable(2 main.cpp)

target_link_libraries(2 calc)