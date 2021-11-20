cmake_minimum_required(VERSION 3.8)
project(Lab_1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_1 main.cpp Hasher.cpp)

if (MSVC)
    target_compile_options(Lab_1
        PRIVATE /W4          # warnings level
        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options(Lab_1
        PRIVATE -Wall        # basic set of warnings
        PRIVATE -pedantic    # modern C++ inspections
        PRIVATE -Werror      # treat all warnings as errors
    )
endif()

target_include_directories(Lab_1 PUBLIC ${PROJECT_DIR}/inc)