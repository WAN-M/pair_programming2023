//
// Created by DELL on 2023/3/13.
//

#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H


#include "Graph.h"
#include "Parameter.h"

class Global {
private:
    Graph graph;
    Parameter parameter;

    Global();
public:
    Global(const Global &) = delete;

    Global &operator=(const Global &) = delete;

    static Global &get_instance();

    Graph &getGraph();

    Parameter &getParameter();

    void reset();
};


#endif //CORE_GLOBAL_H
