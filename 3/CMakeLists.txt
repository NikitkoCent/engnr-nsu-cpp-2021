cmake_minimum_required(VERSION 3.0.0)
project(Lab_3 VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDE ${PROJECT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME} main.cpp)

if (MSVC)
    target_compile_options(${PROJECT_NAME}
        PRIVATE /W4          # warnings level
        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options(${PROJECT_NAME}
        PRIVATE -Wall        # basic set of warnings
        PRIVATE -pedantic    # modern C++ inspections
        PRIVATE -Werror      # treat all warnings as errors
    )
endif()


target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})
