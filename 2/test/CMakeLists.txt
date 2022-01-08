cmake_minimum_required(VERSION 3.17)
project(ct)
add_executable(ct
        tests.cpp
        )

target_link_libraries(ct
        cl
        gtest
        gmock_main
        )

target_include_directories(ct
        PRIVATE "../googletest/googletest/include"
        )

enable_testing()
add_test(NAME googletest COMMAND cl)
