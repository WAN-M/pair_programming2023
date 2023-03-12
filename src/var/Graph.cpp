//
// Created by DELL on 2023/3/7.
//

#include "Graph.h"

Graph::Graph() {}

Graph::Graph(const Graph &o) {
    this->size = o.size;
    this->nodes.assign(o.getNodes().begin(), o.getNodes().end());
    for (int i = 0; i < size; i++) {
        vector<int> v;
        v.assign(o.getEdges().at(i).begin(), o.getEdges().at(i).end());
        this->edges.push_back(v);
    }
}

void Graph::addNode(Word &word, bool autoEdges) {
    this->edges.emplace_back();

    if (autoEdges) {
        for (int i = 0; i < this->nodes.size(); i++) {
            int newPos = (int) this->nodes.size();
            Word node = this->nodes.at(i);
            if (node.getFirst() == word.getLast()) {
                addEdge(newPos, i);
            }
            if (node.getLast() == word.getFirst()) {
                addEdge(i, newPos);
            }
        }
    }

    this->nodes.push_back(word);
    this->size++;
}

void Graph::addEdge(int u, int v) {
    edges.at(u).push_back(v);
}

int Graph::getSize() const {
    return size;
}

Word &Graph::getNode(int pos) {
    return nodes.at(pos);
}

const vector<vector<int>> &Graph::getEdges() const {
    return edges;
}

const vector<Word> &Graph::getNodes() const {
    return nodes;
}


