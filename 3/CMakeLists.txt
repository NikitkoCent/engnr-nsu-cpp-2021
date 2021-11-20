cmake_minimum_required(VERSION 3.0.0)
project(Lab_3 VERSION 0.1.0)

set(INCLUDE ${PROJECT_SOURCE_DIR}/inc)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})
