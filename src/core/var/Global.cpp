//
// Created by DELL on 2023/3/13.
//

#include "Global.h"

Global::Global() = default;

Global &Global::get_instance() {
    static Global instance;
    return instance;
}

Graph &Global::getGraph() {
    return graph;
}

Parameter &Global::getParameter() {
    return parameter;
}
