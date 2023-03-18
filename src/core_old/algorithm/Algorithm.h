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

    virtual int allWordlist(char *result[]) = 0;

    virtual int longestWords(char *result[]) = 0;

    virtual int longestAlphas(char *result[]) = 0;
};


#endif //WORDLIST_ALGORITHM_H
