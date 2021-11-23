cmake_minimum_required(VERSION 3.8)
project(Lab_2 LANGUAGES CXX)

set(INCLUDE ${PROJECT_SOURCE_DIR}/inc)

#GOOGLE TEST
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#END OF GOOGLE TEST

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})

add_subdirectory(${PROJECT_SOURCE_DIR}/src/calc_lib)
target_link_libraries(${PROJECT_NAME} calculator_library)

if (MSVC)
    target_compile_options(${PROJECT_NAME}
        PRIVATE /W4          # warnings level
        PRIVATE /WX          # treat all warnings as errors
    )
else()
    target_compile_options(${PROJECT_NAME}
        PRIVATE -Wall        # basic set of warnings
        #PRIVATE -pedantic    # modern C++ inspections
        PRIVATE -Werror      # treat all warnings as errors
    )
endif()

#TESTING
enable_testing()

add_executable(
    calc_test
    ./tests/calculator_tests.cpp
    ${INCLUDE}
)
target_link_libraries(
    calc_test
    gtest_main
    calculator_library
)

include(GoogleTest)
gtest_discover_tests(calc_test)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)