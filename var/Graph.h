//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_GRAPH_H
#define WORDLIST_GRAPH_H


#include <vector>
#include "Word.h"

class Graph {
private:
    int size = 0;
    vector<Word> nodes;
    vector<vector<int>> edges;
public:
    Graph();

    Graph(Graph const &o);

    void addEdge(int u, int v);

    // 第二个参数表示是否自动增加边的关系
    void addNode(Word &word, bool autoEdges = true);

    int getSize() const;

    Word &getNode(int pos);

    const vector<Word> &getNodes() const;

    const vector<vector<int>> &getEdges() const;
};


#endif //WORDLIST_GRAPH_H
