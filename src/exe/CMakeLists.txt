cmake_minimum_required(VERSION 3.22)
project(exe)

set(CMAKE_CXX_STANDARD 14)

add_executable(exe
        main.cpp
        input/Parameter.cpp
        input/Parameter.h
        input/Scanner.h
        input/Scanner.cpp
        exception/CommandException.h
        exception/FileException.h
        exception/Information.h
        exception/RuntimeException.h
        exception/CommandException.cpp
        exception/FileException.cpp
        exception/RuntimeException.cpp)
