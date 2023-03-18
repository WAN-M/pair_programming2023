//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_GRAPH_H
#define CORE_GRAPH_H


#include "Node.h"

namespace OPTIMIZE {
    class Graph {
    private:
        vector<Node> nodes;
    public:
        Graph();

        void sortAll();

        void resetAll();

        Node &getNode(int pos);
    };
}

#endif //CORE_GRAPH_H
