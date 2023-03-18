//
// Created by DELL on 2023/3/17.
//

#include "Graph.h"
#include "../../tools/Char2Pos.h"
#include "Global.h"

// ��ʼ��vector�м���26�����Ӧ�Ĺ�ϵ����
OPTIMIZE::Graph::Graph() {
    for (int i = 0; i < NODE_SIZE; i++) {
        nodes.emplace_back(i);
    }
}

//void OPTIMIZE::Graph::addEdge(Edge *edge) {
//    nodes[char2pos(edge->getU())].addEdge(edge);
//}

// �������бߺ����
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
