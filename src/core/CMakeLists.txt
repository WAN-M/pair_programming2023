cmake_minimum_required(VERSION 3.21)
project(core)

set(CMAKE_CXX_STANDARD 17)

add_library(core
        SHARED
        library.cpp
        var/Parameter.cpp
        var/Parameter.h
        var/Constant.h
        tools/JudgeChar.h
        tools/JudgeChar.cpp
        var/Information.h algorithm/optimize/Graph.cpp algorithm/optimize/Graph.h algorithm/optimize/Node.cpp algorithm/optimize/Node.h algorithm/optimize/Edge.cpp algorithm/optimize/Edge.h tools/Char2Pos.cpp tools/Char2Pos.h algorithm/optimize/Solver.cpp algorithm/optimize/Solver.h algorithm/optimize/Global.cpp algorithm/optimize/Global.h exception/CommandException.cpp exception/CommandException.h exception/FileException.cpp exception/FileException.h exception/RuntimeException.cpp exception/RuntimeException.h)

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
#        algorithm/Solver.cpp
#        algorithm/Solver.h
#        var/Constant.h
#        tools/JudgeChar.h
#        tools/JudgeChar.cpp
#        var/Information.h
#        exception/MyError.cpp
#        exception/MyError.h
#        var/Global.cpp
#        var/Global.h)