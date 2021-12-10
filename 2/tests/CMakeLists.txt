add_executable(calculator_tests
        tests_all.cpp
        )

target_include_directories(calculator_tests
        PRIVATE "../src/commands"
        )

target_link_libraries(calculator_tests
        commands
        gtest
        gmock_main
        )