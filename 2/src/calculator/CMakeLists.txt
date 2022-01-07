add_executable(calc main.cpp)

target_include_directories(calc PRIVATE "../commands")

target_link_libraries(calc commands)
