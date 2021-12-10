add_executable(calculator
        main.cpp
        )

target_include_directories(calculator
        PRIVATE "../commands"
        )

target_link_libraries(calculator
        commands
        )

if (MSVC)
    target_compile_options(calculator
            PRIVATE /W4
            PRIVATE /WX
            )
else()
    target_compile_options(calculator
            PRIVATE -Wall
            PRIVATE -pedantic
            PRIVATE -Werror
            )
endif()