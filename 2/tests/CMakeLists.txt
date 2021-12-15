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

enable_testing()
add_test(EXAMPLE_TEST calculator_tests)
add_test(EASY_TEST calculator_tests)
add_test(HARD_TEST calculator_tests)
add_test(COMMAND_LINE_TEST calculator_tests)