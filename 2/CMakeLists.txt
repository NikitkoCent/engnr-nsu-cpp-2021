project(cpp_labs)

add_compile_options(-Wall -pedantic)

include_directories(lib/SafeInt/)

target_sources(cpp_labs_2 PRIVATE
        main.cpp
        StackCalculator.cpp
        StackCalculator.hpp
        CommandFactory.h
        Commands.h)

target_sources(cpp_labs_2_test PRIVATE
        test.cpp
        StackCalculator.cpp
        StackCalculator.hpp
        CommandFactory.h
        Commands.h)

target_link_libraries(cpp_labs_2_test gtest gtest_main)
