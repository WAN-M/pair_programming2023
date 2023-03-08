//
// Created by DELL on 2023/3/8.
//

#ifndef WORDLIST_CYCLE_H
#define WORDLIST_CYCLE_H


#include "Algorithm.h"

class Cycle : public Algorithm {
private:
    void longestPath(int getWeight(const string &path));

public:
    explicit Cycle(Graph &graph, Parameter &parameter) : Algorithm(graph, parameter) {

    }

    void allWordlist() override;

    vector<string> &longestWords() override;

    vector<string> &longestAlphas() override;
};


#endif //WORDLIST_CYCLE_H
