add_executable(calculator
        main.cpp
        )

target_include_directories(calculator
        PRIVATE "../commands"
        )

target_link_libraries(calculator
        commands
        )
