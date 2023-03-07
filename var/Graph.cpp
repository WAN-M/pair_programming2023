//
// Created by DELL on 2023/3/7.
//

#include "Graph.h"

void Graph::addNode(Word &word) {
    this->edges.emplace_back();

    for (int i = 0; i < this->nodes.size(); i++) {
        int newPos = (int) this->nodes.size();
        Word node = this->nodes.at(i);
        if (node.getFirst() == word.getLast()) {
            addEdge(newPos, i);
        }
        if (node.getLast() == word.getFirst()) {
            addEdge(i,  newPos);
        }
    }

    this->nodes.push_back(word);
}

void Graph::addEdge(int u, int v) {
    edges.at(u).push_back(v);
}
