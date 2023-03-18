//
// Created by DELL on 2023/3/17.
//

#include <cstring>
#include <algorithm>
#include "Node.h"
#include "Global.h"

OPTIMIZE::Node::Node(int pos) {
    this->pos = pos;
//    memset(edgePos, 0, sizeof(edgePos));
    for (int i = 0; i < NODE_SIZE; i++) {
        edges.emplace_back();
//        edges.push_back(list<Edge *>());
        edgePos[i] = edges[i].begin();
    }
}


using namespace std;
void OPTIMIZE::Node::addEdge(Edge *e) {
    edges[e->getV()].push_back(e);
    next.insert(e->getV());
}

void OPTIMIZE::Node::resetAll() {
//    memset(edgePos, 0, sizeof(edgePos));
    for (int i = 0; i < NODE_SIZE; i++) {
        edgePos[i] = edges[i].begin();
    }
}

OPTIMIZE::Edge *OPTIMIZE::Node::nextEdge(int v) {
//    return edges[v][edgePos[v]];
    return *edgePos[v];
}

bool OPTIMIZE::Node::hasEdge(int v) {
//    return edgePos[v] < edges[v].size();
    return edgePos[v] != edges[v].end();
}

void OPTIMIZE::Node::sortAll() {
    for (int i: next) {
//        sort(edges[i].begin(), edges[i].end());
        edges[i].sort();
        edgePos[i] = edges[i].begin();
    }
}

const set<int> &OPTIMIZE::Node::getNext() const {
    return next;
}

void OPTIMIZE::Node::increaseItr(int v) {
    edgePos[v]++;
}

void OPTIMIZE::Node::decreaseItr(int v) {
    edgePos[v]--;
}

//int OPTIMIZE::Node::getEdgePos(int v) {
//    return edgePos[v];
//}
//
//void OPTIMIZE::Node::setEdgePos(int v, int value) {
//    edgePos[v] = value;
//}


