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

#enable_testing()
#add_test(google_test calculator_tests "../../tests/test_files/HARD_TEST")