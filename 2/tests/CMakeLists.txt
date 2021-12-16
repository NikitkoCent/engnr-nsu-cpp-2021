add_executable(calculator_tests
        tests.cpp
        )
#
#target_include_directories(calculator_tests
#        PRIVATE "../src/commands"
#        )

target_link_libraries(calculator_tests
        gtest
        gmock_main
        )