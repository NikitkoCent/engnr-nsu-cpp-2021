cmake_minimum_required(VERSION 3.10)
project(stack_calc)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -pedantic -Werror)

add_executable (
        stack_calc
        main.cpp
        Helper.h
        Helper.cpp
        Command.h
        Command.cpp
        Context.h
        Context.cpp
        CommandCreator.cpp
        AppException.cpp
)

