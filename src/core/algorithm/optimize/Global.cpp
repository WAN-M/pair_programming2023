//
// Created by DELL on 2023/3/17.
//

#include "Global.h"

OPTIMIZE::Global &OPTIMIZE::Global::get_instance() {
    static Global instance;
    return instance;
}

OPTIMIZE::Graph &OPTIMIZE::Global::getGraph() {
    return graph;
}

Parameter &OPTIMIZE::Global::getParameter() {
    return parameter;
}

void OPTIMIZE::Global::reset() {
    graph = Graph();
    parameter = Parameter();
}

OPTIMIZE::Global::Global() = default;
