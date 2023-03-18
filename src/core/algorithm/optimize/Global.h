//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H


#include "Graph.h"
#include "../../var/Parameter.h"

#define ALPHA_SIZE 26
#define NODE_SIZE 28
#define SOURCE 26
#define TARGET 27

#define MAX_ANS_LEN 20000

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
