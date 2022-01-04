cmake_minimum_required(VERSION 3.16.0)
project(Lab_3 VERSION 1.0.0)

add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

if (MSVC)
    target_compile_options(${PROJECT_NAME}
        PRIVATE /W4          # warnings level
    )
else()
    target_compile_options(${PROJECT_NAME}
        PRIVATE -Wall        # basic set of warnings
        PRIVATE -pedantic    # modern C++ inspections
    )
endif()

enable_testing()

add_executable(
    LinkedList_tests
    LinkedList_tests.cpp
)
target_link_libraries(
    LinkedList_tests
    gtest_main
)

if(MSVC)
    target_compile_options(LinkedList_tests PUBLIC
    /fsanitize=address)

    target_link_options(LinkedList_tests PUBLIC  
    /fsanitize=address)

endif()

if (NOT MSVC)
    target_compile_options(LinkedList_tests PUBLIC  
    -fno-omit-frame-pointer -fsanitize=address)

    target_link_options(LinkedList_tests PUBLIC  
    -fno-omit-frame-pointer -fsanitize=address)
endif()

include(GoogleTest)
gtest_discover_tests(LinkedList_tests)

set_target_properties(LinkedList_tests PROPERTIES
    CXX_STANDARD 17
    CXX_REQUIRED ON
    CXX_EXTENSIONS OFF
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_REQUIRED ON
    CXX_EXTENSIONS OFF
)