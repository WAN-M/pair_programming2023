cmake_minimum_required(VERSION 3.22)
project(exe)

set(CMAKE_CXX_STANDARD 14)

add_executable(exe
        main.cpp
        input/Parameter.cpp
        input/Scanner.cpp
        error/Error.cpp exception/Information.h)
