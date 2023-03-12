//
// Created by DELL on 2023/3/8.
//

#ifndef WORDLIST_ALGORITHM_H
#define WORDLIST_ALGORITHM_H

#include <vector>
#include <string>
#include "../var/Graph.h"
#include "../var/Parameter.h"

using namespace std;

class Algorithm {
protected:
    Parameter &parameter;
    Graph &graph;
public:
    explicit Algorithm(Graph &graph, Parameter &parameter) : graph(graph), parameter(parameter) {}

    virtual ~Algorithm() = default;

    virtual void allWordlist() = 0;

    virtual vector<string> &longestWords() = 0;

    virtual vector<string> &longestAlphas() = 0;
};


#endif //WORDLIST_ALGORITHM_H
