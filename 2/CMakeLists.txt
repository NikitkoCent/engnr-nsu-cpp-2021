cmake_minimum_required(VERSION 3.20)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/safeint/)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_executable(cpp_lab_2
        main.cpp
        Commands.cpp
        Commands.h
        Errors.h
        Operations.cpp
        Operations.h)

add_executable(cpp_lab_2_test
        Tests.cpp
        Commands.cpp
        Commands.h
        Errors.h
        Operations.cpp
        Operations.h)

target_link_libraries(cpp_lab_2_test gtest gtest_main)

enable_testing()

add_test(google_test cpp_lab_2_test)

if (MSVC)
    target_compile_options(cpp_lab_2
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
    target_compile_options(cpp_lab_2_test
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else ()
    target_compile_options(cpp_lab_2
            PRIVATE -Wall        # basic set of warnings
            #            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
    target_compile_options(cpp_lab_2_test
            PRIVATE -Wall        # basic set of warnings
            #            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif ()