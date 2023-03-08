cmake_minimum_required(VERSION 3.24)
project(WordList)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordList main.cpp var/Parameter.cpp var/Parameter.h input/Scanner.cpp input/Scanner.h algorithm/Solver.cpp algorithm/Solver.h var/Word.cpp var/Word.h var/Graph.cpp var/Graph.h algorithm/Algorithm.h algorithm/NoCycle.cpp algorithm/NoCycle.h algorithm/Cycle.cpp algorithm/Cycle.h var/Constant.h tools/JudgeChar.h tools/JudgeChar.cpp var/Information.h)
