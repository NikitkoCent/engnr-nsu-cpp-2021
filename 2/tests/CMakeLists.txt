add_executable(calculator_tests
        tests.cpp
        )

target_link_libraries(calculator_tests
        calculator_lib
        gtest
        gmock_main
        )

target_include_directories(calculator_tests
        PRIVATE "../libs/googletest/googletest/include"
        )

enable_testing()
add_test(NAME googletest COMMAND calculator_tests)