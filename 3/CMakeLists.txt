cmake_minimum_required(VERSION 3.20)
project(DSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")

add_executable(DSC main.cpp SafeQueue.h ThreadPool.cpp ThreadPool.h SafeQueue.cpp)

if (MSVC)
    target_compile_options(DSC
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            PRIVATE /EHsc
            )
else()
    set(CMAKE_CXX_FLAGS "-pthread")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    target_compile_options(DSC
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -Werror      # treat all warnings as errors
            PRIVATE -pedantic
            )
endif()


target_sources(DSC PRIVATE
               SafeQueue.h
               SafeQueue.h
               ThreadPool.h
               ThreadPool.cpp)
