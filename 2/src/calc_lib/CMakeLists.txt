cmake_minimum_required(VERSION 3.8)
project(calculator_library LANGUAGES CXX)

set(INCLUDE ${PROJECT_SOURCE_DIR}/../../inc/)
set(SRC_DIR ${PROJECT_SOURCE_DIR})

set(SOURCES ${SRC_DIR}/App.cpp
        ${SRC_DIR}/ArgParser.cpp
        ${SRC_DIR}/CalcCmds.cpp)

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)