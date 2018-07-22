cmake_minimum_required(VERSION 3.9)
project(cpp_fundamentals_incl_cpp17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "/usr/local/Cellar/gcc/7.3.0_1/bin/gcc-7")
set(CMAKE_CXX_COMPILER "/usr/local/Cellar/gcc/7.3.0_1/bin/g++-7")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(.)

add_executable(cpp_fundamentals_incl_cpp17
        main.cpp
        Person.cpp
        Resource.cpp
        Twitter.cpp
        Utility.cpp)
