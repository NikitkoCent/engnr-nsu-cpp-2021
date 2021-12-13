project(lab2)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(lib/googletest)
add_subdirectory(lib/SafeInt)

include_directories(lib/googletest/googletest/include)
include_directories(lib/SafeInt/Test)

add_executable(lab2 main.cpp Calculator.h command_processing.h tests.h tests.cpp)
target_link_libraries(lab2)

#if (MSVC)
#    target_compile_options(STACK_CALCUTOR
#            PRIVATE /W4 # warnings level
#            PRIVATE /WX # treat all warnings as errors
#            )
#else()
#    target_compile_options(STACK_CALCUTOR
#            PRIVATE -Wall # basic set of warnings
#            PRIVATE -pedantic # modern C++ inspections
#            PRIVATE -Werror # treat all warnings as errors
#            )
#endif()
