cmake_minimum_required(VERSION 3.21)
project(core)

set(CMAKE_CXX_STANDARD 17)

add_library(core
        SHARED
        library.cpp
        var/Parameter.cpp
        var/Parameter.h
        algorithm/Solver.cpp
        algorithm/Solver.h
        var/Word.cpp
        var/Word.h
        var/Graph.cpp
        var/Graph.h
        algorithm/Algorithm.h
        algorithm/NoCycle.cpp
        algorithm/NoCycle.h
        algorithm/Cycle.cpp
        algorithm/Cycle.h
        var/Constant.h
        tools/JudgeChar.h
        tools/JudgeChar.cpp
        var/Information.h
        error/MyError.cpp
        error/MyError.h
        var/Global.cpp
        var/Global.h)

#add_executable(core
#        main.cpp
#        library.cpp
#        library.h
#        var/Parameter.cpp
#        var/Parameter.h
#        algorithm/Solver.cpp
#        algorithm/Solver.h
#        var/Word.cpp
#        var/Word.h
#        var/Graph.cpp
#        var/Graph.h
#        algorithm/Algorithm.h
#        algorithm/NoCycle.cpp
#        algorithm/NoCycle.h
#        algorithm/Cycle.cpp
#        algorithm/Cycle.h
#        var/Constant.h
#        tools/JudgeChar.h
#        tools/JudgeChar.cpp
#        var/Information.h
#        error/MyError.cpp
#        error/MyError.h
#        var/Global.cpp
#        var/Global.h)