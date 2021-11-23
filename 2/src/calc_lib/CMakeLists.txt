cmake_minimum_required(VERSION 3.8)
project(calculator_library LANGUAGES CXX)

set(INCLUDE ${PROJECT_SOURCE_DIR}/../../inc/)
set(SRC_DIR ${PROJECT_SOURCE_DIR})

set(SOURCES ${SRC_DIR}/App.cpp
        ${SRC_DIR}/ArgParser.cpp
        ${SRC_DIR}/CalcCmds.cpp)

#ENABLING SAFEINT
option(SAFEINT_TESTS "compile the tests" OFF)
option(SAFEINT_NO_EXCEPTIONS "disable exceptions" OFF)
option(SAFEINT_SANITIZE "sanitize undefined behaviour" OFF)

add_library(SafeInt INTERFACE)
target_include_directories(SafeInt INTERFACE .)
install(FILES SafeInt.hpp DESTINATION include)
install(FILES LICENSE DESTINATION share)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(MSVC_VERSION LESS 1900)
        target_compile_definitions(SafeInt INTERFACE SAFEINT_REMOVE_NOTHROW)
    endif()
endif()

if(SAFEINT_NO_EXCEPTIONS)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(SafeInt INTERFACE -fno-exceptions)
    endif()
endif()
#END OF SAFEINT

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)