//
// Created by DELL on 2023/3/17.
//

#include "Graph.h"
#include "../../tools/Char2Pos.h"
#include "Global.h"

// 初始向vector中加入26个点对应的关系容器
OPTIMIZE::Graph::Graph() {
    for (int i = 0; i < NODE_SIZE; i++) {
        nodes.emplace_back(i);
    }
}

//void OPTIMIZE::Graph::addEdge(Edge *edge) {
//    nodes[char2pos(edge->getU())].addEdge(edge);
//}

// 加入所有边后调用
void OPTIMIZE::Graph::sortAll() {
    for (Node &node: nodes) {
        node.sortAll();
    }
}

OPTIMIZE::Node &OPTIMIZE::Graph::getNode(int pos) {
    return nodes[pos];
}

void OPTIMIZE::Graph::resetAll() {
    for (Node &node: nodes) {
        node.resetAll();
    }
}
