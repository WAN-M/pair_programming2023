cmake_minimum_required(VERSION 3.24)
project(WordList)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordList main.cpp var/Parameter.cpp var/Parameter.h input/Scanner.cpp input/Scanner.h algorithm/Solver.cpp algorithm/Solver.h algorithm/Word.cpp algorithm/Word.h var/Graph.cpp var/Graph.h)
