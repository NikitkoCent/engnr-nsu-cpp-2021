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
add_test(NAME google_test COMMAND calculator_tests)