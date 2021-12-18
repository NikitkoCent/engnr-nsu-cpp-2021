cmake_minimum_required(VERSION 3.19)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

#add_compile_options(-DUSE_BOOST_FS)

add_link_options(-lpthread -v)

include_directories(dirwalker/)

add_executable(lab3 main.cpp
        dirwalker/SafeQueue.cpp
        dirwalker/ThreadPool.cpp
        dirwalker/SafeQueue.h
        dirwalker/ThreadPool.h)

# Boost
set(boost_min_ver 1.50.0)
set(boost_libs system filesystem)
find_package(Boost ${boost_min_ver})

if(Boost_FOUND)
    find_package(Boost ${boost_min_ver} COMPONENTS ${boost_libs})
endif()

target_link_libraries(lab3 ${Boost_LIBRARIES})



