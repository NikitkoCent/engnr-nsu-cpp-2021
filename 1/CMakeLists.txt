cmake_minimum_required(VERSION 3.8)
project(Lab_1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_1 main.cpp Hasher.cpp)
target_include_directories(Lab_1 PRIVATE ${PROJECT_DIR}/inc)