//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_GRAPH_H
#define WORDLIST_GRAPH_H


#include <vector>
#include "../algorithm/Word.h"

class Graph {
private:
    int size = 0;
    vector<Word> nodes;
    vector<vector<int>> edges;

    void addEdge(int u, int v);

public:
    void addNode(Word &word);

    int getSize() const;

    const vector<Word> &getNodes() const;

    const vector<vector<int>> &getEdges() const;
};


#endif //WORDLIST_GRAPH_H
