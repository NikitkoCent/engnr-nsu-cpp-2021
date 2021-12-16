add_executable(calculator_tests
        tests.cpp
        )

target_link_libraries(calculator_tests
        gtest
        gmock_main
        )

enable_testing()
#add_test(calculator_tests)