//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H


#include "Graph.h"
#include "../../var/Parameter.h"

namespace OPTIMIZE {
    class Global {
    private:
        OPTIMIZE::Graph graph;
        Parameter parameter;

        Global();
    public:
        Global(const Global &) = delete;

        Global &operator=(const Global &) = delete;

        static Global &get_instance();

        OPTIMIZE::Graph &getGraph();

        Parameter &getParameter();
    };
}



#endif //CORE_GLOBAL_H
